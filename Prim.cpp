#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1000;
int p, e; // Số đỉnh và số cạnh
vector<pair<int, int>> list[maxn];
bool used[maxn]; // Đánh dấu đỉnh đã thuộc cây khung

void input() {
    cin >> p >> e;
    for (int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        list[x].push_back({y, w}); // Thêm cạnh x -> y
        list[y].push_back({x, w}); // Thêm cạnh y -> x (đồ thị vô hướng)
    }
    memset(used, false, sizeof(used)); // Đánh dấu tất cả các đỉnh là chưa dùng
}

struct Edge {
    int x, y, w;
};

void prim(int u) {
    vector<Edge> MST; // Cây khung nhỏ nhất
    int d = 0; // Tổng trọng số của cây khung
    used[u] = true;

    while (MST.size() < p - 1) {
        int minW = INT_MAX;
        int X, Y; // Hai đỉnh của cạnh được chọn

        for (int i = 1; i <= p; i++) {
            if (used[i]) {  // Duyệt các đỉnh đã thuộc cây khung
                for (pair<int, int> it : list[i]) {
                    int j = it.first, trongso = it.second;
                    if (!used[j] && trongso < minW) {
                        minW = trongso;
                        X = i; // Đỉnh đã thuộc MST
                        Y = j; // Đỉnh mới thêm vào MST
                    }
                }
            }
        }

        // Thêm cạnh vào cây khung
        MST.push_back({X, Y, minW});
        d += minW;
        used[Y] = true; // Đánh dấu đỉnh Y đã thuộc MST
    }

    // In kết quả
    cout << d << endl;
    for (Edge e : MST) {
        cout << e.x << " " << e.y << " " << e.w << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input();
    prim(1);
    return 0;
}
