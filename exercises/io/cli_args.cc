#include "cli_args.h"
#include "io_math.h"

#include <iostream>
#include <fstream>
#include <string>

Options parse_args(int argc, char* argv[]) {
    Options opt;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-n" && i + 1 < argc) {
            opt.numbers.push_back(std::stod(argv[i + 1]));
            ++i; // skip the number we just read
        }
        else if (arg == "--input" && i + 1 < argc) {
            opt.infile = argv[i + 1];
            ++i;
        }
        else if (arg == "--output" && i + 1 < argc) {
            opt.outfile = argv[i + 1];
            ++i;
        }
        else {
            // If you want: treat unknown args as error
            // std::cerr << "Unknown argument: " << arg << "\n";
        }
    }

    return opt;
}

int run_program(const Options& opt) {
    // Mode A: file streams mode if both input & output are given
    if (!opt.infile.empty() || !opt.outfile.empty()) {
        if (opt.infile.empty() || opt.outfile.empty()) {
            std::cerr << "Error: use both --input <file> and --output <file>\n";
            return 1;
        }

        std::ifstream in(opt.infile);
        std::ofstream out(opt.outfile);

        if (!in.is_open() || !out.is_open()) {
            std::cerr << "Error opening files: " << opt.infile << " " << opt.outfile << "\n";
            return 1;
        }

        process_stream(in, out);
        return 0;
    }

    // Mode B: command-line numbers mode if any -n was provided
    if (!opt.numbers.empty()) {
        for (double x : opt.numbers) {
            print_row(std::cout, x);
        }
        return 0;
    }

    // Mode C: default to stdin mode (read numbers from standard input)
    process_stream(std::cin, std::cout);
    return 0;
}