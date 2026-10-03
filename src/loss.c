#include "loss.h"
#include <math.h>

double cross_entropy(const double *expected, const double *predicted, size_t size) {
	double loss = 0.0;

	for (size_t i = 0; i < size; i++) {
		loss -= expected[i] * log(predicted[i]);
	}

	return loss;
}
