#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 100 + 20;

int main() {

    int n;
    pair <int, int > time[N];
    cin >> n;

    for (int i = 0; i < n; i++) {

        string s;
        cin >> s;

        string h = "", min = "";
        int j = 0;
        while (s[j] != ':')
            h += s[j++];
        while (s[++j])
            min += s[j];
        time[i].first = stoi(h);
        time[i].second = stoi(min);
    }

    sort(time, time + n);

    pair <int, int > start = {6, 30};
    pair <int, int > end = {19, 0};

    pair <int, int > first, last;

    int i = 0;
    while (i < n && time[i] < start)
        i++;

    if (i == n) {
        cout << 0 << endl;
        return 0;
    }


    int j = n - 1;
    while (~j && time[j] > end)
        j--;

    if (j == -1) {
        cout << 0 << endl;
        return 0;
    }

    if (i > j) {
        cout << 0 << endl;
        return 0;
    }

    first = time[i], last = time[j];

    pair <int, int > ten = {10, 0};

    if (first <= ten) {
        pair <int, int > sixteen = {16, 0};

        if (last <= sixteen)
            cout << 24000 << endl;
        else
            cout << 36000 << endl;

        return 0;
    }

    pair <int, int > sixteen = {16, 0};

    if (last <= sixteen)
        cout << 16800 << endl;
    else
        cout << 24000 << endl;

    return 0;
}
