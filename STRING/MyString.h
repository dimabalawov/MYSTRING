#pragma once
#include <iostream>
using namespace std;
class MyString
{
	char* str;
	int len;
public:
	MyString();
	MyString(int length);
	MyString(const char* st);
	MyString(const MyString& b);
	~MyString();
	MyString InputStr();
	void PrintStr() const;
	friend ostream& operator<< (ostream& out, const MyString& st); //���������� ��������� << ��� ������ ������ ����� cout
	void MyStrcpy(const MyString& obj);// ����������� �����
	bool MyStrStr(const char* str);// ����� ��������� � ������
	int  MyChr(char c); // ����� ������� � ������(������ ���������� �������, ���� -1)
	int MyStrLen();// ���������� ����� ������
	void MyDelChr(char c); // ������� ��������� ������ 
	int MyStrCmp(MyString& b); // ��������� ����� -1 � ������ ������ ������ ��� ������ 1 � ������ ������ ��� ������ 0 � ������ �����!

};