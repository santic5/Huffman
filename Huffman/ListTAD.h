#ifndef LISTTAD_H
#define LISTTAD_H

#include "HuffmanNode.h"
#include <string>

class ListTAD {
private:
    HuffmanNode *head;
    HuffmanNode *tall;
    int lenght;

public:
    ListTAD();
    ~ListTAD();
    void add(char value);
    void add(HuffmanNode *node);
    void huffmanAdd(std::string value);
    void remove(int index);
    char retrieve(int index);
    HuffmanNode* getNode(int index);
    std::string retrieve();
    void ascendingFrequencyOrder();
    bool empty();
    bool exist(char value, int &index);
    void setIndex(int prmIndex);
    int getLenght();
};

#endif // LISTTAD_H