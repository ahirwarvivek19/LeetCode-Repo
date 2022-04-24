class Solution {
private:
    int res;
    int n;
    void dfs(int i, int j, int cur, vector<bool> &vis, vector<vector<int>> &D) {
        if (i == 0) {
            res = max(res, cur);
            return;
        }
        for (; j < D.size(); ++j) {
            auto &v = D[j];
            if (vis[v[1]] || vis[v[2]]) continue;
            int ii = (i+1)*i/2;
            if (ii * v[0] + cur <= res) return;
            vis[v[1]] = vis[v[2]] = true;
            dfs(i-1, j + 1, cur + i*v[0], vis, D);
            vis[v[1]] = vis[v[2]] = false;
        }
    }
public:
    int maxScore(vector<int>& A) {
        n = A.size();
        vector<bool> vis(n);
        vector<vector<int>> D;
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                D.push_back({gcd(A[i], A[j]), i, j});
        sort(D.rbegin(), D.rend());
        res = 0;
        dfs(n/2, 0, 0, vis, D);
        return res;
    }
};