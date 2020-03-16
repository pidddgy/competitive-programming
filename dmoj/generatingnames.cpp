// https://dmoj.ca/problem/dmopc19c3p2

#include <bits/stdc++.h>
#define int long long
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int fact[23];

int cntPermutation(string s) {
    map<char, int> cnt;
    for(char x: s) cnt[x]++;

    int ans = 1;
    for(pair<char, int> x: cnt) {
        ans *= fact[x.second];
    }

    return fact[s.size()] / ans;


}
signed main() {
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i <= 15; i++) {
        fact[i] = i*fact[i-1];
    }

    int N, K;
    cin >> N >> K;
    
    string s;
    cin >> s;

    vector<int> indices;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '*') indices.emplace_back(i);
    }

    if(K == 0) {
        cout << cntPermutation(s);
    } else if(K == 1) {
        int res = 0;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        for(char x: alpha) {
            string newS = s;
            newS[indices[0]] = x;
            res += cntPermutation(newS);
            // cout << "permutation of " << newS << " is " << cntPermutation(newS) << endl;
        }
        cout << res << endl;
    } else if(K == 2) {
        int res = 0;
        string alpha = "abcdefghijklmnopqrstuvwxyz";

        for(int i = 0; i < alpha.size(); i++) {
            for(int j = i; j < alpha.size(); j++) {
                string newS = s;
                newS[indices[0]] = alpha[i];
                newS[indices[1]] = alpha[j];

                // cout << "permutation of " << newS << " is " << cntPermutation(newS) << endl;

                res += cntPermutation(newS);


            }

        }

        cout << res << endl;
    }

    

}