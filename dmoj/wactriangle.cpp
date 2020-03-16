// https://dmoj.ca/problem/wac3p5
// orz chadliam

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

vector<string> bloop;
int N;

void shit(string s = ".") {
    if(s.size() == N+1) {
        bloop.emplace_back(s);
        return;
    } else {
        shit(s + "0");
        shit(s + "1");
    }
}

int main() {
    #define int long long
    cin >> N;

    int a[N+1];
    int c[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        cin >> c[i];
    }
    

    shit();

    int mi = LLONG_MAX;
    for(string x: bloop) {
        vector<int> haveN;
        int cost = 0;
        bool bad = false;
        for(int i = 1 ; i <= N; i++) {
            if(x[i] == '1') {
                haveN.emplace_back(a[i]);
            } else {
                cost += c[i];
            }

            for(int j = 0; j < haveN.size(); j++) {
                for(int k = 0; k < haveN.size(); k++) {
                    for(int l = 0; l < haveN.size(); l++) {
                        if(j == k or k == l or j == l) continue;
                    
                        if ((haveN[j] + haveN[k] > haveN[l] and 
                        haveN[j] + haveN[l] > haveN[k] and 
                        haveN[k] + haveN[l] > haveN[j])) {
                            bad = true;
                        }
                    }
                }
                if(bad) break;
            }
            if(bad) break;
        }

        if(!bad) {
            if(cost < mi) {
                mi = cost;
            }
        }
    }

    cout << mi << endl;
}