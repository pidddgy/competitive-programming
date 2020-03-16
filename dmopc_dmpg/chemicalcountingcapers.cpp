// https://dmoj.ca/problem/dmpg19s3

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define MOD 1000000007
#define endl '\n'
#define ll long long
using namespace std;

// check if entire string is valid number
bool strdig(string s) {
    for(char chr: s) {
        if(!isdigit(chr)) {
            return false;
        }
    }
    return true;
}

int main() {
    
    ll N;
    vector<string> thing;
    cin >> N;
    for(;;) {
        string s;
        cin >> s;
        if(cin.fail()) break;

        thing.push_back(s);
    }


    stack<ll> mult;
    ll multiplier = 1;
    unordered_map<string, ll> cnt;
    vector<string> elems;
    for(ll i = thing.size()-1; i >= 0; i--) {

        multiplier %= MOD;
        if(thing[i] == ")")
            continue;
        
        else if(thing[i] == "(") {
            if(mult.size() > 0) {
                multiplier = mult.top();
                mult.pop();
            } else multiplier = 1;
        }

        else if(strdig(thing[i])) {
            mult.push(multiplier);
            multiplier *= stoll(thing[i]);
            multiplier %= MOD;
        }

        else {
            multiplier %= MOD;
            cnt[thing[i]] += multiplier;
            cnt[thing[i]] %= MOD;

            if(find(elems.begin(), elems.end(), thing[i]) == elems.end()) // possible tle
                elems.push_back(thing[i]);
            
            if(mult.size() > 0) {
                multiplier = mult.top();
                mult.pop();
            } else multiplier = 1;
            multiplier %= MOD;
        }
        multiplier %= MOD;
    }

    sort(elems.begin(), elems.end());
    for(string x: elems) {
        cout << x << " " << cnt[x]%MOD << endl;
    }
}
