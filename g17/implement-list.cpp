#include "implement-list.h"

template<typename T>
void List<T>::pushBack(T value){
    Node* newNode = new Node;
    newNode->value = value;
    pushBack(newNode);
}

template<typename T>
void List<T>::pushBack(Node* node){
    if(tail!=nullptr) tail->next = node;
    tail = node;
    if(head==nullptr) head = tail;
}

template<typename T>
void List<T>::moveSecondLargestToEnd() {
    Node* predecessor = secondLargestPredecessor();
    moveSuccessorToEnd(predecessor);
}

template<typename T>
std::string List<T>::toString() {
    std::string res = "";
    Node* curr = head;
    while(curr!=nullptr) {
        res += (res.size()?" ":"")+std::to_string(curr->value);
        curr = curr->next;
    }    
    return res;
}

template<typename T>
typename List<T>::Node* List<T>::secondLargestPredecessor(){
    Node* mx[2] = {nullptr,nullptr};
    Node* predecessors[2] = {nullptr, nullptr};

    Node* current = head;
    Node* previous = nullptr;
    while(current!=nullptr){
        if(mx[0]==nullptr || current->value > mx[0]->value) {
            mx[1] = mx[0];
            predecessors[1] = predecessors[0];
            mx[0] = current;
            predecessors[0] = previous;
        }
        else if(mx[1]==nullptr || current->value > mx[1]->value) {
            mx[1] = current;
            predecessors[1] = previous;
        }
        previous = current;
        current = current->next;
    }

    return predecessors[1];
}

template<typename T>
void List<T>::moveSuccessorToEnd(Node* node){
    Node* successor;
    if(node==nullptr) successor = head;
    else successor = node->next;
    pushBack(successor);  
}

template struct List<int>;