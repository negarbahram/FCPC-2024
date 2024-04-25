//ThE.EnD.AnD.ThE.BeGiNiNg ;
/*
    When I die I wanna know that I lived for a reason
    Anyone can take your life, but not what you believe in, no
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int N=1e6+10 , INF=1e9+7 ;
int n,m,q,par[N],sz[N] ;
vector <int> adj[N],ans ;
pair <int,int> edges[N] ;
set < pair<int,int> > myset ;
bool vis[N] ;
int root(int v){
	if ( v==par[v] )
		return v ;
	return par[v] = root(par[v]) ; 
}
void match(int v,int u){
	u=root(u) ;	v=root(v) ;
	if ( sz[u]>sz[v] )
		swap(u,v) ;
	par[u] = v ;
	sz[v] += sz[u] ;
}
int find_comps(){
	int ret = 0 ;
	for ( int i=1 ; i<=(n*m) ; i++ ){
		int r = root(i) ;
		if ( !vis[r] ){
			vis[r]= 1 ;
			ret++ ;
		}
	}
	return ret ;
}
int main(){
   	ios_base::sync_with_stdio(false); cin.tie(0);
    	cin >> n >> m >> q ;
	for ( int i=0 ; i<q ; i++ ){
		string d ;
		int r,c ;
		cin >> d >> r >> c ;
		int node = ((r-1)*m)+c , nei=node ;
		if ( d=="up" )	nei -= m ;
		else if ( d=="down" )	nei += m ;
		else if ( d=="right" )	nei++ ;
		else	nei-- ;
		if ( nei<node )	swap(nei,node) ;
		edges[i] = {node,nei} ;
		myset.insert({node,nei}) ;
	}
	for ( int i=1 ; i<=(n*m) ; i++ )
		par[i] = i ;
	for ( int r=1 ; r<=n ; r++ )
		for ( int c=1 ; c<=m ; c++ ){
			int node = ((r-1)*m)+c ;
			if ( r!=n )
				if ( myset.find({node,node+m})==myset.end() )
					match(node,node+m) ;
			if ( c!=m )
                                if ( myset.find({node,node+1})==myset.end() )
					match(node,node+1) ;
		}
	int comps=find_comps() ;
	for ( int i=(q-1) ; i>=0 ; i-- ){
		ans.push_back(comps) ;
		int node = edges[i].f , nei = edges[i].s ;
		if ( root(node) != root(nei) ){
			comps-- ;
			match(node,nei) ;
		}
	}
	for ( int i=(q-1) ; i>=0 ; i-- )
		cout << ans[i] << '\n' ;
	return 0 ;
}



