
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k;
    cin >> n >> k;
    
    vector <int> a (n);
    set <int> st;
    unordered_map <int, int> mp;
    for (int & i : a) {
        cin >> i;
        st.insert(i);
        mp[i] ++;
    }
    
    vector <int> b;
    b.reserve(n);
    while (!st.empty()) {
        int x = *st.begin();
        for (int i = x; i <= k; i += x) {
            auto it = st.find(i);
            if (it == st.end()) {
                if (mp[i]) continue;
                cout << -1 << '\n';
                return;
            } else {
                st.erase(it);
            }
        }
        b.push_back(x);
    }

    cout << b.size() << '\n';
    for (int i = 0; i < b.size(); i ++) {
        cout << b[i] << " \n"[i == b.size() - 1];
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}