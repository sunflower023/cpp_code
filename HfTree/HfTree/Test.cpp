#include"HfTree.h"
#include"ref.h"

#include<ctime>

void test1()
{
	char c[] = "aeistdn";
	int w[] = { 10,15,12,3,4,13,1 };
	HfTree<char> t(c, w, 7);
	HfTree<char>::HfCode* result = new HfTree<char>::HfCode[7];
	t.GetCode(result);
	for (int i = 0; i < 7; i++)
	{
		cout << result[i].data << ":" << result[i].code << endl;
	}
}

void test2()
{
	char c[] = { "abcdefghij" };
	int w[] = { 1,6,8,3,2,13,4,15,16,7 };
	HfTree<char> t(c, w, 10);
	HfTree<char>::HfCode* result = new HfTree<char>::HfCode[10];
	t.GetCode(result);
	for (int i = 0; i < 10; i++)
	{
		cout << result[i].data << ":" << result[i].code << endl;
	}
}

void test3()
{
	clock_t start = clock();

	char c[] = {
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789"
		"!@#$%^&*(),.<>/?;':[]\\{}|-=_+"
	};
	int w[] = {
		// 根据字符出现的频率分配权重
		45, 13, 12, 16, 9, 5, 24, 23, 25, 14, 2, 15, 1, 8, 17, 11, 7, 3, 6, 10, 4, 19, 22, 18, 21, 20, 26, 27, 28, 29, 30, 31, 32, 33, 34,
		35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
		69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 
		102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 
		129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155,
		156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182,
		183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
		210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236,
		237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255
	};

	int size = sizeof(w) / sizeof(w[0]);
	HfTree<char> t(c, w, size);
	HfTree<char>::HfCode* result = new HfTree<char>::HfCode[size];
	t.GetCode(result);
	for (int i = 0; i < size; i++)
	{
		cout << result[i].data << ":" << result[i].code << endl;
	}

	clock_t end = clock();
	cout << end - start << endl;
}

int main()
{

	//test1();
	//cout<<endl;
	//test2();
	//cout << endl;
	test3();
	return 0;
}