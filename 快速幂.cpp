/*
a^{k} % p
朴素做法：
底数a, 指数k, 
循环指数次
while (k -- ) a = a * a % p;
时间复杂度是O(k)的。

快速幂时间复杂度是logk的
将指数k = (101)
a^{k} = a^{001 + 100} = a^{001} * a^{100}
预处理出a^{001}, a^{100}等既可以
*/

#include <iostream>
using namespace std;

typedef long long LL;
LL qmi(int a, int k, int p){
    LL res = 1;
    while (k){
        if (k & 1) res =res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    
    return res;
}

int main()
{
    int n;
    cin >> n;
    
    while (n -- ){
        int a, k, p;
        cin >> a >> k >> p;
        cout << qmi(a, k, p) << endl;
    }
    
    return 0;
}
