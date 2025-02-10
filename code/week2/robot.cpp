#include "robot.h"
#include <iostream>

Robot::Robot(std::string robotName) : name(robotName), taskCount(0)
{
    // ��ʼ�����������Ʋ�����������
}

Robot::~Robot()
{
    // �������δ��ɵ�������Ϣ
    for (int i = 0; i < taskCount; ++i)
    {
        if (taskQueue[i].getStatus() == "��ִ��")
        {
            std::cout << "δִ������ID: " << taskQueue[i].getID()
                      << ", ����: " << taskQueue[i].getDescription() << std::endl;
        }
    }
}

void Robot::addTask(int id, std::string desc)
{
    if (taskCount < 100)
    {
        taskQueue[taskCount++] = Task(id, desc); // ���������
    }
}

void Robot::executeTasks()
{
    for (int i = 0; i < taskCount; ++i)
    {
        taskQueue[i].execute(); // ִ������
    }
}

void Robot::displayTasks()
{
    for (int i = 0; i < taskCount; ++i)
    {
        std::cout << "����ID: " << taskQueue[i].getID()
                  << ", ����: " << taskQueue[i].getDescription()
                  << ", ״̬: " << taskQueue[i].getStatus() << std::endl;
    }
}
