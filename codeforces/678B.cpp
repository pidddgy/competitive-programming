// https://codeforces.com/contest/678/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

bool leap(int n) {
    if (n % 400 == 0)  
        return true;  

    if (n % 100 == 0)  
        return false;  
  
    if (n % 4 == 0)  
        return true;  

    return false;  
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int y;
    cin >> y;

    const int daysInWeek = 7;
    int curDay = 1;
    int neededDay = -1;
    bool needLeapYear = false;
    for(int i = 1000; i <= 1000000; i++) {
        if(i == y) {
            neededDay = curDay;
            needLeapYear = leap(i);
        }

        if(i > y) {
            if(curDay == neededDay and leap(i) == needLeapYear) {
                cout << i << endl;
                break;
            }
        }

        curDay++;
        if(leap(i)) curDay++;
        curDay %= 7;
    }
}
