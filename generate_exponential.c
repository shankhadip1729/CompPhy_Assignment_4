#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_RANDOMS 10000
#define LAMBDA 2.0

// Function to generate exponential random number
double generate_exponential(double lambda) {
    double u = rand() / (RAND_MAX + 1.0);
    return -log(1 - u) / lambda;
}

int main() {
    double random_numbers[NUM_RANDOMS];
    
    // Seed the random number generator
    srand(42);
    
    // Generate random numbers
    for (int i = 0; i < NUM_RANDOMS; ++i) {
        random_numbers[i] = generate_exponential(LAMBDA);
    }
    
    // Write random numbers to a file
    FILE *f = fopen("exponential_random_numbers.txt", "w");
    for (int i = 0; i < NUM_RANDOMS; ++i) {
        fprintf(f, "%f\n", random_numbers[i]);
    }
    fclose(f);

    return 0;
}
