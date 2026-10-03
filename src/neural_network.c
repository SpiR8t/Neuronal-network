#include "neural_network.h"
#include "activation.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

double xavier_uniform(int n_in, int n_out) {
	double limit = sqrt(6.0 / (n_in + n_out));

	double u = (double)rand() / (double)RAND_MAX;
	return -limit + 2.0 * limit * u;
}

NeuralNetwork *neural_network_create(size_t input_size, size_t hidden_size, size_t output_size) {
	if (input_size < 2 || hidden_size < 1 || output_size < 1) {
		return NULL;
	}
	NeuralNetwork *neural_network = calloc(1, sizeof(NeuralNetwork));
	if (!neural_network) {
		return NULL;
	}
	neural_network->input_size = input_size;
	neural_network->hidden_size = hidden_size;
	neural_network->output_size = output_size;

	neural_network->hidden_weights = calloc(hidden_size*input_size, sizeof(double));
	if (!neural_network->hidden_weights) {
		return NULL;
	}
	for (size_t i = 0; i < hidden_size*input_size; i++) {
		neural_network->hidden_weights[i] = xavier_uniform(input_size, hidden_size);
	}

	neural_network->hidden_bias = calloc(hidden_size, sizeof(double));
	if (!neural_network->hidden_bias) {
		free(neural_network->hidden_weights);
		return NULL;
	}
	neural_network->output_weights = calloc(hidden_size*output_size, sizeof(double));	
	if (!neural_network->output_weights) {
		free(neural_network->hidden_weights);
		free(neural_network->hidden_bias);
		return NULL;
	}
	for (size_t i = 0; i < hidden_size*input_size; i++) {
		neural_network->output_weights[i] = xavier_uniform(hidden_size, output_size);
	}
	
	neural_network->output_bias = calloc(output_size, sizeof(double));
	if (!neural_network->output_bias) {
		free(neural_network->hidden_weights);
		free(neural_network->hidden_bias);
		free(neural_network->output_weights);
		return NULL;
	}
	neural_network->hidden = calloc(hidden_size, sizeof(double));
	if (!neural_network->hidden) {
		free(neural_network->hidden_weights);
		free(neural_network->hidden_bias);
		free(neural_network->output_weights);
		free(neural_network->output_bias);
		return NULL;
	}
	neural_network->output = calloc(output_size, sizeof(double));
	if (!neural_network->output) {
		free(neural_network->hidden_weights);
		free(neural_network->hidden_bias);
		free(neural_network->output_weights);
		free(neural_network->output_bias);
		free(neural_network->hidden);
		return NULL;
	}
	
	return neural_network;

}

void neural_network_destroy(NeuralNetwork *neural_network) {
	if (!neural_network) {
		return;
	}
	free(neural_network->hidden_weights);
	free(neural_network->hidden_bias);
	free(neural_network->output_weights);
	free(neural_network->output_bias);
	free(neural_network->hidden);
	free(neural_network->output);
	free(neural_network);
}

void neural_network_forward(NeuralNetwork *network, const double *input) {
    size_t input_size = network->input_size;
    size_t hidden_size = network->hidden_size;
    size_t output_size = network->output_size;

    for (size_t i = 0; i < hidden_size; i++) {
    	double sum = network->hidden_bias[i];

    	for (size_t j = 0; j < input_size; j++) {
    		double weight = network->hidden_weights[i * input_size + j];

    		sum += weight * input[j];
    	}

    	network->hidden[i] = sigmoid(sum);
    }

    for (size_t k = 0; k < output_size; k++) {
    	double sum = network->output_bias[k];

    	for (size_t i = 0; i < hidden_size; i++) {
    		double weight = network->output_weights[k * hidden_size + i];

    		sum += weight * network->hidden[i];
    	}

    	network->output[k] = sum; // we will do the softmax then
    }

    softmax(network->output, network->output, network->output_size);
}

Gradient *neural_network_backward(NeuralNetwork *network, const double *input, const double *expected) {
    		Gradient *gradient = gradient_create(network);
		if (!gradient) {
			return NULL;
		}
		
		double *output_delta = calloc(network->output_size, sizeof(double));
		double *hidden_delta = calloc(network->hidden_size, sizeof(double));
		if (!output_delta || !hidden_delta) {
			free(hidden_delta);
			free(output_delta);
			gradient_destroy(gradient);
			return NULL;
		}

		// output delta
		for (size_t k = 0; k < network->output_size; k++) {
			output_delta[k] = network->output[k] - expected[k];
		}

		// output gradient
		for (size_t k = 0; k < network->output_size; k++) {
			gradient->output_bias[k] = output_delta[k];

			for (size_t i = 0; i < network->hidden_size; i++) {
				gradient->output_weights[k*network->hidden_size + i] = output_delta[k] * network->hidden[i];
			}
		}

		// hidden delta
		for (size_t i = 0; i < network->hidden_size; i++) {
			double error = 0.0;

			for (size_t k = 0; k < network->output_size; k++) {
				error += output_delta[k] * network->output_weights[k * network->hidden_size + i];
			}

			hidden_delta[i] = error * network->hidden[i] * (1.0 - network->hidden[i]);
		}

		// hidden gradient
		for (size_t i = 0; i < network->hidden_size; i++) {
			gradient->hidden_bias[i] = hidden_delta[i];

			for (size_t j = 0; j < network->input_size; j++) {
				gradient->hidden_weights[i * network->input_size + j] = hidden_delta[i] * input[j];
			}
		}

		free(output_delta);
		free(hidden_delta);
		return gradient;
}



void neural_network_train(NeuralNetwork *network, Dataset *dataset) {
    return;
}

void neural_network_predict(NeuralNetwork *network, const double *input, double *output) {
    return;
}

