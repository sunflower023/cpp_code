#define _CRT_SECURE_NO_WARNINGS 1
#include"Library.h"
//����
const char* host = "127.0.0.1";
//�û�
const char* use = "root";
//����
const char* password = "hello";
//���ݿ���
const char* database_name = "online_library";
//�˿ں�
const int port = 3306;


Test01()
{
	MYSQL_RES* res = NULL;//��ѯ�����
	MYSQL_ROW row = NULL;//��¼�ṹ��


	//��ʼ��
	MYSQL* con = mysql_init(NULL);

	//�����ַ�����,�Է���������
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

	//��ʼ����
	if (!mysql_real_connect(con, host, use, password, database_name, port, NULL, 0))
	{
		fprintf(stderr, "connect fail", mysql_error(con));
		return -1;
	}

	//Menu();
	//manager_Menu();


	book* book_head = NULL;
	user* user_head = NULL;
	manager* manager_head = NULL;


	book_head = load_Book(book_head, res, row, con);
	user_head = load_User(user_head, res, row, con);
	manager_head = load_Manager(manager_head, res, row, con);

	//Show_remaining_book(res, row, con);
	//borrow_book(1, res, row, con, book_head);
	//return_book(1, res, row, con, book_head);

	//reader_Menu(user_head);
	//Search_book(book_head);
	//Add_new_book(book_head, con);
	//Add_new_user(user_head, con);
	//Add_new_manager(manager_head, con);
	//Show_All_book(book_head);

	//Delete_Book(book_head, con);
	//Change_book(book_head,con);

	//Show_All_user(user_head);
	//Change_User_password(user_head, con);
	//user_Login(user_head);
	//manager_Login(manager_head);

	//if (mysql_query(con, sql))
	//{
	//	fprintf(stderr, "insert fail", mysql_error(con));
	//	return -1;
	//}

	//�ر�����
	mysql_close(con);
}

Test02()
{
	MYSQL_RES* res = NULL;//��ѯ�����
	MYSQL_ROW row = NULL;//��¼�ṹ��


	//��ʼ��
	MYSQL* con = mysql_init(NULL);

	//�����ַ�����,�Է���������
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

	//��ʼ����
	if (!mysql_real_connect(con, host, use, password, database_name, port, NULL, 0))
	{
		fprintf(stderr, "connect fail", mysql_error(con));
		return -1;
	}
	book* book_head = NULL;
	user* user_head = NULL;
	manager* manager_head = NULL;

	
	book_head = load_Book(book_head, res, row, con);
	user_head = load_User(user_head, res, row, con);
	manager_head = load_Manager(manager_head, res, row, con);

	//����
	int input = 0;
	do
	{
		Menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			if (manager_Login(manager_head))
			{
				int input2 = 0;
				do
				{
					manager_Menu();
					scanf("%d", &input2);
					switch (input2)
					{
					case 1:
						Add_new_book(book_head, con);
						break;
					case 2:
						Show_All_book(book_head);
						break;
					case 3:
						Search_book(book_head);
						break;
					case 4:
						Change_book(book_head,con);
						break;
					case 5:
						Delete_Book(book_head, con);
						break;
					case 6:
						Show_All_user(user_head);
						break;
					case 7:
						input2 = 0;
						break;
					case 8:
						Add_new_manager(manager_head, con);
						break;
					case 0:
						input2 = 0;
						input = 0;
						break;
					}
				} while (input2);
			}
			break;
		case 2:
			printf("\n");
			user * cur = user_Login(user_head);
			if (cur)
			{
				int input3 = 0;
				do
				{
					reader_Menu(user_head);
					scanf("%d", &input3);
					switch (input3)
					{
					case 1:
						borrow_book(cur->U_ID, res, row, con, book_head);
						break;
					case 2:
						return_book(cur->U_ID, res, row, con, book_head);
						break;
					case 3:
						Change_User_password(user_head, con);
						break;
					case 4:
						input3 = 0;
						break;
					case 0:
						input3 = 0;
						input = 0;
						break;
					}

				} while (input3);
			}
			break;
		case 3:
			Add_new_user(user_head, con);
			break;
		}
	} while (input);
	
	printf("�ٻᣡ\n");

	//�ر�����
	mysql_close(con);
}

int main()
{
	//Test01();
	Test02();

	return 0;
}