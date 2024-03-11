#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n) {
        if (n <= 1000000)
            cout << n << '\n';
        else if (n <= 5000000)
            cout << n - n / 10 << '\n';
        else
            cout << n - n / 5 << '\n';
        cin >> n;
    }
    return 0;
}
