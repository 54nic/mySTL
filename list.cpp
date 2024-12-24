#include "list.h"
#include "message.h"
#include "node.h"
#include <stddef.h>
list::list(){
    this->head = new Node(NULL);
    this->tail = this->head;
}
list::~list(){
    this->clear();
    this->head->deleteNode();
}
message list::getData(int pos){
    if(pos <= 0) return *new message(-1, NULL);
    Node *ptr = this->head;
    for(int i = 0; i < pos; i++){
        if(ptr->next)
            ptr = ptr->next;
        else return *new message(-1, NULL);
    }
    return *new message(1, (*ptr).data);
}
void list::clear(){
    Node *n = this->tail;
    this->tail = this->head;
    while(n != this->head){
        n = n->last;
        n->next->deleteNode();
    }
}
void list::insert(int pos, int num){
    if(pos <= 0) return;
    Node *ptr = this->head;
    for(int i = 0; i < pos-1; i++){
        if(ptr->next)
            ptr = ptr->next;
        else return;
    }
    if(ptr->next){
        Node* node = new Node(num);
        node->next = ptr->next;
        ptr->next->last = node;
        ptr->next = node;
        node->last = ptr;
    }
    else{
        ptr->next = new Node(num);
        this->tail = ptr->next;
        this->tail->last = ptr;
    }
}
message list::remove(int pos){
    if(pos <= 0) return *new message(-1, NULL);
    Node *ptr = this->head;
    for(int i = 0; i < pos; i++){
        if(ptr->next)
            ptr = ptr->next;
        else return *new message(-1, NULL);
    }
    int data = ptr->data;
    if(ptr->next){
        ptr->next->last = ptr->last;
        ptr->last->next = ptr->next;
        ptr->deleteNode();
    }
    else{
        ptr->last->next = nullptr;
        this->tail = ptr->last;
        ptr->deleteNode();
    }
    return *new message(1, data);
}
