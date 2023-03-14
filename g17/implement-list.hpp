#include <iostream>
#include <cassert>

using namespace std;

struct Node {
    int value;
    Node *next = nullptr;
    Node(int value) {
        this->value = value;
    }
};

class List {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    ~List() {
        while(head!=nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }
    Node* pushBack(int value) {
        Node* node = new Node(value);
        return pushBack(node);
    }
    Node* pushBack(Node* node) {
        node->next = nullptr;
        if(tail==nullptr) head = node;
        else tail->next = node;
        tail = node;
        return node;
    }
    Node* secondLargestPredecessor() {
        // the largest and second largest elements
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
    // remove successor removes node from a list but doesn't deallocate it's memory
    // returns the removed element
    Node* removeSuccessor(Node* node) {
        assert(node!=nullptr);
        if(node->next == tail){
            tail = node;
            return tail;
        }
        Node* result = node->next;
        if(node->next!=nullptr)
            node->next = result->next;
        return result;
    }
    Node* moveSecondLargestToEnd() {
        if(head==nullptr||head==tail) return tail;
        Node* predecessor = secondLargestPredecessor();
        Node* secondLargest;
        if(predecessor==nullptr){
            Node* prevHead = head;
            head = prevHead->next;
            secondLargest = prevHead;
        } else {
            secondLargest = removeSuccessor(predecessor);
        }
        cout<<secondLargest->value<<endl;
        return pushBack(secondLargest);
    }
    void print() {
        printFrom(head);
    }
    void printFrom(Node* node) {
        if(node==nullptr) {
            cout<<"\n";
            return;
        }
        cout<<node->value<<" ";
        printFrom(node->next);
    }
    string toString(){
        string res="";
        Node* curr = head;
        while(curr!=nullptr){
            if(res.size()) res+=" ";
            res+=to_string(curr->value);
            curr = curr->next;
        }
        return res;
    }
};