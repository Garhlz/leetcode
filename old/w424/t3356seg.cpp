#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
#define lc u<<1
#define rc u<<1|1

int w[N];
struct Tree{ //线段树
  int l,r,sum,add;
}tr[N<<2];


void pushup(int u){
    tr[u].sum = tr[lc].sum + tr[rc].sum;
}


void pushdown(int u){
    if(tr[u].add){
        tr[lc].sum+=tr[u].add * (tr[lc].r - tr[lc].l + 1);
        tr[rc].sum+=tr[u].add * (tr[rc].r - tr[rc].l + 1);
        tr[lc].add+=tr[u].add;
        tr[rc].add+=tr[u].add;
        tr[u].add = 0;
    }
}


void build(int u,int l,int r){
    tr[u] = {l,r,w[l],0};//直接在此确定了所有结点的左右编号
    if(l==r)return;
    int m = (l+r)/2;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(u);//递归之后回溯更新当前结点
}


void change(int u,int l,int r,int k){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].sum += (tr[u].r - tr[u].l + 1) * k;
        tr[u].add += k;
        return;//记得一定要返回，不再继续递归修改，留在懒标记中
    }
    int m = (tr[u].l + tr[u].r) / 2;
    pushdown(u);
    if(l<=m)change(lc,l,r,k);
    if(r>m)change(rc,l,r,k);
    pushup(u);
}


int query(int u,int l,int r){
    if(l<=tr[u].l && tr[u].r<=r)return tr[u].sum;
    int m = (tr[u].l + tr[u].r) / 2;
    pushdown(u);
    int ret = 0;
    if(l<=m)ret+=query(lc,l,r);
    if(r>m)ret+=query(rc,l,r);
    return ret;
}



void solve()
{
    int n,m,op,x,y,k;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>w[i];//基本的数组
    }
    build(1,1,n);
    while(m--){
        cin>>op>>x>>y;
        if(op==2)cout<<query(1,x,y)<<'\n';
        else{
            cin>>k;
            change(1,x,y,k);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--)
    solve();
    return 0;
}
