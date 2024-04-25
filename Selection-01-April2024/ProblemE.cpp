#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(), cout.tie();
#define fr first
#define sc second
#define all(v) v.begin(), v.end()
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define wall cerr << "\n----------------\n";

using namespace std;
typedef long long ll;
const int mod = 1e9+7;

ll po(ll b, ll p){
    ll r = 1;
    while(p){
        if(p & 1)r = r * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return r;
}

ll C(int x, int y){
    ll f = 1;
    for(int i = x; i > x-y; i--){
        f = f * i % mod;
    }
    for(int i = 1; i <= y; i++)
		f = f * po(y, mod - 2) % mod;

    return f;
}

const int maxN = 305;

vector<int> g[maxN];
vector<pair<int, int> > v[maxN];

int mark[maxN];

void dfs(int nw, int x){
    mark[nw] = x;
    for(auto u : g[nw]){
        if(!mark[u])
			dfs(u, x);
    }
}

signed main(){
    while(1){
        int n, m, k;
        cin >> n >> m >> k;
        if(n == 0 && m == 0 && k == 0)break;
        
        for(int i = 0; i < n+3; i++)
			v[i].clear(), mark[i] = 0, g[i].clear();

        while(m--){
            int x, y;
            cin >> x >> y;
            x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        for(int i = 0; i < n; i++){
            if(!mark[i]){
                dfs(i, i+1);
            }
        }

        for(int i = 0; i < k; i++){
            int c, s, n;
            cin >> c >> s >> n;
            v[mark[c-1]].push_back({n, s});
        }

        for(int i = 0; i < n+2; i++)sort(all(v[i]));

        ll realans = 0;
        for(int ii = 0; ii <= n; ii++){
            if(v[ii].size() == 0)continue;
            ll ans = v[ii].back().fr+1;
            ll sum = 0;
            k = v[ii].size();
            for(int i = k-1; i >= 0; i--){
                sum += v[ii][i].sc;
                ll x = 0;
                if(i != 0)x = v[ii][i-1].fr+1;
                ans = min(ans, max(sum, x));
            }
            realans += ans;
        }
        cout << realans << '\n';
    }

