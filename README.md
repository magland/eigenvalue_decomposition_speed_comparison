# eigenvalue_decomposition_speed_comparison
**Why is LAPACK/C++ 10+ times slower than MATLAB's eig?**

Using Qt5:
```bash
cd cpp
qmake
make
./eigtest
```

From MATLAB:
```matlab
Run matlab/eigtest.m
```

Here's what I get for the output of C++:
```
***** LAPACKE_dsyev *****
First 10 eigenvalues:
-915.86 -247.659 -20.521 -13.2655 -0.33748 -0.0701345 -0.00401023 -0.000116773 -2.73344e-05 -1.57223e-07 
M=2000: Elapsed time (sec) = 21.291

***** LAPACKE_dsyevd *****
First 10 eigenvalues:
-915.86 -247.659 -20.521 -13.2655 -0.33748 -0.0701345 -0.00401023 -0.000116773 -2.73344e-05 -1.57223e-07 
M=2000: Elapsed time (sec) = 10.62
```

And here's the output of MATLAB:
```
>> eigtest
First 10 eigenvalues:
 -915.8596 -247.6585  -20.5210  -13.2655   -0.3375   -0.0701   -0.0040   -0.0001   -0.0000   -0.0000

M=2000: Elapsed time (sec) = 0.453836
```

The reason for the discrepancy is that MATLAB is making **very** good use of multiple CPUs!

