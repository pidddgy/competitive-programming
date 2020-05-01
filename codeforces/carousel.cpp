// https://codeforces.com/contest/1328/problem/D

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'

    int q;
    cin >> q;

    while(q--) {
        int N;
        cin >> N;

        int a[N+1];
        set<int> distinct;
        for(int i = 1; i <= N; i++) {
            cin >> a[i];
            distinct.emplace(a[i]);
        }

        if(distinct.size() == 1) {
            cout << 1 << endl;
            for(int i = 1; i <= N; i++) {
                cout << 1 << " ";
            }
            cout << endl;
            continue;
        }

        if(N % 2 == 0) {
            cout << 2 << endl;
            for(int i = 1; i <= N; i++) {
                if(i % 2 == 0) {
                    cout << 1 << " ";
                } else {
                    cout << 2 << " ";
                }
            }
            cout << endl;
        } else {

            int ans[N+1];
            bool same = false;
            ans[1] = 1;
            for(int i = 2; i <= N-1; i++) {
                if(a[i] == a[i-1] and !same) {
                    if(i % 2 == 0) {
                        ans[i] = 1;
                    } else {
                        ans[i] = 2;
                    }
                    same = true;
                } else {
                    if(i % 2 == 0) {
                        if(!same) ans[i] = 2;
                        else ans[i] = 1;
                    } else {
                        if(!same) ans[i] = 1;
                        else ans[i] = 2;
                    }
                }
            }

            if(same) {
                ans[N] = 2;
            } else {
                if(a[N] == a[N-1]) {
                    ans[N] = ans[N-1];
                } else if(a[N] == a[1]) {
                    ans[N] = ans[1];
                } 
                
                else 
                ans[N] = 3;
            }

            cout << *max_element(ans+1, ans+N+1) << endl;
            for(int i = 1; i <= N; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }

        // cerr << endl << endl;
    }
}
