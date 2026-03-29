#include <bits/stdc++.h>
using namespace std; // o(n)

long long int dp[1005];
long long int fibo(long long int n)
{
    // if(n == 1)
    //     return 1;
    // if(n == 0)
    //     return 0;
    if (n == 0 || n == 1 || n == 2 || n == 3) // n<2
    {
        if(n==2)
            return 1;
        else if(n==3)
            return 2;
        else
            return n;
    }
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibo(n - 1) + fibo(n - 2) + fibo(n - 3) + fibo(n - 4);
    return dp[n];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    long long int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}