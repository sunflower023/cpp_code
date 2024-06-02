#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql.h>
#include<time.h>


//结构体定义
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

//函数定义

//展示菜单
void Menu();
void manager_Menu();
void reader_Menu(user* head);
void show_Menu_user(user* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql);

//从数据库中加载书籍信息
book* load_Book(book* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql);

//添加新管理员
manager* Add_new_manager(manager* head, MYSQL* mysql);
//添加新借书记录
//borrow_book* Add_new_borrow(borrow_book* head, MYSQL* mysql);

//从数据库中加载书籍信息
book* load_Book(book* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql);
//从数据库中加载借阅信息


//添加新书籍
book* Add_new_book(book* head, MYSQL* mysql);
//展示书籍信息
void Show_All_book(book* head);
//查找书籍信息
void Search_book(book* head);
//删除书籍信息
book* Delete_Book(book* head, MYSQL* mysql);
//修改书籍信息
book* Change_book(book* head, MYSQL* mysql);


//添加新用户
user* Add_new_user(user* head, MYSQL* mysql);
//展示所有的用户信息
void Show_All_user(user* head);
//从数据库中加载用户信息
user* load_User(user* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql);
//从数据库中加载管理员信息
user* load_Manager(user* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql);
//修改用户密码
int Change_User_password(user* head, MYSQL* mysql);
//用户登陆
user* user_Login(user* head);
//管理员登录
manager* manager_Login(manager* head);

//显示有库存的书籍
void Show_remaining_book(MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql);
//借阅图书
int borrow_book(int id, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql, book* head);
//归还图书
int return_book(int id, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql, book* head);