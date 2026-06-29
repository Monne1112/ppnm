LEAST-SQUARES ERROR CONCEALMENT
===============================

This project implements a recovery of missing samples in a one-dimensional signal, using the least-squares 
method in 1.4.4 of https://fedorov.sdfeu.org/prog/book/leastsq.pdf.

The program generates a test signal, randomly removes samples by replacing them
with zeros, and reconstructs the missing values by minimizing the second
differences of the signal. The resulting linear least-squares problem is solved
using my own QR decomposition routine from previous homework.

Files:
- matrix.h      : vector and matrix classes
- qr.h          : QR decomposition and linear solver
- recover.h/.cc: least-squares recovery routine
- main.cc       : test program and data generation
- recover.gpi   : gnuplot script for visualization
- Makefile      : build rules

Usage:
    make plot

This generates:
- recover.data
- recover.png

The plot shows the original signal, the corrupted signal, and the recovered
samples.

Self-evaluation:
9.3/10

The implementation successfully reconstructs missing samples and uses my own QR
least-squares solver. The code could be improved by using a more efficient
construction of the recovery matrix and by testing additional recovery scenarios.