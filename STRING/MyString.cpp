#include "MyString.h"
#include <iostream>
using namespace std;


MyString::MyString()
{
	len = 80;
	str = new char[len];
}
MyString::MyString(int lenght)
{
	len = lenght;
	str = new char[len];
}
MyString::MyString(const char* st)
{
	len = (strlen(st) + 1);
	str = new char[len];
	for (size_t i = 0; i < len; i++)
	{
		str[i] = st[i];
	}
}
MyString::MyString(MyString&& b)
{
	len = b.len;
	str = b.str;
	b.len = 0;
	b.str = nullptr;

}
MyString::MyString(const MyString& b)
{
	MyStrcpy(b);
}
MyString::~MyString()
{
	delete[] str;
}
char* MyString::getPtr() const
{
	return str;
}
int MyString::getLen() const
{
	return len;
}
void MyString::setLen(int a)
{
	len = a;
}
void MyString::setPtr(char* ptr)
{
	str = ptr;
}
void MyString::InputStr(const char* st)
{
	delete[] str;
	str = new char[strlen(st)+1];
	len = strlen(st) + 1;
	for (size_t i = 0; i < len; i++)
	{
		str[i] = st[i];
	}

}
void MyString::PrintStr() const
{
	for (size_t i = 0; i < len; i++)
	{
		cout << str[i];
	}
}
ostream& operator<< (ostream& out, const MyString& st)
{
	char* ptr = st.getPtr();
	return out<<ptr;
}
istream& operator>> (istream& in, MyString& st)
{
	char buffer[80];
	in >> buffer;
	delete[] st.getPtr();
	char* tempptr = new char[strlen(buffer) + 1];
	int templen = (strlen(buffer) + 1);
	for (size_t i = 0; i < templen; i++)
	{
		tempptr[i] = buffer[i];
	}
	st.setPtr(tempptr);
	st.setLen(templen);
	return in;
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
MyString& MyString::operator=(const MyString& b)
{
	if (this == &b)
		return *this;
	delete[] str;
	str = new char[b.len];
	len = b.len;
	for (size_t i = 0; i < b.len; i++)
	{
		str[i] = b.str[i];
	}
	return *this;
}
MyString MyString::operator+(const MyString& a)
{
	MyString newstr(a.len+len);
	newstr.len = a.len + len;
	for (size_t i = 0,j=0; i < newstr.len; i++)
	{
		if (i < len-1)
			newstr.str[i] = str[i];
		else
			newstr.str[i] = a.str[j++];
	}
	return newstr;
}
MyString MyString::operator+(int a)
{
	MyString newstr(a + len);
	newstr.len = a + len;
	int i = 0;
	for (; i < len-1; i++)
	{
		newstr.str[i] = str[i];
	}
	for (; i < (a + len - 1); i++)
	{
		newstr.str[i] = ' ';
	}
	newstr.str[newstr.len - 1] = 0;
	return newstr;
}
MyString MyString::operator+(const char* st)
{
	MyString newstr((strlen(st)) + len);
	newstr.len = ((strlen(st)) + len);
	for (size_t i = 0, j = 0; i < newstr.len; i++)
	{
		if (i < len-1)
			newstr.str[i] = str[i];
		else
		{
			newstr.str[i] = st[j];
			j++;
		}
	}
	return newstr;
}
MyString& MyString::operator++()
{
	char* newstr = new char[len + 1];
	for (size_t i = 0; str[i]!=0; i++)
	{
		newstr[i] = str[i];
	}
	delete[] str;
	newstr[len - 1] = ' ';
	newstr[len] = 0;
	str = newstr;
	++len;
	return *this;
}
MyString& MyString::operator++(int a)
{
	MyString temp(*this);
	char* newstr = new char[len + 1];
	for (size_t i = 0; str[i] != 0; i++)
	{
		newstr[i] = str[i];
	}
	delete[] str;
	newstr[len - 1] = ' ';
	newstr[len] = 0;
	str = newstr;
	++len;
	return temp;
}
MyString& MyString::operator+=(int a)
{
	char* newstr = new char[len +a];
	int i = 0;
	for (; i < len - 1; i++)
	{
		newstr[i] = str[i];
	}
	for (size_t j = 0; j < a; j++)
	{
		newstr[i] = ' ';
		i++;
	}
	newstr[len+a-1] = 0;
	delete[] str;
	str = newstr;
	len += a;
	return *this;
}
MyString MyString::operator-(int a)
{
	if (a >= len)
	{
		cout << "Error. strlen is less than substraction " << endl;
		return *this;
	}
	MyString newstr;
	newstr.len = (len - a);
	newstr.str = new char[newstr.len];
	for (size_t i = 0; i < newstr.len-1; i++)
	{
		newstr.str[i] = str[i];
	}
	newstr.str[newstr.len - 1] = 0;
	return newstr;
}
MyString& MyString::operator-=(int a)
{
	if (a >= len)
	{
		cout << "Error. strlen is less than substraction " << endl;
		return *this;
	}
	MyString newstr((len - a));
	newstr.len = (len - a);
	for (size_t i = 0; i < newstr.len - 1; i++)
	{
		newstr.str[i] = str[i];
	}
	delete[] str;
	newstr.str[len - 1] = 0;
	len = newstr.len;
	str = newstr.str;
	return *this;
}
MyString& MyString::operator--()
{
	if (len < 2)
	{
		cout << "Error. strlen is less than substraction " << endl;
		return *this;
	}
	char* newstr = new char[len - 1];
	for (size_t i = 0; i < len - 2; i++)
	{
		newstr[i] = str[i];
	}
	delete[] str;
	newstr[len - 2] = 0;
	str = newstr;
	--len;
	return *this;
}
MyString& MyString::operator--(int)
{
	if (len < 2)
	{
		cout << "Error. strlen is less than substraction " << endl;
		return *this;
	}
	MyString temp = *this;
	char* newstr = new char[len - 1];
	for (size_t i = 0; i<len-2; i++)
	{
		newstr[i] = str[i];
	}
	delete[] str;
	newstr[len - 2] = 0;
	str = newstr;
	--len;
	return temp;
}
MyString& MyString::operator=(MyString&& b)
{
	if (this == &b)
		return *this;
	delete[] str;
	len = b.len;
	b.len = 0;
	str = b.str;
	b.str = nullptr;
	return *this;
}
bool MyString::operator==(MyString b)
{
	if (MyStrCmp(b) == 0)
		return 1;
	else
		return 0;
}
MyString& MyString::operator()(const char* a)
{
	delete[] str;
	len = (strlen(a) + 1);
	str = new char[len];
	for (size_t i = 0; i < len; i++)
	{
		str[i] = a[i];
	}
	return *this;
}
char MyString::operator[](int index)
{
	return str[index];
}
  