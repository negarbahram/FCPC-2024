#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define pb push_back
#define int long long 
using namespace std ;
const int maxn = 1e6 ,maxq = 5e4 + 100 , inf = 1e9+100 , mod = 1e9+7 ;


signed main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n ;
	cin >> n ;
	vector <pair <int , int > > v ;
	for(int i = 1; i <= n ; i++){
		int l , r ;
		cin >> l >> r; 
		v.pb({l , -r});
	}
	if(n == 1){
		cout << "0\n";
		return 0 ;
	}
	sort(all(v));
	int mr = -v[0].second ;
	bool ok =  0 ;
	vector <pair <int ,int> > vec ;
	vec.pb({v[0].first , -v[0].second});
	for(int i =1 ; i < v.size() ; i++){
		int u = -v[i].second ;
		if(u <= mr){
			ok = 1;
			continue ;
		}
		mr = u ;
		vec.pb({v[i].first , -v[i].second });
	} 
	int ans = vec[0].second - vec[0].first ;
	for(int i = 1 ; i < vec.size() ; i++){
		int l = max(vec[i].first , vec[i-1].second) , r = vec[i].second ;
		ans += r-l ;
	}
	if(ok == 0){
		int mi = min(min(vec[0].second , v[1].first) - vec[0].first , vec.back().second - max(vec.back().first , vec[vec.size() - 2].second)) ;
		for(int i = 1 ; i < vec.size()-1 ; i++){
			int l  = max(vec[i].first , vec[i-1].second) , r = min(vec[i].second , vec[i+1].first) ;
			mi = min(mi , r-l);
		}
		ans -= mi ;
	}
	cout << ans ; 
	return 0 ;
}


