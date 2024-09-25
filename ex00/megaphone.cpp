#include <iostream>

int main(int argc, char**argv) {
    int i = 1;
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while (i < argc) {
        for (size_t j = 0; j < strlen(argv[i]); j++) {
            std::cout << (char)toupper(argv[i][j]);
        }
        i++;
        if (i != argc)
            std::cout << " ";
    }
    return 0;
}