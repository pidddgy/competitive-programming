// https://dmoj.ca/problem/bts19p1      

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N;
    cin >> N;

    string cute[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> cute[i];
    }

    string s;
    cin >> s;

    int ans = 2147483647;
    int miind = -1;
    for(int i = 1; i <= N; i++) {
        if(cute[i].size() > s.size()) continue;

        // watch(cute[i].size())
        // watch(s.size())


        int edit = s.size() - cute[i].size();

        if(edit < ans) {
            ans = edit;
            miind = i;
        }
    }
    cout << cute[miind] << endl;
}