/** これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました **/
#include<bits/stdc++.h>
using namespace std;
 
#define rep(i,x,y) for(int i=x;i<y;i++)
#define repr(i,x,y) for(int i=x;i>=y;i--)
// #define int long long
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((int)x.size())
#define all(x) begin(x), end(x)
#define memo(x,y) memset((x),(y),sizeof((x)))
 
using pii = pair<int,int>;
using vi = vector<int>;
using vii = vector<pair<int,int>>;
 
constexpr int mod = 1e9 + 7 , N = 2e5 + 5;
constexpr long long inf = 1e18;
constexpr long double eps = 1e-6; 
 
string s;
int vis[7][7];
int cnt=0;
bool ok(int x, int y) { return x >= 0 && y >= 0 && x < 7 && y < 7; }
void go(int x,int y,int idx){
 
   if( x==0&&y==6){
    if(idx==48)cnt++;
    return;
   }
 
   if(ok(x-1,y)&&vis[x-1][y])
    if(ok(x+1,y)&&vis[x+1][y])
        if(ok(x,y-1)&&!vis[x][y-1])
            if(ok(x,y+1)&&!vis[x][y+1])
                return;
 
    if(ok(x,y-1)&&vis[x][y-1])
     if(ok(x,y+1)&&vis[x][y+1])
        if(ok(x-1,y)&&!vis[x-1][y])
            if(ok(x+1,y)&&!vis[x+1][y])
                return;
 
    if(x==6||x==0)
        if(ok(x,y-1)&&!vis[x][y-1])
            if(ok(x,y+1)&&!vis[x][y+1])
                return;
    if(y==6||y==0)
        if(ok(x-1,y)&&!vis[x-1][y])
            if(ok(x+1,y)&&!vis[x+1][y])
                return;
 
    vis[x][y]=1;
 
    if(s[idx]=='?' || s[idx]=='R'){
        if(ok(x+1,y)){
         if(vis[x+1][y]==0)
            go(x+1,y,idx+1);
        }
    }
 
    if(s[idx]=='?' || s[idx]=='D'){
        if(ok(x,y+1)){
          if(vis[x][y+1]==0)
            go(x,y+1,idx+1);
        }
    }
 
 
    if(s[idx]=='?' || s[idx]=='U'){
        if(ok(x,y-1)){
         if(vis[x][y-1]==0)
            go(x,y-1,idx+1);
        }
    }
 
    if(s[idx]=='?' || s[idx]=='L'){
        if(ok(x-1,y)){
          if(vis[x-1][y]==0)
            go(x-1,y,idx+1);
 
        }
    }
 
   vis[x][y]=0;
}
void Onigiri()
{
  cin>>s;
  go(0,0,0);
  cout<<cnt;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   //cout.precision(10);cout<<fixed;
   #ifdef Zoro
   freopen("/home/pritish/Competitive/in", "r", stdin);
   freopen("/home/pritish/Competitive/out", "w", stdout);
   #endif  
 
   int t=1; 
   //cin>>t;
 
   while(t--)
   {Onigiri();cout<<"\n";}
 
   cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
   return 0;
}