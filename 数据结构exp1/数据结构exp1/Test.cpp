#define _CRT_SECURE_NO_WARNINGS 1
#include"sLinkList.h"

int main()
{
	sLinkList<int> s;
	int pos, x;
	int option;
	do
	{
		cout << "-----------------------------\n";
		cout << "请选择你要进行的操作\n";
		cout << "1.insert       2.remove\n";
		cout << "3.search       4.visit \n";
		cout << "5.traverse     0.exit  \n";
		cout << "-----------------------------\n";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "请输入你要插入的位置和数字:\n";
			cin >> pos >> x;
			s.insert(pos, x);
			cout << "插入成功!\n";
			break;
		case 2:
			cout << "请输入你要删除的位置:\n";
			cin >> pos;
			s.remove(pos);
			cout << "删除成功!\n";
			break;
		case 3:
			cout << "请输入你要搜索的值：\n";
			cin >> x;
			if (s.search(x) == -1) cout << "不存在该值!\n";
			else cout << "该值的位置是:" << s.search(x) << endl;
			break;
		case 4:
			cout << "请输入你要访问的下标：\n";
			cin >> pos;
			cout << "该下标的值为：" << s.visit(pos) << endl;
			break;
		case 5:
			cout << "遍历结果为：\n";
			s.traverse();
			break;
		case 0:
			break;
		default:
			cout << "选择错误，请重新选择!\n";
			break;
		}

	} while (option);

	return 0;
}