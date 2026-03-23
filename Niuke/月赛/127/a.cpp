#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    std :: string s[7] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};
    vector<PII> arr(7);
    for (int i = 0; i < 7; i ++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort (arr.begin(), arr.end());
    cout << s[arr[6].second] << endl;

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}