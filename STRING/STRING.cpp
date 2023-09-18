

#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    MyString a("Hello");
    MyString b("Hello1");
    a = b;
    cout << a;
}
