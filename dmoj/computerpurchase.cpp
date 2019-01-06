// https://dmoj.ca/problem/ccc10s1

#include <bits/stdc++.h>
using namespace std;
bool compare(pair<string, int> l, pair<string, int> r) {
    if(l.second > r.second)
        return true;
    else if (r.second > l.second)
        return false;
    else
        return lexicographical_compare(l.first.begin(), l.first.end(), r.first.begin(), r.first.end());
}
int main() {
    int N;
    cin >> N;

    pair<string, int> AQT[N];

    for(int i = 0; i < N; i++) {
        string name;
        int R, S, D;
        cin >> name >> R >> S >> D;
        AQT[i].first = name;
        AQT[i].second = 2*R + 3*S + D;
    }

    sort(AQT, AQT+N, compare);
    
    cout << AQT[0].first << endl;
    if(N > 1)
        cout << AQT[1].first << endl;
}
