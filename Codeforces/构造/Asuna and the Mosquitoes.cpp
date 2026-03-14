// 30 + ANS
    #include<bits/stdc++.h>
    #define int long long
    using namespace std;
    const int mod = 998244353;

    void ovo(){   
        int n; cin >> n;
        vector <int> od, os;
        od.reserve(n); os.reserve(n);

        int t; for (int i = 0; i < n; i ++) {
                cin >> t;
                if (t & 1) od.push_back(t);
                else os.push_back(t);
        }

        if (od.empty()) {
            cout << ranges :: max (os) << '\n';
        } else if (os.empty()) {
            cout << ranges :: max (od) << '\n';
        } else {
            int s1 = accumulate(od.begin(), od.end(), 0LL);
            int s2 = accumulate(os.begin(), os.end(), 0LL);
            cout << s1 + s2 - od.size() + 1 << '\n';
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