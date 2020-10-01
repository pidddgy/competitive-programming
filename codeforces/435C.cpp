// https://codeforces.com/contest/435/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

map<int, string> arr;
set<int> used;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int curLevel = 0;

    for(int i = -2000; i < 2000; i++) {
        string thing = "";
        for(int j = 0; j < 3000; j++) thing += ' ';

        arr[i] = thing;
    }

    int curPos = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        for(int j = 0; j < a; j++) {
            if(j != 0) {
                if(i%2 == 0) {
                    curLevel--;
                } else {
                    curLevel++;
                }
            }
          

            used.emplace(curLevel);        

            // cerr << "setting " << curLevel << " " << curPos << endl;
            if(i%2==0)
                arr[curLevel][curPos] = '/';
            else
                arr[curLevel][curPos] = '\\';

            curPos++;
        }
    }

    for(int x: used) {
        // watch(x)
        for(int i = 0; i < curPos; i++) {
            cout << arr[x][i];
        }
        cout << endl;
    }
}