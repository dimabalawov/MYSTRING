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
	MyString& operator=(const MyString& b);
	~MyString();
	void InputStr(const char* st);
	void PrintStr() const;
	friend ostream& operator<< (ostream& out, const MyString& st); //перегрузка оператора << для вывода строки через cout
	void MyStrcpy(const MyString& obj);// копирование строк
	bool MyStrStr(const char* str);// поиск подстроки в строке
	int  MyChr(char c); // поиск символа в строке(индекс найденного символа, либо -1)
	int MyStrLen();// возвращает длину строки
	void MyDelChr(char c); // удаляет указанный символ 
	int MyStrCmp(MyString& b); // сравнение строк -1 – первая строка меньше чем вторая 1 – первая больше чем вторая 0 – строки равны!
	MyString operator+(const MyString& a);
	MyString operator+(int a);
	MyString operator+(const char* st);
	MyString& operator++(); 
	MyString& operator++(int a);
	MyString& operator+=(int a);
};