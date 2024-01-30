#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include <cstdlib>
#include "source.h"
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

void inputTime(int &hours, int &minutes);

void inputDate(int &day, int &month, int &year, int &weekDay);

void inputPriority(int &priority);

bool isAttended();

int dateRatio(int hours, int minutes, int days, int months, int years);

std::shared_ptr<Meeting> createMeeting();

std::shared_ptr<Task> createTask();

std::shared_ptr<Reminder> createReminder();

void menu();