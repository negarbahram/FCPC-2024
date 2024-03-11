#include<bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
 
#define mp make_pair
#define pb push_back
#define in insert
#define ers erase
#define S second
#define F first

const int N = 1e2 + 5;
const int inF = 1e9 + 7;
int n, x[2 * N], y[2 * N], z[N], xCnt, yCnt, zCnt, dist[4 * N * N * N];
bool availablePoints[4 * N * N * N], vis[4 * N * N * N];
set<int> xPoints, yPoints, zPoints;
int adj[4 * N * N * N][10];
set<pii> q;

class point {
    public:
    int x, y, z;
} stPoint, enPoint;

class building {
    public:
    point westSouth, eastNorth;
} buildings[N];

void read_input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> buildings[i].westSouth.x >> buildings[i].westSouth.y;
        cin >> buildings[i].eastNorth.x >> buildings[i].eastNorth.y;
        cin >> buildings[i].westSouth.z;
        buildings[i].eastNorth.z = buildings[i].westSouth.z;
    }
    
    cin >> stPoint.x >> stPoint.y >> stPoint.z;
    cin >> enPoint.x >> enPoint.y >> enPoint.z;
}

void sortPoints() {
    for (int i = 0; i < n; i++) {
        xPoints.in(buildings[i].westSouth.x);
        xPoints.in(buildings[i].eastNorth.x);
        
        yPoints.in(buildings[i].westSouth.y);
        yPoints.in(buildings[i].eastNorth.y);
        
        zPoints.in(buildings[i].westSouth.z);
    }
    
    xPoints.in(stPoint.x);
    xPoints.in(enPoint.x);
    
    yPoints.in(stPoint.y);
    yPoints.in(enPoint.y);
    
    zPoints.in(stPoint.z);
    zPoints.in(enPoint.z);
    zPoints.in(0);
    
    for (auto p : xPoints) {
        x[xCnt] = p;
        xCnt++;
    }
    
    for (auto p : yPoints) {
        y[yCnt] = p;
        yCnt++;
    }
    
    for (auto p : zPoints) {
        z[zCnt] = p;
        zCnt++;
    }
}

int convertX(int xOfBuilding) {
    int l = 0, r = xCnt;
    
    while(r - l > 1) {
        int mid = (l + r) / 2;
        x[mid] > xOfBuilding? r = mid : l = mid;
    }
    
    return l;
}

int convertY(int yOfBuilding) {
    int l = 0, r = yCnt;
    
    while(r - l > 1) {
        int mid = (l + r) / 2;
        y[mid] > yOfBuilding? r = mid : l = mid;
    }
    
    return l;
}

int convertZ(int zOfBuilding) {
    int l = 0, r = zCnt;
    
    while(r - l > 1) {
        int mid = (l + r) / 2;
        z[mid] > zOfBuilding? r = mid : l = mid;
    }
    
    return l;
}

void convertPoints() {
    for (int i = 0; i < n; i++) {
        buildings[i].westSouth.x = convertX(buildings[i].westSouth.x);
        buildings[i].eastNorth.x = convertX(buildings[i].eastNorth.x);
        
        buildings[i].westSouth.y = convertY(buildings[i].westSouth.y);
        buildings[i].eastNorth.y = convertY(buildings[i].eastNorth.y);
        
        buildings[i].westSouth.z = convertZ(buildings[i].westSouth.z);
        buildings[i].eastNorth.z = buildings[i].westSouth.z;
    }
    
    stPoint.x = convertX(stPoint.x);
    enPoint.x = convertX(enPoint.x);
    
    stPoint.y = convertY(stPoint.y);
    enPoint.y = convertY(enPoint.y);
    
    stPoint.z = convertZ(stPoint.z);
    enPoint.z = convertZ(enPoint.z);
}

void determineAvailablePoints() {
    memset(availablePoints, 1, sizeof (availablePoints));
    
    for (int i = 0; i < n; i++) {
        int x1 = buildings[i].westSouth.x, x2 = buildings[i].eastNorth.x;
        int y1 = buildings[i].westSouth.y, y2 = buildings[i].eastNorth.y;
        int z1 = buildings[i].westSouth.z;
        
        for (int ix = x1 + 1; ix < x2; ix++)
            for (int iy = y1 + 1; iy < y2; iy++)
                for (int iz = 0; iz < z1; iz++) {
                    int node = xCnt * yCnt * iz + yCnt * ix + iy;
                    availablePoints[node] = 0;
                }
    }
}

void makeEdge() {
    memset(adj, inF, sizeof (adj));
    
    for (int ix = 0; ix < xCnt; ix++)
        for (int iy = 0; iy < yCnt; iy++)
            for (int iz = 0; iz < zCnt; iz++) {
                int node = xCnt * yCnt * iz + yCnt * ix + iy;
                
                if (availablePoints[node]) {
                    if (iz > 0) 
                        if (availablePoints[node - xCnt * yCnt]) {
                            adj[node][0] = z[iz] - z[iz - 1];
                        }
                        else adj[node][0] = inF;
                    
                    if (iz < zCnt - 1) 
                        if (availablePoints[node + xCnt * yCnt]) {
                            adj[node][1] = z[iz + 1] - z[iz];
                        }
                        else adj[node][1] = inF;
                    
                    if (ix > 0)
                        if (availablePoints[node - yCnt]) {
                            adj[node][2] = x[ix] - x[ix - 1];
                        }
                        else adj[node][2] = inF;
                        
                    if (ix < xCnt - 1) 
                        if (availablePoints[node + yCnt]) {
                            adj[node][3] = x[ix + 1] - x[ix];
                        }
                        else adj[node][3] = inF;
                        
                    if (iy > 0)
                        if (availablePoints[node - 1]) {
                            adj[node][4] = y[iy] - y[iy - 1];
                        }
                        else adj[node][4] = inF;
                        
                    if (iy < yCnt - 1)
                        if (availablePoints[node + 1]) {
                            adj[node][5] = y[iy + 1] - y[iy];
                        }
                        else adj[node][5] = inF;
                }
                else 
                    for (int i = 0; i < 6; i++)
                        adj[node][i] = inF;
            }
}

void deleteEdge() {
    for (int i = 0; i < n; i++) {
        
        int x1 = buildings[i].westSouth.x, x2 = buildings[i].eastNorth.x;
        int y1 = buildings[i].westSouth.y, y2 = buildings[i].eastNorth.y;
        int z1 = buildings[i].westSouth.z;
        
        for (int ix = x1 + 1; ix <= x2 - 1; ix++)
            for (int iy = y1 + 1; iy <= y2 - 1; iy++)
                for (int iz = 1; iz <= z1 - 1; iz++) {
                    int node = xCnt * yCnt * iz + yCnt * ix + iy;
                    for (int i = 0; i < 6; i++)
                        adj[node][i] = inF;
                }
        
        for (int ix = x1 + 1; ix <= x2 - 1; ix++)
            for (int iy = y1 + 1; iy <= y2 - 1; iy++) {
                int node = xCnt * yCnt * z1 + yCnt * ix + iy;
                adj[node][0] = inF;
            }
            
        for (int ix = x1 + 1; ix <= x2 - 1; ix++)
            for (int iy = y1 + 1; iy <= y2 - 1; iy++) {
                int node = xCnt * yCnt * 0 + yCnt * ix + iy;
                adj[node][1] = inF;
            }
            
        for (int iy = y1 + 1; iy <= y2 - 1; iy++)
            for (int iz = 0; iz <= z1 - 1; iz++) {
                int node = xCnt * yCnt * iz + yCnt * x2 + iy;
                adj[node][2] = inF;
            }
            
        for (int iy = y1 + 1; iy <= y2 - 1; iy++)
            for (int iz = 0; iz <= z1 - 1; iz++) {
                int node = xCnt * yCnt * iz + yCnt * x1 + iy;
                adj[node][3] = inF;
            }
        
        for (int ix = x1 + 1; ix <= x2 - 1; ix++)
            for (int iz = 0; iz <= z1 - 1; iz++) {
                int node = xCnt * yCnt * iz + yCnt * ix + y2;
                adj[node][4] = inF;
            }
            
        for (int ix = x1 + 1; ix <= x2 - 1; ix++)
            for (int iz = 0; iz <= z1 - 1; iz++) {
                int node = xCnt * yCnt * iz + yCnt * ix + y1;
                adj[node][5] = inF;
            }
    }
}
 
void dijkstra() {
    int stNode = xCnt * yCnt * stPoint.z + yCnt * stPoint.x + stPoint.y;
    
    memset(dist, inF, sizeof (dist));
    dist[stNode] = 0;
    q.in(pii(0, stNode));
            
    while(!q.empty()) {
        
		set<pii> :: iterator it = q.begin();
		int u = it->second;
		q.ers(it);
		vis[u] = true;
	
	    int v = u - xCnt * yCnt;
		if (!vis[v]) 
		    if (dist[v] > dist[u] + adj[u][0]) {
		        if (dist[v] < inF)
		            q.ers(pii(dist[v], v));
		        dist[v] = dist[u] + adj[u][0];
		        q.in(pii(dist[v], v));
		    }
		    
		v = u + xCnt * yCnt;
		if (!vis[v]) 
		    if (dist[v] > dist[u] + adj[u][1]) {
		        if (dist[v] < inF)
		            q.ers(pii(dist[v], v));
		        dist[v] = dist[u] + adj[u][1];
		        q.in(pii(dist[v], v));
		    }
		    
		v = u - yCnt;
		if (!vis[v]) 
		    if (dist[v] > dist[u] + adj[u][2]) {
		        if (dist[v] < inF)
		            q.ers(pii(dist[v], v));
		        dist[v] = dist[u] + adj[u][2];
		        q.in(pii(dist[v], v));
		    }
		    
	    v = u + yCnt;
		if (!vis[v]) 
		    if (dist[v] > dist[u] + adj[u][3]) {
		        if (dist[v] < inF)
		            q.ers(pii(dist[v], v));
		        dist[v] = dist[u] + adj[u][3];
		        q.in(pii(dist[v], v));
		    }
	    
	    v = u - 1;
		if (!vis[v]) 
		    if (dist[v] > dist[u] + adj[u][4]) {
		        if (dist[v] < inF)
		            q.ers(pii(dist[v], v));
		        dist[v] = dist[u] + adj[u][4];
		        q.in(pii(dist[v], v));
		    }
		    
	    v = u + 1;
		if (!vis[v]) 
		    if (dist[v] > dist[u] + adj[u][5]) {
		        if (dist[v] < inF)
		            q.ers(pii(dist[v], v));
		        dist[v] = dist[u] + adj[u][5];
		        q.in(pii(dist[v], v));
		    }
	}
}

void solve() {
    sortPoints();
    convertPoints();
    determineAvailablePoints();
    makeEdge();
    deleteEdge();
    dijkstra();
    debug();
}

void output() {
    int enNode = xCnt * yCnt * enPoint.z + yCnt * enPoint.x + enPoint.y;
    cout << dist[enNode] << '\n';
}

int main() {
    read_input();
    solve();
    output();
    return 0;
}