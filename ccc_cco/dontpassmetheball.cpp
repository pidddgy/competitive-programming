// https://dmoj.ca/problem/ccc12s1

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int total = 0; int num; int incr = 1;
    scanf("%i", &num);
    for(int i = 1; i <= num - 3; i++)
    {
        for(int x = 1; x <= incr; x++)
        {
            total += x;
        }
        incr++;
    }
    printf("%i\n",total);
}
