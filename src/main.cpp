#include <string>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <functional>

#include "huffmanNode.h"


std::string getHuffmanEncoding(std::string rawMessage) {
    std::unordered_map<char, unsigned int> counts;
    
    auto comp = []( HuffmanNode* lhs, HuffmanNode* rhs ) -> bool { return *lhs > *rhs; };
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, decltype (comp) > nodesToCombine(comp);
    // get counts for each character
    for(auto c = rawMessage.begin(); c < rawMessage.end(); c++) {
        counts[*c] = counts[*c] + 1;
    }

    for(auto& [encodedChar, priority] : counts) {
        HuffmanNode* tmp = new HuffmanNode(priority, encodedChar);
        nodesToCombine.push(tmp);
    }
    // use counts to make huffman tree
    while(!nodesToCombine.empty()) {
        HuffmanNode* minNode = nodesToCombine.top();
        nodesToCombine.pop();
        std::cout << minNode->getEncodedChar() << ": " << minNode->getPriority() << std::endl;
    }

    return rawMessage;
} 


int main () {
    // read input

    // parse input
    std::string rawMessage = "streets are stone stars are not";
    getHuffmanEncoding(rawMessage);
    // produce output
}