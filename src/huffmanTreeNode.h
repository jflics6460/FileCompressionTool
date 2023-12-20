#include <iostream>

class HuffmanTreeNode {
public:
    HuffmanTreeNode(unsigned int priority, char encodedChar) 
    : left(nullptr)
    , right(nullptr)
    , priority(priority)
    , encodedChar(encodedChar)
    {}

    HuffmanTreeNode(HuffmanTreeNode* left_in, HuffmanTreeNode* right_in) 
    : left(nullptr)
    , right(nullptr)
    , priority(0)
    , encodedChar('*')
    {
        if (left_in != nullptr) {
            priority += left_in->priority;
            left = left_in;
        }
        if (right_in != nullptr) {
            priority += right_in->priority;
            right = right_in;
        }
    }

    ~HuffmanTreeNode() {
        if(left != nullptr) {
            delete left;
        }
        if(right != nullptr) {
            delete right;
        }
    }

    HuffmanTreeNode& operator=(HuffmanTreeNode&& other) {
        if(this != &other) {
            // Free currently held resources
            if(left != nullptr) {
                delete left;
            }
            if(right != nullptr) {
                delete right;
            }
            
            // Move in new resources
            left = other.left;
            right = other.right;
            priority = other.priority;
            encodedChar = other.encodedChar;

            // Invalidate other
            other.left = nullptr;
            other.right = nullptr;
        }
        return *this;
    }

    HuffmanTreeNode(HuffmanTreeNode&& other) 
    : left(other.left)
    , right(other.right)
    , priority(other.priority)
    , encodedChar(other.encodedChar)
    {
        other.left = nullptr;
        other.right = nullptr;
    }

    unsigned int getPriority() {
        return priority;
    }

    char getEncodedChar() {
        return encodedChar;
    }

    void debug_print_to_cout() {
        if(left != nullptr) {
            left->debug_print_to_cout();
        }

        std::cout << encodedChar;

        if(right != nullptr) {
            right->debug_print_to_cout();
        }
    }

    // FIXME: remove this comment
    // maybe want these all to be private, and only give the tree direct access?
    HuffmanTreeNode* left;
    HuffmanTreeNode* right;
private:
    unsigned int priority;
    char encodedChar;    

// Friend function and constructor deletion boilerplate
public:
    friend bool operator>(const HuffmanTreeNode& lhs, const HuffmanTreeNode& rhs);
    friend bool operator<(const HuffmanTreeNode& lhs, const HuffmanTreeNode& rhs);
    friend bool operator>=(const HuffmanTreeNode& lhs, const HuffmanTreeNode& rhs);
    friend bool operator<=(const HuffmanTreeNode& lhs, const HuffmanTreeNode& rhs);
    friend bool operator==(const HuffmanTreeNode& lhs, const HuffmanTreeNode& rhs);
    friend bool operator!=(const HuffmanTreeNode& lhs, const HuffmanTreeNode& rhs);

    HuffmanTreeNode(HuffmanTreeNode& other) = delete;
    HuffmanTreeNode operator=(HuffmanTreeNode& other) = delete;
};


bool operator>(const HuffmanTreeNode& lhs, const HuffmanTreeNode& rhs) {
    return lhs.priority > rhs.priority;
}

bool operator<(const HuffmanTreeNode& lhs, const HuffmanTreeNode& rhs) {
    return lhs.priority < rhs.priority;
}

bool operator<=(const HuffmanTreeNode& lhs, const HuffmanTreeNode& rhs) {
    return lhs.priority <= rhs.priority;
}

bool operator>=(const HuffmanTreeNode& lhs, const HuffmanTreeNode& rhs) {
    return lhs.priority >= rhs.priority;
}

bool operator==(const HuffmanTreeNode& lhs, const HuffmanTreeNode& rhs) {
    return lhs.priority == rhs.priority;
}

bool operator!=(const HuffmanTreeNode& lhs, const HuffmanTreeNode& rhs) {
    return lhs.priority != rhs.priority;
}
