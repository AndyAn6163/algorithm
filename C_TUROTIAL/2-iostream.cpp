#include <iostream>
using namespace std;

int main()
{
    /*
        &a 取出變量 a 的地址
        *a 取出指針變量 a 地址解引用得到的值 (a 為指針變量)
        *(&a)，取出 a 的地址，解引用得到 a 的值
        int a = b is setting a's VALUE to b's VALUE，將 b 的值存入變量 a
        int *a = &b is setting a's VALUE to the ADDRESS of b，將 b 的地址存入指針變量 a
        int &a = b is setting a's ADDRESS to b's ADDRESS (a is a reference to b)，將 b 的地址設為 a 的地址
        Study Blog: int& a = b 的解釋 (stevie1027.blogspot.com)
    */

    // 宣告變量 a 值為 10，宣告指針變量 p
    int a=10, *p;
    // 指針變量 p 儲存變量 a 的地址，&a 表取 a 地址
    p=&a;
    // 將 b 的地址設為 a 的地址
    int &b=a;
    // 宣告變量 s 值為 c++
    string s="c++";
    // 宣告指針變量 ps 儲存變量 s 的地址，&s 表取 s 地址
    string *ps=&s;

    // 變量 a 值為 10
    cout<<a<<endl;
    // 變量 a 的地址
    cout<<&a<<endl;

    // 指針變量 p 的地址，即 a 的地址
    cout<<p<<endl; 
    // 指針變量 p 解引用得到的值 10，即 a 的值
    cout<<*p<<endl;

    // 變量 b 的地址，即 a 的地址
    cout<<&b<<endl;
    // 變量 b 值為 10，即 a 的值
    cout<<b<<endl;

    // 變量 s 值為 c++
    cout<<s<<endl;
    // 變量 s 的地址
    cout<<&s<<endl;

    // 指針變量 ps 的地址，即 s 的地址
    cout<<ps<<endl;
    // 指針變量 ps 解引用得到的值 c++，即 s 的值
    cout<<*ps<<endl;

}