#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //我方
    int x = 0, y = 0;  //初始位置
    int direction = 0; //初始方向为上
    //敌方
    int enemyX[100], enemyY[100]; //保存敌人位置
    int enemyCount = 0;           //敌人数量
    char command;
    int distance;

    while (true)
    {
        cout << "请输入指令：";
        cin >> command; 

        switch (command)
        {
        case 'q': 
            return 0;

        case 'w': //前进
            cin >> distance;
            switch (direction)
            {
            case 0: y += distance; break;
            case 1: x += distance; break;
            case 2: y -= distance; break;
            case 3: x -= distance; break;
            }
            break;

        case 's': //后退
            cin >> distance;
            switch (direction)
            {
            case 0: y -= distance; break;
            case 1: x -= distance; break;
            case 2: y += distance; break;
            case 3: x += distance; break;
            }
            break;

        case 'a': //逆时针旋转
            direction = (direction + 3) % 4;
            break;

        case 'd': //顺时针旋转
            direction = (direction + 1) % 4;
            break;

        case 'x': //新增敌人
        {
            int enemyXPos, enemyYPos;
            cin >> enemyXPos >> enemyYPos;
            enemyX[enemyCount] = enemyXPos;
            enemyY[enemyCount] = enemyYPos;
            enemyCount++;

            //计算最近的敌人
            int minDist = 1000000;
            int nearestEnemyIndex = -1;
            for (int i = 0; i < enemyCount; i++)
            {
                int dist = abs(x - enemyX[i]) + abs(y - enemyY[i]);
                if (dist < minDist)
                {
                    minDist = dist;
                    nearestEnemyIndex = i;
                }
            }

            //输出最近敌人位置
            cout << "最近敌人位置: (" << enemyX[nearestEnemyIndex] << ", " << enemyY[nearestEnemyIndex] << ")" << endl;

            //计算推荐方向
            string action = "";
            int dx = enemyX[nearestEnemyIndex] - x;
            int dy = enemyY[nearestEnemyIndex] - y;

            if (dx > 0) action = "右 (d)";
            else if (dx < 0) action = "左 (a)";
            else if (dy > 0) action = "上 (w)";
            else if (dy < 0) action = "下 (s)";

            cout << "推荐方向: " << action << endl;
            break;
        }

        default:
            cout << "无效指令，请输入 w/s/a/d/x/q。" << endl;
            break;
        }

        //输出当前位置和方向
        cout << "位置: (" << x << ", " << y << "), 方向: ";
        switch (direction)
        {
        case 0: cout << "上"; break;
        case 1: cout << "右"; break;
        case 2: cout << "下"; break;
        case 3: cout << "左"; break;
        }
        cout << endl;
    }

    return 0;
}