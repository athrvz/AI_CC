#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>
#define vvi vector <vi>
#define rep(i, a, n) for(int i = a; i < n; i++)

bool isSafe(int row, int col, vvi & b) {
    int r = row, c = col, n = b.size();
    while(c--) {
        if(b[r][c] == 1) return false;
    }
    c = col;
    while(r-- && c--) {
        if(b[r][c] == 1) return false;
    }
    r = row; c = col;
    while(r < n && c--) {
        if(b[r][c] == 1) return false;
    }
    return true;
}

bool NQueens(int col, vvi & board) {
    if(col == board.size()) 
        return 1;
        
    rep(row, 0, board.size()) {
        if(isSafe(row, col, board)) {
            board[row][col] = 1;
            bool flag = NQueens(col + 1, board);
            if(flag) return 1;
            board[row][col] = 0;
        }
    }
    return 0;
}

void print(vvi & mat) {
    rep(i, 0, mat.size()) {
        rep(j, 0, mat.size()) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    vvi board(n, vi(n, 0));
    bool flag = NQueens(0, board);
    print(board);
    cout << flag << endl;
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int getH(vvi & curr, vvi final, int n, int m) {
    int count = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(curr[i][j] != final[i][j]) count++;
        }
    }
    
    return count;
}

vector <pair<int,int>> dir = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

bool inside(int i, int j, int n, int m) {
    return ((i >= 0 && i < n) && (j >= 0 && j < m));
}

void Astar(vvi & curr, vvi & final, int i, int j, int n, int m, int & H, int & minH) {
    H = getH(curr, final, n, m);
    if(H == 0 || H > minH) 
        return;
    minH = H;
    
    for(auto p : dir) {
        int newi = i + p.first, newj = j + p.second;
        if(inside(i, j, n, m)) {
            swap(curr[i][j], curr[newi][newj]);
            Astar(curr, final, newi, newj, n, m, H, minH);
            if(H == 0) 
                return;
            swap(curr[i][j], curr[newi][newj]);
        }
    }
}

void print(vvi & mat) {
    rep(i, 0, mat.size()) {
        rep(j, 0, mat.size()) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vvi start = {
        {1, 2, 3},
        {0, 4, 5},
        {6, 7, 8}
    };
    vvi final = {
        {1, 2, 0},
        {4, 5, 3},
        {6, 7, 8}
    };
    
    int n = final.size(), m = final[0].size();
    
    int H = getH(start, final, n, m);
    int minH = H;
    
    int x, y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
            if(start[i][j] == 0) {
                x = i; y = j;
            }
    }
    
    Astar(start, final, x, y, n, m, H, minH);
    
    print(start);
    
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////

void bfs(int node, vi & vis, vvi & graph) {
    if(vis[node] == 1) return;
    queue <int> q;
    q.push(node);
    
    while(!q.empty()) {
        int k = q.size();
        while(k--) {
            int curr = q.front(); q.pop();
            vis[curr] = 1;
            cout << curr << " ";
            for(int adj : graph[curr])
                if(vis[adj] == 0) 
                    q.push(adj);
        }
        cout << endl;
    }
}


void dfs(int node, vi & vis, vvi & graph) {
    if(vis[node] == 0) {
        vis[node] = 1;
        
        for(int adj : graph[node])
            if(vis[adj] == 0) 
                dfs(adj, vis, graph);
        
        cout << node << " ";
    }
}

int main() {
    vvi graph = {
        {1, 2},
        {0},
        {0}
    };
    
    vi vis(3, 0);
    for(int i = 0; i < 3; i++) {
        // dfs(i, vis, graph);
        bfs(i, vis, graph);
    }
    
    return 0;
}