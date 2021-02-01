// https://codeforces.com/contest/558/problem/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define cerr cout
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

const int maxn = 300500;

int n;
int a[maxn];

int cnt[maxn];
int steps[maxn];
int vis[maxn];
int dis[maxn];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        queue<int> Q;
        Q.push(x);
        dis[x] = 0;

        while(!Q.empty()) {
            int S = Q.front(); Q.pop();

            if(S > 100500) continue;
            if(vis[S] == i) continue;

            vis[S] = i;
            steps[S] += dis[S];
            cnt[S]++;

            dis[S/2] = dis[S]+1;
            dis[S*2] = dis[S]+1; 
            Q.push(S/2);
            Q.push(S*2);
        }
    }

    int mi = LLONG_MAX;
    for(int i = 0; i <= 1e5; i++) {
        if(cnt[i] == n) {
            mi = min(mi, steps[i]);
        }
    }

    cout << mi << endl;
}

/*

operations are bit shifts
odd numbers can -1 in two operations

each number has two edges

for some reason it is tree

do tree reroot dp

7 -> 3

dfs

maintain sum of distances in each subtree -> cur
maintain number of a[i] in subtree -> sum

dfs
update ans
for every to:
    cur -= sum[to]
    sum[v] -= sum[to]

    cur += sum[v]
    sum[to] += sum[v]

0 is bad, handle that edge case by having all elements go to 0








*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
