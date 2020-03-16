// http://codeforces.com/contest/1187/problem/B

#include <bits/stdc++.h>
#define MAXN 200005
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define endl '\n'
using namespace std;

int cnt[26][200005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string s;
    cin >> s;
    for(int i = 0; i < N; i++) {
        cnt[s[i]-'a'][i]++;
    }

    for(int i = 0; i < 26; i++) {
        // bool asdf = false;
        for(int j = 1; j < N; j++) {
            cnt[i][j] += cnt[i][j-1];
            // if(cnt[i][j] != 0) {
                // asdf = true;
                // char cute = i+'a';
                // cout << "cnt contains " << cnt[i][j] << " of " << cute << " in first " << j << " chars " << endl;
            // }
        }

        // if(asdf)cout << endl;
    }

    int m;
    cin >> m;

    for(int q = 0; q < m; q++) {
        string t;
        cin >> t;

        int qcnt[26];
        for(int i = 0; i < 26; i++) qcnt[i] = 0;
        
        for(int i = 0; i < t.size(); i++) {
            char chr = t[i];
            qcnt[chr-'a']++;
        }

        int l = 0;
        int r = N-1;

        int mid = (l+r)/2;
        int lastgood = -1;

        while(l <= r) {
            // watch(l)
            // watch(r)
            mid = (l+r)/2;
            // watch(mid)

            bool good = true;
            for(int i = 0; i < 26; i++) {
                // char cuute = i+'a';
                if(qcnt[i] > cnt[i][mid]) {
                    // cout << "failed on " << cuute << endl;
                    // watch(qcnt[i])
                    // watch(cnt[i][mid])
                    good = false;
                    break;
                }
            }

        //    watch(good)

            if(good) {
                r = mid-1;
                lastgood = mid;
            } else {
                l = mid+1;
            }
            // cout << endl;
        }
        assert(lastgood != -1);
        cout << lastgood+1 << endl;


    }

}