#include "ListTAD.h"
#include "HuffmanNode.h"

#include <iostream>

ListTAD::ListTAD() {
    this->head = nullptr;
    this->tall = nullptr;
    this->lenght = 0;
}

ListTAD::~ListTAD() {
    for(int i = 0; i < this->lenght; i++){
        this->remove(0);
    }
}

void ListTAD::setIndex(int prmIndex){
    this->lenght = prmIndex;
}

bool ListTAD::empty(){
    return this->head == nullptr || lenght == 0;
}

int ListTAD::getLenght(){
    return this->lenght;
}

void ListTAD::huffmanAdd(const std::string value){
    for(char i : value){
        int index;
        if(exist(i, index)){
            HuffmanNode* aux = this->getNode(index);
            aux->setFrequency(aux->getFrequency() + 1);
        }else{
            this->add(i);
        }
    }
}

void ListTAD::add(char value){
    HuffmanNode* newNode = new HuffmanNode(value, 1, 0, nullptr, nullptr, nullptr);
    if(this->empty()){
        this->head = newNode;
    } else {
        HuffmanNode* aux = this->head;
        while(aux->getNext() != nullptr){
            aux = aux->getNext();
        }
        aux->setNext(newNode);
    }
    this->lenght++;
}

void ListTAD::add(HuffmanNode* node){
    if (node == nullptr) {
        return;
    }
    if(this->empty()){
        this->head = node;
    } else {
        HuffmanNode* aux = this->head;
        while(aux->getNext() != nullptr){
            aux = aux->getNext();
        }
        aux->setNext(node);
    }
    this->lenght++;
}

void ListTAD::remove(int index){
    if(index == 0 && this->head != nullptr){
        HuffmanNode* aux = this->head;
        this->head = this->head->getNext();
        aux->setNext(nullptr);
        this->lenght--;
    }else{
        HuffmanNode* aux = this->head;
        for(int i = 0; i < index - 1; i++){
            aux = aux->getNext();
        }
        HuffmanNode* toDelete = aux->getNext();
        aux->setNext(toDelete->getNext());
        this->lenght--;
    }
}

bool ListTAD::exist(char value, int &index){
    for(int i = 0; i < this->lenght; i++){
        if(value == this->retrieve(i)){
            index = i;
            return true;
        }
    }
    return false;
}

char ListTAD::retrieve(int index){
    HuffmanNode* aux = this->head;
    for(int i = 0; i < index; i++){
        aux = aux->getNext();
    }
    return aux->getInfo();
}

std::string ListTAD::retrieve(){
    std::string aux;
    HuffmanNode* current = this->head;
    while(current != nullptr){
        aux += current->getInfo();
        current = current->getNext();
    }
    return aux;
}

HuffmanNode* ListTAD::getNode(int index){
    if(index < 0 || index >= this->lenght){
        std::cout << "Index out of bounds" << std::endl;
        return nullptr;
    }
    HuffmanNode* aux = this->head;
    for(int i = 0; i < index; i++){
        aux = aux->getNext();
    }
    return aux;
}

void ListTAD::ascendingFrequencyOrder(){
    for(int i = 0; i < this->lenght - 1; i++){
        for(int j = i + 1; j < this->lenght; j++){
            if(this->getNode(i)->getFrequency() > this->getNode(j)->getFrequency()){
                HuffmanNode* nodeI = this->getNode(i);
                HuffmanNode* nodeJ = this->getNode(j);
                char tempInfo = nodeI->getInfo();
                int tempFrequency = nodeI->getFrequency();
                nodeI->setInfo(nodeJ->getInfo());
                nodeI->setFrequency(nodeJ->getFrequency());
                nodeJ->setInfo(tempInfo);
                nodeJ->setFrequency(tempFrequency);
            }
        }
    }
}