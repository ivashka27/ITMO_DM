#include<bits/stdc++.h>
 
#define int long long
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
string ibwt(string r) {
    int len = r.size();
    vector<string> table(len);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            table[j] = r[j] + table[j];
        }
        sort(all(table));
    }
    return table[0];
}
 
int32_t main() {
    string s; cin >> s;
    cout << ibwt(s);
    return 0;
}