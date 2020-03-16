// http://codeforces.com/contest/1203/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long
    int Q; cin >> Q;

    while(Q--) {
        int N; cin >> N;


        int a[(4*N)+1];
        int cnt[10005];
        int backup[10005];

        for(int i = 0; i < 10005; i++) {
            cnt[i] = 0;
            backup[i] = 0;
        }

        for(int i = 1; i <= 4*N; i++) {
            cin >> a[i];

            cnt[a[i]]++;
            backup[a[i]]++;
        }
        

        bool found = false;
        for(int i = 1; i <= 4*N; i++) {
            for(int j = 1; j <= 4*N; j++) {

                bool good = true;
                for(int k = 0; k < 10005; k++) {
                    cnt[k] = backup[k];
                }

                int prod = a[i] * a[j];

                for(int k = 1; k < 10005; k++) {
                    if(cnt[k] == 0) continue;
                    if(cnt[k] != 0 and prod%k != 0) {
                        good = false;
                    }
                    if(k > prod) continue; 

                    cnt[k] -= 2;
                    cnt[prod/k] -= 2;

                
                    if(cnt[k] < 0 or cnt[prod/k] < 0) good = false;
                }
                if(good) found = true;
            }
        }

        if(found)
            cout << "YES"<< endl;
        else {
            cout << "NO" << endl;
        }

    }
}