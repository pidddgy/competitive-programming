// https://dmoj.ca/problem/cpc19c1p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    deque<int> a;
    for(int i = 1; i <= N; i++) {
        a.emplace_back(i);
    }

    while(!a.empty()) {
        cout << a.front() << " ";
        a.pop_front();

        if(!a.empty()) {
            cout << a.back() << " ";
            a.pop_back();
        }
        
    }
    cout << endl;
}
