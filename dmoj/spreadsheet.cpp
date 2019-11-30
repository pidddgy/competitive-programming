// https://dmoj.ca/problem/ccc04s3

#include <bits/stdc++.h>
#define vs vector<string>
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

//str/int map
string st[15][15];
int in[15][15];

bool num(string s) {
    for(char chr: s) if(!isdigit(chr)) return false;
    return true;
}

vs spl(string s) {
    vs ret;
    string cur;
    for(char chr: s) {
        if(chr != '+') cur += chr;
        else {
            ret.pb(cur);
            cur = "";
        }
    }
    ret.pb(cur);
    return ret;
}

pii val(string s) {
    return {s[0]-'A'+1, s[1]-'0'};
}

int main() {
    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= 9; j++)
            cin >> st[i][j];

    
    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= 9; j++)
            if(num(st[i][j])) {
                in[i][j] = stoi(st[i][j]);
            } else {
                in[i][j] = -1;
            }
    
    bool change = true;
    while(change) {
        change = false;
        for(int i = 1; i <= 10; i++) {
            for(int j = 1; j <= 9; j++) {
                // if(i == 1) {
                //     cout << "currently on " << i << " " << j << endl;
                // }
                if(in[i][j] == -1) {
                    int tot = 0;
                    vs cute = spl(st[i][j]);
                    bool bad = false;
                    for(string s: cute) {

                        pii coord = val(s);
                        // if(i == 1) {
                        //     cout << "a child is " << s << endl;
                        //     cout << "or " << coord.fi << " " << coord.se << endl;
                        // }
                        if(in[coord.fi][coord.se] == -1) bad = true;
                        else tot += in[coord.fi][coord.se];
                    }

                    if(bad) continue;
                    else {
                        in[i][j] = tot;
                        change = true;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 9; j++) {
            if(in[i][j] == -1) cout << "* ";
            else cout << in[i][j] << " ";
        }
        cout << endl;
    }


    
}
