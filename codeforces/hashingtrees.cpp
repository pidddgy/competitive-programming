// https://codeforces.com/contest/901/problem/A/

#include <bits/stdc++.h>
#define scope for(int scope = 1; scope <= 1; scope++)
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int h;
    cin >> h;

    int a[h+2];
    int sum = 0;
    int first = -1;
    int second = -1;
    for(int i = 1; i <= h+1; i++) {
        cin >> a[i];
        sum += a[i];

        if(a[i] > 1) {
            if(a[i-1] > 1) {
                second = i;
                first = i-1;
            }
        }
    }

    watch(first)
    watch(second)
    if(!((first != -1) and (second != -1))) {
        cout << "perfect" << endl;
        return 0;
    } else {
        // cout << "ambiguous" << endl;
        watch(second)
        vector<int> out1;
        vector<int> out2;
        scope {
            vector<int> finds;
            vector<int> sinds;

            int ans[sum+1];
            int cur = 0;
            int ind = 1;
            for(int i = 1; i <= h+1; i++) {
                vector<int> possnext;
                watch(i)
                watch(a[i])
                for(int j = 1; j <= a[i]; j++) {
                    cerr << "setting " << ind << " to " << cur << endl;
                    ans[ind] = cur;

                    possnext.emplace_back(ind);
                    ind++;
                }

                cerr << "setting cur to " << possnext[0] << endl;
                cur = possnext[0];
            }
            for(int i = 1; i <= sum; i++) {
                // cout << ans[i] << " ";
                out1.emplace_back(ans[i]);
            }
            // cout << endl;
        }
        cerr << "second run" << endl;
        watch(second)
        cerr << endl;
        scope {
            vector<int> finds;
            vector<int> sinds;

            int ans[sum+1];
            int cur = 0;
            int ind = 1;
            int backup = 0;
            for(int i = 1; i <= h+1; i++) {
                vector<int> possnext;
                watch(i)
                watch(a[i])
                for(int j = 1; j <= a[i]; j++) {
                    cerr << "setting " << ind << " to " << cur << endl;

                    if(i == second and j == 1) {
                        ans[ind] = backup;
                        cerr << "hiiii" << endl;
                    } else {
                        ans[ind] = cur;
                    }

                    possnext.emplace_back(ind);
                    ind++;
                }

                cerr << "setting cur to " << possnext[0] << endl;

                if(i == first) {
                    backup = possnext[possnext.size()-1];
                }
                cur = possnext[0];
            }
            for(int i = 1; i <= sum; i++) {
                // cout << ans[i] << " ";
                out2.emplace_back(ans[i]);
            }
            // cout << endl;
        }

        if(out1 == out2) {
            cout << "perfect" << endl;
             for(int x: out1) {
                cout << x << " ";
            }
            cout << endl;

            for(int x: out2) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << "ambiguous" << endl;
            for(int x: out1) {
                cout << x << " ";
            }
            cout << endl;

            for(int x: out2) {
                cout << x << " ";
            }
            cout << endl;
        }

    }

}