// https://codeforces.com/contest/1281/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'

    #define cerr if(false) cerr
    #define watch(x) cerr << (#x) << " is " << (x) << endl;

    int N;
    cin >> N;

    while(N--) {
        string s, c;
        cin >> s >> c;

        for(int i = 0; i < s.size(); i++) {
            cerr << "i is " << i << endl;
            char x = CHAR_MAX;
            int ind = -69420;
            for(int j = i+1; j < s.size(); j++) {
                if(s[j] <= x) {
                    x = s[j];
                    ind = j;
                }
            }

            if(s[i] > x) {
                assert(ind != -69420);
                cerr << "swapping " << i << "," << ind << endl;
                swap(s[i], s[ind]);
                break;
            }
        }

        watch(s)

        if(lexicographical_compare(s.begin(), s.end(), c.begin(), c.end())) {
            cout << s << endl;
        } else {
            cout << "---" << endl;
        }


    }
}