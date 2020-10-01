// https://codeforces.com/contest/486/problem/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const string alpha = "abcdefghijklmnopqrstuvwxyz";
int cost(char x, char y) {

    int cup = 0, cdown = 0;
    char cur = x;

    while(cur != y) {
        cup++;

        if(cur == 'z') {
            cur = 'a';
        } else {
            cur++;
        }
    }

    cur = x;
    while(cur != y) {
        cdown++;

        if(cur == 'a') {
            cur = 'z';
        } else {
            cur--;
        }
    }

    return min(cup, cdown);
}

int re(int n) {
    return n/2;
}

int le(int n) {
    int res = n/2;

    if(n%2==0) res--;

    return res;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, p;

    cin >> n >> p;
    string s;
    cin >> s;

    string cpy = s;
    
    int wrong = 0;
    int leftmost = -1, rightmost = -1;
    for(int i = 0; i < n/2; i++) {
        if(s[i] != s[n-i-1]) {
            wrong++;
            if(leftmost == -1) {
                leftmost = i;
            }
            rightmost = i;
        }
    }

    int l = 0;
    int lc = 0;
    int cur = p-1;

    int dir = -1;

    while(lc < wrong) {
        if(s[cur] != s[n-cur-1]) {
            l += cost(s[cur], s[n-cur-1]);
            lc++;
            s[cur] = s[n-cur-1];
        }
        if(lc == wrong) break;
        if(cur == re(n) or cur == 0 or cur == leftmost or cur == (n-rightmost-1)) dir = 1;

        l++;

        cur += dir;
    }
    
    s = cpy;

    int r = 0;
    int rc = 0;
    cur = p-1;
    dir = 1;

    while(rc < wrong) {
        if(s[cur] != s[n-cur-1]) {
            r += cost(s[cur], s[n-cur-1]);
            s[cur] = s[n-cur-1];
            rc++;
        }

        if(rc == wrong) break;
        if(cur == le(n) or cur == n-1 or cur == rightmost or cur == (n-leftmost-1)) dir = -1;

        r++;
        cur += dir;
    }

    cout << min(l, r) << endl;
}