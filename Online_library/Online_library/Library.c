#define _CRT_SECURE_NO_WARNINGS 1
#include"Library.h"

//��ʼ�˵�
void Menu()
{
	printf("***************************************\n");
	printf("*      ��ӭ��������ͼ�����ϵͳ��     *\n");
	printf("*                                     *\n");
	printf("*            1.����Ա��¼             *\n");
	printf("*            2.���ߵ�¼               *\n");
	printf("*            3.����ע��               *\n");
	printf("*            0.�˳���ϵͳ             *\n");
	printf("***************************************\n");
}
void manager_Menu()
{
	printf("***************************************\n");
	printf("*            ��ӭ�㣬����Ա            \n");
	printf("*                                     \n");
	printf("*            1.����鼮              \n");
	printf("*            2.��ʾ�鼮              \n");
	printf("*            3.�����鼮               \n");
	printf("*            4.�޸��鼮               \n");
	printf("*            5.ɾ���鼮               \n");
	printf("*            6.��ʾ�û�����            \n");
	printf("*            7.�������˵�              \n");
	printf("*            8.����¹���Ա              \n");
	printf("*            0.�˳���ϵͳ             \n");
	printf("***************************************\n");
}
void reader_Menu(user* head)
{
	printf("***************************************\n");
	printf("*          ��ӭ�㣬����           \n");
	printf("*                                     \n");
	printf("*          1.�����鼮                  \n");
	printf("*          2.�黹�鼮                  \n");
	printf("*          3.�޸�����                  \n");
	printf("*          4.�������˵�                \n");
	printf("*          0.�˳���ϵͳ                \n");
	printf("*                                     \n");
	printf("***************************************\n");
}


//�����ݿ��м����鼮��Ϣ
book* load_Book(book* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql)
{
	book* p = NULL;
	book* pcur = head;

	//��ѯ����
	mysql_query(mysql, "select * from book;");

	//��ȡ�����
	res = mysql_store_result(mysql);

	//��ֵ��Ϊ����
	while (row = mysql_fetch_row(res))
	{
		p = NULL, pcur = head;
		p = (book*)malloc(sizeof(book));
		if (p == NULL)
		{
			perror("malloc fail");
			exit(1);
		}

		if (head == NULL)
		{
			head = p;
		}
		else
		{
			while (pcur->next != NULL)
			{
				pcur = pcur->next;
			}
			pcur->next = p;
		}

		p->B_ID = atoi(row[0]);
		strcpy(p->B_NAME, row[1]);
		strcpy(p->Author, row[2]);
		strcpy(p->Publish, row[3]);
		p->Price = atoi(row[4]);
		p->Quantity = atoi(row[5]);
		p->next = NULL;
	}

	//�ͷŽ����
	mysql_free_result(res);
	return head;
}

//������鼮
book* Add_new_book(book* head, MYSQL* mysql)
{
	book* newbook = (book*)malloc(sizeof(book));
	if (newbook == NULL)
	{
		perror("malloc fail");
		exit(1);
	}

	if (head == NULL)
	{
		head = newbook;
	}
	else
	{
		//�ҵ�β�ڵ�
		book* pcur = head;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = newbook;
	}

	printf("�������鼮��ţ�");
	scanf("%d", &(newbook->B_ID));

	//������ظ�

	printf("���������ƣ�");
	scanf("%s", newbook->B_NAME);
	printf("���������ߣ�");
	scanf("%s", newbook->Author);
	printf("����������磺");
	scanf("%s", newbook->Publish);
	printf("������۸�");
	scanf("%f", &(newbook->Price));
	printf("������������");
	scanf("%d", &(newbook->Quantity));

	//�������鼮��Ϣ�������ݿ�
	char sql[256];
	sprintf(sql, "insert into book values('%d','%s','%s','%s','%f','%d')",
		newbook->B_ID, newbook->B_NAME, newbook->Author, newbook->Publish, newbook->Price, newbook->Quantity);
	mysql_query(mysql, sql);

	newbook->next = NULL;
	printf("��ӳɹ���\n");
	return head;
}
//������û�
user* Add_new_user(user* head, MYSQL* mysql)
{
	user* newuser = (user*)malloc(sizeof(user));
	user* pcur = head;
	if (newuser == NULL)
	{
		perror("malloc fail");
		exit(1);
	}

	if (head == NULL)
	{
		head = newuser;
	}
	else
	{
		//�ҵ�β�ڵ�
		book* pcur = head;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = newuser;
	}

	printf("�������û���ţ�");
	scanf("%d", &(newuser->U_ID));
	printf("�������û��˺ţ�");
	scanf("%s", newuser->U_Account);
	printf("�������û����룺");
	scanf("%s", newuser->U_Password);

	char sql[256];
	sprintf(sql, "insert into user values('%d','%s','%s')",
		newuser->U_ID, newuser->U_Account, newuser->U_Password);
	mysql_query(mysql, sql);

	newuser->next = NULL;
	printf("��ӳɹ���\n");
	return head;
}
//����¹���Ա
manager* Add_new_manager(manager* head, MYSQL* mysql)
{
	manager* newmanager = (manager*)malloc(sizeof(manager));
	user* pcur = head;
	if (newmanager == NULL)
	{
		perror("malloc fail");
		exit(1);
	}

	if (head == NULL)
	{
		head = newmanager;
	}
	else
	{
		//�ҵ�β�ڵ�
		book* pcur = head;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = newmanager;
	}

	printf("���������Ա��ţ�");
	scanf("%d", &(newmanager->M_ID));
	printf("���������Ա�˺ţ�");
	scanf("%s", newmanager->M_Account);
	printf("���������Ա���룺");
	scanf("%s", newmanager->M_Password);

	char sql[256];
	sprintf(sql, "insert into manager values('%d','%s','%s')",
		newmanager->M_ID, newmanager->M_Account, newmanager->M_Password);
	mysql_query(mysql, sql);

	newmanager->next = NULL;
	printf("��ӳɹ���\n");
	return head;
}

//չʾ�鼮��Ϣ
void Show_All_book(book* head)
{
	book* p = head;
	printf("===================================================================================\n");
	printf("|����                    |����            |������          |�۸�  |���  |���    |\n");
	while (p != NULL) {
		printf("-----------------------------------------------------------------------------------\n");
		printf("|%-24s|%-16s|%-16s|%-6.2f|%-6d|%-8d|\n", p->B_NAME, p->Author, p->Publish, p->Price, p->Quantity, p->B_ID);
		p = p->next;
	}
	printf("===================================================================================\n");

}
//�����鼮��Ϣ
void Search_book(book* head)
{
	book* p = head;
	char search[100];
	int option;
	printf("=======================\n");
	printf("|   �������ѯ����Ŀ  |\n");
	printf("|    1.ͼ����         |\n");
	printf("|    2.������         |\n");
	printf("|    3.������         |\n");
	printf("=======================\n");
	scanf("%d", &option);
	while (1)
	{
		printf("=======================\n");
		printf("|   �������ѯ������   |\n");
		printf("=======================\n");
		scanf("%s", search);
		printf("===================================================================================\n");
		printf("|����                    |����            |������          |�۸�  |���  |���    |\n");

		int flag = 1;
		while (p != NULL)
		{
			switch (option)
			{
			case 1:
				if (strstr(p->B_NAME, search))
				{
					flag = 0;
					printf("-----------------------------------------------------------------------------------\n");
					printf("|%-24s|%-16s|%-16s|%-6.2f|%-6d|%-8d|\n", p->B_NAME, p->Author, p->Publish, p->Price, p->Quantity, p->B_ID);
				}
				break;
			case 2:
				if (strstr(p->Author, search))
				{
					flag = 0;
					printf("-----------------------------------------------------------------------------------\n");
					printf("|%-24s|%-16s|%-16s|%-6.2f|%-6d|%-8d|\n", p->B_NAME, p->Author, p->Publish, p->Price, p->Quantity, p->B_ID);
				}
				break;
			case 3:
				if (strstr(p->Publish, search))
				{
					flag = 0;
					printf("-----------------------------------------------------------------------------------\n");
					printf("|%-24s|%-16s|%-16s|%-6.2f|%-6d|%-8d|\n", p->B_NAME, p->Author, p->Publish, p->Price, p->Quantity, p->B_ID);
				}
				break;
			}
			p = p->next;
		}
		if (flag)
		{
			printf("-----------------------------------------------------------------------------------\n");
			printf("|%-24s|%-16s|%-16s|%-6s|%-6s|%-8s|\n", "��", "��", "��", "��", "��", "��");
		}

		printf("===================================================================================\n");
		break;
	}
}
//ɾ���鼮��Ϣ
book* Delete_Book(book* head, MYSQL* mysql)
{
	book* p = head;
	book* pcur = NULL;
	int id, option;
	char sql[256];
	printf("������ɾ���鼮�ı�ţ�");
	scanf("%d", &id);
	while (p)
	{
		if (id == p->B_ID)
		{
			break;
		}
		pcur = p;
		p = p->next;
	}
	if (p == NULL)
	{
		printf("δ�ҵ���ID��ŵ��鼮\n");
		return 0;
	}
	else
	{
		printf("===================================================================================\n");
		printf("|����                    |����            |������          |�۸�  |���  |���    |\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("|%-24s|%-16s|%-16s|%-6.2f|%-6d|%-8d|\n", p->B_NAME, p->Author, p->Publish, p->Price, p->Quantity, p->B_ID);
		printf("===================================================================================\n");

		printf("================\n");
		printf("|�Ƿ�ȷ��ɾ����|\n");
		printf("|0.ȡ��  1.ȷ��|\n");
		printf("================\n");

		scanf("%d", &option);
		switch (option)
		{
		case 1:
			sprintf(sql, "delete from book where B_ID = %d;", id);
			mysql_query(mysql, sql);
			if (p == head)
			{
				head = head->next;
				free(p);
			}
			else
			{
				pcur->next = p->next;
				free(p);
			}
			printf("�ѳɹ�ɾ��\n");
			option = 0;
			break;
		case 0:
			printf("ȡ��ɾ��\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	}
	return head;
}
//�޸��鼮��Ϣ
book* Change_book(book* head, MYSQL* mysql)
{
	int id;
	int option = 0;
	book* p = head;
	char sql[256];
	printf("��������Ҫ�޸ĵ��鼮��ţ�");
	scanf("%d", &id);
	while (p)
	{
		if (id == p->B_ID)
		{
			break;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("δ�ҵ���ID��ŵ��鼮\n");
		return 0;
	}
	else
	{
		do
		{
			printf("===================================================================================\n");
			printf("|����                    |����            |������          |�۸�  |���  |���    |\n");
			printf("-----------------------------------------------------------------------------------\n");
			printf("|%-24s|%-16s|%-16s|%-6.2f|%-6d|%-8d|\n", p->B_NAME, p->Author, p->Publish, p->Price, p->Quantity, p->B_ID);
			printf("===================================================================================\n");

			printf("================\n");
			printf("|��ѡ���޸ĵ�����|\n");
			printf("|     1.����    |\n");
			printf("|     2.����    |\n");
			printf("|    3.������   |\n");
			printf("|     4.�۸�    |\n");
			printf("|    5.�����   |\n");
			printf("|   0.�˳��޸�  |\n");
			printf("================\n");
			scanf("%d", &option);

			switch (option)
			{
			case 1:
				printf("�������޸ĺ��������");
				scanf("%s", p->B_NAME);
				break;

			case 2:
				printf("�������޸ĺ�����ߣ�");
				scanf("%s", p->Author);
				break;

			case 3:
				printf("�������޸ĺ�ĳ����磺");
				scanf("%s", p->Publish);
				break;

			case 4:
				printf("�������޸ĺ�ļ۸�");
				scanf("%f", &(p->Price));
				break;

			case 5:
				printf("�������޸ĺ�Ŀ������");
				scanf("%d", &(p->Quantity));
				break;
			case 0:
				break;
			}
		} while (option);
	}

	sprintf(sql, "update book set B_NAME = '%s', Author = '%s', Publish = '%s', Price = %f, Quantity = %d where B_ID = %d;",
		p->B_NAME, p->Author, p->Publish, p->Price, p->Quantity, p->B_ID);
	mysql_query(mysql, sql);

	printf("�޸ĳɹ���\n");
	return 0;
}

//չʾ���е��û���Ϣ
void Show_All_user(user* head)
{
	user* p = head;
	printf("=========================================================\n");
	printf("|�û����                   |�˺�          |����          |\n");
	while (p != NULL) {
		printf("---------------------------------------------------------\n");
		printf("|%-27d|%-14s|%-14s|\n", p->U_ID, p->U_Account, p->U_Password);
		p = p->next;
	}
	printf("=========================================================\n");
}
//�����ݿ��м����û���Ϣ
user* load_User(user* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql)
{
	user* p = NULL, * pr = head;
	mysql_query(mysql, "select * from user;");
	res = mysql_store_result(mysql);

	while (row = mysql_fetch_row(res))
	{
		p = NULL, pr = head;
		p = (user*)malloc(sizeof(user));
		if (p == NULL)
		{
			perror("malloc fail");
			exit(1);
		}
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			while (pr->next != NULL)
			{
				pr = pr->next;
			}
			pr->next = p;
		}
		p->U_ID = atoi(row[0]);
		strcpy(p->U_Account, row[1]);
		strcpy(p->U_Password, row[2]);
		p->next = NULL;
	}

	mysql_free_result(res);

	return head;
}
//�����ݿ��м��ع���Ա��Ϣ
user* load_Manager(user* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql)
{
	manager* p = NULL, * pr = head;
	mysql_query(mysql, "select * from manager;");
	res = mysql_store_result(mysql);

	while (row = mysql_fetch_row(res))
	{
		p = NULL, pr = head;
		p = (manager*)malloc(sizeof(manager));
		if (p == NULL)
		{
			perror("malloc fail");
			exit(1);
		}
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			while (pr->next != NULL)
			{
				pr = pr->next;
			}
			pr->next = p;
		}
		p->M_ID = atoi(row[0]);
		strcpy(p->M_Account, row[1]);
		strcpy(p->M_Password, row[2]);
		p->next = NULL;
	}

	mysql_free_result(res);

	return head;
}
//�޸��û�����
int Change_User_password(user* head, MYSQL* mysql)
{
	char account[30];
	char password[30];
	char sql[256];
	int option;
	user* p = head;
	printf("�������û��˺ţ�");
	scanf("%s", account);
	while (p)
	{
		if (!strcmp(account, p->U_Account))
		{
			break;
		}
		p = p->next;
	}

	if (p == NULL)
	{
		printf("û�в��ҵ����û�\n");
		return 0;
	}
	else
	{
		printf("==============================\n");
		printf("|�˺�                |���  |\n");
		printf("------------------------------\n");
		printf("|%-20s|%6d|\n", p->U_Account, p->U_ID);
		printf("==============================\n");
	}

	while (1)
	{
		printf("��������˺�����:");
		scanf("%s", password);
		if (strcmp(password, p->U_Password) == 0)
		{
			printf("�����������룺");
			scanf("%s", password);
			sprintf(sql, "update user set U_Password = '%s' where U_ID = %d;", password, p->U_ID);
			mysql_query(mysql, sql);
			printf("�޸ĳɹ���");
			break;
		}
		else
		{
			printf("�������,������\n");
		}
	}
}
//�û���½
user* user_Login(user* head)
{
	user* p = head;
	char account[30], password[30];
	printf("�������˺ţ�");
	scanf("%s", account);
	while (p != NULL)
	{
		if (!strcmp(account, p->U_Account))
		{
			break;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("û�в��ҵ����˺ţ�\n");
		return 0;
	}
	else
	{
		while (1)
		{
			printf("���������룺");
			scanf("%s", password);
			if (strcmp(password, p->U_Password) == 0)
			{
				printf("�ɹ���¼��\n");
				break;
			}
			else {
				printf("����������������룡\n");
			}
		}
	}

	return p;
}
//����Ա��¼
manager* manager_Login(manager* head)
{
	manager* p = head;
	char account[30], password[30];
	printf("�������˺ţ�");
	scanf("%s", account);
	while (p != NULL)
	{
		if (!strcmp(account, p->M_Account))
		{
			break;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("û�в��ҵ����˺ţ�\n");
		return NULL;
	}
	else
	{
		while (1)
		{
			printf("���������룺");
			scanf("%s", password);
			if (strcmp(password, p->M_Password) == 0)
			{
				printf("�ɹ���¼��\n");
				break;
			}
			else {
				printf("����������������룡\n");
			}
		}
	}

	return p;
}

//��ʾ�п����鼮
void Show_remaining_book(MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql)
{
	mysql_query(mysql, "select * from book;");
	res = mysql_store_result(mysql);
	printf("===================================================================================\n");
	printf("|����                    |����            |������          |�����         |���    \n");
	while (row = mysql_fetch_row(res)) {
		//����������0�����
		if (atoi(row[5]) > 0) {
			printf("-----------------------------------------------------------------------------------\n");
			printf("|%-24s|%-16s|%-16s|%-15d|%-8d\n", row[1], row[2], row[3], atoi(row[5]), atoi(row[0]));
		}
	}
	printf("===================================================================================\n");
}
//����ͼ��
int borrow_book(int id, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql, book* head)
{
	Show_remaining_book(res, row, mysql);
	char sql[256];
	int b_id;
	book* p = head;
	printf("������Ҫ���ĵ��鼮��ţ�");
	scanf("%d", &b_id);

	while (head != NULL)
	{
		if (b_id == p->B_ID)
		{
			sprintf_s(sql, sizeof(sql), "select * from book where B_ID = %d;", b_id);
			mysql_query(mysql, sql);
			res = mysql_store_result(mysql);
			row = mysql_fetch_row(res);
			if (atoi(row[5]) <= 0)
			{
				printf("��������㣡\n");
				return 0;
			}
			else
			{
				time_t rawtime;
				struct tm* timeinfo;
				char date_str[11]; // �㹻�洢 "YYYY-MM-DD" ��ʽ�������ַ���

				// ��ȡ��ǰʱ���ʱ���
				time(&rawtime);

				// ��ʱ���ת��Ϊ����ʱ��
				timeinfo = localtime(&rawtime);

				// ʹ��sprintf���ꡢ�¡��ո�ʽ��Ϊ�ַ���
				// ע�⣺tm_year�Ǵ�1900�꿪ʼ�ģ�������Ҫ+1900
				// tm_mon�Ǵ�0��ʼ�ģ�������Ҫ+1
				sprintf(date_str, "%d-%02d-%02d",
					timeinfo->tm_year + 1900,
					timeinfo->tm_mon + 1,
					timeinfo->tm_mday);

				sprintf(sql, "insert into borrow_book values (%d,%d,'%s','%s','%s');", id, b_id, date_str, "NULL", "BORROWED");
				mysql_query(mysql, sql);
				sprintf(sql, "update book set Quantity = Quantity - 1 where B_ID = %d;", b_id);
				mysql_query(mysql, sql);
				printf("���ĳɹ�!\n");
				return 0;
			}
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("ͼ���Ų�����\n");
	}

	return 0;
}
//�黹ͼ��
int return_book(int id, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql, book* head)
{
	int b_id;
	book* p = head;
	char sql[256];
	printf("������Ҫ�黹���鼮��ţ�");
	scanf("%d", &b_id);
	while (p != NULL)
	{
		if (b_id == p->B_ID)
		{
			time_t rawtime;
			struct tm* timeinfo;
			char date_str[11];
			time(&rawtime);
			timeinfo = localtime(&rawtime);
			sprintf(date_str, "%d-%02d-%02d",
				timeinfo->tm_year + 1900,
				timeinfo->tm_mon + 1,
				timeinfo->tm_mday);
			sprintf(sql, "update book set Quantity = Quantity + 1 where B_ID = %d;", p->B_ID);
			mysql_query(mysql, sql);
			sprintf(sql, "update borrow_book set Return_time = '%s', State = '%s' where U_ID = %d AND B_ID = %d;"
				, date_str, "RETURNED", id, p->B_ID);
			mysql_query(mysql, sql);
			printf("�黹�ɹ�!\n");
			break;
		}
		p = p->next;
	}
	if (p == NULL) 
	{
		printf("�����ڸý����ͼ�飡\n");
	}

	return 0;
}