#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 100;
bool b[maxn];
int d[maxn];
int h[maxn];
int st[maxn];
int fe[maxn];
int par[maxn];
int ind = 1;
int k;
vector <int> g[maxn];
void dfs(int v){
	int u;
	d[v] = 1;
	st[v] = ind;
	ind++;
	for (int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if (b[u] == 0){
			b[u] = 1;
			par[u] = v;
			h[u] = h[v]+1;
			dfs(u);
			d[v] += d[u];
		}
	}
	fe[v] = ind;
	ind++;
	return;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,v,u;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	b[1] = 1;
	dfs(1);
	long long x = 0, y = 0;
	long long t = h[n] - 1;
	t /= 2;
	int o = n;
	while(t--){
		o = par[o];
	}
	y = d[o];
	x = n - d[o];
	if (x > y){
		cout <<"Negar";
		return 0; 
	}
	cout << "Niayesh";
	return 0;
}

