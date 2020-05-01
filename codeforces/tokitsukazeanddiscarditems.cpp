// https://codeforces.com/contest/1190/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    #define endl '\n'
    #define cerr if(false) cerr
    #define int long long

    int n, m, k;
    cin >> n >> m >> k;

    int p[m+1];
    for(int i = 1; i <= m; i++) cin >> p[i];

    int ans = 0;
    int i = 1;
    while(i <= m) {
        int lastrm = i;
        cerr << "currently on " << i << endl;
        int page = ((p[i]-lastrm))/k;
        page++;
        cerr << "page is " << page << endl;

        while(i <= m and ((p[i]-lastrm)/k)+1 == page) {
            cerr << p[i] << " is page " << ((p[i]-lastrm)/k)+1 << endl;
            i++;
        }

        ans++;
    }

    cout << ans << endl;
}