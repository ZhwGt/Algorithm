/* 
递推公式 c[a][b] = c[a-1][b-1] + c[a-1][j]
证明：
假设一堆苹果有a个，从中选取b个的方案数。
对于任意一个苹果要么在b个中，要么不在
  在的话只需要从a-1个中选b-1个。
  不在的话只要从a-1个中选b个。
*/

#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
const int N = 2010;
int c[N][N];

void init()
{
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
}

int main()
{
    init();
    
    int n;
    cin >> n;
    while (n -- ){
        int a, b;
        cin >> a >> b;
        cout << c[a][b] << endl;
    }
    return 0;
}
