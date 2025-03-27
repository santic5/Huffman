#include "ArbinTAD.h"
#include "HuffmanNode.h"
#include <iostream>

ArbintTAD::ArbintTAD(HuffmanNode *node) {
    this->root = node;
}

ArbintTAD::~ArbintTAD() {
    delete this->root;
}

HuffmanNode* ArbintTAD::getRoot() {
    return this->root;
}

std::string ArbintTAD::retrieve(HuffmanNode* node) {
    if (node == nullptr) {
        return "";
    }
    std::string result = "";
    result += node->getInfo();
    result += retrieve(node->getLeft());
    result += retrieve(node->getRight());
    return result;
}

std::string ArbintTAD::retrieve() {
    return retrieve(this->root);
}

void ArbintTAD::print() {
    print(this->root);
}

void ArbintTAD::print(HuffmanNode* node) {
    if(!(node == nullptr)){ 
        print(node->getLeft());
        std::cout << "Node: " << node->getInfo() << " -  " << node->getCard() << " - " << node->getFrequency() << std::endl;
        print(node->getRight());
    }
}

void ArbintTAD::generateHuffmanCodes(std::string word) {
    if (root == nullptr) {
        std::cout << "El árbol está vacío." << std::endl;
        return;
    }
    std::queue<std::pair<HuffmanNode*, std::string>> q;
    q.push({root, ""});
    std::unordered_map<char, std::string> huffmanCodes;
    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        HuffmanNode* node = current.first;
        std::string path = current.second;
        if (node->getLeft() == nullptr && node->getRight() == nullptr) {
            huffmanCodes[node->getInfo()] = path;
            std::cout << "Nodo hoja: " << node->getInfo() << " | Código: " << path << std::endl;
        }

        if (node->getLeft() != nullptr) {
            q.push({node->getLeft(), path + "0"});
        }
        if (node->getRight() != nullptr) {
            q.push({node->getRight(), path + "1"});
        }
    }
    std::cout << "Códigos de Huffman generados:" << std::endl;
    for (const auto& pair : huffmanCodes) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << "Cadena codificada: " << std::endl;
    try{
        for(char c : word){
            std::cout << huffmanCodes[c] << " ";
        }
        std::cout << std::endl;
    }catch(std::exception e){
        std::cout << "Error trying to get huffmancode of char" << e.what() << std::endl;
    }
}

void ArbintTAD::parseArbin(ListTAD *list) {
    if(!list->empty() && list->getLenght() > 1){
        int plus = list->getNode(0)->getFrequency() + list->getNode(1)->getFrequency();
        HuffmanNode *node = new HuffmanNode(plus, nullptr, nullptr, nullptr);
        node->setLeft(list->getNode(0));
        node->getLeft()->setCard(0);
        node->setRight(list->getNode(1));
        node->getRight()->setCard(1);
        list->remove(0);
        list->remove(0);
        list->add(node);
        std::cout << "INFORMACION DE NODO A INGRESAR: (" << node->getInfo() << " Card:" << node->getCard()<< " Frequency: " << node->getFrequency() <<") -> izq:" << node->getLeft()->getInfo() << " der:" << node->getRight()->getInfo() << std::endl;
        root = node;
        parseArbin(list);
    } else if (list->getLenght() == 1) {
        root = list->getNode(0);
    }
}