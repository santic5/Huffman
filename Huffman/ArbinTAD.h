#ifndef ARBINTAD_H
#define ARBINTAD_H

#include <string>
#include <queue>
#include <unordered_map>
#include <iostream>
#include "HuffmanNode.h"
#include "ListTAD.h"

class ArbintTAD {
private:
    HuffmanNode *root;
public:
    ArbintTAD(HuffmanNode *node = nullptr);
    ~ArbintTAD();
    HuffmanNode* getRoot();
    void parseArbin(ListTAD *list);
    std::string retrieve();
    std::string retrieve(HuffmanNode* node);
    void generateHuffmanCodes(std::string word);
    void print();
    void print(HuffmanNode* node);
};

#endif