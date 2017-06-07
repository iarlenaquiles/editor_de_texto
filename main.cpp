#include <iostream>
#include "editor.h"
#include <istream>
#include <string>
using namespace std;

int main(){
    Editor lista;
    char op;

    cout << "i: inserir\nS: show\nb: backspace\n>: mover direita\n<: mover esquerda\nd: delete\nb: backup\nq: sair\n";
    do{

        cin >> op;

        switch (op) {
        case 'i':
            char value;
            cin >> value;
            lista.insert(value);
            lista.show();
            break;
        case 's':
            //cout << "valores da lista: ";
            lista.show();
            break;
        case 'r':
            lista.backspace();
            lista.show();
            break;
        case '>':
            lista.moverCursorDireita();
            lista.show();
            break;
        case '<':
            lista.moverCursorEsquerda();
            lista.show();
            break;
        case 'd':
            lista.deleteCaractere();
            lista.show();
            break;
        case 'b':
            lista.showPilha();
            break;
        case 'z':
            lista.controlZ();
            break;
        default:
//            char valuede;
//            cin >> valuede;
//            lista.insert(valuede);
//            lista.show();
            break;
        }
    }while(op != 'q');

    return 0;
}
