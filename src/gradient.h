#ifndef GRADIENT_H
#define GRADIENT_H

#include "neural_network.h"

typedef struct {
    double *hidden_weights;
    double *hidden_bias;
    double *output_weights;
    double *output_bias;
} Gradient;


#endif
