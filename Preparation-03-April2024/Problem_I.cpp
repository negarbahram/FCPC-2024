// b o t //
// l b m b h //
// r z r //
// m t m //
#include <bits/stdc++.h>
using namespace std;
const long long maxn=2e5+10;
const long long mod=1e9+7;
long long d[maxn],d2[maxn],dp[maxn],a[maxn],b[maxn],ja[maxn];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	d[1]=1;
	d[2]=1;
	d2[2]=1;
	dp[0]=1;
	for (int i=3; i<maxn; i++){
		d[i]=d[i-1]+d2[i-1];d[i]%=mod;
		d2[i]=d[i-1];d2[i]%=mod;
	}
	for (int i=1; i<maxn; i++){
		dp[i]=d[i]+d2[i];dp[i]%=mod;
	}
	int n;
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	if (n==1){
		cout << a[1] ;
		return 0; 
	}
	
	long long v,u;
	long long maxx=1ll*dp[n]*a[1];maxx%=mod;
	for (int i=2; i<=n; i++){
		u=dp[n]-1ll*2*d[i-1]*dp[n-i];
		u%=mod;
		u+=mod;
		u%=mod;
		u=1ll*u*a[i];
		u%=mod;
		maxx+=u;
		maxx%=mod;
	}
	cout << maxx ;
	return 0;
}

