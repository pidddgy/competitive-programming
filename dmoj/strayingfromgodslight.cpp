// https://dmoj.ca/problem/bfs19p2

#include <bits/stdc++.h>
#define maxn 1505
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
using namespace std;


char a[maxn][maxn];
bool vis[maxn][maxn];

// state - > min times to move left
ll dp[maxn][maxn];

ll sq(ll n) { return n*n;};
int main() {

    for(ll i = 0; i < maxn; i++)
        for(ll j = 0; j < maxn; j++) {
            dp[i][j] = INT_MAX;
            a[i][j] = 'x';
            vis[i][j] = false;
        }

    ll N;
    cin >> N;

    for(ll i = 1; i <= N; i++) {
        for(ll j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }

    dp[1][1] = 0;

    for(ll i = 1; i <= N; i++) {
        for(ll j = 1; j <= N; j++) {
            if(i == 1 and j == 1) continue;

            vector<ll> cute;
            cute.emplace_back(dp[i][j]);
            if(a[i-1][j] == '.') {
                cute.emplace_back(dp[i-1][j]);
            }
            if(a[i][j+1] == '.') {
                cute.emplace_back(dp[i][j+1]+1);
            }
            if(a[i][j-1] == '.') {
                cute.emplace_back(dp[i][j-1]);
            }
            
            ll mi = INT_MAX;
            for(ll x: cute) mi = min(mi, x);

            dp[i][j] = mi;


        }

         for(ll j = N; j >= 1; j--) {
            if(i == 1 and j == 1) continue;

            vector<ll> cute;
            cute.emplace_back(dp[i][j]);
            if(a[i-1][j] == '.') {
                cute.emplace_back(dp[i-1][j]);
            }
            if(a[i][j+1] == '.') {
                cute.emplace_back(dp[i][j+1]+1);
            }
            if(a[i][j-1] == '.') {
                cute.emplace_back(dp[i][j-1]);
            }
            
            ll mi = INT_MAX;
            for(ll x: cute) mi = min(mi, x);

            dp[i][j] = mi;


        }
    }

    queue<ll> rQ;
    queue<ll> cQ;
    vis[1][1] = true;
    rQ.push(1);
    cQ.push(1);

    while(!rQ.empty()) {
        ll r = rQ.front(); rQ.pop();
        ll c = cQ.front(); cQ.pop();


        if(a[r][c+1] == '.' and !vis[r][c+1]) {
            rQ.push(r);
            cQ. push(c+1);
            vis[r][c+1] = true;        
        } 

        if(a[r][c-1] == '.' and !vis[r][c-1]) {
            rQ.push(r);
            cQ.push(c-1);
            vis[r][c-1] = true;        
        } 

        if(a[r+1][c] == '.' and !vis[r+1][c]) {
            rQ.push(r+1);
            cQ.push(c);
            vis[r+1][c] = true;        
        } 
    } 

    if(!vis[N][N]) {
        cout << -1 << endl;

    }

    if(vis[N][N]) {
        cout << ((N-1)*(N-1)) + 
        (dp[N][N]*dp[N][N]) + 
        ((N-1 + dp[N][N]) *  (N-1 + dp[N][N])) 
        << endl;
    }
}