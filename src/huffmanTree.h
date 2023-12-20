#include <string>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <functional>

#include "huffmanTreeNode.h"

class HuffmanTree {
    // FIXME: Edge case: string with only one character 
public:
    // TODO: eventually take generic stream
    HuffmanTree(std::string rawMessage) {
        std::unordered_map<char, unsigned int> counts;

        auto comp = []( HuffmanTreeNode* lhs, HuffmanTreeNode* rhs ) -> bool { return *lhs > *rhs; };
        std::priority_queue<HuffmanTreeNode*, std::vector<HuffmanTreeNode*>, decltype (comp) > nodesToCombine(comp);

        // Get counts for each character
        for(auto c = rawMessage.begin(); c < rawMessage.end(); c++) {
            counts[*c] = counts[*c] + 1;
        }

        // Seed tree with disjoint nodes
        for(auto& [encodedChar, priority] : counts) {
            HuffmanTreeNode* tmp = new HuffmanTreeNode(priority, encodedChar);
            nodesToCombine.push(tmp);
        }

        // Iteratively combine nodes
        while(!nodesToCombine.empty()) {
            HuffmanTreeNode* minNode = nodesToCombine.top();
            nodesToCombine.pop();

            if(!nodesToCombine.empty()) {
                HuffmanTreeNode* secondMinNode = nodesToCombine.top();
                nodesToCombine.pop();

                HuffmanTreeNode* combinedNode = new HuffmanTreeNode(minNode, secondMinNode);
                nodesToCombine.push(combinedNode);
            } else {
                root = minNode;
            }
        }

        debug_print_to_cout();
    }


private:
    HuffmanTreeNode* root;

    void debug_print_to_cout() {
        if (root != nullptr) {
            root->debug_print_to_cout();
        }
    }
};