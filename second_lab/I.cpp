#include<bits/stdc++.h>
 
//#define int long long
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
int a[20][300000];
int cnt[300000];
string s;    
 
void encode() {
    string ans = "";
    int pw = 1, lg = 0, len = 0;
    for (int i = 0; i < s.size();) {
        if (ans.size() == pw - 1) {
            ans += "0", pw *= 2, len++;
            continue;
        }
        ans += s[i], i++, len++;
    }
    //cout << ans << "\n";
    lg = ceil(log2(pw));
    pw = 1;
    for (int j = 0; j < len; j++) for (int num = j + 1, i = 0; num > 0; a[i++][j] = num % 2, num /= 2);
    for (int i = 0; i < lg; i++) {
        int cur = 0;
        for (int j = 0; j < len; j++) {
            cur += (ans[j] - '0') * a[i][j];
            //cout << cur << "\n";
        }
        cnt[i] = cur; cnt[i] %= 2;
    }
     
    for (int i = 0; i < lg; i++) {
        ans[pw - 1] = (char)(cnt[i]+'0');
        pw *= 2;
    }
    cout << ans << "\n";
}
 
void decode() {
    int lg = ceil(log2(s.size())), cur = 1, pw = 1, len = s.size();
    //cout << len << "\n";
    vector<char> ss;
    //cout << s << "\n";
    for (auto e : s)
        ss.push_back(e);
    cur = 0;
    for (int j = 0; j < len; j++) {
        for (int num = j + 1, i = 0; num > 0; a[i++][j] = num % 2, num /= 2);
    }
    for (int i = 0; i < lg; i++) {
        int cur = 0;
        for (int j = 0; j < len; j++) {
            cur += (ss[j] - '0') * a[i][j];
            //cout << cur << "\n";
        }
        cnt[i] = cur; cnt[i] %= 2;
    }
    for (int i = 0; i < lg; i++) {
        cur += pw * cnt[i];
        pw *= 2;
    } pw = 1;
    if (!(int)(ss[cur - 1] - '0')) ss[cur - 1] = '1';
    else ss[cur - 1] = '0';
    string ans = "";
    for (int i = 0; i < ss.size(); i++) {
         
        if (i + 1 != pw) ans += ss[i];
        else pw *= 2;
        //cout << i << "\n";
    }
    cout << ans << "\n";
}
 
int32_t main() {
    memset(a, 0, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
    int t; cin >> t;
    cin >> s;
    if (t == 1) encode();
    else decode();
    return 0;
}