// 15
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k;  cin >> n >> k;
    string s;  cin >> s;

    int cnt = count(s.begin(), s.end(), '1');
    if (cnt <= k) {
        cout << "Alice" << '\n';
    } else {
        if (n < 2 * k) {
            cout << "Alice" << '\n';
        } else {
            cout << "Bob" << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}