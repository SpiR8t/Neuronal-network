#include "neural_network.h"
#include <stdlib.h>
#include <stdio.h>

NeuralNetwork *neural_network_create(size_t input_size, size_t hidden_size, size_t output_size) {
    return NULL;
}

void neural_network_destroy(NeuralNetwork *neural_network) {
    return;
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