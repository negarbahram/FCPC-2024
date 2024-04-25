#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int n,m,x1,x2,Y1,y2;
vector <pair<int,int> > v; 
int ans[MAXN];

bool check(int ind,int x,int y)
{
    ll a=v[ind].first,b=v[ind].second; // from (a,Y1) to (b,y2)
    if(x>max(a,b))
        return true;
    if(x<min(a,b))
        return false;
    ll r1=(Y1-y2)*(a-x),r2=(Y1-y)*(a-b);
    return (r1<r2);

}

int calc(int x,int y)
{
    int s=0,e=v.size()-1;
    while(e-s>1)
    {
        int mid=(s+e)/2;
        if(check(mid,x,y)) // (x,y) is on the right side of mid
            s=mid;
        else
            e=mid;
    }
    return e;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        if(n==0)
            return 0;
        cin>>m>>x1>>Y1>>x2>>y2;
        v.push_back({0,0});
        for(int i=1;i<=n;i++)
        {
            int u,l;
            cin>>u>>l;
            u-=x1;
            l-=x1;
            v.push_back({u,l});
        }
        v.push_back({x2-x1,x2-x1});
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            x-=x1;
            ans[calc(x,y)]++;
        }
        for(int i=1;i<v.size();i++)
            cout<<i-1<<": "<<ans[i]<<endl;
        cout<<endl;
        memset(ans,0,sizeof ans);
        v.clear();
    }
    return 0;
}
