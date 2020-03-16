// https://codeforces.com/contest/1216/problem/B

#include <bits/stdc++.h>
using namespace std;

struct num{
    int val, ind;
};

bool comp(num l, num r) {
    return l.val > r.val;
}


int main() {
    int N;
    cin >> N;

    num a[N+1];
    for(int i = 1; i <= N; i++) {
        int cute;
        cin >> cute;

        a[i].val = cute;
        a[i].ind = i;
    }
    

    sort(a+1, a+N+1, comp);

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int x = i-1;
        ans += a[i].val * x+1;
    }

    cout << ans << endl;
    for(int i = 1; i <= N; i++) {
        cout << a[i].ind << " ";
    }
    cout << endl;


}