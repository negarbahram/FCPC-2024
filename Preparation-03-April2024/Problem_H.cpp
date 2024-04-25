#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int MAXN=1e5+10;
ordered_set s;
ll x[MAXN],ans;

int main()
{
    ios::sync_with_stdio(false);
    ll n,v;
    cin>>n>>v;
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=0;i<n;i++)
    {
        ll t;
        cin>>t;
        ll val=x[i]-v*t;
        ans+=s.order_of_key(val);
        s.insert(val);
    }
    cout<<ans<<endl;
    return 0;
}
