#include "ring.h"

void task() {
    int choice, size, data, index1, index2;

    safe_input(cout << "\nWelcome everybody!\n"
                       "Now we are at Gomel circus and we gonna create a list:)\n"
                       "Please enter size of the list: ", cin >> size, size > 0 && size < 101);

    Ring ring = Ring(size);

    safe_input(cout << "\nPlease, choose how do you wanna create list:\n"
                       "1 - by random;\n"
                       "2 - manually.\n", cin >> choice, choice > 0 && choice < 3);

    switch (choice) {
        case 1:
            srand(time(NULL));
            for (int i = 0; i < size; i++) {
                data = rand() % 100 + 1;
                ring.edit(i, data);
            }
            break;
        case 2:
            cout << "Enter the data:\n";
            for (int i = 0; i < size - 1; i++) {
                safe_input(, cin >> data, 1);
                ring.edit(i, data);
            }
            break;
    }
    cout << "\nYour list: ";
    ring.print();

    cout << "\nOkay, we've finished list entering!!!\n"
            "But...\n";

    while (1) {
        safe_input(cout << "\nChoose what do you wanna do with list:\n"
                           "1 - add element to the list;\n"
                           "2 - subtract element from the list;\n"
                           "3 - compare elements of list;\n"
                           "4 - print the list;\n"
                           "5 - exit program.\n", cin >> choice, choice > 0 && choice < 6);

        switch (choice) {
            case 1:
                safe_input(cout << "Enter data: ", cin >> data, 1);
                ring += data;
                break;
            case 2:
                safe_input(cout << "Enter index of the element you wanna delete: ", cin >> data,
                           data > -1 && data < size);
                ring -= *ring.get_node(data);
                break;
            case 3: {
                safe_input(cout << "Enter index of the first element: ", cin >> index1,
                           index1 > -1 && index1 < size);
                safe_input(cout << "Enter index of the second element: ", cin >> index2,
                           index2 > -1 && index2 < size);
                Node a = ring.find(index1);
                Node b = ring.find(index2);
                if (a == b) {
                    cout << "\nElements are equal\n";
                    break;
                } else if (a > b) {
                    cout << "\nThe first element is bigger than the second one\n";
                    break;
                } else if (a >= b) {
                    cout << "\nThe first element is bigger or equal than the second one\n";
                    break;
                } else if (a < b) {
                    cout << "\nThe first element is less than the second one\n";
                    break;
                } else if (a <= b) {
                    cout << "\nThe first element is less or equal than the second one\n";
                    break;
                } else if (a != b) {
                    cout << "\nElements are not equal";
                    break;
                }
            }
            case 4:
                ring.print();
                break;
            case 5:
                exit(0);
        }
    }
}
