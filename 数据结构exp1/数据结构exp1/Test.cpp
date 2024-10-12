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
		cout << "��ѡ����Ҫ���еĲ���\n";
		cout << "1.insert       2.remove\n";
		cout << "3.search       4.visit \n";
		cout << "5.traverse     0.exit  \n";
		cout << "-----------------------------\n";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "��������Ҫ�����λ�ú�����:\n";
			cin >> pos >> x;
			s.insert(pos, x);
			cout << "����ɹ�!\n";
			break;
		case 2:
			cout << "��������Ҫɾ����λ��:\n";
			cin >> pos;
			s.remove(pos);
			cout << "ɾ���ɹ�!\n";
			break;
		case 3:
			cout << "��������Ҫ������ֵ��\n";
			cin >> x;
			if (s.search(x) == -1) cout << "�����ڸ�ֵ!\n";
			else cout << "��ֵ��λ����:" << s.search(x) << endl;
			break;
		case 4:
			cout << "��������Ҫ���ʵ��±꣺\n";
			cin >> pos;
			cout << "���±��ֵΪ��" << s.visit(pos) << endl;
			break;
		case 5:
			cout << "�������Ϊ��\n";
			s.traverse();
			break;
		case 0:
			break;
		default:
			cout << "ѡ�����������ѡ��!\n";
			break;
		}

	} while (option);

	return 0;
}