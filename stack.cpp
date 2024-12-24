#include "stack.h"
#include "message.h"
#include "node.h"
#include <stddef.h>
stack::stack(){
    this->head = nullptr;
    this->tail = nullptr;
}
stack::~stack(){
    this->clear();
}
message stack::top(){
    if(this->tail) return *new message(1, this->tail->data);
    return *new message(-1,NULL);
}
void stack::clear(){
    Node *n = this->head;
    while(n != this->tail){
        n = n->next;
        n->last->deleteNode();
    }
    this->head = nullptr;
    this->tail = nullptr;
}
void stack::push(int num){
    if(this->tail){
        this->tail->addNode(num);
        this->tail = this->tail->next;
    }
    else{
        this->head = new Node(num);
        this->tail = this->head;
    }
}
message stack::pop(){
    if(this->tail){
        if(this->tail == this->head){
            int data = this->tail->data;
            this->tail = nullptr;
            this->head = nullptr;
            return *new message(1, data);
        }
        else{
            int data = this->tail->data;
            this->tail = this->tail->last;
            this->tail->next->deleteNode();
            return *new message(1, data);
        }
    }
    else{
        return *new message(0, 0);
    }
    
}
