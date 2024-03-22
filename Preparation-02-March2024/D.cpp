#include <iostream>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <vector>
#include <map>

#define F first
#define S second

using namespace std;

vector <pair <int, char > > finalList;
map <char, vector <string > > ans;
map <string, int > pot;
vector <string > potList[10];

unordered_map <string, pair <int, string > > mp {
        {"Russia", {65, "UEFA"}},
        {"Spain", {8, "UEFA"}},
        {"Denmark", {19, "UEFA"}},
        {"Serbia", {38, "UEFA"}},
        {"Germany", {1, "UEFA"}},
        {"Peru", {10, "CONMEBOL"}},
        {"Iceland", {21, "UEFA"}},
        {"Nigeria", {41, "CAF"}},
        {"Brazil", {2, "CONMEBOL"}},
        {"Switzerland", {11, "UEFA"}},
        {"Costa Rica", {22, "CONCACAF"}},
        {"Australia", {43, "AFC"}},
        {"Portugal", {3, "UEFA"}},
        {"England", {12, "UEFA"}},
        {"Sweden", {25, "UEFA"}},
        {"Japan", {44, "AFC"}},
        {"Argentina", {4, "CONMEBOL"}},
        {"Colombia", {13, "CONMEBOL"}},
        {"Tunisia", {28, "CAF"}},
        {"Morocco", {48, "CAF"}},
        {"Belgium", {5, "UEFA"}},
        {"Mexico", {16, "CONCACAF"}},
        {"Egypt", {30, "CAF"}},
        {"Panama", {49, "CONCACAF"}},
        {"Poland", {6, "UEFA"}},
        {"Uruguay", {17, "CONMEBOL"}},
        {"Senegal", {32, "CAF"}},
        {"South Korea", {62, "AFC"}},
        {"France", {7, "UEFA"}},
        {"Croatia", {18, "UEFA"}},
        {"Iran", {34, "AFC"}},
        {"Saudi Arabia", {63, "AFC"}}
};

bool dfs(int I, int J) {

    string name = potList[I][J];

    if (I == 4 && J == 7) {
        for (char c = 'A'; c <= 'H'; c++)
            if (ans[c].size() < 4) {
                int cnt = 0, sw = 0;
                for (auto s: ans[c]) {
                    if (pot[s] == pot[name])
                        sw = 1;
                    if (mp[s].S == mp[name].S)
                        cnt++;
                }
                if (sw)
                    continue;
                if (cnt < 1 || (cnt < 2 && mp[name].S == "UEFA")) {
                    ans[c].push_back(name);
                    return true;
                }
            }
        return false;
    }

    for (char c = 'A'; c <= 'H'; c++) {
        if (ans[c].size() == 4)
            continue;
        int cnt = 0, sw = 0;
        for (auto s: ans[c]) {
            if (pot[s] == pot[name])
                sw = 1;
            if (mp[s].S == mp[name].S)
                cnt++;
        }
        if (sw)
            continue;
        if (cnt < 1 || (cnt < 2 && mp[name].S == "UEFA")) {
            ans[c].push_back(name);
            int nextI = I, nextJ = J + 1;
            if (nextJ == 8) nextI++, nextJ = 0;
            if (dfs(nextI, nextJ))
                return true;
            ans[c].pop_back();
        }
    }

    return false;
}

void solve() {
    char c = 'A';
    for (auto s: potList[1])
        ans[c++].push_back(s);
    dfs(2, 0);
    for (char c = 'A'; c <= 'H'; c++) {
        int res = 0;
        for (auto s: ans[c])
            res += mp[s].F;
        finalList.emplace_back(res, c);
    }
    sort(finalList.begin(), finalList.end());
    for (auto p: finalList)
        cout << p.S << ' ' << p.F << endl;
}

int main() {
    string s;
    cin >> s;
    int potNum = 1, potConut = 0;
    while (s != "End") {
        if (s == "Saudi" || s == "South" || s == "Costa") {
            string t;
            cin >> t;
            s += ' ';
            s += t;
        }
        if (*(s.end() - 1) == ',')
            s.erase(s.size() - 1);
        potConut++;

        pot[s] = potNum;
        potList[potNum].push_back(s);

        if (potConut == 8)
            potNum++, potConut = 0;

        if (potNum == 5) {
            solve();
            potNum = 1;
            ans.clear();
            finalList.clear();
            for (int i = 1; i < 5; i++)
                potList[i].clear();
        }

        cin >> s;
    }
}
