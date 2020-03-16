// https://codeforces.com/contest/1325/problem/D

#include <bits/stdc++.h>
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int u, v;
    cin >> u >> v;

    vector<int> ans;

    ans.emplace_back(u);

    int diff = v-u;
    if(diff < 0) {
        cerr << "shit" << endl;
        cout << -1 << endl;
        return 0;
    }

    for(int i = 60; i >= 0; i--) {
        int add = pow(2, i);
        add *= 2;

        if(add <= diff) {
            cerr << "trying to add " << add << endl;
            bool found = false;
            bool found2 = false;
            int ind = 0;

            int shift = i-1;
            watch(shift)
            if(shift < 0) {
                shift = 0;
            }


            vector<int> inds;
            for(int &x: ans) {
                if(!(x & (1 << (shift)))) {
                    if(!(found and found2)) {
                        cerr << x << " has " << shift << "th bit not set" << endl;
                        

                        watch(shift)
                        x ^= (1 << shift);
                        cerr << "is now " << x << endl;
                        if(found) {
                            cerr << "setting found2 to true" << endl;
                            found2 = true;
                        } else {
                            found = true;
                        }
                        cerr << "reg subtract " << add << endl;
                        diff -= add/2;
                        break;
                    }
                }
                ind++;
            }

            if(!found) {
                ans.emplace_back(1 << (shift));
                cerr << "subtractinggg" << endl;
                diff -= add/2;
            }

            if(!found2) {
                ans.emplace_back(1 << (shift));
                cerr << "subtractingsdfdsf" << endl;
                diff -= add/2;
            }
            cerr << endl;
        }
    }

    int sum = 0;
    for(int x: ans) {
        sum += x;
    }

    int sdiff = v-sum;
    if(sdiff < 0) {
        cout << -1 << endl;
        return 0;
    }
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
    cout << "sdiff is " << sdiff << endl;
    cerr << "ehl l o oo o @@#@!#@!#!@#!#!@#" << endl;
    cout << endl;
    for(int i = 60; i >= 0; i--) {
        int add = pow(2, i);
        add *= 2;

        if(add <= sdiff) {
            cout << "trying to add " << add << endl;
            bool found = false;
            bool found2 = false;
            int ind = 0;

            int shift = i-1;
            watch(shift)
            if(shift < 0) {
                shift = 0;
            }


            vector<int> inds;
            for(int &x: ans) {
                if(!(x & (1 << (shift)))) {
                    if(!(found and found2)) {
                        cout << x << " has " << shift+1 << "th bit not set" << endl;
                        cout << "is " << (1 << shift) << endl;
                        

                        watch(shift)
                        x += add/2;
                        cout << "is now " << x << endl;
                        if(found) {
                            cerr << "setting found2 to true" << endl;
                            found2 = true;
                        } else {
                            found = true;
                        }
                        cout << "reg subtract " << add/2 << endl;
                        sdiff -= add/2;
                        break;
                    }
                }
                ind++;
            }

            if(!found) {
                ans.emplace_back(add/2);
                cout << "subtractinggg" << endl;
                sdiff -= add/2;
            }

            if(!found2) {
                ans.emplace_back(add/2);
                cout << "subtractingsdfdsf" << endl;
                sdiff -= add/2;
            }
            cerr << endl;
        }
    }

    cout << "sdiff is " << sdiff << endl;


    if(diff != 0) {
        watch(diff)
        cout << -1 << endl;
    } else if(sdiff != 0)  {
        cout << -1 << endl;
    } else {
        vector<int> nz;

        // cout << ans.size() << endl;
        for(int x: ans) {
            if(x != 0) {
                nz.emplace_back(x);
            }
        }

        cout << nz.size() << endl;
        for(int x: nz) {
            cout << x << " ";
        }
        cout << endl;
    }
}