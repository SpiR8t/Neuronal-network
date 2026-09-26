typedef struct
{
    double *input;
    double *expected;
} TrainingExample;

typedef struct
{
    TrainingExample *examples;
    size_t size;
    size_t input_size;
    size_t output_size;
} Dataset;