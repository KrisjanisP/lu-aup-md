template<typename T>
struct List{
public:
    void pushBack(T);
    void moveSecondLargestToEnd();
    T removeSuccesor();
    string toString();
private:
    struct Node {
        T value;
        Node* next;
    };
    Node<T>* head;
    Node<T>* tail;
    Node* secondLargestPredecessor();
    Node* moveSuccessorToEnd();
};