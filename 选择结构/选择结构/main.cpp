#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
using namespace std;
int stonetolb(int);
int main()
{
	//int a;
	//int b;
	//int c;
	//a = b = c = 10;
	//cout << a;
	//cout << b;
	//cout <<	c;
	//int score = 0;
	//cout << "������һ������" <<endl;
	//cin >> score;
	//cout << "����ķ�����" << score << endl;
	//if (score >= 600) cout << "һ��\n";
	//else if (score >= 500) cout << "����\n";
	//else if (score >= 400) cout << "����\n";
	//else cout << "û���ϱ���\n";
	double a = 0;
	//a = sqrt(5);
	//cout << a << endl;
	int stone;
	cout << "Enter the weight in stone: ";
	cin >> stone;
	int pounds = stonetolb(stone);
	cout << stone << "stone = ";
	cout << pounds << "pounds." << endl;
	return 0;
}
int stonetolb(int sts)
{
	return 14 * sts;
}