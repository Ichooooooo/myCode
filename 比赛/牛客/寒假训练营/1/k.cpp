#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n;  cin >> n;
    int sum = 0, mul = 1;
    for (int i = 1; i <= n; i ++) {
        sum += i;
        mul *= i;
    }
    if (sum == mul) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i ++) cout << i << ' ';
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}