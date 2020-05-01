// https://codeforces.com/contest/676/problem/C

#include <bits/stdc++.h>
#define cerr if(false) cerr
using namespace std;

const int maxn = 100500;

unordered_map<char, unordered_map<int, int>> psa;
int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    s = "."+s;

    for(int i = 1; i <= n; i++) {
        psa[s[i]][i] = psa[s[i]][i-1]+1;
        if(s[i] == 'a') {
            psa['b'][i] = psa['b'][i-1];
        } else {
            psa['a'][i] = psa['a'][i-1];
        }
    }

    int best = 1;
    for(int i = 1; i <= n; i++) {
        // change all to a

        int l = i;
        int r = n;

        while(l <= r) {
            int m = (l+r)/2;
            if(psa['b'][m] - psa['b'][i-1] <= k) {
                best = max(best, m-i+1);
                cerr << "go from " << i << " to " << m << " with b" << endl;
                cerr << "count is " << psa['b'][m] - psa['b'][i-1] << endl;
                l = m+1;
            } else {
                r = m-1;
            }
        }

        l = i;
        r = n;
        while(l <= r) {
            int m = (l+r)/2;
            if(psa['a'][m] - psa['a'][i-1] <= k) {
                best = max(best, m-i+1);
                cerr << "go from " << i << " to " << m << " with a" << endl;
                l = m+1;
            } else {
                r = m-1;
            }
        }
    }

    cout << best << endl;
}