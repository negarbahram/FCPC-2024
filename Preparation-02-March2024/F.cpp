#include<bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
 
#define mp make_pair
#define pb push_back
#define in insert
#define ers erase
#define S second
#define F first

const int N = 1e3 + 5, M = 1e5 + 5;
int n, m, deg[N];
pii par[N];
bool vis[N];
set<int> adj[N];
vector<int> ans;
set<pii> degVer;
vector<pii> adjTree[N];
set<pii> adjW[N];

void read_input() {
    cin >> n >> m;
   
    for (int i = 0; i < m; i++) {
        int v, u, w, a;
       
        cin >> v >> u >> w >> a;
        v--, u--;
       
        adjW[v].in(mp(w, u));
        adjW[u].in(mp(w, v));
       
        if (a) {
            adjTree[v].pb(mp(u, w));
            adjTree[u].pb(mp(v, w));
        }
    }
}

void ord_dfs(int v) {
    vis[v] = 1;
    for (auto u : adjTree[v])
        if (!vis[u.F]) {
            par[u.F].F = v;
            par[u.F].S = u.S;
            ord_dfs(u.F);
        }
}

void solve() {
    // root vertex :
    for (int v = 0; v < n; v++) {
        //cout << "*** " << v << '\n';
        ans.clear();
        for (int u = 0; u < n; u++)
            adj[u].clear();
        degVer.clear();
        memset(vis, 0, sizeof (vis));
        memset(deg, 0, sizeof (deg));
       
        // finding parent of each vertex :
        ord_dfs(v);
       
        // finding out which vertex has come before another :
       
        for (int u = 0; u < n; u++)
            if (u != v) {
                for (auto e : adjW[u])
                    if (e.F >= par[u].S)
                        break;
                    else // an edge from v to u in case v should come before u :
                        adj[u].in(e.S);
            }
        
        // an edge from each parent to their children :
        for (int u = 0; u < n; u++)
            if (u != v) 
                adj[par[u].F].in(u);
        
        for (int u = 0; u < n; u++)
            for (auto t : adj[u])
                deg[t]++;
     
        // set of degs and vertices :
        for (int u = 0; u < n; u++)
            degVer.in(mp(deg[u], u));
       
        while(degVer.size()) {
            pii u = *(degVer.begin());
            if (u.F != 0) break;
            degVer.ers(u);
            ans.pb(u.S);
            for (auto t : adj[u.S]) {
                degVer.ers(mp(deg[t], t));
                deg[t]--;
                degVer.in(mp(deg[t], t));
            }
        }
       
        if (ans.size() == n)
            return;
    }
}

void write_output() {
    if (ans.size() != n)
        cout << "Wrong Map!";
    else
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] + 1 << ' ';
           
    cout << '\n';
}

int main() {
    read_input();
    solve();
    write_output();
    return 0;
}