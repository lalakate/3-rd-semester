#include "ring.h"

Ring::Ring(int size_) {
    head = nullptr;
    size = size_;
    for (int i = 0; i < size_; i++) {
        push(0);
    }
}

void Ring::push(int data) {
    Node *elem = new Node(data, nullptr);
    if (!head) {
        head = elem;
        head->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = elem;
        elem->next = head;
    }
    size++;
}

void Ring::pop() {
    if (head == nullptr) {
        std::cout << "\nList is empty.";
        return;
    } else if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node *last = head;
        Node *prev = nullptr;
        while (last->next != head) {
            prev = last;
            last = last->next;
        }
        delete last;
        prev->next = head;
    }
    size--;
    cout << "The data was deleted successfully!";
}

void Ring::remove(int index) {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    if (index == 0) {
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node *last = head;
            while (last->next != head)
                last = last->next;
            Node *temp = head;
            head = head->next;
            last->next = head;
            delete temp;
        }
    } else {
        Node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }
    size--;
}

int Ring::get_index(Node *node) {
    Node *temp = head;
    int index = 0;
    while (temp != node) {
        temp = temp->next;
        index++;
    }
    return index;
}

int Ring::get_index(int value) {
    Node *temp = head;
    int index = 0;
    while (temp->data != value) {
        temp = temp->next;
        index++;
    }
    return index;
}

Node *Ring::get_node(int index) {
    Node *temp = head;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    return temp;
}

void Ring::print() {
    if (head == nullptr)
        cout << "There is no data\n";
    else {
        Node *temp = head->next;
        cout << head->data << " ";
        while (temp != head) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void Ring::edit(int index, int new_data) {
    Node *temp = head;
    if (head == nullptr) {
        cout << "There is no data\n";
        return;
    }
    for (int i = 0; i < index; i++)
        temp = temp->next;
    temp->data = new_data;
}

Node Ring::find(const int &index) {
    Node *current = head;
    for (int i = 0; i < index; i++)
        current = current->next;
    return *current;
}

Node &Node::operator=(const Node &node) {
    data = node.data;
    next = node.next;
    return *this;
}

Node &Node::operator+(const Node &node) {
    Ring ring = Ring(2);
    ring.push(data);
    ring.push(node.data);
    return *this;
}

Ring &Ring::operator+(const Node &node) {
    push(node.data);
    return *this;
}

Ring &Ring::operator+=(const Node &node) {
    *this = *this + node;
    return *this;
}

Ring &Ring::operator+=(const int value) {
    push(value);
    return *this;
}

Ring &Ring::operator-(Node &node) {
    remove(get_index(&node));
    return *this;
}

Ring &Ring::operator-=(Node &node) {
    *this = *this - node;
    return *this;
}

Ring &Ring::operator-=(const int value) {
    remove(get_index(value));
    return *this;
}

void Ring::operator delete(void *ring) {
    free(ring);
}

void *Ring::operator new(size_t size) {
    void *ring = malloc(size * sizeof(Ring));
    return ring;
}

bool Node::operator==(const Node &node) {
    return data == node.data;
}

bool Node::operator!=(const Node &node) {
    return data != node.data;
}

bool Node::operator>(const Node &node) {
    return data > node.data;
}

bool Node::operator<(const Node &node) {
    return data < node.data;
}

bool Node::operator>=(const Node &node) {
    return data >= node.data;
}

bool Node::operator<=(const Node &node) {
    return data <= node.data;
}