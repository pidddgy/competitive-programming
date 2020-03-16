// https://dmoj.ca/problem/dmopc18c6p4

#include <bits/stdc++.h>
#define pii pair<int, int>
#define de first
#define ri second
#define ll long long
using namespace std;
const int maxv = 1000001;

ll p[maxv];
ll m[maxv];

ll pp[maxv];
ll pm[maxv];

int main() {
    int N, P, M;
    cin >> N >> P >> M;

    pii U[N+1];
    for(int i = 1; i <= N; i++) cin >> U[i].de >> U[i].ri;

    for(int i = 1; i <= P; i++) {
        int a; cin >> a;
        p[a]++;
    }

    for(int i = 1; i <= M; i++) {
        int a; cin >> a;
        m[a]++;
    }

    for(int i = maxv-2; i >= 1; i--) {
        p[i] += p[i+1];
        pp[i] = pp[i+1] + p[i];

        m[i] += m[i+1];
        pm[i] = pm[i+1] + m[i];
    }

    int ind = 1;
    ll minn = LLONG_MAX;

    for(int i = 1; i <= N; i++) {
        ll a = pp[U[i].de+1] + pm[U[i].ri+1];
        if(a < minn) {
            ind = i;
            minn = a;
        }
    }

    cout << ind << endl;
    
}
