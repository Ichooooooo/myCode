#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;

    auto hanoi = [](int n, char a, char b, char c, auto self) -> void {
        if (n == 0) return;
        self (n - 1, a, c, b, self);
        cout << a << ' ' << c << endl;
        self (n - 1, b, a, c, self);
    };

    char a = 'A', b = 'B', c = 'C';
    hanoi (n, a, b, c, hanoi);                                            
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