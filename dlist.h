#ifndef DLIST_H
#define DLIST_H
#include "dnode.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
struct DList{
    DNode * head;
    DNode * tail;

    //criar
    DList(){
        head = new DNode;
        tail = new DNode;
        head->next = tail;
        head->prev = nullptr;
        tail->prev = head;
        tail->next = nullptr;
    }

    ~DList(){

    }

    void _clone(DList lista_other, DNode * node){
        if(node->next == nullptr)
            return;
        this->push_back(node->value);
        _clone(lista_other, node->next);
    }

    void clone(DList lista_other){
        _clone(lista_other, lista_other.front());
    }

    //Destruir
    void rdestroy(DNode * node){
        if(node == nullptr)
            return;
        rdestroy(node->next);
        delete node;
    }

    void destroy(){
        rdestroy(head);
    }

    //inserir
    void insert_before(DNode * node, int value){
        DNode * x = new DNode(value);
        x->next = node;
        x->prev = node->prev;
        node->prev = x;
        x->prev->next = x;
    }

    void push_back(int value){
        insert_before(tail, value);
    }

    void push_front(int value){
        insert_before(head->next, value);
    }

    //visualizar
    void rshow(DNode * node){
        if(node == tail)
            return;
        cout << node->value;
        rshow(node->next);
    }

    void show(){

        rshow(head->next);
        cout << endl;
    }

    void _reverse_print(DNode * node){
        if(node == tail)
            return;
        if(node == head)
            return;
        if(node == nullptr)
            return;
        _reverse_print(node->next);
        cout << node->value << " ";


    }

    void reverse_print(){
        cout << "[ ";
        _reverse_print(head->next);
        cout << "]\n";
    }


    //acessar
    DNode * front(){
        return head->next;
    }

    DNode * _back(DNode * node){
        if(node->next == tail)
            return node;
        return _back(node->next);
    }
    DNode * back(){
        return _back(this->front());
    }

    //manipular
    bool _is_empty(DNode * node){
        if(node == tail)
            return true;
        return false;
        _is_empty(node->next);
    }

    bool is_empty(){
        return _is_empty(this->front());
    }

    DNode * _find(DNode * node, int value){
        if(node == tail)
            return nullptr;
        if(node->value == value)
            return node;
        _find(node->next, value);
    }

    DNode * find(int value){
        return _find(head->next, value);
    }

    int _size(DNode * node){
        if(node == tail)
            return 0;
        return 1 + _size(node->next);
    }

    int size(){
        return _size(head->next);
    }

    bool _equals(DNode * node, DNode * nodeaux){
        if(node == nullptr && nodeaux == nullptr)
            return true;
        else if(node->value != nodeaux->value)
            return false;
        return _equals(node->next, nodeaux->next);
    }

    bool equals(DList lista){
        return _equals(this->head->next, lista.head->next);
    }

    //remover
    void pop_front(){
        remove(this->front()->value);
    }

    void pop_back(){
        remove(this->back()->value);
    }

    DNode * _remove(DNode * node, char value){
        if(node->next == nullptr)
            return nullptr;
        //else if(node->next->value == value){
        else if(strcmp(node->next->value, value) == 0){
            auto aux = node->next;
            node->next = aux->next;
            aux->next = nullptr;
            return aux;
        }

        return _remove(node->next, value);
    }

    DNode * remove(int value){
        return _remove(this->head, value);
    }
};
#endif // DLIST_H
