#!/bin/bash

infile=double_pamath_core.cpp
ofile=double_pamath_core.so
g++ -o $ofile -Ofast -fopenmp -shared -fPIC $infile

infile=float_pamath_core.cpp
ofile=float_pamath_core.so
g++ -o $ofile -Ofast -fopenmp -shared -fPIC $infile

infile=long_double_pamath_core.cpp
ofile=long_double_pamath_core.so
g++ -o $ofile -Ofast -fopenmp -shared -fPIC $infile
