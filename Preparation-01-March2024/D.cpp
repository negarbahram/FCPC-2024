#include <iostream>
#include <string>
using namespace std;

const int N = 1e6 + 10;

int score[N][5];

int main() {
    int n;
    cin >> n;
    while (n) {
        for (int i = 0; i < N - 5; i++)
            for (int j = 0; j < 5; j++)
                score[i][j] = 0;
        for (int i = 0; i < n; i++) {
            int d;
            cin >> d;
            for (int j = 0, scr = 3; j < d; j++, scr--) {
                int id;
                cin >> id;
                score[id][0] += scr;
                score[id][scr]++;
            }
        }
        int mx = -500, cnt = 0, ans = -1;
        for (int i = 0; i < N - 5; i++)
            if (score[i][0] > mx)
                mx = score[i][0];
        for (int i = 0; i < N - 5; i++)
            if (score[i][0] == mx)
                cnt++, ans = i;
        if (cnt == 1)
            cout << ans << '\n';
        else {
            int mx2 = -500;
            cnt = 0, ans = -1;
            for (int i = 0; i < N - 5; i++)
                if (score[i][0] == mx && score[i][3] > mx2)
                    mx2 = score[i][3];
            for (int i = 0; i < N - 5; i++)
                if (score[i][0] == mx && score[i][3] == mx2)
                    cnt++, ans = i;
            if (cnt == 1)
                cout << ans << '\n';
            else {
                int mx3 = -500;
                cnt = 0, ans = -1;
                for (int i = 0; i < N - 5; i++)
                    if (score[i][0] == mx && score[i][3] == mx2 && score[i][2] > mx3)
                        mx3 = score[i][2];
                for (int i = 0; i < N - 5; i++)
                    if (score[i][0] == mx && score[i][3] == mx2 && score[i][2] == mx3)
                        cnt++, ans = i;
                if (cnt == 1)
                    cout << ans << '\n';
                else {
                    for (int i = 0; i < N - 5; i++)
                        if (score[i][0] == mx && score[i][3] == mx2 && score[i][2] == mx3)
                            cout << i << ' ';
                    cout << '\n';
                }
            }
        }
        cin >> n;
    }
    return 0;
}
