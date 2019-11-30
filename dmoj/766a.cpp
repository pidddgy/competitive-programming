// http://codeforces.com/contest/766/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;

    if(a==b)
        cout<<-1<<endl;
    else
        cout<<max(a.size(),b.size())<<endl;
}