#pragma once

#include <memory>
#include <iostream>
#include <ctime>
#include <limits>
#include <ostream>
#include <windows.h>

using namespace std;

#define safe_input(cout_line, cin_line, checks, err_message)     \
while (true)                                                 \
    {                                                            \
        cout_line;                                               \
        bool f = static_cast<bool>(cin_line);                    \
        char c = cin.get();                                      \
        if (f && isspace(c) && checks)                           \
            break;                                               \
        HANDLE hConsole;                                         \
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);              \
        SetConsoleTextAttribute(hConsole, 4);                    \
        err_message;                                             \
        SetConsoleTextAttribute(hConsole, 7);                    \
        if (!isspace(c))                                         \
        {                                                        \
            cin.clear();                                         \
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); \
        }                                                        \
    }


template<typename T> requires is_same<T, int>::value || is_same<T, double>::value

class Ring {
public:
    class Node {
    public:
        T data;
        Node *next;
        Node *prev;
    public:
        Node(T value, Node *next_, Node *prev_) {
            this->data = value;
            this->next = next_;
            this->prev = prev_;
        }
    };

    Node *head;
    int size;

    Ring(int size_) {
        head = nullptr;
        size = size_;
        for (int i = 0; i < size_; i++)
            push(0);
    }


    void push(T value);

    void remove(Node *target);

    int get_index(Node *node);

    int get_index(T value);

    Node *get_node(int index);

    void edit(int index, T new_data);

    friend ostream &operator<<(ostream &out, Ring<T> &ring) {
        if (ring.head == nullptr)
            cout << "\nList is empty.\n";
        else {
            Ring<T>::Node *temp = ring.head->next;
            out << ring.head->data << " ";
            while (temp != ring.head) {
                out << temp->data << " ";
                temp = temp->next;
            }
        }
        return out;
    }

    friend istream &operator>>(istream &in, Ring<T> &ring) {
        int choice, data;
        if (ring.size != 0) {
            safe_input(cout << "\nPlease, choose how do you wanna create list:\n"
                               "1 - by random;\n"
                               "2 - manually.\n", cin >> choice, choice > 0 && choice < 3,
                       cout << "Bad input. Try again.\n");

            switch (choice) {
                case 1:
                    srand(time(NULL));
                    for (int i = 0; i < ring.size; i++) {
                        data = rand() % 100 + 1;
                        ring.edit(i, data);
                    }
                    break;
                case 2:
                    cout << "Enter the data:\n";
                    for (int i = 0; i < ring.size; i++) {
                        safe_input(, in >> data, 1, cout << "Bad input. Try again.\n");
                        ring.edit(i, data);
                    }
                    break;
            }
        }
        cout << "\nYour list: " << ring;
        return in;
    }
};


void task();
