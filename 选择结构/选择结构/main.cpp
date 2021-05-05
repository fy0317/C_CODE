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
	//cout << "请输入一个分数" <<endl;
	//cin >> score;
	//cout << "输入的分数是" << score << endl;
	//if (score >= 600) cout << "一本\n";
	//else if (score >= 500) cout << "二本\n";
	//else if (score >= 400) cout << "三本\n";
	//else cout << "没考上本科\n";
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