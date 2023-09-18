#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
	len = 80;
	str = new char[80];
}
MyString::MyString(int lenght)
{
	len = lenght;
	str = new char[len];
}
MyString::MyString(const char* st)
{
	len = 1;
	for (size_t i = 0; st[i]!=0; i++)
	{
		len++;
	}
	str = new char[len];
	for (size_t i = 0; i < len; i++)
	{
		str[i] = st[i];
	}
}
MyString::MyString(const MyString& b)
{
	MyStrcpy(b);
}
MyString::~MyString()
{
	delete[] str;
}
void MyString::PrintStr() const
{
	for (size_t i = 0; i < len; i++)
	{
		cout << str[i];
	}
}
ostream& operator<< (std::ostream& out, const MyString& st)
{
	return out<<st.str;
}
void MyString::MyStrcpy(const MyString& obj)
{
	if (obj.str == nullptr)
		return;
	delete[] str;
	str = new char[obj.len];
	len = obj.len;
	for (size_t i = 0; i < obj.len; i++)
	{
		str[i] = obj.str[i];
	}
}
bool MyString::MyStrStr(const char* str)
{
	if (str[0] == 0)
		return 0;
	for (size_t i = 0,j=0; i < len; i++)
	{
		if (str[j] == this->str[i])
		{
			if (str[j + 1] == 0)
				return true;
			else if (str[j + 1] == this->str[i + 1])
				++j;
			else
				j = 0;
		}
	}
	return false;
}
int  MyString::MyChr(char c)
{
	for (size_t i = 0; i < len; i++)
	{
		if (c == str[i])
			return i;
	}
	return -1;
}
int MyString::MyStrLen()
{
	int lenght=0;
	for (size_t i = 0; str[i]!=0; i++)
	{
		lenght++;
	}
	return lenght;
}
void MyString::MyDelChr(char c)
{
	if (MyChr(c) == -1)
		return;
	char* newstr = new char[len - 1];
	for (size_t i = 0,j=0; i < len; i++)
	{
		if (str[i] != c)
		{
			newstr[j] = str[i];
			++j;
		}
	}
	delete[] str;
	str = newstr;
	len--;
}
int MyString::MyStrCmp(MyString& b)
{
	if (b.len > len)
		return -1;
	if (b.len < len)
		return 1;
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] > b.str[i])
			return 1;
		if (str[i] < b.str[i])
			return -1;
	}
	return 0;
}
  