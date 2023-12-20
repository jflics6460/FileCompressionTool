#include <string>

#include "huffmanTree.h"

int main () {
    // read input

    // parse input
    std::string rawMessage = "streets are stone stars are not";
    HuffmanTree test(rawMessage);
    test.generateEncodings();
    std::cout << "j";
    // produce output
}