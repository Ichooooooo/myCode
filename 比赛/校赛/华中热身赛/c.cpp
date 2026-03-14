#include<bits/stdc++.h>
#define int long long 
#define endl '\n' 
#define INF 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define x first 
#define y second 
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod=998244353;
const double eps = 1e-10;

struct node{
    int a, b;
    int p;
};

bool cmp(node x, node y){
    if(x. a != y.a)  return x.a > y.a;
    else    return x.b < y.b;
}

void solve(){   
    int n;
    cin >> n;
    vector<node> mp(n);
    vector<string> ss(n);
    for(int i = 0; i < n; i ++){
        cin >> ss[i] >> mp[i].a >> mp[i].b;
        mp[i].p = i;
    }
    sort(mp.begin(), mp.end(), cmp);
    cout << ss[mp[0].p] << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}