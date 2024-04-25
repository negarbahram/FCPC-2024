#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll d[10];

int main()
{
    ios::sync_with_stdio(false);
    ll n,df,de;
    cin>>n>>df>>de;
    for(int i=0;i<10;i++)
        cin>>d[i];
    ll ans=df;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++)
            ans+=d[s[j]-'0'];
        ans+=de;
    }
    cout<<ans<<endl;
    return 0;
}
