#include "ring.cpp"

int size_input() {
    int size_;
    safe_input(cout << "\nHello everybody!\n"
                       "I've made this two-ordered list by myself :)\n"
                       "So let's fill it!\n"
                       "Please enter size of the list: ", cin >> size_, 1,
               cout << "Bad input. Try again.\n");
    if (size_ < 0 || size_ > 100) throw "Incorrect size.\n";
    return size_;
}

void task() {
    int choice, size, data, index;

    try {
        size = size_input();
    }
    catch (...) { return; }

    Ring ring = Ring<int>(size);

    cin >> ring;

    while (true) {
        safe_input(cout << "\nChoose what do you wanna do with list:\n"
                           "1 - add element to the list;\n"
                           "2 - delete the element by index;\n"
                           "3 - print the list;\n"
                           "4 - exit program.\n", cin >> choice, choice > 0 && choice < 5,
                   cout << "Bad input. Try again.\n");

        switch (choice) {
            case 1:
                if (size >= 100) throw "Too much elements.\n";
                try {
                    safe_input(cout << "Enter data: ", cin >> data, 1, cout << "Bad input. Try again.\n");
                    ring.push(data);
                    size++;
                }
                catch (...) { return; }
                break;
            case 2:
                if (size == 0)
                    throw "List is empty.\n";
                try {
                    safe_input(cout << "Enter the index: ", cin >> index, index > -1 && index < size,
                               cout << "Bad input. Try again.\n");
                    ring.remove(ring.get_node(index));
                    size--;
                } catch (...) { return; }
                break;
            case 3:
                cout << ring << endl;
                break;
            case 4:
                exit(0);
        }
    }
}