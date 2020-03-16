// https://mcpt.ca/problem/ahc19p5

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int N, M;
vector<string> combo;

void prop(string s = ".") { 
    if(s.size() == N+1) combo.emplace_back(s);
    else {
        prop(s+"0");
        prop(s+"1");
    }
}
int main() {
    #define int long long

    cin >> N >> M;
    prop();

    int a[N+1];
    for(int i = 1; i <= N; i++) cin >> a[i];

    int ans = INT_MIN;
    string comb;
    for(string x: combo) {
        bool odd = false;
        int sum = 0;
        bool good = true;
        for(int i = 1; i <= x.size(); i++) {
            if(x[i] == '1') {
                odd = !odd;
                if(odd) {
                    sum += a[i];
                } else {
                    sum -= a[i];
                }
            }
        }

        vector<int> inds;

        for(int i = 1; i < x.size(); i++) {
            if(x[i] == '1') {
                inds.emplace_back(i);
            }
        }


        if(inds.size() != 0)
        for(int i = 0; i < inds.size()-1; i++) {
            // cout << "using " << inds[i] << " and " << inds[i+1] << endl;
            if(abs(a[inds[i]] - a[inds[i+1]]) > M) {
                good = false;
            }
        }

        if(sum > ans and good) {
            ans = sum;
            comb = x;
        }
        // cout << "HI" << endl;
    }
    cout << ans << endl;

    for(int i = 1; i <= N; i++) {
        if(comb[i] == '1') cout << i << " ";
    }
    cout << endl;


    
}