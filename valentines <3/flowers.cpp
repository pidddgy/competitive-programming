// https://dmoj.ca/problem/valentines19j4

#include <bits/stdc++.h>
#define eb emplace_back
#define vi vector<long long>
using namespace std;
int N, M;
vi m;
vi p;
vector<vi> b;

long long int thingo(vi d, long long int s) {
    long long maxV = -2147483647;
    if(d.size() == 3) return s;

    for(int i = 0; i < N; i++) {
        if(find(d.begin(), d.end(), i) != d.end()) {
            continue;
        }

        bool isBad = false;
        for(auto bad: b[i]) {
            if(find(d.begin(), d.end(), bad) != d.end()) {
                isBad = true;
            }
        }

        if(isBad) continue;

        vi e = d;
        e.eb(i);

        long long int t = s;
        t *= m[i];
        t += p[i];

        long long int a = thingo(e, t);
        if (a > maxV) maxV = a;
    }

    return maxV;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        b.eb(vi());
        int m_i, p_i;
        cin >> m_i >> p_i;
        m.eb(m_i);
        p.eb(p_i);
    }

    for(int i = 0; i < M; i++) {
        int c, d;
        cin >> c >> d;

        b[c-1].eb(d-1);
        b[d-1].eb(c-1);
    }

    cout << thingo(vi(), 0) << endl;
}
