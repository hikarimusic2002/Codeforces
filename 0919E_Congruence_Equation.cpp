#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b==0) {
        x=1 ;
        y=0 ;
        return a ;
    }
    ll x1, y1 ;
    ll g=exgcd(b,a%b,x1,y1) ;
    x=y1 ;
    y=x1-(a/b)*y1 ;
    return g ;
}

int main()
{
    ll a,b,p,x ;
    scanf("%lld %lld %lld %lld",&a,&b,&p,&x) ;
    ll ans=0, a0=1 ;
    for (ll i=1;i<=p-1;++i) {
        a0=a0*a%p ;
        ll t=i*a0%p ;
        ll r=x/(p-1) ;
        r += (i <= x%(p-1) ) ? 1 : 0 ;
        ll k, m ;
        exgcd(a0,p,k,m) ;
        k*=b ;
        k=(((i+1-k)%p)+p)%p ;
        if (k==0) k=p ;
        if (r>=k) ans += 1+(r-k)/p ;
    }
    printf("%lld",ans) ;
    return 0;
}
