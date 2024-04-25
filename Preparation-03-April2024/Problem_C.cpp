#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
string t[MAXN];

struct node
{
    node *ch[26];
    node *tab,*par;
    int dis;
    node(node *parent)
    {
        for(int i=0;i<26;i++)
            ch[i]=NULL;
        tab=NULL;
        par=parent;
        dis=-1;
    }
};
node *root=new node(NULL);

void add_dict(string s)
{
    node *cur=root;
    for(int i=0;i<s.length();i++)
    {
        if(cur->ch[s[i]-'a']==NULL)
            cur->ch[s[i]-'a']=new node(cur);
        cur=cur->ch[s[i]-'a'];
    }
    node *res=cur;
    cur=root;
    for(int i=0;i<s.length();i++)
    {
        if(cur->tab==NULL and cur!=root) //tricky test!
            cur->tab=res;
        cur=cur->ch[s[i]-'a'];
    }
    if(cur->tab==NULL)
        cur->tab=res;
}

void add_q(string s)
{
    node *cur=root;
    for(int i=0;i<s.length();i++)
    {
        if(cur->ch[s[i]-'a']==NULL)
            cur->ch[s[i]-'a']=new node(cur);
        cur=cur->ch[s[i]-'a'];
    }
}

void bfs()
{
    queue <node*> q;
    q.push(root);
    root->dis=0;
    while(q.size())
    {
        node *v=q.front();
        q.pop();
        for(int i=0;i<26;i++)
            if(v->ch[i]!=NULL and v->ch[i]->dis==-1)
            {
                q.push(v->ch[i]);
                v->ch[i]->dis=v->dis+1;
            }
        if(v->tab!=NULL and v->tab->dis==-1)
        {
            q.push(v->tab);
            v->tab->dis=v->dis+1;
        }
        if(v->par!=NULL and v->par->dis==-1)
        {
            q.push(v->par);
            v->par->dis=v->dis+1;
        }
    }
}

int calc(string s)
{
    node *cur=root;
    for(int i=0;i<s.length();i++)
        cur=cur->ch[s[i]-'a'];
    return cur->dis;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        add_dict(s);
    }
    for(int i=0;i<m;i++)
    {
        cin>>t[i];
        add_q(t[i]);
    }
    bfs();
    for(int i=0;i<m;i++)
        cout<<calc(t[i])<<endl;
    return 0;
}
