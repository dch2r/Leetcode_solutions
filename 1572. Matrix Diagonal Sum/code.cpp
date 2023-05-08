class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
         int N = mat.size(), sum = 0;
        for (int i = 0; i < N; ++i) sum += i == N - i - 1 ? mat[i][i] : (mat[i][i] + mat[N - i - 1][i]);
        return sum;
    }
};
