#include <bits/stdc++.h>
using namespace std;

int ans(int n)
{
    if (n == 1)
        return 1;

    while (n > 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else if (n > 4)
            n -= 3;
        else
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int res = ans(n);

        res == 1 ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}