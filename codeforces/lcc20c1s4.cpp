// https://mcpt.ca/problem/lcc20c1s4

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 200500;

int n, m;

// .fi = size, .se = colour
pii clowns[maxn];
vector<pii> shoes[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> clowns[i].se >> clowns[i].fi;
    }

    for(int i = 1; i <= m; i++) {
        cin >> shoes[i].se >> shoes[i].fi;
    }

    sort(clowns+1, clowns+n+1);
    reverse(clowns+1, clowns+n+1);

    // pop back from shoes
    sort(shoes+1, shoes+m+1);

    int useless = 0;

    // how many useful shoes of colour i?
    map<int, int> useful;

    for(int i = 1; i <= n; i++) {
        
    }
}

/*

sort clowns in nondecreasing shoe size

sort shoes in nondecreasing 

start with the clown i. Find all shoes that we can give this clown. if there is a shoe that fits and has the clowns favourite colour then it is never optimal to not give i its favourite colour. otherwise . . .
    - try every colour. if we give this colour to x, could we have used it in clowns 1 to i-1?
    - if there is any colour we couldn't have used anyway, give this to clown i. otherwise it doesn't matter

maintain count in prefix

maintain number of shoes that would be useless
map<int, int> useful

after iterating, if this clown's colour is 0 and there is some of colour left in suffix add to unused, subtract



bookkeeping

cnt[colour] -> frequency

countercase:

clown a wants colour x


find case where we can use all colours in i-1

1 5
2 7
1 8
2 9

colour, shoe size

1 1
1 1
2 1
2 1



bipartite directed graph

start with any valid set then switch

give each clown the smallest shoe possible



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
