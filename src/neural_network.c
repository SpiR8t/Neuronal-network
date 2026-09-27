#include "neural_network.h"
#include <stdlib.h>
#include <stdio.h>

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

	// initializing the weights ?
	//
	
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
    return;

}

void neural_network_backward(NeuralNetwork *network, const double *expected) {
    return;
}

void neural_network_train(NeuralNetwork *network, Dataset *dataset) {
    return;
}

void neural_network_predict(NeuralNetwork *network, const double *input, double *output) {
    return;
}
