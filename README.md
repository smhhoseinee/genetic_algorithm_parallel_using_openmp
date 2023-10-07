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
### Selection: Individuals are selected probabilistically based on fitness to form the next generation population. Higher fitness means higher selection chance.

### Crossover: Pairs of selected individuals reproduce to create offspring for the next generation. Offspring are expected to have higher fitness but randomness can lead to the opposite.

### Mutation: Random changes are introduced to an individual's genes with a small probability. This step has O(1) time complexity and does not impact runtime.

## Other Sections
### Initial population: Read from a static file instead of random generation for consistent benchmarking.

### Sorting: Simple O(n^2) sort to order the population by fitness.

### Fitness evaluation: Compute fitness value for each individual.

## Analysis
Comparisons are made between serial and parallel execution with different population sizes and max iterations. Parallelization provides significant speedups for large populations and iterations.

Thread counts are analyzed in static and dynamic modes. After 4 threads, dynamic outperforms static as thread counts increase.

## Challenges and Key Points
The sequential nature of genetic algorithm steps posed challenges for parallelization. Each step was parallelized separately.

Too many threads negatively impacts performance after a point.

Comparisons of static and dynamic threads provided useful insights.

Trends in execution time charts are noteworthy.

Source code is available on Github for reference.
