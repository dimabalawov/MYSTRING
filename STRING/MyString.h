#pragma once
#include <iostream>
using namespace std;
class MyString
{
	char* str;
	int len;
public:
	MyString();//конструктор по умолчанию
	MyString(int length);//конструктор с параметром
	MyString(const char* st);//конструктор с инициализией строкой
	MyString(const MyString& b);//конструктор копирования
	MyString(MyString&& a);//конструктор переноса
	~MyString();//деструктор
	//методы акссессоры.
	char* getPtr() const;
	int getLen() const;
	void setLen(int a);
	void setPtr(char* ptr);
	void InputStr(const char* st);//присваивание строки объекту
	void PrintStr() const;//вывод объекта
	void MyStrcpy(const MyString& obj);// копирование строк
	bool MyStrStr(const char* str);// поиск подстроки в строке
	int  MyChr(char c); // поиск символа в строке(индекс найденного символа, либо -1)
	int MyStrLen();// возвращает длину строки
	void MyDelChr(char c); // удаляет указанный символ 
	int MyStrCmp(MyString& b); // сравнение строк -1 – первая строка меньше чем вторая 1 – первая больше чем вторая 0 – строки равны!
	//перегруженные операторы
	MyString& operator=(const MyString& b);
	MyString operator+(const MyString& a);
	MyString operator+(int a);
	MyString operator+(const char* st);
	MyString& operator++(); 
	MyString& operator++(int a);
	MyString& operator+=(int a);
	MyString operator-(int a);
	MyString& operator--(int a);
	MyString& operator--();
	MyString& operator-=(int a);
	MyString& operator=(MyString&& b);
	bool operator==(MyString b);
	MyString& operator()(const char* a);
	char operator[](int index);


};

ostream& operator<< (ostream& out, const MyString& st);//перегрузка cout << 
istream& operator>> (istream& in, MyString& st);//перегрузка cin >> 