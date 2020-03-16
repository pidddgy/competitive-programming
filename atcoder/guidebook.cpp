// https://atcoder.jp/contests/abc128/tasks/abc128_b

#include <bits/stdc++.h>
#define psi pair<string, int>
#define fi first
#define se second
using namespace std;

struct Entry {
    string name;
    int score;
    int index;
};

bool compare(const Entry& l, const Entry& r) {
    return l.name < r.name; 
}

bool compare2(const Entry& l, const Entry& r) {
    return l.score > r.score; 
}
int main() {
    int N;
    cin >> N;
    Entry a[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i].name >> a[i].score;
        a[i].index = i;
    }


    sort(a+1, a+N+1, compare2);
    stable_sort(a+1, a+N+1, compare);

    for(int i = 1; i <= N; i++) {
       // cout << cute.name << " " << cute.score << endl;
        cout << a[i].index << endl;
    }



    
}
