#include <stdio.h>

using namespace std;
using ui = unsigned int;

const ui P = 50647;

template<typename T1, typename T2>
struct Pair{
    T1 first;
    T2 second;
};

template<typename T>
class Map {
private:
    struct Entry {
        T value;
        ui orig_key;
        Entry* next;
        ~Entry(){delete next;}
    };
    Entry* buckets[P];
public:
    Map(){for(int i=0;i<P;i++) buckets[i]=nullptr;}
    T& operator[](ui key){
        ui hashed = key%P;
        Entry** head = &buckets[hashed];
        if ((*head)==nullptr){
            (*head)=new Entry{T{},key,nullptr};
            return (*head)->value;
        }
        while((*head)!=nullptr&&(*head)->orig_key!=key){
            if((*head)->next==nullptr){
                (*head)->next=new Entry{T{},key,nullptr};
                return (*head)->next->value;
            }
            (*head) = (*head)->next;
        }
        return (*head)->value;
    }
    ~Map(){for(int i=0;i<P;i++) delete buckets[i];}
};

template<typename T>
struct List{
public:
    List() {
        head=nullptr;
        tail=nullptr;
    }
    ~List() {
        while(head!=nullptr){
            Node* next = head->next;
            delete head;
            head = next;
        }
    }
    int size() {
        return _size;
    }
    void push(T value){
        Node* newNode = new Node();
        newNode->value = value;
        push(newNode);
    }
    void print() {
        Node* curr = head;
        bool head = true;
        while(curr!=nullptr){
            if(!head) printf(" %u", curr->value);
            else {printf("%u", curr->value); head=false;}
            curr = curr->next;
        }
    }
private:
    struct Node {
        T value;
        Node* next;
    };
    Node *head, *tail;
    int _size = 0;
    void push(Node* node){
        _size++;
        if(head==nullptr) head=tail=node;
        else tail->next=node,tail=node;
        node->next = nullptr;
    }
};

Map<Pair<ui,ui>> inviting;
Map<bool> invited;

List<ui> results[10000];

void dfs(ui participant, int level) {
    auto descendants = inviting[participant];
    if(descendants.first!=0) dfs(descendants.first, level+1);
    if(descendants.second!=0) dfs(descendants.second, level+1);
    results[level].push(participant);
}

int main() {
    freopen("team.in","r",stdin);
    freopen("team.out","w",stdout);

    ui input[10000][3];
    int n=0;
    scanf("%u %u %u", &input[n][0], &input[n][1], &input[n][2]);
    while(input[n][0]!=0||input[n][1]!=0||input[n][2]!=0){
        n++;
        scanf("%u %u %u", &input[n][0], &input[n][1], &input[n][2]);
    }
    
    for(int i=0;i<n;i++) {
        inviting[input[i][0]]=Pair<ui,ui>{input[i][1],input[i][2]};
        invited[input[i][1]] = true;
        invited[input[i][2]] = true;
    }
    

    for(int i=0;i<n;i++){
        if(!invited[input[i][0]]) dfs(input[i][0],0);
    }

    for(int i=9999;i>=0;i--){
        if(results[i].size()==0) continue;
        printf("%d: ",i);
        results[i].print();
        printf("\n");
    }
}