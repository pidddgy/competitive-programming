// http://codeforces.com/contest/1253/problem/0

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        int N;
        cin >> N;

        int a[N+1];
        int b[N+1];
        for(int i = 1; i <= N; i++) cin >> a[i];
        for(int i = 1; i <= N; i++) cin >> b[i];

        string ans = "YES";
        bool started = false;
        bool used = false;
        int diff;
        for(int i = 1; i <= N; i++) {
            if(a[i] != b[i]) {
                if(!started) {
                    started = true;
                    diff = b[i]-a[i];
                    // cout << "setting diff to " << diff << endl;
                } else if(used) {
                    ans = "NO";
                } else {
                    // watch(b[i]-a[i])
                    if(b[i] - a[i] != diff) {
                        ans = "NO";
                    }
                }
            } else {
                if(started) used = true;
            }

            // watch(diff)
        }

        if(diff <= 0) ans = "NO";

        cout << ans << endl;


    }
}

// cd "/Users/mjnc/Documents/programming /competitive-programming/codeforces/" && g++ singlepush.cpp -std=c++11 -Wall -o singlepush && "/Users/mjnc/Documents/programming /competitive-programming/codeforces/"singlepush < input.txt && rm "/Users/mjnc/Documents/programming /competitive-programming/codeforces/"singlepush