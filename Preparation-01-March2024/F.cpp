#include<bits/stdc++.h>
using namespace std;

int ans;
string s;
int mark[10][10];

bool check(int i, int j, int x) {
	for (int k1 = 0; k1 < 3; k1++) {
		for (int k2 = 0; k2 < 3; k2++) {
			mark[k1][k2] = 0;
		}
	}
	mark[i][j] = 1;
	for (int k = 0; k < s.size(); k++) {
		switch(s[k]) {
			case('U') :
				i--;
				mark[i][j]++;
				if (x & (1 << k)) {
					i--;
					if (i < 0) {
						return false;
					}
					mark[i][j]++;
				}
				break;
			
			case('D') :
				i++;
				mark[i][j]++;
				if (x & (1 << k)) {
					i++;
					mark[i][j]++;
				}
				break;

			case('R') :
				j--;
				mark[i][j]++;
				if (x & (1 << k)) {
					j--;
					if (j < 0) {
						return false;
					}
					mark[i][j]++;
				}
				break;
				
			case('L') :
				j++;
				mark[i][j]++;
				if (x & (1 << k)) {
					j++;
					mark[i][j]++;
				}
				break;
		}
		if (i < 0 || i > 2 || j < 0 || j > 2) {
			return false;
		}
	}
	for (int k1 = 0; k1 < 3; k1++) {
		for (int k2 = 0; k2 < 3; k2++) {
			if (mark[k1][k2] > 1) {
				return false;
			}
		}
	}
	return true;
}

int32_t main() {
	cin >> s;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++){
			for (int B = 0; B < (1 << (s.size())); B++) {
				ans += check(i, j, B);
			}
		}
	}
	cout << ans;
}


