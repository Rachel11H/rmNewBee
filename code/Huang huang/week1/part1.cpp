#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 0,y = 0;   //初始位置
    int direction = 0; //初始方向为上
    const string directions[] = {"上","右","下","左"};
    char command;
    int distance;

    while(true)
    {
        cout << "请输入指令：";
        cin >> command;
        if (command == 'q'){
            break;
        }

        switch (command)
        {
        case 'w': //前进
            cin >> distance;
            if (direction == 0)
                y += distance;
            else if (direction == 1)
                x += distance;
            else if (direction == 2)
                y -= distance;
            else if (direction == 3)
                x -= distance;
            break;
        
        case 's': //后退
            cin >> distance;
            if (direction == 0)
                y -= distance;
            else if (direction == 1)
                x -= distance;
            else if (direction == 2)
                y += distance;
            else if (direction == 3)
                x += distance;
            break;

        case 'a': //逆时针旋转
            direction = (direction + 3) % 4;
            break;

        case 'd': //顺时针旋转
            direction = (direction + 1) % 4;
            break;

        default:
            continue;
        }

        //输出当前位置和方向
        cout << "位置: (" << x << "," << y << ")，方向: " << directions[direction] << endl;
    }

    return 0;
}