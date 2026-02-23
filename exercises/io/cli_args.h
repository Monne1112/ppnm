#pragma once
#include <string>
#include <vector>

struct Options {
    std::vector<double> numbers;   // for: -n 1 -n 2 ...
    std::string infile;            // for: --input file
    std::string outfile;           // for: --output file
};

Options parse_args(int argc, char* argv[]);
int run_program(const Options& opt);