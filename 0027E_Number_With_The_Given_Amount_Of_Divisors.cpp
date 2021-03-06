#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define n_max 1000
#define p_max 10
#define lim 1e18

ll dp[n_max+5][p_max+5], n ;
ll pr[p_max+5]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43} ;

ll mul (ll a,ll b) {
    ll ans=a*b ;
    if (b>lim/a) ans=lim ;
    return ans ;
}

ll binpow(ll a,int n) {
    ll ans=1 ;
    while (n) {
        if (n&1) {
            ans=mul(ans,a) ;
        }
        a=mul(a,a) ;
        n>>=1 ;
    }
    return ans ;
}

void cal() {
    for (int i=1;i<=n_max;++i) {
        dp[i][1]= binpow(2,i-1) ;
    }
    for (int j=2;j<=p_max;++j) {
        for (int i=1;i<=n_max;++i) {
            dp[i][j]=dp[i][j-1] ;
            for (int k=1;k*k<=i;++k) {
                if (i%k==0) {
                    dp[i][j]=min( dp[i][j], mul(dp[i/k][j-1],binpow(pr[j],k-1)) ) ;
                }
            }
        }
    }
}

int main()
{
    cal() ;
    scanf("%lld",&n) ;
    printf("%lld",dp[n][p_max]) ;
    return 0;
}
