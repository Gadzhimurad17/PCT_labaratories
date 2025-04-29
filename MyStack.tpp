#include <iostream>
#include <ostream>

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    ListNode(const T& val) : data(val), next(nullptr) {}
    ListNode(const ListNode& other) : data(other.data), next(nullptr) {}
};

template <typename T>
class MyStack {
private:
    typedef ListNode<T> Node;
    Node* top;

public:
    MyStack();
    ~MyStack();
    MyStack(const MyStack<T>& other);
    MyStack<T>& operator=(const MyStack<T>& other);

    void push(const T& value);
    T pop();
    bool isEmpty() const;
    void clear();

    friend std::ostream& operator<<(std::ostream& os, const MyStack& stack) {
        MyStack temp(stack);
        bool first = true;
        while (!temp.isEmpty()) {
            if (!first) os << " * ";
            os << temp.pop();
            first = false;
        }
        return os;
    }

    void printReversed(std::ostream& os) const {
        MyStack temp(*this);
        MyStack reversed;
        while (!temp.isEmpty()) {
            reversed.push(temp.pop());
        }
        bool first = true;
        while (!reversed.isEmpty()) {
            if (!first) os << " * ";
            os << reversed.pop();
            first = false;
        }
    }
};

template <typename T>
MyStack<T>::MyStack() : top(nullptr) {}

template <typename T>
MyStack<T>::~MyStack() { 
    clear(); 
}

template <typename T>
MyStack<T>::MyStack(const MyStack<T>& other) : top(nullptr) {
    const Node* temp = other.top;
    MyStack<T> reversed;
    while (temp) {
        reversed.push(temp->data);
        temp = temp->next;
    }
    while (!reversed.isEmpty()) {
        push(reversed.pop());
    }
}

template <typename T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T>& other) {
    if (this != &other) {
        clear();
        const Node* temp = other.top;
        MyStack<T> reversed;
        while (temp) {
            reversed.push(temp->data);
            temp = temp->next;
        }
        while (!reversed.isEmpty()) {
            push(reversed.pop());
        }
    }
    return *this;
}

template <typename T>
void MyStack<T>::push(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

template <typename T>
T MyStack<T>::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    Node* temp = top;
    T val = top->data;
    top = top->next;
    delete temp;
    return val;
}

template <typename T>
bool MyStack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
void MyStack<T>::clear() {
    while (!isEmpty()) {
        pop();
    }
}
