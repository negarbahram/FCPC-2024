#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=(int)a;i<=b;i++)
typedef long long llint;

const int N = 1e5 + 20;
int cnt[N], n, m;
llint ans;


int main(){
    scanf("%d%d", &n, &m);
    int a;
    REP(i, 1, n){
        scanf("%d", &a);
        cnt[a % m]++;
    }

    REP(rem, 0, m/2){
        if (rem == 0 || m - rem == rem){
            ans += 1LL * cnt[rem] * (cnt[rem]-1) / 2;
        }
        else {
            ans += 1LL * cnt[rem] * cnt[m - rem];
        }
    }

    printf("%lld\n", ans);

    return 0;
}

