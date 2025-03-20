#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000;

struct edge {
    int u, v;
    int w;

    edge(int _u, int _v, int _w){
        u = _u;
        v = _v;
        w = _w;
    }
};

int n, m; // n dinh, m canh
int parent[maxn], sz[maxn];
vector<edge> canh;

//Disjoint set de kiem tra trung lap
void make_set() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = i;
    }
}

int find(int v) {
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}


bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a==b) return false; // a, b trung nhau, khong gop vao duoc
    if(sz[a] < sz[b] ) swap(a,b);
    parent[b] = a;
    sz[a] + sz[b];
    return true;
}


void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        edge e = edge(x, y, w);
        canh.push_back(e);
    }
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}
void kruskal() {
    // tao cay
    vector<edge> mst;
    int d = 0;
    //sort
    sort(canh.begin(), canh.end(), cmp);

    //Loop
    for(int i = 0; i < m; i++) {
        if(mst.size() == n - 1) break; // cay khung cuc tieu co n - 1 canh, da du
        edge e = canh[i]; // canh min

        // kiem tra disjoint set, khong tao thanh chu trinh'

        if(Union(e.u, e.v)) {   
                mst.push_back(e);
                d+= e.w;
        }   
    }

    if(mst.size() != n - 1) {
        cout << "khong ton tai";
    } else {
        cout << "MST :" << d << endl;
        for( auto it : mst){
            cout << it.u << " " << it.v << ' ' << it.w << endl;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input();
    make_set();
    kruskal();
    return 0;
}




