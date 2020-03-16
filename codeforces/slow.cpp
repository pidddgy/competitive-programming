// link

#include <bits/stdc++.h>
using namespace std;
vector<string> answer;

void getStrings( string s, int digitsLeft )
{
   if( digitsLeft == 0 ) // the length of string is n
      answer.push_back( s );
   else
   {
      getStrings( s + "0", digitsLeft - 1 );
      getStrings( s + "1", digitsLeft - 1 );
   }
}


int main() {
    for(int thing = 100; thing <= 100; thing++) {
            getStrings( "", thing);

        int ans = 0;
        for(string x: answer) {
            bool good = true;
            for(int i = 1; i+1 < x.size(); i++) {
                if(x[i] == x[i-1] and x[i] == x[i+1]) {
                    good = false;
                }
            }
            if(good) {
                cout << x << endl;
                ans++;
            }
        }
        cout << "----" << endl;
        cout << ans << endl;

        answer = vector<string>();


    }

    

}