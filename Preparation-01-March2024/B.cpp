#include <iostream>
using namespace std;

int main() {
    int m, n, a[20], b[120][20];
    cin >> m >> n;
    while (m || n) {
        for (int i = 0; i < m; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> b[i][j];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int sw = 1;
            for (int j = 0; j < m && sw; j++)
                if (b[i][j] > a[j])
                    sw = 0;
            cnt += sw;
        }
        cout << cnt << '\n';
        cin >> m >> n;
    }
    return 0;
}
