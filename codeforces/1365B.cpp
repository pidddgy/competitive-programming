// https://codeforces.com/contest/1365/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 505;
int a[maxn];
int type[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        for(int i = 1; i <= N; i++) {
            cin >> a[i];
        }

        set<int> T;
        for(int i = 1; i <= N; i++) {
            cin >> type[i];
            T.emplace(type[i]);
        }

        for(int i = 1; i <= N; i++) {
            int mi = a[i];
            int miind = i;
            for(int j = i+1; j <= N; j++) {
                if(type[i] != type[j] and a[j] < mi) {
                    mi = a[j];
                    miind = j;
                }
            }

            swap(a[i], a[miind]);
            swap(type[i], type[miind]);
        }

        string ans = "Yes";
        for(int i = 2; i <= N; i++) {
            if(a[i] < a[i-1]) {
                ans = "No";
            }
        }

        if(T.size() == 2) ans = "Yes";

        cout << ans << endl;
    }
}
