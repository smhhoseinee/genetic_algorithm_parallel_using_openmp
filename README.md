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
