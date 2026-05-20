#include "file_convertor.hpp"

int main(int argc, char* argv[]) {
    Arguments args;

    if (!parseArguments(argc, argv, args)) {
        return 1;
    }

    ensureOutputPath(args);

    if (!convertImage(args)) {
        return 1;
    }

    return 0;
}
