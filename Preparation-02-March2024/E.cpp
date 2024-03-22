#include <iostream>
using namespace std;

int calculate(int x) {
    int label = 0, res = 0;
    while (x) {
        int k = x % 10;
        if (label % 2)
            res += (k * 2) > 9? k * 2 - 9: k * 2;
        else
            res += k;
        x /= 10;
        label++;
    }
    return res;
}

int main() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    while (a || b || c || d) {

        int res = 0;
        res += calculate(a);
        res += calculate(b);
        res += calculate(c);
        res += calculate(d);

        cout << (!(res % 10)? "Yes": "No") << endl;

        cin >> a >> b >> c >> d;
    }
    return 0;
}
