#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e2 + 10, MOD = 1e9 + 7;
int n, m, k, adam, fire;
string grid[N];
bool visited[N][N];
int seen[N][N];

int indx[8] = {-1, +1, 0, 0, -1, +1, -1, +1};
int indy[8] = {0, 0, -1, +1, +1, +1, -1, -1};

class QItem {
public:
    int row;
    int col;
    int dist;
    QItem(int x, int y, int w)
        : row(x), col(y), dist(w)
    {
    }
};

vector<QItem> v;

int bfs_adam(QItem source) {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
	
	queue<QItem> q;
    q.push(source);
    visited[source.row][source.col] = true;
    
	while (!q.empty()) {
        QItem p = q.front();
        q.pop();
        if (grid[p.row][p.col] == 't') return p.dist;
        
 		for (int i = 0; i < 4; i++) {
 			if (p.row + indx[i] >= 0 && p.row + indx[i] < n && p.col + indy[i] >= 0 && p.col + indy[i] < m && visited[p.row + indx[i]][p.col + indy[i]] == false && seen[p.row + indx[i]][p.col + indy[i]] > p.dist + 1) {
	            q.push(QItem(p.row + indx[i], p.col + indy[i], p.dist + 1));
	            visited[p.row + indx[i]][p.col + indy[i]] = true;
	        }
		}
		
    }
    return 1e9 + 1;
}

int bfs_atash(QItem source) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
	seen[source.row][source.col] = 0;
	
	queue<QItem> q;
    q.push(source);
    visited[source.row][source.col] = true;
	while (!q.empty()) {
        QItem p = q.front();
        q.pop();
        if (grid[p.row][p.col] == 't')
            return p.dist;
 
 
 		for (int i = 0; i < 8; i++) {
 			if (p.row + indx[i] >= 0 && p.row + indx[i] < n && p.col + indy[i] >= 0 && p.col + indy[i] < m && visited[p.row + indx[i]][p.col + indy[i]] == false) {
	            q.push(QItem(p.row + indx[i], p.col + indy[i], p.dist + k));
	            visited[p.row + indx[i]][p.col + indy[i]] = true;
	            seen[p.row + indx[i]][p.col + indy[i]] = min(seen[p.row + indx[i]][p.col + indy[i]], p.dist + k);
	        }
		}
    }
}

void read_input() {
	v.clear();
	fire = 1e9;
	adam = 0;
	QItem source1(0, 0, 0);

	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		for (int j = 0; j < m; j++) {
			
			visited[i][j] = 0;
			seen[i][j] = 1e9;
			if (grid[i][j] == 's') {
				source1.row = i;
                source1.col = j;
			}
			if (grid[i][j] == 'f') {
				
				QItem source2(0, 0, 0);
				source2.row = i;
				source2.col = j;
				v.pb(source2);
			}
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		fire = min(fire, bfs_atash(v[i]));
	}
	
	adam = bfs_adam(source1);
	if (fire <= adam) {
		cout << "Impossible\n";
	}
	else {
		cout << adam << '\n';
	}
	
}

int32_t main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while(true) {
		cin >> n >> m >> k;
		if (!n && !m && !k) {
			return 0;
		}
		read_input();
		
	}
	return 0;
}
