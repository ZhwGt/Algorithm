/* 
整数d、a、b
若 d|a, d|b, 则d|(ax + by) <1>。

下面的[]是下取整的意思
a % b = a - [a/b]*b = a -c*b , 
证明：
(a, b) = (b, a % b)
转化证明：
(a, b) = (b, a-c*b)
对于任何一个公约数d
左边：d|a 并且 d|b , 由<1>可知，右边d|b, d|(ax + by)，证明完毕。
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int q;
    cin >> q;
    
    while (q -- ){
        int a, b;
        cin >> a >> b;
        //cout << __gcd(a, b) << endl; // __gcd stl库函数
        cout << gcd(a, b) << endl;
    }
    return 0;
}
