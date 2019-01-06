// https://dmoj.ca/problem/ccc01s5

#include <bits/stdc++.h>
using namespace std;

vector<string> aqt, bqt;
int m, n;
bool found = false;

void thingo(vector<int> A = {}) {
    if(found)
        return;

    string a, b;
    for(auto num: A) {
        a.append(aqt[num-1]);
        b.append(bqt[num-1]);
    }

    if(a == b && A.size() > 0) {
        cout << A.size() << "\n";
        for(auto cute: A)
            cout << cute << "\n";
        found = true;
    } else if (A.size() < m)
        for(int i = 1; i <= n; i++) {
            vector<int> newA = A;
            newA.push_back(i);
            thingo(newA);
        }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        string cute;
        cin >> cute;
        aqt.push_back(cute);
    }

    for(int i = 0; i < n; i++) {
        string cute;
        cin >> cute;
        bqt.push_back(cute);
    }

    thingo();
    if(!found)
        cout << "No solution." << "\n";
}
