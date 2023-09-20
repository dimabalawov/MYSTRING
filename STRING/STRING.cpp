

#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    MyString a("Hello");
    MyString b("Hi");
    a.InputStr("Bye");
    cout << a << endl;
    b.MyStrcpy(a);
    cout << b << endl;
    cout << a.MyStrStr("ye") << endl;
    cout << a.MyChr('B') << endl; //возврат индекса, либо -1 если не нашел символ
    cout << a.MyStrLen() << endl;
    a.MyDelChr('e');
    cout << a << endl;
    cout << a.MyStrCmp(b) << endl;
    cout << a + b << endl; //конкатенация
    cout << a + "hello" << endl; //конкатенация
    cout << a + 10 << endl; //добавление символов в строку
    a = b;//присваивание с копированием
    cout << a << endl;
    cout << ++a << endl;
    a("Hello");
    cout << a << endl;
    a = a - 1;
    cout << a << endl;
    cout << a[0] << endl;
  



}
