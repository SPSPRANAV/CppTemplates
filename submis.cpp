#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define f(i,a,b) for(ull i=a;i<b;i++)
#define frev(i,a,b) for(ll i=a-1;i>=b;i--)
#define ll  long long
#define ull  unsigned long long
#define vi vector<int>
#define vl vector<ll>
#define mpl pair<ll,ll>
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
ll max_val(ll a,ll b)
{
  if(a>=b)return a;
  else return b;
}
ll min_val(ll a, ll b)
{
  if(a<=b)return a;
  else return b;
}
int main()
{
  ll t;
  t=1;
  cin>>t;
  while(t--)
  {
  ll n;
  cin>>n;
  ll p[n];ll c[n];
  map<int,int> m;
  f(i,1,n+1)
  {
    cin>>p[i];
    m.insert(make_pair(p[i],i));
    c[i]=1;
  }

  int x=m[1];
  ll maxi=1;
  string ans="Yes\n";
  f(i,1,n+1)
  {
    int y=m[i];
    //cout<<"y is : "<< y<<"  c[y] is : "<<c[y]<<" maxi is :  "<<maxi<<endl;
    if(c[y]==maxi)
    {

      if(y!=n && c[y+1]!=0){c[y+1]+=c[y];maxi=c[y+1];}
      else{maxi=1;}
      c[y]=0;
    }
    else{ans="No\n";break;}
  }
  cout<<ans;
  }
return 0;
}
