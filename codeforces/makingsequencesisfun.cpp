// https://codeforces.com/contest/373/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define int unsigned long long

const long double EPS = 1e-1;

int pow10(int n)    
{
    return stoll("1"+string(n,'0'));
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int w, m, k;
    cin >> w >> m >> k;

    int l = 0;
    int r = 1e16;
    int lastgood = 0;
    
    while(l <= r) {
        int mid = (l+r)/2;
        int cost = 0;
        int curLen = 0;
        int cur = m;
        // mid = 9;
        int cnt = 0;
        while(curLen < mid and cost < w) {
            cnt++;
            if(cnt == 100000) break;

            // cout << "mid is " << mid << endl;
            // cout << "curLen is " << curLen << endl;
            int dig = (log10l(cur))+1;
            int next = pow10(dig);

            // cout << "next is " << next << endl;
            int per = dig*k;
            int buy = 0;

            if(curLen + (next-cur) > mid) {
                buy = (mid+m-cur)*per;
                curLen += (mid+m)-cur;
            } else {
                buy = (next-cur)*per;
                curLen += next-cur;
                cerr << " buying" << next-cur << endl;
                cerr << "curlen is now " << curLen << endl;
            }

            cost += buy;
            cur = next;

        }

        watch(curLen)
        cerr << "cost to buy " << mid << " is " << cost << endl;
        if(cost <= w and curLen == mid) {
            l = mid+1;
            lastgood = mid;
        } else {
            r = mid-1;
        }
        // break;
    }

    cout << lastgood << endl;
}