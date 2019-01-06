// https://dmoj.ca/problem/globexcup18s2

#include <bits/stdc++.h>
#define pii pair<long long, long long>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    double N, M, K;
    cin >> N >> M >> K;

    long double sumNeeded = (N * M) * (K/M);
    long long currentSum = 0;
    long long hours = 0;

    vector<pii> tests(N); //.first == expected mark, .second == hrs needed for mark++

    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        tests[i].first = a;
        tests[i].second = b;
        currentSum += a;
    }

    sort(tests.begin(), tests.end(), [](pii l, pii r){ return l.second < r.second; });
    
    for(int i = 0; i < tests.size(); i++) {
        currentSum += (int)sumNeeded-currentSum;
    }
    cout << hours << "\n";
}
