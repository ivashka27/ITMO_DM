#include<bits/stdc++.h>
 
#define int long long
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
int32_t main() {
    string s; cin >> s;
    string alph = "abcdefghijklmnopqrstuvwxyz";
    int n = s.size();
     
    for (int i = 0; i < n; i++) {
        int pos = (int)alph.find(s[i]);
        cout << pos + 1 << " ";
        alph = alph[pos] + alph.substr(0, pos) + alph.substr(pos + 1); 
    }
     
    return 0;
}