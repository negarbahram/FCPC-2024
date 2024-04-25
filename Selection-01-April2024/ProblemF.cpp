#include <bits/stdc++.h>
using namespace std;

ifstream fin("team.in");
ofstream fout("team.out");

const int mod = 1e9 + 9;
const int kN = 1e3;
const int kK = 10;
int a[1 + kN], b[1 + kN], sum[1 + kK][1 + kN][1 + kN], sum2[1 + kK][1 + kN][1 + kN];
void addSelf(int &x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
}

int add(int x, int y) {
  addSelf(x, y);
  return x;
}

void testCase() {
  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 1; i <= N; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + N + 1);
  for (int i = 1; i <= M; ++i) {
    cin >> b[i];
  }
  sort(b + 1, b + M + 1);
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      int dp = 0;
      if (b[j] < a[i]) {
        dp = 1;
      }
      sum[1][i][j] = add(sum[1][i][j - 1], dp);
      sum2[1][i][j] = add(sum2[1][i - 1][j], sum[1][i][j]);
    }
  }
  for (int k = 2; k <= K; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= M; ++j) {
        int dp = 0;
        if (b[j] < a[i]) {
          dp = sum2[k - 1][i - 1][j - 1];
        }
        sum[k][i][j] = add(sum[k][i][j - 1], dp);
        sum2[k][i][j] = add(sum2[k][i - 1][j], sum[k][i][j]);
      }
    }
  }
  int ans = 0;
  for (int i = K; i <= N; ++i) {
    addSelf(ans, sum[K][i][M]);
  }
  cout << ans;
}

int main() {
  int tests = 1;
  for (int tc = 0; tc < tests; ++tc) {
    testCase();
  }
  fin.close();
  fout.close();
  return 0;
}
