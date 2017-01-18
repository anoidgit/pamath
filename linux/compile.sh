#!/bin/bash
infile=pamath_core.cpp
ofile=pamath_core.so
g++ -o $ofile -Ofast -fopenmp -shared -fPIC $infile
