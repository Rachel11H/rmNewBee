#include <iostream>
#include "robot.h"
using namespace std;

int main() {
    string robotName;
    cout << "���������������: ";
    cin >> robotName;
    
    Robot robot(robotName);
    string command;

    while (true) {
        cout << "������������/ִ��/��ʾ/�˳���: ";
        cin >> command;

        if (command == "�˳�") {
            break;
        } else if (command == "���") {
            int id;
            string desc;
            cin >> id >> desc;
            robot.addTask(id, desc);
        } else if (command == "ִ��") {
            robot.executeTasks();
        } else if (command == "��ʾ") {
            robot.displayTasks();
        } else {
            cout << "��Ч��������ԡ�" << endl;
        }
    }

    return 0;
}
