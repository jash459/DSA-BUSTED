#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
class Solution {
  int limit; 
  string suff; 
  ll dp[16][2][2]; 
public:
  ll get(int ci, bool is_last, bool valid, string &s) {
    int sz = (int) s.size(); 
    int suff_sz = (int) suff.size(); 
    if (sz < suff_sz) {
      return 0LL; 
    }
    if (ci == sz) {
      return ll(valid);
    }
    ll &ans = dp[ci][is_last][valid]; 
    if (ans != -1LL) return ans; 
    ans = 0LL; 
    int till = (is_last ? s[ci] - '0' : limit); 
    for (int i = 0; i <= till; i++) {
      bool is_valid = (sz - ci <= suff_sz ? i == suff[suff_sz - (sz - ci)] - '0' : true); 
      ans += get(ci + 1, is_last && (i == till), valid && is_valid && i <= limit, s); 
    }
    return ans; 
  }
  ll solve(ll n) {
    string s = to_string(n); 
    memset(dp, -1LL, sizeof(dp)); 
    return get(0, true, true, s); 
  }
  ll numberOfPowerfulInt(ll start, ll finish, int limit, string s) {
    this -> suff = s; 
    this -> limit = limit; 
    return solve(finish) - solve(start - 1);   
  }
};
