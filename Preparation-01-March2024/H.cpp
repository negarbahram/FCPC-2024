#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll maxn = 4e2 + 18, inf = 2e9;
int dp[maxn][maxn] , pd[maxn][maxn] , ps[maxn][maxn], a[maxn][maxn], b[maxn][maxn] , c[maxn][maxn];

int main(){
    memset(pd , -31 , sizeof(pd));
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> c[i][j];
        }
    }
    for(int j = 0 ; j <= m ; j++){
        for(int i = 0 ; i < n ; i++){
            cin >> b[i][j];
        }
    }
    for(int l = 1 ; l <= n + m ; l++){
        int pr = 0;
        for(int i = 1 ; i <= n ; i++){
            int j = l - i;
            if(j < 0 || j > m) continue;
            pr += a[i - 1][j];
            ps[l][i] = pr;
        }
    }
    pd[0][0] = 0;
    for(int l = 1 ; l <= n + m ; l++){
        memset(dp , -31 , sizeof(dp));
        for(int i = 0 ; i <= n ; i++){
            int ji = l - i;
            if(ji < 0 || ji > m) continue;
            for(int k = i ; k <= n ; k++){
                int jk = l - k;
                if(jk < 0) break;
                int h = -inf;
                if(k > 0 && ji > 0){
                    h = max(h , pd[i][k - 1] - b[k - 1][jk] - c[i][ji - 1]);
                }
                if(jk > 0){
                    h = max(h , pd[i][k] - c[i][ji - 1] - c[k][jk - 1]);
                }
                if(i > 0){
                    h = max(h , pd[i - 1][k - 1] - b[i - 1][ji] - b[k - 1][jk]);
                }
                if(i > 0 && jk > 0){
                    h = max(h , pd[i - 1][k] - c[k][jk - 1] - b[i - 1][ji]);
                }
                dp[i][k] = h + ps[l][k] - ps[l][i];
            }
        }
        memcpy(pd , dp , sizeof(dp));
    }
    cout << dp[n][n] << '\n';
    return 0;
}
