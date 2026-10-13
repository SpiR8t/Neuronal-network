#include "neural_network.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	srand(42);

	const size_t input_size = 2;
	const size_t hidden_size = 4;
	const size_t output_size = 2;

	double input_0[] = {1.0, 0.0};
	double input_1[] = {0.0, 0.0};
	double input_2[] = {0.0, 1.0};
	double input_3[] = {1.0, 1.0};

	double expected_0[] = {0.0, 1.0};
	double expected_1[] = {1.0, 0.0};
	double expected_2[] = {0.0, 1.0};
	double expected_3[] = {1.0, 0.0};

	TrainingExample examples[] = {
		{input_0, expected_0},
		{input_1, expected_1},
		{input_2, expected_2},
		{input_3, expected_3},
	
	};

	Dataset dataset = {
		.examples = examples,
		.size = 4,
		.input_size = input_size,
		.output_size = output_size
	};
	
	NeuralNetwork *network = neural_network_create(input_size, hidden_size, output_size);

	if (!network) {
		printf("Error creating the network");
		return EXIT_FAILURE;
	}

	printf("Starting the training\n");

	neural_network_train(network, &dataset, 2000, 0.1);

	printf("\nPrediction after training: to dev\n");
	neural_network_destroy(network);
}
