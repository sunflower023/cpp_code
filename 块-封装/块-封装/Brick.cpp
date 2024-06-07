#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<easyx.h>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#define PICTURE 40



class Brick {
private:

    IMAGE image[12];
    int x, y;     // 坐标信息
    int width;    // 图片宽度
    int number;   // 当前存储的数字


public:
    // 构造函数
    Brick(int xPos, int yPos, int imgWidth, int num)
        : x(xPos), y(yPos), width(imgWidth), number(num) 
    {
        //加载图片
        for (int i = 0; i < 12; i++)
        {
            char number[100];
            sprintf(number, ".\\images\\%d.jpg", i);
            loadimage(&image[i], number, PICTURE, PICTURE);
        }
    }

    void Show()
    {
        initgraph(5*PICTURE,5*PICTURE, EX_SHOWCONSOLE);
        putimage(PICTURE, PICTURE, &image[1]);
    }

    // 其他可能的公有函数...
};

int main() {

   
    // 创建一个Brick对象
    Brick myBrick(0, 0, 40, 0); // 假设初始数字为0
    myBrick.Show();

    getchar();
    return 0;
}