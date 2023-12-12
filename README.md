# Parallelized Genetic Algorithm using OpenMP(opm) 
run parallel version using the command below :
```
g++ .\genetic_paralleled_using_omp.cpp -o .\parallel.exe -fopenmp
.\parallel.exe
```
or run unparalleled version istead :
```
g++ .\genetic_no_parallelism.cpp -o .\unparalleled.exe -fopenmp
.\unparalleled.exe
```
---
- Note that these results are based on ``population.txt ``which is a sample population (you can generate your own population using the ``rnad_population_generator.py`` python script )
- you can find detailed report about this implementation on  ``report.pdf`` file

Time/Population execution results: 

![Screenshot 2022-09-27 135734](https://user-images.githubusercontent.com/45815376/192565314-2eeb1b7f-26aa-49cc-bc62-90aa65cbefa3.png)

Time/Iterations Diagram : 

![Screenshot 2022-09-27 135755](https://user-images.githubusercontent.com/45815376/192565289-0581f6e3-580d-4f36-ac04-0f06e3426ca3.png)

Time/Threads Diagram : 

![Screenshot 2022-09-27 135809](https://user-images.githubusercontent.com/45815376/192565305-07990bd5-a8d5-446d-9539-689635fb42a3.png)


# Full Report:

Here is a summary of the key points from the Persian report translated into English:

## Genetic Algorithm
The genetic algorithm is a heuristic search algorithm based on Darwin's theory of evolution. The main steps of the algorithm include Selection, Crossover, and Mutation. These steps are completely sequential, meaning each step depends on the output of the previous step.

The most computationally intensive parts are Selection and Crossover, where parallelization provides significant performance improvements.

The algorithm requires setting several key parameters like Population size, Max Iterations, and Mutation Probability which are hardcoded. Different parameter configurations lead to different performance and accuracy results.

## Main Algorithm Steps
Selection: Individuals are selected probabilistically based on fitness to form the next generation population. Higher fitness means higher selection chance.

Crossover: Pairs of selected individuals reproduce to create offspring for the next generation. Offspring are expected to have higher fitness but randomness can lead to the opposite.

Mutation: Random changes are introduced to an individual's genes with a small probability. This step has O(1) time complexity and does not impact runtime.

## Other Sections
Initial population: Read from a static file instead of random generation for consistent benchmarking.

Sorting: Simple O(n^2) sort to order the population by fitness.

Fitness evaluation: Compute fitness value for each individual.

## Analysis
Comparisons are made between serial and parallel execution with different population sizes and max iterations. Parallelization provides significant speedups for large populations and iterations.

Thread counts are analyzed in static and dynamic modes. After 4 threads, dynamic outperforms static as thread counts increase.

The provided code is an implementation of a genetic algorithm in C++, which aims to find an optimal solution to a problem by mimicking the process of natural selection and evolution. The algorithm starts with an initial population of chromosomes, which are potential solutions to the problem. It then iteratively performs selection, crossover, and mutation operations on the population to generate the next generation of chromosomes. The code uses OpenMP, a library for shared-memory parallel programming, to parallelize certain parts of the algorithm and improve its performance. OpenMP allows the code to be executed in parallel by distributing the workload among multiple threads. Here is an explanation of the parallelism in the code: 

1. Specifying the number of threads: The following line sets the number of threads to be used by OpenMP to 64. 
```cpp 
omp_set_num_threads(64);
``` 

This means that the subsequent parallel regions will be executed using 64 threads. 

2. Parallelizing the main loop: The main algorithmic loop, which represents the iterations of the genetic algorithm, is parallelized using OpenMP's parallel for directive. This allows multiple iterations of the loop to be executed concurrently by different threads. 
```cpp 
#pragma omp parallel for for (int i = 0; i < ITER; i++) { // ... }
```

3. Parallelizing the printing of the population: The `print_pop` function, which prints the population, is also parallelized using OpenMP's parallel for directive. This allows multiple threads to print different chromosomes of the population simultaneously. 
```cpp
void print_pop(chrom pop[POPULATION]) { // ... #pragma omp parallel for for (int i = 0; i < POPULATION; i++) { // ... } // ... }
``` 

4. Parallelizing the conversion of chromosome string to chromosome structure: The `convert_str_2_chrom` function, which converts a string representation of a chromosome to a chromosome structure, is parallelized using OpenMP's parallel for directive. This allows multiple threads to perform the conversion for different bits of the chromosome simultaneously. 
```cpp
chrom convert_str_2_chrom(char *chrom_str) { chrom chromo; #pragma omp parallel for for (int i = 0; i < GENE_COUNT; i++) { // ... } return chromo; } 
```

5. Parallelizing the calculation of fitness values: The calculation of fitness values for each chromosome in the population is parallelized using OpenMP's parallel for directive. This allows multiple threads to calculate fitness values for different chromosomes concurrently.
```cpp
#pragma omp parallel for for (int i = 0; i < POPULATION; i++) { popcurrent[i].fit = fitness(popcurrent[i]); total_fitness += popcurrent[i].fit; }
```

6. Parallelizing the selection process: The `select` function, which performs the selection operation on the current population, is parallelized using OpenMP's parallel for directive. This allows multiple threads to select different chromosomes from the population concurrently.
```cpp
void select(chrom popcurrent[POPULATION], chrom selected[POPULATION]) { // ... #pragma omp parallel for for (int j = 0; j < POPULATION; j++) { // ... } // ... }
```
7. Parallelizing the sorting of the population: The `sort` function, which sorts the population based on fitness values, is parallelized using OpenMP's parallel for directive. This allows multiple threads to sort different parts of the population concurrently.
```cpp
void sort(chrom popcurrent[POPULATION]) { // ... #pragma omp parallel for collapse(2) for (int i = 0; i < POPULATION; i++) { for (int j = 0; j < POPULATION - 1; j++) { // ... } } // ... }
``` 
8. Parallelizing the mutation operation: The `mutation` function, which introduces random mutations in the population, is parallelized using OpenMP's parallel for directive. This allows multiple threads to mutate different chromosomes concurrently.
```cpp
void mutation(chrom popnext[POPULATION]) { // ... #pragma omp parallel for for (int chrom_counter = 0; chrom_counter < POPULATION; chrom_counter++) { // ... } }
```
Overall, the parallelism in the code leverages OpenMP to divide the workload among multiple threads, allowing for concurrent execution of different parts of the genetic algorithm. This can potentially improve the performance of the algorithm by utilizing the available computational resources more efficiently.


## Challenges and Key Points
The sequential nature of genetic algorithm steps posed challenges for parallelization. Each step was parallelized separately.

Too many threads negatively impacts performance after a point.

Comparisons of static and dynamic threads provided useful insights.

Trends in execution time charts are noteworthy.

Source code is available on Github for reference.
