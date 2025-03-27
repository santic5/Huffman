#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>

class HuffmanNode {
private:
    char info;
    int frequency;
    int card;
    HuffmanNode *next;
    HuffmanNode *left;
    HuffmanNode *right;

public:
    // Constructor
    HuffmanNode(char info, int frequency = 0, int card = 0, 
                HuffmanNode* next = nullptr, HuffmanNode* left = nullptr, HuffmanNode* right = nullptr);
    HuffmanNode(int frequency = 0, HuffmanNode* next = nullptr, HuffmanNode* left = nullptr, HuffmanNode* right = nullptr);
    // Destructor
    ~HuffmanNode();
    // Getters
    char getInfo() const;
    int getFrequency() const;
    int getCard() const;
    HuffmanNode* getNext() const;
    HuffmanNode* getLeft() const;
    HuffmanNode* getRight() const;

    // Setters
    void setInfo(const char &newInfo);
    void setFrequency(int newFrequency);
    void setCard(int newCard);
    void setNext(HuffmanNode* newNext);
    void setLeft(HuffmanNode* newLeft);
    void setRight(HuffmanNode* newRight);
};

#endif // HUFFMANNODE_H