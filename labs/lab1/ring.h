#ifndef LAB_1_RING_H
#define LAB_1_RING_H

#include <memory>
#include <iostream>
#include <ctime>
#include <limits>

using namespace std;

#define safe_input(cout_line, cin_line, checks)                  \
    while (true)                                                 \
    {                                                            \
        cout_line;                                               \
        bool f = static_cast<bool>(cin_line);                    \
        char c = cin.get();                                      \
        if (f && isspace(c) && checks)                           \
            break;                                               \
        cout << "Bad input" << endl;                             \
        if (!isspace(c))                                         \
        {                                                        \
            cin.clear();                                         \
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); \
        }                                                        \
    }

class Node {
public:
    int data;
    Node *next;

    Node(int value, Node *next_) {
        this->data = value;
        this->next = next_;
    }

    Node &operator+(const Node &node);

    Node &operator=(const Node &node);

    bool operator==(const Node &node);

    bool operator!=(const Node &node);

    bool operator>(const Node &node);

    bool operator<(const Node &node);

    bool operator>=(const Node &node);

    bool operator<=(const Node &node);
};

class Ring {
    Node *head;
    int size;
public:
    Ring(int size_);

    void push(int data);

    void pop();

    void edit(int index, int new_data);

    void print();

    void remove(int index);

    int get_index(Node *node);

    int get_index(int value);

    Node *get_node(int index);

    Node find(const int &index);

    Ring &operator+(const Node &node);

    Ring &operator+=(const Node &node);

    Ring &operator+=(const int value);

    Ring &operator-(Node &node);

    Ring &operator-=(Node &node);

    Ring &operator-=(const int value);

    void operator delete(void *ring);

    void *operator new(size_t size);
};

void task();

void extra_task();

#endif //LAB_1_RING_H