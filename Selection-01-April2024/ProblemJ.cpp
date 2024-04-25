#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
const int MAXN = 1e5 + 10;
const long long MAXV = 1e18;
pair<long long,long long> a[MAXN];
int fen[MAXN];
long long n,t;

long long f(int i)
{
    return a[i].first+t*a[i].second;
}

void put(long long ind,int val)
{
    while(ind < MAXN)
    {
        fen[ind] = max(fen[ind], val);
        ind += (ind & (-ind));
    }
}

int get(long long ind)
{
    int ret = 0;
    while(ind > 0)
    {
        ret = max(ret, fen[ind]);
        ind -= (ind & (-ind));
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> t;
    for(int i = 0; i < n ; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    vector<long long> q;
    for(int i = 0;i < n; i++)
        q.push_back(f(i));
    sort(q.begin(),q.end());
    int res = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        int ans = 1;
        int ind = lower_bound(q.begin(),q.end(),f(i)) - q.begin() +1;
        ans = max(ans, get(ind) + 1);
        put(ind, ans);
        res = max(res, ans);
    }
    cout << res << endl;
    return 0;
}
