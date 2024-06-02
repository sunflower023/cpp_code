#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql.h>
#include<time.h>


//�ṹ�嶨��
typedef struct manager_table
{
	int M_ID;
	char M_Account[30];
	char M_Password[30];
	struct manager_table* next;
}manager;

typedef struct book_table
{
	int B_ID;
	char B_NAME[30];
	char Author[30];
	char Publish[30];
	float Price;
	int Quantity;
	struct book_table* next;
}book;

typedef struct user_table
{
	int U_ID;
	char U_Account[30];
	char U_Password[30];
	struct user_table* next;
}user;

//��������

//չʾ�˵�
void Menu();
void manager_Menu();
void reader_Menu(user* head);
void show_Menu_user(user* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql);

//�����ݿ��м����鼮��Ϣ
book* load_Book(book* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql);

//����¹���Ա
manager* Add_new_manager(manager* head, MYSQL* mysql);
//����½����¼
//borrow_book* Add_new_borrow(borrow_book* head, MYSQL* mysql);

//�����ݿ��м����鼮��Ϣ
book* load_Book(book* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql);
//�����ݿ��м��ؽ�����Ϣ


//������鼮
book* Add_new_book(book* head, MYSQL* mysql);
//չʾ�鼮��Ϣ
void Show_All_book(book* head);
//�����鼮��Ϣ
void Search_book(book* head);
//ɾ���鼮��Ϣ
book* Delete_Book(book* head, MYSQL* mysql);
//�޸��鼮��Ϣ
book* Change_book(book* head, MYSQL* mysql);


//������û�
user* Add_new_user(user* head, MYSQL* mysql);
//չʾ���е��û���Ϣ
void Show_All_user(user* head);
//�����ݿ��м����û���Ϣ
user* load_User(user* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql);
//�����ݿ��м��ع���Ա��Ϣ
user* load_Manager(user* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql);
//�޸��û�����
int Change_User_password(user* head, MYSQL* mysql);
//�û���½
user* user_Login(user* head);
//����Ա��¼
manager* manager_Login(manager* head);

//��ʾ�п����鼮
void Show_remaining_book(MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql);
//����ͼ��
int borrow_book(int id, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql, book* head);
//�黹ͼ��
int return_book(int id, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql, book* head);