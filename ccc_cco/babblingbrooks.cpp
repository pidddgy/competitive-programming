// https://dmoj.ca/problem/ccc00j4

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    vector<int> river;
    for(int i = 0; i < N; i++) {
        int aqt; cin >> aqt;
        river.push_back(aqt);
    }

    for(;;) {
        int aqt; cin >> aqt;
        if(aqt == 99) {
            int nqt; double pqt;
            cin >> nqt >> pqt;
            river.insert(river.begin() + nqt-1, river[nqt-1] * (pqt / 100));
            river[nqt] -= river[nqt-1];

        }
        if(aqt == 88) {
            int nqt;
            cin >> nqt;
            river[nqt-1] += river[nqt];
            river.erase(river.begin() + nqt);
        }
        if(aqt == 77)
            break;
    }
    for(auto aqt: river)
        cout << aqt << " ";

    cout << endl;
}