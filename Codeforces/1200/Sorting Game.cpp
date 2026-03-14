#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n;  cin >> n;
    string s, t;   cin >> s;
    t = s;  ranges :: sort (t);
    
    if (s == t) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
            vector <int> p;  p.reserve(n);

        for (int i = 0; i < n;  i++) {
            if (s[i] != t[i]) {
                p.push_back(i + 1);
            }
        }

        cout << p.size() << endl;
        for (int & i : p)  cout << i << ' ';
        cout << endl;
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