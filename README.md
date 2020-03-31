# Introduction
This repo contains the source code for a solution to the problem of adding a number to a sample and calculating the median value of the sample. 

# Solution details
The actual solution is based on the following few ideas:
1. The sample is stored in two separate containers using `priority_queue` for both. 
1. The first container uses default constructor, which leads to `top()` returning the maximum element (it is called `left_queue`), the second container is initialized so that `top()` would return the smallest element (`right_queue`). 
1. When adding a value, it is added to only one of the above, so that all elements in `left_queue` are less or equal to each element in `right_queue` and vice versa.
1. The two objects are rebalanced so that their sizes differ with each other by at most one.
1. Thus, the median is calculated for constant time (either as one `top` operation or as mean of the two `top` operations).
1. The drawback is that adding the number has logarithmic complexity.


# Techical Details
1. Data structure is part of `streamingMedian.h` file. 
1. Building is done via CMake and `CMakeLists.txt`
1. `main.cpp` contains simple example of usage. 
1. `testRunner.cpp` contains code that does unit testing for the data structure. The actual tests are performed via `ctest` based on the files in `tests` directory.