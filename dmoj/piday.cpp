// https://dmoj.ca/problem/ccc15j5

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"

using namespace std;
int ans = 0;
int n, k;

void f(int a, int last, int remain, int people) {
    if(people==0) {
        if(a == n) {
            ans++;
        } //else cout << "NO" << endl;
        return;
    }

    if(remain == 0) return;

    int l = last;

    for(int i = remain/people; i <= remain; i++) {
        int n = a+i;
        f(n, i, remain-i, people-1);
    }
}
int main() {
    scanf("%i%i", &n, &k);

    for(int i = 1; i <= n/k; i++) {
        f(i, i, n-i, k-1);
    }
    
    printf("%i\n", ans);
}