#include "ring.h"

template<typename T>
requires is_same<T, int>::value || is_same<T, double>::value
void Ring<T>::push(T value) {
    Node *elem = new Node(value, nullptr, nullptr);
    if (!head) {
        head = elem;
        head->next = head;
        head->prev = head;
    } else {
        elem->prev = head->prev;
        elem->next = head;
        head->prev->next = elem;
        head->prev = elem;
    }
}

template<typename T>
requires is_same<T, int>::value || is_same<T, double>::value
void Ring<T>::remove(Node *target) {
    if (head == nullptr || target == nullptr) {
        return;
    }
    if (head->next == head) {
        delete target;
        head = nullptr;
        return;
    }
    if (target == head) {
        head = head->next;
        head->prev = target->prev;
        target->prev->next = head;
        delete target;
        return;
    }

    Node *current = head;
    while (current->next != head && current->next != target)
        current = current->next;
    if (current->next == head)
        return;

    current->next = target->next;
    target->next->prev = current;
    delete target;
}

template<typename T>
requires is_same<T, int>::value || is_same<T, double>::value
int Ring<T>::get_index(Node *node) {
    Node *temp = head;
    int index = 0;
    while (temp != node) {
        temp = temp->next;
        index++;
    }
    return index;
}

template<typename T>
requires is_same<T, int>::value || is_same<T, double>::value
int Ring<T>::get_index(T value) {
    Node *temp = head;
    int index = 0;
    while (temp->data != value) {
        temp = temp->next;
        index++;
    }
    return index;
}

template<typename T>
requires is_same<T, int>::value || is_same<T, double>::value
typename Ring<T>::Node *Ring<T>::get_node(int index) {
    Node *temp = head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;
    return temp;
}

template<typename T>
requires is_same<T, int>::value || is_same<T, double>::value
void Ring<T>::edit(int index, T new_data) {
    Node *temp = head;
    if (head == nullptr) {
        cout << "There is no data\n";
        return;
    }
    for (int i = 0; i < index; i++)
        temp = temp->next;
    temp->data = new_data;
}