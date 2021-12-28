#include<bits/stdc++.h>
 
#define int long long
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
string sh(string s) {
    string res = "";
    res.push_back(s.back());
    res += s.substr(0, s.size() - 1);
    return res;
}
 
int32_t main() {
    string s; cin >> s;
    vector<string> a;
    for (int i = 0; i < s.size(); i++) {
        a.push_back(s = sh(s));
    }
     
    sort(all(a));
    for (auto e : a) cout << e.back();
     
    return 0;
}