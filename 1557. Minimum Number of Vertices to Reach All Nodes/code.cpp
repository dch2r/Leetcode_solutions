class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      vector<int> nodes(n, 0);
        for (auto e : edges) ++nodes[e[1]];
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (nodes[i] == 0)
                ans.push_back(i);
        return ans;  
    }
};
