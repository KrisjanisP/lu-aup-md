template<typename T>
struct List{
public:
    void pushBack(T);
    void moveSecondLargestToEnd();
    std::string toString();
private:
    struct Node {
        T value;
        Node* next;
    };
    Node* head, tail;
    Node* secondLargestPredecessor();
    void moveSuccessorToEnd(Node*);
};