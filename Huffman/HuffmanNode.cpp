#include "HuffmanNode.h"

HuffmanNode::HuffmanNode(char info, int frequency, int card, HuffmanNode* next, HuffmanNode* left, HuffmanNode* right) 
    : info(info), frequency(frequency), card(card), next(next), left(left), right(right) {}

HuffmanNode::HuffmanNode(int frequency, HuffmanNode* next, HuffmanNode* left, HuffmanNode* right)
    : info('_'), frequency(frequency), card(0), next(next), left(left), right(right) {}

HuffmanNode::~HuffmanNode() {}

char HuffmanNode::getInfo() const { return info; }
int HuffmanNode::getFrequency() const { return frequency; }
int HuffmanNode::getCard() const { return card; }
HuffmanNode* HuffmanNode::getNext() const { return next; }
HuffmanNode* HuffmanNode::getLeft() const { return left; }
HuffmanNode* HuffmanNode::getRight() const { return right; }

void HuffmanNode::setInfo(const char &newInfo) { info = newInfo; }
void HuffmanNode::setFrequency(int newFrequency) { frequency = newFrequency; }
void HuffmanNode::setCard(int newCard) { card = newCard; }
void HuffmanNode::setNext(HuffmanNode* newNext) { next = newNext; }
void HuffmanNode::setLeft(HuffmanNode* newLeft) { left = newLeft; }
void HuffmanNode::setRight(HuffmanNode* newRight) { right = newRight; }