#include <iostream>
using namespace std;

int calculateScore(int x) {
    if (x <= 10 * 10)
        return 10;
    if (x <= 30 * 30)
        return 9;
    if (x <= 50 * 50)
        return 8;
    if (x <= 70 * 70)
        return 7;
    if (x <= 90 * 90)
        return 6;
    if (x <= 110 * 110)
        return 5;
    if (x <= 130 * 130)
        return 4;
    if (x <= 150 * 150)
        return 3;
    if (x <= 170 * 170)
        return 2;
    if (x <= 190 * 190)
        return 1;
    return 0;
}

int main() {

    int n, sum = 0;
    cin >> n;

    while (n--) {

        int x, y;
        cin >> x >> y;

        sum += calculateScore(x * x + y * y);
    }

    cout << sum << endl;

    return 0;
}
