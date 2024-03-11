#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int N = 1e3 + 10, K = 200 + 20;

int n, k;
int pos[N][K];
bool in[N], out[N];
vector<int> ans, adj[N];

bool dfs(int u) {
    in[u] = true;
    for (auto v: adj[u]) {
        if (!in[v])
            dfs(v);
        if (in[v] && !out[v])
            return false;
    }
    ans.push_back(u);
    out[u] = true;
    return true;
}

bool topoloSort() {
    for (int i = n - 1; ~i; i--)
        if (!in[i] && !dfs(i))
            return false;
    return true;
}

int main() {
    cin >> n >> k;
    while (k || n) {

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                pos[--x][i] = j;
            }

        for (int i = 0; i < n; i++)
            adj[i].clear();

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int cnt = 0;
                for (int l = 0; l < k; l++)
                    cnt += (pos[i][l] < pos[j][l]);
                if (k % 2 == 0 && cnt == k / 2)
                    continue;
                if (cnt >= k / 2 + 1)
                    adj[i].push_back(j);
                else
                    adj[j].push_back(i);
            }

        for (int i = 0; i < n; i++)
            sort(adj[i].begin(), adj[i].end(), greater<int>());

        ans.clear();
        for (int i = 0; i < n; i++)
            in[i] = false, out[i] = false;

        if (!topoloSort()) {
            cout << "No solution\n";
        }
        else {
            for (int i = ans.size() - 1; ~i; i--)
                cout << ans[i]  + 1 << ' ';
            cout << endl;
        }

        cin >> n >> k;
    }
    return 0;
}