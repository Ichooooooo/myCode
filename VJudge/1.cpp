#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define double long double
using ll = long long;
const ll mod = 998244353;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

bool check(int mid, vector<int> a, int m){
    int sum = 0;
    int cnt  = 0;
        for(int i = 0; i < a.size(); i ++){
        if(sum + a[i] > mid){
            // cout << "mid : " << mid << "sum : " << sum;
            sum = a[i];
            cnt ++;
            // cout << "cnt :" << cnt << endl;
        }else if(sum + a[i] == mid){
            sum = 0;
            cnt ++;
            // cout << "mid : " << mid << "sum : " << sum << "cnt :" << cnt << endl;
        }else{
            sum += a[i];
        }
    }
    if(sum != 0){
        cnt ++;
    }
    // cout << mid << " " << cnt << endl;
    if(cnt <= m){
        return true;
    }else{
        return false;
    }
}

void solve(){
	int n, m;
    cin >> n >> m;
    vector<int> a(n);
    ll sum = 0;
    for(int & i : a){
        cin >> i;
        sum += i;
    }
    int l = *max_element(a.begin(), a.end());
    int r = sum;
    // cout << "l : " << sum << endl;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid, a, m)){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << l << endl;
}

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _=1;
	// cin>>_;
	while(_--){
		solve();
	}
	return 0;
}