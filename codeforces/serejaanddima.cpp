// http://codeforces.com/contest/381/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    deque<int> D;
    while(N--) {
        int a; cin >> a;
        D.emplace_back(a);
    }

    int s = 0, d = 0;
    bool isSTurn = true;
    while(D.size()) {
        if(D.front() > D.back()) {
            if(isSTurn) s += D.front();
            else d += D.front();

            D.pop_front();
        } else {
            if(isSTurn) s += D.back();
            else d += D.back();

            D.pop_back();
        }

        isSTurn = !isSTurn;
    }
    cout << s << " " << d << endl;
}
