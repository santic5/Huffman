#include "ListTAD.h"
#include "ArbinTAD.h"
#include <iostream>

using namespace std;

int main(){
    ListTAD list;
    list.huffmanAdd("programa");
    cout << list.retrieve() << endl;
    list.ascendingFrequencyOrder();
    cout << list.retrieve() << endl;
    cout << "--- IMPRIMIENDO INFORMACION DEL ARBOL ---" << endl;
    ArbintTAD arbin;
    cout << "Arbol creado " << endl;
    arbin.parseArbin(&list);
    cout << "Arbol parseado" << endl;
    cout << "Recorrido:" << endl;
    arbin.generateHuffmanCodes("programa");
    cout << "Fin del recorrido" << endl;
    return 0;
}