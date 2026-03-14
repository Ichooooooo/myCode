## LST/最长递增子序列

从数列 *a* 中任意删除若干个整数，构造一个单调递增的数列。请你求出该单调递增数列的最大可能长度。

##### 基本考点：二分，递推

##### 基本思路：

1. 维护一个**长度为i的递增序列的最小尾数**数组b，然后更新，遍历a数组，找到b中第一个比a_i大的最小数替代它,如果找不到就新开接在b最后面，时间复杂度O(n ^ log(n))；

2. dp写法，暴力，时间复杂度O(n ^ n)；


```cpp
//解法1
void solve(){   
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> b(n + 1);
    int ans = 1;
    b[1] = a[1];

    for (int i = 2; i <= n; i++) {
        int pos = lower_bound(b.begin() + 1, b.begin() + ans + 1, a[i]) - b.begin();
        b[pos] = a[i];
        if (pos > ans) ans++;
    }

    cout << ans << '\n';
}

```

```cpp
//解法2
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i  = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<int> dp(n + 1, 1);
    for (int i = 1; i <= n ; i ++) {
        for (int j = i - 1; j > 0; j --) {
            if(a[i]> a[j])
                dp[i] = max (dp[i], dp[j] + 1);
        }   
    }

    cout << ranges :: max(dp) << endl;
    //注意你的dp是1-based，虽然不影响结果
}
```cpp

https://atcoder.jp/contests/abc439/tasks/abc439_e

基本考点：二维转一维LIS，排序
```cpp
void solve(){   
    int n;
    cin >> n;
    vector <PII> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin() + 1, a.end(), [] (PII x, PII y) {
        if (x.first != y.first) return x.first < y.first;
        else return x.second > y.second;
    });

    vector<int> dp;
    for (int i = 1; i <= n; i ++) {
        int x = a[i].second;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }

    cout << dp.size() << endl;
}
```cpp

//wo ri ni ma de AI
基本考点：离散化 + 树状数组维护 + LIS

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
typedef pair<int,int> PII;
bool cmp(PII a,PII b){
	if(a.first==b.first)return a.second>b.second;
	return a.first<b.first;
}
const int N=2e5+5;
int lowbit(int x){return x&-x;}
int maxs[N];
void add(int x,int d){
	while(x<N){
		maxs[x]=max(maxs[x],d);
		x+=lowbit(x);
	}
}
int find(int x){
	int res=0;
	while(x){
		res=max(maxs[x],res);
		x-=lowbit(x);
	}
	return res;
}
void solve(){
	int n;cin>>n;
	PII p[n];
	map<int,int>mp;
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
		mp[p[i].second]=0;
	}
	int idx=0;
	for(auto &p:mp){
		p.second=++idx;
	}
	for(int i=0;i<n;i++)p[i].second=mp[p[i].second];
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++){
		int h=p[i].second;
		int mx=find(h-1);
		add(h,mx+1);
	}
	int ans=find(N-1);
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	for(int t=1;t<=T;t++){
		solve();
	}
}
```cpp
