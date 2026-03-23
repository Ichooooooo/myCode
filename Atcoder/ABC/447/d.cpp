
    #include<bits/stdc++.h>
    #define int long long
    using namespace std;
    const int mod = 998244353;

    void ovo(){   
        string s;  cin >> s;
        int n = s.size();
        set <int> st;
        for (int i = 0; i < n; i ++) {
            if (s[i] == 'C') st.insert(i);
        }

        int cnt = 0, na = 0;
        for (int i = 0; i < n; i ++) {
            if (s[i] == 'A') na ++;
            else if (s[i] == 'B') {
                auto p = st.upper_bound(i);
                if (na > 0 && p != st.end()) {
                    cnt ++;
                    na --;
                    st.erase(p);
                }
            }
        }

        cout << cnt << '\n';
        
    }

    signed main(){
        ios::sync_with_stdio(false); cin.tie(0);
        int _=1;
        // cin>>_;

        while(_--)  ovo();  return 0;
    }