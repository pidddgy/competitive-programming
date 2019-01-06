// https://dmoj.ca/problem/ccc01s1

 #include <bits/stdc++.h>
 #pragma GCC optimize "Ofast"
  using namespace std;
int main() {
     cin.sync_with_stdio(0); cin.tie(0);
     vector<char> C, D, H; cin.ignore();
    char aqt; string last;
         for(;;) {cin >> aqt;if(aqt == 'D') break;C.push_back(aqt);}
    for(;;) { cin >> aqt; if(aqt == 'H') break; D.push_back(aqt);} for(;;) { cin >> aqt;if(aqt == 'S') break; H.push_back(aqt);}
      getline(cin, last); vector<char> S (last.begin(), last.end()); 
    int cp = 0; for(auto chr: C) {
        switch(chr) { case 'A': cp += 4; break; case 'K': cp += 3;break;case 'Q': cp += 2;break;case 'J': cp += 1;break;
        }
    } switch(C.size()) { case 0: cp += 3;break;
    case 1: cp += 2;break; case 2: cp += 1;break;
    } int dp = 0; for(auto chr: D) {
        switch(chr) 
        { case 'A': dp += 4;break; case 'K': dp += 3;break;
            case 'Q': dp += 2;break; case 'J': dp += 1;break; }
    } switch(D.size()) { case 0: dp += 3;break; case 1: dp += 2;break; case 2: dp += 1;break;
    } int hp = 0; for(auto chr: H) {
             switch(chr) { case 'A': hp += 4;break;
            case 'K': hp += 3;break; case 'Q': hp += 2;break;
            case 'J': hp += 1;break; }
    }
    switch(H.size()) { case 0: hp += 3;break;
        case 1: hp += 2;break; case 2: hp += 1;break; }
     int sp = 0;
    for(auto chr: S) {
        switch(chr) {
            case 'A': sp += 4;break;  case 'K': sp += 3;break;
            case 'Q': sp += 2;break; case 'J': sp += 1;break;
        }
    } switch(last.size()) 
    { case 0: sp += 3;break;
        case 1: sp += 2;break; case 2: sp += 1;break;
    }
     cout << "Cards Dealt Points" << endl;
    cout     << "Clubs ";   for(auto chr: C) cout << chr << " ";
      cout << cp << endl;
    cout <<  "Diamonds "; for(auto chr: D) cout << chr << " ";
     cout << dp << endl;
      cout << "Hearts ";
       for(auto chr: H) cout << chr << " ";
                                                        cout << hp << endl; cout << "Spades ";
    for(auto chr: S) cout << chr << " "; cout << sp << endl; cout << "Total " << cp + hp + dp + sp << endl;
}
