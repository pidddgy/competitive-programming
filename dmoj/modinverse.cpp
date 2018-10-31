// https://dmoj.ca/problem/ccc01j2

#include<bits/stdc++.h>
#pragma GCC optimize "Ofast"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

int main(){
    int output = -1;
    int x; int m;
    scan(x);
    scan(m);
    
    for(int n = 1; n <= 100; n++)
    {
        if(x*n % m == 1)
        {
            output = n;
            break;
        }
    }
    if(output > 0)
        printf("%i\n", output);
    else  
        printf("No such integer exists.\n");
}
