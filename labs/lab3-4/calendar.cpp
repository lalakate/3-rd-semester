#include "calendar.h"
#include <string.h>

void inputTime(int &hours, int &minutes) {
    int method;
    std::cout << "Entering time\n";
    safe_input(cout << "Choose the input method:\n1 - random\n2 - keyboard input\n", cin >> method,
               method > 0 && method < 3);

    switch (method) {
        case 1: {
            hours = rand() % 24;
            minutes = rand() % 60;

            break;
        }
        case 2: {
            safe_input(cout << "Enter hours: ", cin >> hours, hours > -1 && hours < 24);
            safe_input(cout << "Enter minutes: ", cin >> minutes, minutes > -1 && minutes < 60);
            break;
        }
        default:
            break;
    }
    std::cout << "Result: ";
    std::cout << std::setfill('0');
    std::cout << std::setw(2) << hours << ":";
    std::cout << std::setw(2) << minutes << std::endl;
    std::cout << std::setfill(' ');
}

void inputDate(int &day, int &month, int &year) {
    std::cout << "Entering date\n";
    std::cout << "Choose the input method:\n1 - random\n2 - keyboard input\n";
    int method;
    safe_input(cout << "Choose the input method:\n1 - random\n2 - keyboard input\n", cin >> method,
               method > 0 && method < 3);

    switch (method) {
        case 1: {
            day = rand() % 31 + 1;
            month = rand() % 12 + 1;
            year = rand() % 48 + 1990;
            break;
        }
        case 2: {
            safe_input(cout << "Enter day: ", cin >> day, day > 0 && day < 32);
            safe_input(cout << "Enter month: ", cin >> month, month > 0 && month < 13);
            safe_input(cout << "Enter year: ", cin >> year, year > 1970 && year < 2038);

        }
        default:
            break;
    }
    std::cout << "Result: ";
    std::cout << std::setfill('0');
    std::cout << std::setw(2) << day << ".";
    std::cout << std::setw(2) << month << "." << std::setw(4) << year << "\n";
    std::cout << std::setfill(' ');
}

void inputPriority(int &priority) {
    int method;
    std::cout << "Entering priority\n";
    safe_input(cout << "Choose the input method:\n1 - random\n2 - keyboard input\n", cin >> method,
               method > 0 && method < 3);

    switch (method) {
        case 1: {
            priority = rand() % 5 + 1;
            break;
        }
        case 2: {
            safe_input(cout << "Enter priority(1 - 5): ", cin >> priority, priority > 0 && priority < 6);
        }
        default:
            break;
    }
}

bool isAttended() {
    int answer;
    safe_input(cout << "Did you attend the meeting? (1 - yes/2 - no)\n", cin >> answer, answer > 0 && answer < 3);
    return (answer == 1);
}

bool isCompleted() {
    int answer;
    safe_input(cout << "Is the task completed? (1 - yes/2 - no)\n", cin >> answer, answer > 0 && answer < 3);
    return (answer == 1);
}

int dateRatio(int hours, int minutes, int days, int months, int years) {
    Time time(hours, minutes);
    Date date(days, months, years);
    Time nowTime;
    nowTime.setNowTime();
    Date nowDate;
    nowDate.setNowData();

    if (date < nowDate || date == nowDate && time < nowTime) {
        return -1;
    } else if (date == nowDate && time == nowTime) {
        return 0;
    } else
        return 1;
}

std::shared_ptr<Meeting> createMeeting() {
    int hours, minutes, days, months, years;
    inputTime(hours, minutes);
    inputDate(days, months, years);
    std::string status;
    if (dateRatio(hours, minutes, days, months, years) == 1) {
        status = "Planned";
    } else {
        if (isAttended())
            status = "Attended";
        else
            status = "Not attended";
    }
    std::shared_ptr<Meeting> meeting;
    meeting = std::make_shared<Meeting>(hours, minutes, days, months, years, status);
    return meeting;
}

std::shared_ptr<Task> createTask() {
    int hours, minutes, days, months, years;
    inputTime(hours, minutes);
    inputDate(days, months, years);
    std::string status;
    if (dateRatio(hours, minutes, days, months, years) == 1) {
        status = "Planned";
    } else {
        if (isCompleted())
            status = "Completed";
        else
            status = "Not completed";
    }
    std::shared_ptr<Task> task = std::make_shared<Task>(hours, minutes, days, months, years, status);
    return task;
}

std::shared_ptr<Reminder> createReminder() {
    int hours, minutes, days, months, years;
    inputTime(hours, minutes);
    inputDate(days, months, years);
    std::string status;
    if (dateRatio(hours, minutes, days, months, years) <= 0) {
        std::cout << "You can not create a reminder for a time that has already passed\n";
    } else {
        std::string message;
        std::cin.ignore();
        std::cout << "Enter a reminder message\n";
        std::getline(std::cin, message);
        std::shared_ptr<Reminder> reminder = std::make_shared<Reminder>(hours, minutes, days, months, years, message);
        return reminder;
    }
    return nullptr;
}

void menu() {
    std::vector<std::shared_ptr<Event>> eventArray;
    int action;
    while (true) {
        safe_input(cout << "Select an action...\n"
                           "1 - add new meeting\n"
                           "2 - add new task\n"
                           "3 - add new reminder\n"
                           "4 - print all events\n"
                           "5 - exit\n", cin >> action, action > 0 && action < 6);
        switch (action) {
            case 1: {
                auto newEvent = std::make_shared<Event>(createMeeting());
                eventArray.push_back(newEvent);
                break;
            }
            case 2: {
                auto newEvent = std::make_shared<Event>(createTask());
                eventArray.push_back(newEvent);
                break;
            }
            case 3: {
                std::shared_ptr<Reminder> reminder;
                reminder = createReminder();
                if (reminder != nullptr) {
                    auto newEvent = std::make_shared<Event>(reminder);
                    eventArray.push_back(newEvent);
                }
                break;
            }
            case 4: {
                for (int i = 0; i < eventArray.size(); i++) {
                    eventArray[i]->print();
                    std::cout << std::endl;
                }

                break;
            }
            case 5: {
                std::cout << "\nExit...\n";
                break;
            }
            default:
                std::cout << "Error \n";
                break;
        }
    }
}
