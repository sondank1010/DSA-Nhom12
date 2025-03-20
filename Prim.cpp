#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h> // Added for INT_MAX
using namespace std;

const int maxn = 1000;
int p, e; // p dinh, e canh

vector<pair<int, int>> list[maxn];
bool used[maxn]; // Danh dau xem dinh do co thuoc tap cay khung khong

void input() {
    cin >> p >> e;
    for(int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        list[x].push_back({y, w}); // Them vao 1 dinh va trong so w
        list[y].push_back({x, w}); // Ensure the graph is undirected
    }
    memset(used, false, sizeof(used)); // false cho cac dinh
}   

struct Edge {
    int x, y, w;
};

void prim(int u) {
    vector<Edge> MST; // cay khung
    int d = 0 ; // do dai
    used[u] = true;

    while(MST.size() < p - 1) {
        int minW = INT_MAX;
        int X = -1, Y = -1; // Initialize properly

        for(int i = 1; i <= p ;i++) {
            if(used[i] == true) {
                // duyet list
                for(pair<int, int> it : list[i]) {
                    int j = it.first, trongso = it.second;
                    if(!used[j] && trongso < minW) {
                        minW = trongso;
                        X = j; 
                        Y = i;
                    }
                }
            }
        }

        // Ensure a valid edge is found
        if (X == -1 || Y == -1) break; 

        MST.push_back({X, Y, minW});
        d += minW;
        used[X] = true; // cho dinh X vao V(MST), delete X ra khoi V
    }

    cout << d << endl;
    for (Edge e : MST)
        cout << e.x << " " << e.y << " " << e.w << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input();
    prim(1);
}
