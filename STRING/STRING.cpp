

#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    MyString a("Hello");
    MyString b("Hello1");
    a+=10;
    cout << a.MyStrLen();
}
