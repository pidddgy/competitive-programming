#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int top[2] = {1, 2};
    int bot[2] = {3, 4};
    string s;
    getline(cin, s);

    for(auto chr: s) {
        if(chr == 'V'){
            int temp;
            temp = top[0];
            top[0] = top[1];
            top[1] = temp;

            temp = bot[0];
            bot[0] = bot[1];
            bot[1] = temp;

        } else if (chr == 'H') {
            int temp;
            
            temp = top[0];
            top[0] = bot[0];
            bot[0] = temp;

            temp = top[1];
            top[1] = bot[1];
            bot[1] = temp;
        }
    }

    cout << top[0] << " " << top[1] << endl << bot[0] << " " << bot[1] << endl;
}
