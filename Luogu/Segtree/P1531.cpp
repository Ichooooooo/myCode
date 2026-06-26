
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = (int)2e5 + 9;

struct SegmentTree{
    int n;
    vector<int> seg;

    SegmentTree(int n):n(n),seg(n<<2,0){}

    void up(int i){
        seg[i] = max(seg[i<<1],seg[i<<1|1]);
    }

    void build(int l,int r,int i,vector<int>& a){
        if(l==r){
            seg[i] = a[l];
        }
        else{
            int mid = l+r>>1;
            build(l,mid,i<<1,a);
            build(mid+1,r,i<<1|1,a);
            up(i);
        }
    }

    void update(int u,int l,int r,int i,int k){
        if(l==r){
            return [&]{seg[i] = max(seg[i] , k);}();
        }
        int mid = l+r>>1;
        if(u<=mid){
            update(u,l,mid,i<<1,k);
        }
        else{
            update(u,mid+1,r,i<<1|1,k);
        }
        return up(i);
    }

    void update(int u,int k){
        return update(u,1,n,1,k);
    }

    int query(int u,int v,int l,int r,int i){
        if(u<=l && r<=v){
            return seg[i];
        }
        int mid = l+r>>1;
        int res = 0;
        if(u<=mid) res = max(res , query(u,v,l,mid,i<<1));
        if(v>mid) res = max(res , query(u,v,mid+1,r,i<<1|1));
        return res;
    }

    int query(int l,int r){
        return query(l,r,1,n,1);
    }
};

void ovo() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1,0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    SegmentTree seg(n);
    seg.build(1,n,1,a);
    while(m--){
        char op;
        int l,r;
        cin >> op >> l >> r;
        if(op=='Q'){
            cout << seg.query(l,r) << endl;
        }
        else{
            seg.update(l,r);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}