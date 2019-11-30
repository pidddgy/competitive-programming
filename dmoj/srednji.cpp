// https://dmoj.ca/problem/coci07c1p5

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, B;
    cin >> N >> B;

    int a[N];
    int ind;
    for(int i = 0; i < N; i++) {
        int b; cin >> b;
        if(b > B) a[i] = 1;
        else if(b < B) a[i] = -1;
        else {
            a[i] = 0;
            ind = i;
        }
    }

    unordered_map<int, vector<int>> p;
    int cur = 0;
    int res = 0;

    for(int i = 0; i < N; i++) {
        cur += a[i];

        if(p.find(cur) != p.end() && ind <= i)
            for(auto j: p[cur])
                if(j < ind)
                    res++;
        
        if(cur == 0 && ind <= i)
            res++;

        p[cur].emplace_back(i);
    }
    
    cout << res << endl;
}



