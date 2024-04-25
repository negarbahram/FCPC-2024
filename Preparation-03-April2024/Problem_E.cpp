#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=(int)a;i<=b;i++)
typedef long long llint;

const llint MOD = 1e9 + 7;
const int N = 2010;

int a[N], d, m, n;
int ten[N];
llint dp[N][N][2][2];

inline int isGood(string str){
    n = (int)str.size();
    REP(i, 0, n-1)
        a[n-i-1] = str[i] - '0';
    llint rem = 0;
    REP(i, 0, n-1){
        if (i % 2 == 0 && a[i] == d)
            return 0;
        rem = (rem + ten[i] * a[i]) % m;
    }
    return rem == 0 ? 1: 0;
}

inline llint go(int t, int rem, bool strictlyLess, bool nonZero){
    if (t == -1){
      //  if (nonZero == false && d == 0)
      //      return 0;
        return rem == 0 ? 1: 0;
    }

    llint& res = dp[t][rem][strictlyLess][nonZero];
    if (res != -1 && strictlyLess && nonZero)
        return res;
   // REP(i, 0, n-t-1) cout << "   ";
    //cout << "processing  " << t <<  "   ##  stricyly = " << strictlyLess << endl;
    res = 0;
    int newRem;

    if (strictlyLess){
        REP(cur, 0, 9){
            if (d != 0 && cur == d && t % 2 == 0)
                continue;
            if (d == 0 && cur == d && t % 2 == 0 && nonZero)
                continue;

            newRem = (rem + ten[t] * cur) % m;
            llint tmp = go(t-1, newRem, true, (cur > 0) || nonZero);
            res += tmp;
            //    REP(i, 0, n-t) cout << "   ";
            //    cout << "digit = " << cur << "  --> " << tmp << endl;
            if (res >= MOD) res -= MOD;
        }
    }
    else {
        REP(cur, 0, a[t]-1){
            if (d != 0 && cur == d && t % 2 == 0)
                continue;
            if (d == 0 && cur == d && t % 2 == 0 && nonZero)
                continue;

            newRem = (rem + ten[t] * cur) % m;
            res += go(t-1, newRem, true, (cur > 0) || nonZero);
            if (res >= MOD) res -= MOD;
        }
        if (d != 0 && a[t] == d && t % 2 == 0)
            return res;
        if (d == 0 && a[t] == d && t % 2 == 0 && nonZero)
            return res;
       //         REP(i, 0, n-t-1) cout << "   ";
      //  cout << t << "-th digit is equal to " << a[t] << endl;
        newRem = (rem + ten[t] * a[t]) % m;
        res += go(t-1, newRem, false, (a[t] > 0) || nonZero);
        if (res >= MOD) res -= MOD;
    }
     //   REP(i, 0, n-t-1) cout << "   ";

  /*  cout << "dp[" << t << "][" << rem << "] =  " << dp[t][rem] << endl;
        REP(i, 0, n-t-1) cout << "   ";

    cout << "end of " << t << endl;
    */
    return res;
}

inline llint calc(string str){
  //  cout << endl << "cacl  " << str << endl;
    n = (int)str.size();
    REP(i, 0, n-1)
        a[n-i-1] = str[i] - '0';
    return go(n-1, 0, false, false);
}

int main(){
    memset(dp, -1, sizeof dp);
    ios_base::sync_with_stdio(0);
    string strL, strR;
    cin >> strL >> strR >> d >> m;

    ten[0] = 1 % m;
    REP(i, 1, N-1)
        ten[i] = (ten[i-1] * 10) % m;

    llint ans = (calc(strR) - calc(strL) + isGood(strL) + MOD) % MOD;  // change to test strength of tests
    cout << ans << endl;

    return 0;
}

