#ifndef DNODE_H
#define DNODE_H
struct DNode{
    char value;
    DNode * next;
    DNode * prev;

    DNode(int value = ' ', DNode * next = nullptr, DNode * prev = nullptr){
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};
#endif // DNODE_H
