#ifndef EDITOR_H
#define EDITOR_H
#include <list>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

struct Editor{
    list <char> lista;
    list <char> listaBackup;
    stack <char> pilha;

    Editor(){
        lista.push_front('|');
    }

    void insert(char value){
        for(auto it = lista.begin(); it != lista.end(); it++){
            if(*it == '|'){
                lista.insert(it, value);
                break;
            }
        }
    }

    void show(){
        for(auto it = lista.begin(); it != lista.end(); it++)
            cout << *it;

        cout << endl;
    }
    list <char> :: iterator aux;
    void backspace(){
        for(auto it = lista.begin(); it != lista.end(); it++){
            if((*it == '|') && (*it != lista.front())){
                lista.erase(--it);
                pilha.push(*it);
                aux = it;
                break;
            }
        }
    }

    void showPilha(){
        //       while(!pilha.empty()){
        cout << ' ' << pilha.top();
        //           pilha.pop();
        //       }
        cout << "\n";
    }

    void _controlZ(list <char> :: iterator it){
        lista.insert(it, pilha.top());
    }
    void controlZ(){
        _controlZ(aux);
    }
    void swap(list <char> :: iterator iterator, list<char> :: iterator it){
        char aux = *it;
        *it = *iterator;
        *iterator = aux;
    }



    void deleteCaractere(){
        for(auto it = lista.begin(); it != lista.end(); it++){
            if((*it == '|') && (*it != lista.back())){
                lista.erase(++it);
                break;
            }
        }
    }

    void moverCursorDireita(){
        for(auto it = lista.begin(); it != lista.end(); it++){
            if((*it == '|') && (*it != lista.back())){
                auto aux = it++;
                swap(it, aux);
                break;
            }
        }
    }

    void moverCursorEsquerda(){
        for(auto it = lista.begin(); it != lista.end(); it++){
            if((*it == '|') && (*it != lista.front())){
                auto aux = it--;
                swap(it, aux);
                break;
            }
        }
    }
};

#endif // EDITOR_H
