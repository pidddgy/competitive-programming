// please fucking work
#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

string N, H;

string getSubstr(int l, int r) {
    string res;
    for(int i = l; i <= r; i++) {
        if(i < 0) {
            assert(false);
            continue;
        }
        res.push_back(H[i]);
    }

    return res;
}


string alpha = "abcdefghijklmnopqrstuvwxyz";
int main() {
    int ans = 0;
    cin >> N >> H;

    int prefsums[30][H.size()];
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < H.size(); j++) {
            prefsums[i][j] = 0;
        }
    }

    set<string> shit;
    for(int i = 0; i < H.size(); i++) {
        char x = H[i];

        prefsums[x-'a'][i]++;
    }

    for(int l = 0; l < 26; l++) {
        for(int i = 1; i < H.size(); i++) {
            prefsums[alpha[l]-'a'][i] += prefsums[alpha[l]-'a'][i-1];
        }
    }

    // for(int i = 0; i < H.size(); i++) {
    //     cout << prefsums[0][i] << " ";
    // }
    // cout << endl;


    int ncnt[30];
    for(int i = 0; i < 30; i++) ncnt[i] = 0;
    
    for(char x: N) {
        ncnt[x-'a']++;
    }

    // deque<char> window;
    // for(int i = 0; i < N.size(); i++) {
    //     window.push_back(H[i]);
    // }

    for(int i = N.size()-1; i < H.size(); i++) {
        int cnts[30];
        for(int i = 0; i < 30; i++) cnts[i] = 0;

        for(int l = 0; l < 26; l++) {
            if(alpha[l]-'a' < 0 or alpha[l]-'a' >= 26) continue;
            cnts[alpha[l]-'a'] += prefsums[alpha[l]-'a'][i];
            if(i >= N.size()) {
                cnts[alpha[l]-'a'] -= prefsums[alpha[l]-'a'][i-N.size()];
            }
        }

        bool allmatch = true;

        // watch(curStr)
        // watch(i)
        // watch(N.size())
        
        for(int l = 0; l < 26; l++) {
            if(alpha[l]-'a' < 0 or alpha[l]-'a' >= 26) continue;
            
            if(cnts[alpha[l]-'a'] != ncnt[alpha[l]-'a']) {
                allmatch = false;
                // cout << "failed on char " << x << endl;
                // watch(x-'a')
                // watch(cnts[x-'a'])
                // watch(ncnt[x-'a'])
                break;
            }
        }


        if(allmatch) {
            string curStr = getSubstr(i-N.size()+1, i);
            if(shit.find(curStr) == shit.end()) {
                shit.emplace(curStr);
                // cout << curStr << " works " << endl;
                ans++;
            }
       
        }

        // window.pop_front();
    
        // if(i+1 < H.size())
        //     window.push_back(H[i+1]);
        // cout << endl;
    }

    cout << ans << endl;



    

}