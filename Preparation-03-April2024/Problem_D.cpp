#include <bits/stdc++.h>
using namespace std;
const int MAXN=310;
vector <string> s[12];
char c[MAXN][MAXN];
int cnt[20],tmp[20];

void add(int ind,string t)
{
    s[ind].push_back(t);
}

bool check(int x,int y,int ind)
{
    bool can=true;
    for(int i=0;i<5;i++)
        for(int j=0;j<s[ind][0].size();j++)
            if(c[x+i][y+j]!=s[ind][i][j] and s[ind][i][j]!='.')
                can=false;
    return can;
}

int main()
{
    ios::sync_with_stdio(false);
    add(0,".AA.");
    add(0,"A..A");
    add(0,"AAAA");
    add(0,"A..A");
    add(0,"A..A");

    add(1,"BBB.");
    add(1,"B..B");
    add(1,"BBB.");
    add(1,"B..B");
    add(1,"BBB.");

    add(2,".CCC");
    add(2,"C...");
    add(2,"C...");
    add(2,"C...");
    add(2,".CCC");

    add(3,"DDD.");
    add(3,"D..D");
    add(3,"D..D");
    add(3,"D..D");
    add(3,"DDD.");

    add(4,"EEEE");
    add(4,"E...");
    add(4,"EEE.");
    add(4,"E...");
    add(4,"EEEE");

    add(5,"FFFF");
    add(5,"F...");
    add(5,"FFF.");
    add(5,"F...");
    add(5,"F...");

    add(6,".GGG");
    add(6,"G...");
    add(6,"G.GG");
    add(6,"G..G");
    add(6,".GGG");

    add(7,"H..H");
    add(7,"H..H");
    add(7,"HHHH");
    add(7,"H..H");
    add(7,"H..H");

    add(8,"I");
    add(8,"I");
    add(8,"I");
    add(8,"I");
    add(8,"I");

    add(9,"...J");
    add(9,"...J");
    add(9,"...J");
    add(9,"J..J");
    add(9,".JJ.");

    add(10,"K..K");
    add(10,"K.K.");
    add(10,"KK..");
    add(10,"K.K.");
    add(10,"K..K");

    add(11,"L..");
    add(11,"L..");
    add(11,"L..");
    add(11,"L..");
    add(11,"LLL");

    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>c[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<12;k++)
                if(check(i,j,k))
                    cnt[k]++;
    int ans=0;
    for(int i=0;i<q;i++)
    {
        memset(tmp,0,sizeof tmp);
        string t;
        bool can=true;
        cin>>t;
        for(int j=0;j<t.length();j++)
            tmp[t[j]-'A']++;
        for(int j=0;j<12;j++)
        {            
            if(tmp[j]>cnt[j])
            {
                can=false;
                break;
            }
        }
        if(can)
            ans++;
    }
    cout<<ans<<endl;
    for(int i=0;i<12;i++)
        cerr<<cnt[i]<<" ";
    cerr<<endl;
    return 0;
}
