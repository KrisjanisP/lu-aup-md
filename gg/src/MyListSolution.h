#pragma once
#include <iostream>

template<typename T>
struct MyListSolution{
public:
    MyListSolution();
    ~MyListSolution();
    void pushBack(T);
    void moveSecondLargestToEnd();
    int length();
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