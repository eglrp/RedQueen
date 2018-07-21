/**
 *
 上了高中之后，学习了数字的幂，他十分喜欢这种数字表示方法，比如xy。
由此，他想出了一种十分奇妙的数字比较方法，给出两个数字x和y，请你比较xy和yx的大小，
如果前者大于后者，输出">"，小于则输出"<"，等于则输出"="。

两个数字x和y。
满足1 <= x,y <= 109

一个字符，">"，"<"或者"="。

分析

取对数进行比较。
 */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int x,y;
    cin>>x>>y;
    if(x == y)
        cout<<"="<<endl;
    else
    {
        long double a = 1.0 * y * log10(x);
        long double b = 1.0 * x * log10(y);
        if(abs(a-b) < 1e-15)
            cout<<"="<<endl;
        else if(a>b)
            cout<<">"<<endl;
        else
            cout<<"<"<<endl;
    }
    return 0;
}