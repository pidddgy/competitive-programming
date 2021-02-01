#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define y1 lsdjkfhshfdsighoihweogihewoghi
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
    int operator()(pii x) const { return x.first* 31 + x.second; }
};

const int maxm = 200500;
const int maxn = 25;

int a[maxm][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;
    cin >> m >> n >> k;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for(int t = 1; t <= n-1; t++) {
        vector<pii> v;
        for(int x = 1; x <= m; x++) {
            v.emplace_back(a[x][t], a[x][t+1]);
        }

        sort(all(v));

        // map<pii, int> cnt;
        gp_hash_table<pii, int, chash> cnt;

        for(pii x: v) {
            ans += cnt[{x.fi-k, x.se-k}];

            cnt[x]++;
        }
    }

    cout << ans << endl;
}

/*
80 000 000

gcc-10 --sysroot "/Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/usr/include" dmopc20c3p2.cpp -std=c++11 -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wshift-overflow -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector -fsanitize=address -fsanitize=integer-divide-by-zero -fsanitize=vla-bound -fsanitize=return -fsanitize=signed-integer-overflow -o dmopc20c3p2 && "/Users/mjnc/Documents/programming/competitive-programming/codeforces/"dmopc20c3p2 < input.txt

gcc-10  dmopc20c3p2.cpp -std=c++11 -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wshift-overflow -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector -fsanitize=address -fsanitize=integer-divide-by-zero -fsanitize=vla-bound -fsanitize=return --sysroot -fsanitize=signed-integer-overflow -o dmopc20c3p2 && "/Users/mjnc/Documents/programming/competitive-programming/codeforces/"dmopc20c3p2 < input.txt

gcc-9 dmopc20c3p2.cpp -std=c++11 -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wshift-overflow -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector -fsanitize=address -fsanitize=integer-divide-by-zero -fsanitize=vla-bound -fsanitize=return -fsanitize=signed-integer-overflow -o dmopc20c3p2 && "/Users/mjnc/Documents/programming/competitive-programming/codeforces/"dmopc20c3p2 < input.txt

g++-10  dmopc20c3p2.cpp -std=c++11 -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wshift-overflow -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector -fsanitize=address -fsanitize=integer-divide-by-zero -fsanitize=vla-bound -fsanitize=return --sysroot -fsanitize=signed-integer-overflow -o dmopc20c3p2 && "/Users/mjnc/Documents/programming/competitive-programming/codeforces/"dmopc20c3p2 < input.txt
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?