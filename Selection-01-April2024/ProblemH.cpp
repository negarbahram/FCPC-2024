#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define SZ(x) (int)(x.size())
#define el '\n'
#define pb push_back
typedef long long ll;
typedef pair <int , int> pii;

const int N = 1e5 + 10, oo = INT_MAX - 5;

ll n, a[N];
vector <int> bit1[65], adj[N];
vector <pii> edgs;

void grp(ll x, int i) {
	
	for (int j = 0; x > 0; j++) {
		if (x % 2)
			bit1[j].pb(i);
		x >>= 1;
	}

}

void input() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {

		cin >> a[i];
		grp(a[i], i);

	}

}

void check3() {
	
	for (int i = 0; i < 62; i++) {
		if (SZ(bit1[i]) >= 3) {
			cout << 3 << el;
			exit(0);
		}
	}

}

void cnct(int u, int v) {
	adj[u].pb(v);
	adj[v].pb(u);
}

void mkgrph() {
	
	for (int i = 0; i < 62; i++) {
		for (auto u: bit1[i]) {
			for (auto v: bit1[i]) {
				if (v != u) {
					cnct(u, v);
					edgs.pb({u, v});
				}
			}
		}
	}

}

int bfs(int u, int v) {
	
	int h[N];
	queue <int> q;
	fill(h, h + n, oo);

	h[u] = 0;
	q.push(u);

	while(!q.empty()) {
		int x = q.front();
	       	q.pop();
		for (auto y: adj[x]) {
			if (x == u && y == v)
				continue;
			if (h[y] == oo) {
				h[y] = h[x] + 1;
				q.push(y);
			}
		}
	}

	return h[v] + 1;

}

void findgirth() {
	
	int ans = oo;

	for (auto e: edgs) {
		
		int u = e.F, v = e.S;
		
		ans = min(ans, bfs(u, v));

	}

	if (ans == oo)
		cout << -1 << el;
	else
		cout << ans << el;

}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);	
	
	input();
	
	check3();

	mkgrph();
		
	findgirth();

	return 0;
}

