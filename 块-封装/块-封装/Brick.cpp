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
    int x, y;     // ������Ϣ
    int width;    // ͼƬ���
    int number;   // ��ǰ�洢������


public:
    // ���캯��
    Brick(int xPos, int yPos, int imgWidth, int num)
        : x(xPos), y(yPos), width(imgWidth), number(num) 
    {
        //����ͼƬ
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

    // �������ܵĹ��к���...
};

int main() {

   
    // ����һ��Brick����
    Brick myBrick(0, 0, 40, 0); // �����ʼ����Ϊ0
    myBrick.Show();

    getchar();
    return 0;
}