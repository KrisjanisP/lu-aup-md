#pragma once
#include <iostream>

template<typename T>
struct List{
public:
    List();
    void pushBack(T);
    void moveSecondLargestToEnd();
    std::string toString();
private:
    struct Node {
        T value;
        Node* next;
    };
    Node *head, *tail;
    void pushBack(Node*);
    Node* secondLargestPredecessor();
    void moveSuccessorToEnd(Node*);
};