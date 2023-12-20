class HuffmanNode {
public:
    HuffmanNode(unsigned int priority, char encodedChar) 
    : left(nullptr)
    , right(nullptr)
    , priority(priority)
    , encodedChar(encodedChar)
    {}

    HuffmanNode(HuffmanNode* left, HuffmanNode* right) 
    : left(left)
    , right(right)
    {
        priority = left->priority + right->priority;
        encodedChar = '\0';
    }

    ~HuffmanNode() {
        if(left != nullptr) {
            delete left;
        }
        if(right != nullptr) {
            delete right;
        }
    }

    HuffmanNode& operator=(HuffmanNode&& other) {
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

    HuffmanNode(HuffmanNode&& other) 
    : left(other.left)
    , right(other.right)
    , priority(other.priority)
    , encodedChar(other.encodedChar)
    {
        other.left = nullptr;
        other.right = nullptr;
    }

    HuffmanNode(HuffmanNode& other)
    : left(nullptr)
    , right(nullptr)
    , priority(other.priority)
    , encodedChar(other.encodedChar)
    {
        if (other.left != nullptr) {
            left = new HuffmanNode(*other.left);
        }

        if (other.right != nullptr) {
            right = new HuffmanNode(*other.right);
        }
    }

    HuffmanNode operator=(HuffmanNode& other) {
        if(this != &other) {
            if(other.left != nullptr) {
                left = new HuffmanNode(*other.left);
            } else {
                left = nullptr;
            }

            if(other.right != nullptr) {
                right = new HuffmanNode(*other.right);
            } else {
                right = nullptr;
            } 

            priority = other.priority;
            encodedChar = other.encodedChar;
        }
        return *this; 
    }


    unsigned int getPriority() {
        return priority;
    }

    char getEncodedChar() {
        return encodedChar;
    }
    
private:
    HuffmanNode* left;
    HuffmanNode* right;

    unsigned int priority;
    char encodedChar;    

// Operator overloads are friends
public:
    friend bool operator>(const HuffmanNode& lhs, const HuffmanNode& rhs);
    friend bool operator<(const HuffmanNode& lhs, const HuffmanNode& rhs);
    friend bool operator>=(const HuffmanNode& lhs, const HuffmanNode& rhs);
    friend bool operator<=(const HuffmanNode& lhs, const HuffmanNode& rhs);
    friend bool operator==(const HuffmanNode& lhs, const HuffmanNode& rhs);
    friend bool operator!=(const HuffmanNode& lhs, const HuffmanNode& rhs);

};


bool operator>(const HuffmanNode& lhs, const HuffmanNode& rhs) {
    return lhs.priority > rhs.priority;
}

bool operator<(const HuffmanNode& lhs, const HuffmanNode& rhs) {
    return lhs.priority < rhs.priority;
}

bool operator<=(const HuffmanNode& lhs, const HuffmanNode& rhs) {
    return lhs.priority <= rhs.priority;
}

bool operator>=(const HuffmanNode& lhs, const HuffmanNode& rhs) {
    return lhs.priority >= rhs.priority;
}

bool operator==(const HuffmanNode& lhs, const HuffmanNode& rhs) {
    return lhs.priority == rhs.priority;
}

bool operator!=(const HuffmanNode& lhs, const HuffmanNode& rhs) {
    return lhs.priority != rhs.priority;
}
