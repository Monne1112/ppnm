#include <iostream>
#include <thread>
#include <vector>
#include <cmath>


int nthreads = 1, nterms = (int)1e8; /* default values */
for(int i=0;i<argc;i++) {
   std::string arg = argv[i];
   if(arg=="-threads" && i+1<argc) nthreads=std::stoi(argv[i+1]);
   if(arg=="-terms" && i+1<argc) nterms=std::stoi(argv[i+1]);
   }