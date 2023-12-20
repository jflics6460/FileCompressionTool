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

    void generateEncodings() {
        // TODO: fails if char does not appear in tree
        std::vector<bool> encodingAccumulator(0);
        generateEncodingsSearch(root, encodingAccumulator);
    }


private:
    std::unordered_map<char, std::vector<bool> > charToEncoding;
    HuffmanTreeNode* root;

    void generateEncodingsSearch(HuffmanTreeNode* root, std::vector<bool>& encoding) {
        if(root->left == nullptr and root->right == nullptr) {
            charToEncoding[root->getEncodedChar()] = encoding;
            std::cout << root->getEncodedChar() << ": ";
            for(auto bit : encoding) {
                std::cout << bit;
            }
            std::cout << std::endl;
        }

        if(root->left != nullptr) {
            encoding.push_back(0);
            generateEncodingsSearch(root->left, encoding);
            encoding.pop_back();
        }

        if(root->right != nullptr) {
            encoding.push_back(1);
            generateEncodingsSearch(root->right, encoding);
            encoding.pop_back();
        }

    }

    void debug_print_to_cout() {
        if (root != nullptr) {
            root->debug_print_to_cout();
        }
        std::cout << std::endl;
    }
};