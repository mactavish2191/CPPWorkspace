#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl "\n"
#define test ll t; cin>>t; while(t--)
typedef long long int ll;

ll solve(vector<ll>&a,ll c01,ll c10,ll st){
    ll ans=0;
    for(auto it:a){
        if(it!=st){
            ans+=(it==0?c01:c10);
        }
        st^=1;
    }
    return ans;
}

int main() {
    test
    {
      ll n,c01,c10;
      cin>>n>>c01>>c10;
      vector<ll>a(n);
      for(auto &it:a) cin>>it;
      ll ans=1e18;
      ans=min(ans,solve(a,c01,c10,0ll));
      ans=min(ans,solve(a,c01,c10,1ll));
      cout<<ans<<endl;
    }
	return 0;
}

