// https://codeforces.com/contest/1036/problem/D
    
#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'
    int n;
    cin >> n;
    
    int a[n+1];
    int atot = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        atot += a[i];
    }
    
    int m;
    cin >> m;
    int b[m+1];
    int btot = 0;
    
    for(int i = 1; i <= m; i++) {
        cin >> b[i]; 
        btot += b[i];
    }
    
    if(atot != btot) {
        cout << -1 << endl;
        return 0;
    }
    
    int ap = 1;
    int bp = 1;
    
    int asum = a[ap];
    int bsum = b[bp];
    
    int al = n;
    int bl = m;
    
    int sub = 0;
    
    while(ap <= n and bp <= m) {
        int at = 0;
        int bt = 0;
        int lap = ap;
        int lbp = bp;
        while(asum != bsum and ap <= n and bp <= m) {
            if(asum < bsum) {
                ap++;
                at++;
                asum += a[ap];
            } else {
                bp++;
                bt++;
                bsum += b[bp];
            }
        }
    
        al -= at;
        bl -= bt;
    
        if(asum == bsum) {
            ap++;
            bp++;
    
            asum = a[ap];
            bsum = b[bp];
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << max(al, bl) << endl;
}