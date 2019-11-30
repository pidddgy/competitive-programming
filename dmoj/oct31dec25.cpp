// https://dmoj.ca/problem/wac2p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;

    string ans;
    if(s=="Monday")
        ans = "Tuesday";
    if(s == "Tuesday")
        ans = "Wednesday";
    if(s == "Wednesday")
        ans = "Thursday";
    if(s == "Thursday")
        ans = "Friday";
    if(s == "Friday")
        ans = "Saturday";
    if(s == "Saturday")
        ans = "Sunday";
    if(s == "Sunday")
        ans = "Monday";




    cout << ans << endl;
}