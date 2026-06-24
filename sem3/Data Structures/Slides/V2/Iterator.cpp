#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Node {
private:
    T object;
    Node* nextNode;

public:
    T& get() { return object; }
    const T& get() const { return object; }

    void set(const T& obj) { object = obj; }
    Node* getNext() { return nextNode; }
    const Node* getNext() const { return nextNode; }
    void setNext(Node* nextNode) { this->nextNode = nextNode; }

    Node(const T& obj, Node* next = NULL) {
        object = obj;
        this->nextNode = next;
    }

    Node() { this->nextNode = NULL; }
};

template <typename T>
class List {
private:
    Node<T>* head; // dummy head
    Node<T>* tail;
    int size;

public:
    List() {
        head = tail = new Node<T>(); // dummy node
        size = 0;
    }

    void insertAtHead(const T& obj) {
        Node<T>* newNode;
        head->setNext(newNode = new Node<T>(obj, head->getNext()));
        if (size == 0) {
            tail = newNode;
        }
        size++;
    }

    void insertAtTail(const T& obj) {
        Node<T>* newNode = new Node<T>(obj, NULL);
        tail->setNext(newNode);
        tail = newNode;
        size++;
    }

    // ---------- Iterator ----------
    class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* node = NULL) : current(node) {}

        T& operator*() { return current->get(); }

        Iterator& operator++() { // prefix ++
            if (current != NULL)
                current = current->getNext();
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() { return Iterator(head->getNext()); }
    Iterator end() { return Iterator(NULL); }

    // ---------- Indexing operator ----------
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        Node<T>* current = head->getNext(); // skip dummy head
        for (int i = 0; i < index; i++) {
            current = current->getNext();
        }
        return current->get(); // return reference
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        Node<T>* current = head->getNext();
        for (int i = 0; i < index; i++) {
            current = current->getNext();
        }
        return current->get();
    }

    // ---------- Utility for testing ----------
    void display() {
        for (Iterator it = begin(); it != end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    int getSize() const { return size; }
};

int main() {
    List<int> myList;
    myList.insertAtHead(10);
    myList.insertAtHead(20);
    myList.insertAtTail(5);

    cout << "List elements using iterator: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Using display(): ";
    myList.display();

    cout << "Element at index 0: " << myList[0] << endl; // 20
    cout << "Element at index 1: " << myList[1] << endl; // 10
    cout << "Element at index 2: " << myList[2] << endl; // 5

    // Modify element using []
    myList[1] = 99;
    cout << "After modification: ";
    myList.display();

    return 0;
}