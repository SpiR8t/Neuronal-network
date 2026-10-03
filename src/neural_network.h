#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <stddef.h>

// fake definition to avoid errors during testing
typedef struct {
	int a;
} Dataset;
//

typedef struct {
    double *hidden_weights;
    double *hidden_bias;
    double *output_weights;
    double *output_bias;
} Gradient;

Gradient *gradient_create(const NeuralNetwork *network);
void gradient_destroy(Gradient *gradient);

typedef struct {
	size_t input_size;
	size_t hidden_size;
	size_t output_size;

	double *hidden_weights;
	double *hidden_bias;

	double *output_weights;
	double *output_bias;

	double *hidden;
	double *output;
} NeuralNetwork;

NeuralNetwork *neural_network_create(size_t input_size, size_t hidden_size, size_t output_size);
void neural_network_destroy(NeuralNetwork *neural_network);

void neural_network_forward(NeuralNetwork *network, const double *input);
void neural_network_backward(NeuralNetwork *network, const double *expected);
void neural_network_train(NeuralNetwork *network, Dataset *dataset);

void neural_network_predict(NeuralNetwork *network, const double *input, double *output);


#endif
