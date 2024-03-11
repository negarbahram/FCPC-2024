// mamnoon az Team Cherry baraye code! :)

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool checkCHar(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_') || (c == '.') || (c >= '0' && c <= '9');
}

bool checkDChar(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '-') || (c == '.') || (c >= '0' && c <= '9');
}

bool checkNAme(string &str, int &loc) {
  char pre = '.';
  int len = 0;
  for (char &c: str) {
    if (checkCHar(c)) {
      if (c == '.' && pre == '.') {
        return false;
      } else if (c != '.') {
        len++;
      }
      if (c >= 'A' && c <= 'Z') {
        c += 32;
      }
      pre = c;
    } else if (c == '@') break;
    else return false;
  }
  if (str[loc - 1] == '.') return false;
  for (int i = 0; str[i] != '@'; i++) {
    if (str[i] == '.') {
      str.erase(i, 1);
      i--;
      loc--;
    }
  }
  return 6 <= len && len <= 30;
}

bool checkDomain(string &str, int loc) {
  size_t lent = str.length() - loc - 1;
  if (3 > lent || lent > 30)
    return false;
  char pre = '.';
  for (auto it = str.begin() + loc + 1; it != str.end(); it++) {
    if (checkDChar(*it)) {
      if (*it == '.' && pre == '.')
        return false;
      if (*it >= 'A' && *it <= 'Z')
        *it += 32;
      pre = *it;
    } else return false;
  }
  if (*(str.end() - 1) == '.') return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  set<string> list;
  string temp;
  cin >> temp;
  for (int j = 0; j < n; j++) {
    auto addLoc = temp.find('@');
    int loc = (int) addLoc;
    if (addLoc != string::npos) {
      bool c1 = checkNAme(temp, loc);
      bool c2 = checkDomain(temp, loc);
      if (c1 && c2) {
        list.insert(temp);
      }
    }
    if (j != n - 1) cin >> temp;
  }
  cout << list.size();
  return 0;
}
