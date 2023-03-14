/*
=== G17 =======================================

Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā,
cita starpā parādot gan sākotnējās, gan rezultējošās vērtības.
Abās programmās:  
  a) jābūt iespējai ievadīt saraksta elementus (izveidot patvaļīgu sarakstu),
  b) jāpielieto uzrakstītā funkcija sarakstam,  
  c) jāizdrukā saraksts pēc funkcijas darbības.  
  d) beigās jāiznīcina saraksts - korekti jāatbrīvo izdalītā atmiņa(lietojot delete vai clear).
Sīkākas prasības sk. Laboratorijas darbu noteikumos.

G17. Uzrakstīt funkciju, kas atrod saraksta otro lielāko elementu, ja tāds eksistē un pārvieto to uz saraksta beigām. Darbība jāveic, pārkabinot saites, nevis pārkopējot elementu vērtības.
*/
#include <iostream>
#include <cassert>
#include <gtest/gtest.h>

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
            tail->next = nullptr;
            return tail;
        }
        Node* result = node->next;
        if(node->next!=nullptr)
            node->next = result->next;
        result->next = nullptr;
        return result;
    }
    Node* moveSecondLargestToEnd() {
        Node* predecessor = secondLargestPredecessor();
        Node* secondLargest;
        if(predecessor==nullptr){
            Node* prevHead = head;
            head = prevHead->next;
            prevHead->next = nullptr;
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

int main() {
    cout<<"G17. Uzrakstit funkciju, kas atrod saraksta otro lielako elementu, ja tas eksiste un parvieto to uz saraksta beigam.\n";
    cout<<"Ievadiet sarakstu, kuru norobežo nulle, piemēram, \"1 2 3 0\": ";
    List list;
    int x;
    cin>>x;
    while(x!=0){
        list.pushBack(x);
        cin>>x;
    }
    cout<<"Saraksts pirms funkcijas izpildes: "; list.print();
    list.moveSecondLargestToEnd();
    cout<<"Saraksts pec funkcijas izpildes: "; list.print();
}

TEST(implemented,twoAscending){
    List list;
    list.pushBack(1);
    list.pushBack(2);
    EXPECT_EQ(list.toString(),"1 2");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(),"2 1");
}