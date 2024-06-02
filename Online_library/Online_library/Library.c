#define _CRT_SECURE_NO_WARNINGS 1
#include"Library.h"

//初始菜单
void Menu()
{
	printf("***************************************\n");
	printf("*      欢迎进入线上图书管理系统！     *\n");
	printf("*                                     *\n");
	printf("*            1.管理员登录             *\n");
	printf("*            2.读者登录               *\n");
	printf("*            3.读者注册               *\n");
	printf("*            0.退出本系统             *\n");
	printf("***************************************\n");
}
void manager_Menu()
{
	printf("***************************************\n");
	printf("*            欢迎你，管理员            \n");
	printf("*                                     \n");
	printf("*            1.添加书籍              \n");
	printf("*            2.显示书籍              \n");
	printf("*            3.查找书籍               \n");
	printf("*            4.修改书籍               \n");
	printf("*            5.删除书籍               \n");
	printf("*            6.显示用户数据            \n");
	printf("*            7.返回主菜单              \n");
	printf("*            8.添加新管理员              \n");
	printf("*            0.退出本系统             \n");
	printf("***************************************\n");
}
void reader_Menu(user* head)
{
	printf("***************************************\n");
	printf("*          欢迎你，读者           \n");
	printf("*                                     \n");
	printf("*          1.借阅书籍                  \n");
	printf("*          2.归还书籍                  \n");
	printf("*          3.修改密码                  \n");
	printf("*          4.返回主菜单                \n");
	printf("*          0.退出本系统                \n");
	printf("*                                     \n");
	printf("***************************************\n");
}


//从数据库中加载书籍信息
book* load_Book(book* head, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql)
{
	book* p = NULL;
	book* pcur = head;

	//查询数据
	mysql_query(mysql, "select * from book;");

	//获取结果集
	res = mysql_store_result(mysql);

	//将值赋为链表
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

	//释放结果集
	mysql_free_result(res);
	return head;
}

//添加新书籍
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
		//找到尾节点
		book* pcur = head;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = newbook;
	}

	printf("请输入书籍编号：");
	scanf("%d", &(newbook->B_ID));

	//检测编号重复

	printf("请输入名称：");
	scanf("%s", newbook->B_NAME);
	printf("请输入作者：");
	scanf("%s", newbook->Author);
	printf("请输入出版社：");
	scanf("%s", newbook->Publish);
	printf("请输入价格：");
	scanf("%f", &(newbook->Price));
	printf("请输入库存量：");
	scanf("%d", &(newbook->Quantity));

	//将新增书籍信息存入数据库
	char sql[256];
	sprintf(sql, "insert into book values('%d','%s','%s','%s','%f','%d')",
		newbook->B_ID, newbook->B_NAME, newbook->Author, newbook->Publish, newbook->Price, newbook->Quantity);
	mysql_query(mysql, sql);

	newbook->next = NULL;
	printf("添加成功！\n");
	return head;
}
//添加新用户
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
		//找到尾节点
		book* pcur = head;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = newuser;
	}

	printf("请输入用户编号：");
	scanf("%d", &(newuser->U_ID));
	printf("请输入用户账号：");
	scanf("%s", newuser->U_Account);
	printf("请输入用户密码：");
	scanf("%s", newuser->U_Password);

	char sql[256];
	sprintf(sql, "insert into user values('%d','%s','%s')",
		newuser->U_ID, newuser->U_Account, newuser->U_Password);
	mysql_query(mysql, sql);

	newuser->next = NULL;
	printf("添加成功！\n");
	return head;
}
//添加新管理员
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
		//找到尾节点
		book* pcur = head;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = newmanager;
	}

	printf("请输入管理员编号：");
	scanf("%d", &(newmanager->M_ID));
	printf("请输入管理员账号：");
	scanf("%s", newmanager->M_Account);
	printf("请输入管理员密码：");
	scanf("%s", newmanager->M_Password);

	char sql[256];
	sprintf(sql, "insert into manager values('%d','%s','%s')",
		newmanager->M_ID, newmanager->M_Account, newmanager->M_Password);
	mysql_query(mysql, sql);

	newmanager->next = NULL;
	printf("添加成功！\n");
	return head;
}

//展示书籍信息
void Show_All_book(book* head)
{
	book* p = head;
	printf("===================================================================================\n");
	printf("|书名                    |作者            |出版社          |价格  |库存  |编号    |\n");
	while (p != NULL) {
		printf("-----------------------------------------------------------------------------------\n");
		printf("|%-24s|%-16s|%-16s|%-6.2f|%-6d|%-8d|\n", p->B_NAME, p->Author, p->Publish, p->Price, p->Quantity, p->B_ID);
		p = p->next;
	}
	printf("===================================================================================\n");

}
//查找书籍信息
void Search_book(book* head)
{
	book* p = head;
	char search[100];
	int option;
	printf("=======================\n");
	printf("|   请输入查询的项目  |\n");
	printf("|    1.图书名         |\n");
	printf("|    2.书作者         |\n");
	printf("|    3.出版社         |\n");
	printf("=======================\n");
	scanf("%d", &option);
	while (1)
	{
		printf("=======================\n");
		printf("|   请输入查询的内容   |\n");
		printf("=======================\n");
		scanf("%s", search);
		printf("===================================================================================\n");
		printf("|书名                    |作者            |出版社          |价格  |库存  |编号    |\n");

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
			printf("|%-24s|%-16s|%-16s|%-6s|%-6s|%-8s|\n", "无", "无", "无", "无", "无", "无");
		}

		printf("===================================================================================\n");
		break;
	}
}
//删除书籍信息
book* Delete_Book(book* head, MYSQL* mysql)
{
	book* p = head;
	book* pcur = NULL;
	int id, option;
	char sql[256];
	printf("请输入删除书籍的编号：");
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
		printf("未找到此ID编号的书籍\n");
		return 0;
	}
	else
	{
		printf("===================================================================================\n");
		printf("|书名                    |作者            |出版社          |价格  |库存  |编号    |\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("|%-24s|%-16s|%-16s|%-6.2f|%-6d|%-8d|\n", p->B_NAME, p->Author, p->Publish, p->Price, p->Quantity, p->B_ID);
		printf("===================================================================================\n");

		printf("================\n");
		printf("|是否确定删除？|\n");
		printf("|0.取消  1.确定|\n");
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
			printf("已成功删除\n");
			option = 0;
			break;
		case 0:
			printf("取消删除\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	}
	return head;
}
//修改书籍信息
book* Change_book(book* head, MYSQL* mysql)
{
	int id;
	int option = 0;
	book* p = head;
	char sql[256];
	printf("请输入你要修改的书籍编号：");
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
		printf("未找到此ID编号的书籍\n");
		return 0;
	}
	else
	{
		do
		{
			printf("===================================================================================\n");
			printf("|书名                    |作者            |出版社          |价格  |库存  |编号    |\n");
			printf("-----------------------------------------------------------------------------------\n");
			printf("|%-24s|%-16s|%-16s|%-6.2f|%-6d|%-8d|\n", p->B_NAME, p->Author, p->Publish, p->Price, p->Quantity, p->B_ID);
			printf("===================================================================================\n");

			printf("================\n");
			printf("|请选择修改的内容|\n");
			printf("|     1.书名    |\n");
			printf("|     2.作者    |\n");
			printf("|    3.出版社   |\n");
			printf("|     4.价格    |\n");
			printf("|    5.库存量   |\n");
			printf("|   0.退出修改  |\n");
			printf("================\n");
			scanf("%d", &option);

			switch (option)
			{
			case 1:
				printf("请输入修改后的书名：");
				scanf("%s", p->B_NAME);
				break;

			case 2:
				printf("请输入修改后的作者：");
				scanf("%s", p->Author);
				break;

			case 3:
				printf("请输入修改后的出版社：");
				scanf("%s", p->Publish);
				break;

			case 4:
				printf("请输入修改后的价格：");
				scanf("%f", &(p->Price));
				break;

			case 5:
				printf("请输入修改后的库存量：");
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

	printf("修改成功！\n");
	return 0;
}

//展示所有的用户信息
void Show_All_user(user* head)
{
	user* p = head;
	printf("=========================================================\n");
	printf("|用户编号                   |账号          |密码          |\n");
	while (p != NULL) {
		printf("---------------------------------------------------------\n");
		printf("|%-27d|%-14s|%-14s|\n", p->U_ID, p->U_Account, p->U_Password);
		p = p->next;
	}
	printf("=========================================================\n");
}
//从数据库中加载用户信息
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
//从数据库中加载管理员信息
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
//修改用户密码
int Change_User_password(user* head, MYSQL* mysql)
{
	char account[30];
	char password[30];
	char sql[256];
	int option;
	user* p = head;
	printf("请输入用户账号：");
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
		printf("没有查找到该用户\n");
		return 0;
	}
	else
	{
		printf("==============================\n");
		printf("|账号                |编号  |\n");
		printf("------------------------------\n");
		printf("|%-20s|%6d|\n", p->U_Account, p->U_ID);
		printf("==============================\n");
	}

	while (1)
	{
		printf("请输入该账号密码:");
		scanf("%s", password);
		if (strcmp(password, p->U_Password) == 0)
		{
			printf("请输入新密码：");
			scanf("%s", password);
			sprintf(sql, "update user set U_Password = '%s' where U_ID = %d;", password, p->U_ID);
			mysql_query(mysql, sql);
			printf("修改成功！");
			break;
		}
		else
		{
			printf("密码错误,请重试\n");
		}
	}
}
//用户登陆
user* user_Login(user* head)
{
	user* p = head;
	char account[30], password[30];
	printf("请输入账号：");
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
		printf("没有查找到该账号！\n");
		return 0;
	}
	else
	{
		while (1)
		{
			printf("请输入密码：");
			scanf("%s", password);
			if (strcmp(password, p->U_Password) == 0)
			{
				printf("成功登录！\n");
				break;
			}
			else {
				printf("密码错误！请重新输入！\n");
			}
		}
	}

	return p;
}
//管理员登录
manager* manager_Login(manager* head)
{
	manager* p = head;
	char account[30], password[30];
	printf("请输入账号：");
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
		printf("没有查找到该账号！\n");
		return NULL;
	}
	else
	{
		while (1)
		{
			printf("请输入密码：");
			scanf("%s", password);
			if (strcmp(password, p->M_Password) == 0)
			{
				printf("成功登录！\n");
				break;
			}
			else {
				printf("密码错误！请重新输入！\n");
			}
		}
	}

	return p;
}

//显示有库存的书籍
void Show_remaining_book(MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql)
{
	mysql_query(mysql, "select * from book;");
	res = mysql_store_result(mysql);
	printf("===================================================================================\n");
	printf("|书名                    |作者            |出版社          |库存量         |编号    \n");
	while (row = mysql_fetch_row(res)) {
		//若余量大于0则输出
		if (atoi(row[5]) > 0) {
			printf("-----------------------------------------------------------------------------------\n");
			printf("|%-24s|%-16s|%-16s|%-15d|%-8d\n", row[1], row[2], row[3], atoi(row[5]), atoi(row[0]));
		}
	}
	printf("===================================================================================\n");
}
//借阅图书
int borrow_book(int id, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql, book* head)
{
	Show_remaining_book(res, row, mysql);
	char sql[256];
	int b_id;
	book* p = head;
	printf("请输入要借阅的书籍编号：");
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
				printf("库存量不足！\n");
				return 0;
			}
			else
			{
				time_t rawtime;
				struct tm* timeinfo;
				char date_str[11]; // 足够存储 "YYYY-MM-DD" 格式的日期字符串

				// 获取当前时间的时间戳
				time(&rawtime);

				// 将时间戳转换为本地时间
				timeinfo = localtime(&rawtime);

				// 使用sprintf将年、月、日格式化为字符串
				// 注意：tm_year是从1900年开始的，所以需要+1900
				// tm_mon是从0开始的，所以需要+1
				sprintf(date_str, "%d-%02d-%02d",
					timeinfo->tm_year + 1900,
					timeinfo->tm_mon + 1,
					timeinfo->tm_mday);

				sprintf(sql, "insert into borrow_book values (%d,%d,'%s','%s','%s');", id, b_id, date_str, "NULL", "BORROWED");
				mysql_query(mysql, sql);
				sprintf(sql, "update book set Quantity = Quantity - 1 where B_ID = %d;", b_id);
				mysql_query(mysql, sql);
				printf("借阅成功!\n");
				return 0;
			}
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("图书编号不存在\n");
	}

	return 0;
}
//归还图书
int return_book(int id, MYSQL_RES* res, MYSQL_ROW row, MYSQL* mysql, book* head)
{
	int b_id;
	book* p = head;
	char sql[256];
	printf("请输入要归还的书籍编号：");
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
			printf("归还成功!\n");
			break;
		}
		p = p->next;
	}
	if (p == NULL) 
	{
		printf("不存在该借出的图书！\n");
	}

	return 0;
}