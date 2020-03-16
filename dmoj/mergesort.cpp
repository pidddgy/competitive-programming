// link

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int a[69420];
int cnt = 0;

// returns 1->N in sorted order
vector<int> f(int l, int r) {
    vector<int> shit;
    if(r == l) {
        shit.emplace_back(a[l]);
        return shit;
    }

    int m = (l+r)/2;

    vector<int> leftshit = f(l, m);
    vector<int> rightshit = f(m+1, r);


    int lp = 0;
    int rp = 0;

    while(lp < leftshit.size() and rp < rightshit.size()) {
        if(leftshit[lp] < rightshit[rp]) {
            shit.emplace_back(leftshit[lp]);
            // cout << "appending left at ind " << lp << endl;
            lp++;
            // cout << "the value of at ind lp is now " << leftshit[lp] << endl;
            // cout << "val at rp is " << rightshit[rp] << endl;
        } else {
            shit.emplace_back(rightshit[rp]);
            // cout << "appending right at ind " << rp << endl;

            rp++;
        }

        if(lp == leftshit.size()) break;
        if(rp == rightshit.size()) break;

   
    }

    while(lp < leftshit.size()) {
            // cout << "appending left at ind " << lp << endl;

        shit.emplace_back(leftshit[lp]);
        lp++;
    }

    while(rp < rightshit.size()) {
        shit.emplace_back(rightshit[rp]);
            // cout << "appending right at ind " << rp << endl;

        rp++;
    }

    // cout << "answer for " << l << " " << r << " is: " << endl;
    // cout << "descended from " << l << " " << m << " and " << m+1 << " " << r << endl;
    // for(int x: shit) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // cout << endl;
    return shit;


}
int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for(int x: f(0, N-1)) {
        cout << x << " ";
    }
    cout << endl;

}