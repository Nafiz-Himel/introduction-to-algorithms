#include<bits/stdc++.h>
using namespace std;

void rec(int n)
{
    if(n>5)
        return;
    cout << n << endl;
    rec(n+1);
}

int recc(int n)
{
    if(n>5)
        return 0;
    int sum = recc(n+1);
    return sum + n;
}

int main()
{
    rec(1);
    cout << recc(1) << endl;
    return 0;
}