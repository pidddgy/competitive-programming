// https://dmoj.ca/problem/cco07p2

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    unordered_map<string, bool> seen;
    for(int i = 0; i < N; i++) {
        priority_queue<int> cute;
        for(int j = 0; j < 6; j++) {
            int a;
            cin >> a;
            cute.emplace(a);
        }
        string aa;
        while(!cute.empty()) {
            aa += cute.top() + '0';
            cute.pop();
        }
        if(seen[aa]) {
            cout << "Twin snowflakes found." << endl;
            return 0;
        }
        seen[aa] = true;
    }
    cout << "No two snowflakes are alike." << endl;   
}
