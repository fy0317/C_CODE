#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//int main()
//{
//	//C语言风格
//	char arr[] = "Hello World";
//	//C++风格字符串
//	string arr1 = "Hello World";		//包含头文件<string>
//	cout << arr << endl;
//	cout << arr1 << endl;
//	bool flag = true;
//	cout << flag << endl;
//	cout << "size of bool = " << sizeof(bool) << endl;
//	system("pause");
//	return 0;
//}

int main()
{
	//数据输入   cin
	//int a = 0;
	//float b = 3.14f;
	//cout << "请输入a的值" << endl;
	//cin >> b;
	//cout <<""<<b << endl
	//
	//char c = 0;
	//cin >> c;
	//cout << "" << c << endl;

	//string str = "000";
	//cin >> str;
	//cout << "" << str << endl;
	//int a = 10;
	//int b = 4;
	//cout << a / b * b << endl;
	int a = 10, b = 10;
	b = a++ * b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 0;
}