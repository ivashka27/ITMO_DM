#include<bits/stdc++.h>
 
#define int long long
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
int32_t main() {
    string s; cin >> s;
    string t = "";
    string buf = "";
    string alph = "abcdefghijklmnopqrstuvwxyz";
    int n = s.size();
    int l = 0;
    int r = 0;
    int ans = 0;
    vector<string> lzw;
    for (int i = 0; i < 26; i++) {
        string cur = "";
        cur.push_back(alph[i]);
        lzw.push_back(cur);
    }
     
    //for (auto e : lzw) cout << e << " ";
    //cout << "\n";
     
    for (;l < n;) {
        r = 0, buf = t + s[l];
        while (r < lzw.size() && lzw[r] != buf) r++;
        if (buf != lzw[r]) {
            cout << ans << " ";
            lzw.push_back(buf), t = "";
        } 
        else ans = r, t = lzw[r], l++;
    }
    cout << r;
     
    return 0;
}