#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define n_max 1000000

void cal_fac(vector<ll>& fac) {
    for (int i=2;i<=n_max;++i) {
        fac[i]=i*fac[i-1] % mod ;
    }
}

bool is_good(ll n, ll a, ll b) {
    while (n) {
        if (n%10!=a && n%10!=b) return false ;
        n/=10 ;
    }
    return true ;
}

ll inv(ll a) {
    ll n=mod-2 ;
    ll ans=1 ;
    while (n) {
        if (n&1) {
            ans*=a ;
            ans%=mod ;
        }
        a*=a ;
        a%=mod ;
        n>>=1 ;
    }
    return ans ;
}

int main()
{
    vector<ll> fac(n_max+5,1) ;
    cal_fac(fac) ;
    ll a,b,n, ans=0 ;
    scanf("%lld %lld %lld",&a,&b,&n) ;
    for (ll i=0;i<=n;++i) {
        if (is_good(i*a+(n-i)*b, a, b)) {
            ans+=fac[n]*inv(fac[n-i]*fac[i]%mod) % mod ;
            ans%=mod ;
        }
    }
    printf("%lld",ans) ;
    return 0;
}
