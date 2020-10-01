// Link

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define cerr cout

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    for(int rem = 0; rem <= b; rem += 2) {
        int s = a+(rem/2);
        int c = b-rem;

        int amt = min(s, c/2);
        cerr << "removing " << rem << " gives us " << s << " " << c << " with result " << amt << endl;
    }
}