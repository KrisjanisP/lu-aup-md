#include "implement-list.h"

template<typename T>
List<T>::Node* List<T>::secondLargestPredecessor(){
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