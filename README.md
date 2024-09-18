# CodilityTasks

## Table of Contents
-----------------

* [Introduction](#introduction)
* [Building and Running](#building-and-running)

## Introduction
---------------

This project contains solutions for following codility tasks:
1. [TapeEquilibrium](https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/)
2. [MaxCounters](https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/)
3. [GenomicRangeQuery](https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/)
4. [MinAvgTwoSlice](https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/)
5. [Triangle](https://app.codility.com/programmers/lessons/6-sorting/triangle/)
6. [NumberofDiscIntersections](https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/)
7. [Nesting](https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/)
8. [StoneWall](https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/)
9. [Dominator](https://app.codility.com/programmers/lessons/8-leader/dominator/)
10. [EquiLeader](https://app.codility.com/programmers/lessons/8-leader/equi_leader/)
11. [MaxSliceSum](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/)
12. [MaxDoubleSliceSum](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/)
13. [Flags](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/) 
14. [Peaks](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/peaks/)
15. [CountNonDivisible](https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible/) 

## Building and Running
---------------------

To build and run the project locally, follow these steps:

1. Clone the repository
2. Navigate to the project directory: `cd CodilityTasks`
3. Create a build directory: `mkdir build`
4. Navigate to the build directory: `cd build`
5. Run CMake: `cmake ..`
6. Build the project: `make`
7. Run tasks: `./<TaskName>/<taskName>`

To build and run the project in container, follow these steps:

1. Clone the repository
2. Navigate to the project directory: `cd CodilityTasks`
3. Create image: `docker build -t codilityimage .`
4. Run contianer `docker run --rm -it -v.:/app --name codilitycontainer codilityimage`
5. Create a build directory: `mkdir build`
6. Navigate to the build directory: `cd build`
7. Run CMake: `cmake ..`
8. Build the project: `make`
9. Run tasks: `./<TaskName>/<taskName>`

