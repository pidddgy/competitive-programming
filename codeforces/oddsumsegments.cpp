// http://codeforces.com/contest/1196/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        int n, k;
        cin >> n >> k;

        int a[n+1];
        int tot = 0;
        for(int j = 1; j <= n; j++) {
            cin >> a[j];
            tot += a[j];
        }

        // if(k == 1) {
        //     if(tot % 2 == 1) {
        //         cout << "NO" << endl;
        //     } else {
        //         cout << "YES" << endl;
        //         cout << n << endl;
        //     }
        //     continue;
        // }


        vector<int> ans;
        int seg = 0;

        int j = 1;
        if(seg != k-1) {
            for(; j <= n; j++) {
                if(a[j] % 2 == 1) {
                    ans.emplace_back(j);
                    seg++;
                    if(seg == k-1) {
                        ans.emplace_back(n);
                        j++;
                        break;
                    }
                }
            }
        } else ans.emplace_back(n);

        int odd = 0;

        for(int l = j; l <= n; l++) {
            if(a[l] % 2 == 1) odd++;
        }

        if(seg != k-1 || odd % 2 == 0) {
            cout << "NO" << endl;
        }  else {
            cout << "YES" << endl;
            for(auto x: ans) {
                cout << x << " ";
            }

            cout << endl;

        }

    
    }

    
}