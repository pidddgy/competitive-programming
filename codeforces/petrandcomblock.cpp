// http://codeforces.com/contest/1097/problem/B

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> aqt;
int N;
bool found = false;

void thingo(vector<int> bqt = {}, int idx = 0) {

    if(found == true) return;

    if(bqt.size() == N) {
        int total = 0;
        for(int i = 0; i < N; i++) {
            total += bqt[i];
        }
        if((total % 360) == 0)
            found = true;
        else
            return;
    }

    vector<int> newAQT = bqt;
    newAQT.push_back(aqt[idx]);
    thingo(newAQT, idx+1);

    newAQT.back() *= -1;
    thingo(newAQT, idx+1);
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int bqt;
        cin >> bqt;
        aqt.emplace_back(bqt);
    }

    thingo();
    if(found == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}