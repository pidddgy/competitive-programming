// https://dmoj.ca/problem/ccc01s5

#include <bits/stdc++.h>
#define cerr cout

using namespace std;

vector<string> v1, v2;
int m, n;
bool found = false;

void f(vector<int> A = {}) {
    if(found)
        return;

    string a, b;
    cerr << "A is: " << endl;
    for(int x: A) {
        cerr << x << " ";
    }
    cerr << endl;
    for(auto num: A) {
        a.append(v1[num-1]);
        b.append(v2[num-1]);
    }

    watch(a);
    watch(b)

    if(a == b && A.size() > 0) {
        cout << A.size() << "\n";
        for(auto x: A)
            cout << x << "\n";
        found = true;
    } else if (A.size() < m)
        for(int i = 1; i <= n; i++) {
            vector<int> newA = A;
            newA.push_back(i);
            f(newA);
        }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        string x;
        cin >> x;
        v1.push_back(x);
    }

    for(int i = 0; i < n; i++) {
        string x;
        cin >> x;
        v2.push_back(x);
    }

    f();
    if(!found)
        cout << "No solution." << "\n";
}

/*

a
abaaa
ab

aaa
ab
b

2 1 1 3

a -> abaaa + a + a + ab
b -> ab + aaa + aaa + b

A = {3}

a -> absdfsf
b -> bsdfsd




*/