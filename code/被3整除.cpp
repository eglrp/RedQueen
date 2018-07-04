/**
 *小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。
并且小Q对于能否被3整除这个性质很感兴趣。
小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。
 *
 * 输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。
 * 输出描述:
输出一个整数, 表示区间内能被3整除的数字个数。

输入例子1:
2 5

输出例子1:
3

手算一下会发现规律。
三个数为一组,第一个数不能被3整除,另外两个可以被3整除。
于是把区间端点都移到某组的开端,记录移动过程中满足的数, 之后就可以通过(b - a) / 3 * 2快速计算。


 */

#include<iostream>
using namespace std;
 
int main(){
    int left, right;
    long long result = 0;
     
    cin >> left >> right;
    for(int i=left; i<=right; ++i){
        switch(i%3){
            case 1: ;break;
            case 2: ++result;break;
            case 0: ++result;break;
        }
    }
    cout << result << endl;
}