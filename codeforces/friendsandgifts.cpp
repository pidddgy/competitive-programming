// https://codeforces.com/problemset/problem/1283/C

#include <bits/stdc++.h>
#define cerr if(false) cerr
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N+1];
    unordered_map<int, bool> need;
    unordered_map<int, bool> have;

    for(int i = 1; i <= N; i++) {
        need[i] = true;
    }

    for(int i = 1; i <= N; i++) {
        int _;
        cin >> _;

        if(_ == 0) {
            have[i] = true;
        } else {
            need[_] = false;
        }
        a[i] = _;
    }

    vector<int> needs;
    vector<int> haves;

    for(int i = 1; i <= N; i++) {
        if(have[i]) haves.emplace_back(i);
        if(need[i]) needs.emplace_back(i);
    }

    assert(haves.size() == needs.size());

    for(int i = 0; i < haves.size(); i++) {
        cerr << haves[i] << " ";
    }
    cerr << endl;

    for(int i = 0; i < haves.size(); i++) {
        cerr << needs[i] << " ";
    }
    cerr << endl;
    for(int i = 0; i < haves.size(); i++) {
        if(i == 0) {
            if(haves[i] == needs[i]) {
                swap(needs[i], needs[i+1]);
                cerr << "swapping on ind " << i << endl;
            }
        }
        
        if(i < haves.size()-1) {
            if(haves[i+1] == needs[i+1]) {
                swap(needs[i], needs[i+1]); // lol pray for no out of bounds
                cerr << "swapping next, swapping on ind " << i << endl;
            }
        }


        cerr << "setting ind " << haves[i] << " to " << needs[i] << endl;
        a[haves[i]] = needs[i];
    }

    for(int i = 1; i <= N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}