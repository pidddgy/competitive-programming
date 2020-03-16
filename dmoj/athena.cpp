#include <bits/stdc++.h>
#define int long long
using namespace std;

struct fuckthisproblem {
    int ind;
    int val;

    fuckthisproblem(int IND, int VAL) {
        ind = IND;
        val = VAL;
    }
};

bool sortshit(fuckthisproblem &l, fuckthisproblem &r) {
    if(l.val == r.val) {
        return l.ind < r.ind;
    }

    return l.val < r.val;
}

signed main() {
    // bool shit = make_pair(3, 1) < make_pair(2, 2);
    // cout << shit << endl;
    int shit;
    cin >> shit;

    vector<fuckthisproblem> shitt;

    for(int i = 1; i <= shit; i++) {
        int valshit;
        cin >> valshit;
        
        shitt.emplace_back(i, valshit);
    }

    int bestVal = INT_MAX;
    pair<int, int> bestshit = {INT_MAX, INT_MAX};
    for(int i = 0; i < shit; i++) {
        for(int j = 0; j < shit; j++) {
            if(i == j) continue;
            if(abs(shitt[i].val + shitt[j].val) < bestVal) {
                bestVal = abs(shitt[i].val + shitt[j].val);
                
                bestshit = make_pair(i, j);
            } else if(abs(shitt[i].val + shitt[j].val)) {
                if(make_pair(i, j) < bestshit) {
                    bestshit = make_pair(i, j);
                }
            }

        }
    }

    cout << bestVal << endl;
    cout << bestshit.first+1 << " " << bestshit.second+1 << endl;


}