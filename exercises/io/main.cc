#include "cli_args.h"
#include <cstdlib>

int main(int argc, char* argv[]) {
    Options opt = parse_args(argc, argv);
    int code = run_program(opt);
    return code == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}