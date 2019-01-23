#include <bits/stdc++.h>

using namespace std;

#define oo 1e5

// Đây là code tìm cây khung nhỏ nhất trong đồ thị liên thông sử dụng thuật toán Prim, chú ý là đồ thị phải liên thông nhé

int n, m, x, y, value;
vector<vector<pair<int, int> > > graph; // đồ thị lưu bằng danh sách kề
vector<pair<int, int> > MST;    // lưu cây khung
vector<bool> vis; // mảng đánh dấu với false là chưa xét, true là đã xét

void input() {
        cin >> n >> m;       // nhập số lượng đỉnh và số lượng cạnh
        graph.resize(n);
        vis.resize(n);
        MST.resize(n);
        for(int i = 0; i < n; i++) MST[i].second = oo;
        for(int i = 0; i < m; i++) {
                cin >> x >> y >> value;
                graph[x - 1].push_back(make_pair(y - 1, value));
                graph[y - 1].push_back(make_pair(x - 1, value));
        }
}

void prim() {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // hàng đợi ưu tiên để duyệt cạnh có trọng số thấp nhất
        pq.push(make_pair(0, 0));       // vì là đồ thị liên thông nên duyệt đỉnh nào cũng được, ta duyệt đỉnh 0 có trọng số là 0.
        MST[0] = make_pair(0,0);
        vis[0] = true;
        while(!pq.empty()) {    // lặp đến khi nào hàng đợi rỗng, có nghĩa là tất cả các cạnh đều được duyệt qua thì dừng
                int tmp = pq.top().second;      // lấy đỉnh trong đầu tiên trong hàng đợi ra gán vào biến tmp;
                vis[tmp] = true;        // đánh dấu đã xét hay là thêm vào cây khung đều được
                pq.pop();
                for(int i = 0; i < graph[tmp].size(); i++) {
                        int weight = graph[tmp][i].second;      // gán trọng số vào biến weight
                        int q = graph[tmp][i].first;            // gán đỉnh tiếp theo vào biến q
                        if(!vis[q] && MST[q].second > weight) {   // nếu đỉnh chưa xét và trọng số lớn hơn cạnh đang xét thì ta mới thao tác tiếp
                                pq.push(make_pair(weight, q));  // thêm cạnh vào hàng đợi
                                MST[q] = make_pair(tmp, weight);        // gán tạm giá trị vào cây khung.
                        }
                }
        }
}

void proceesed() {
        input();
        prim();
        for(int i = 1; i < n; i++) {
                cout << "Canh: " <<  i + 1  << " " << MST[i].first + 1 << " Trong so: " << MST[i].second << endl;
        }
}

int main() {
        proceesed();
        return 0;
}
