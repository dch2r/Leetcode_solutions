class Solution {
public:
    string s, p;
    vector<vector<int>> memo;
    
    bool dfs(int i, int j){
        if(j == p.size()) return i == s.size();
        
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        
        if(i == s.size()){
            if((p.size()-j) % 2 != 0) return false;
            for(int k = j+1; k < p.size(); k+=2){
                if(p[k] != '*') return false;
            }
            return true;
        }
        
        bool first_match = (p[j] == '.' || p[j] == s[i]);
        
        if(j+1 < p.size() && p[j+1] == '*'){
            memo[i][j] = (first_match && dfs(i+1, j)) ||
                dfs(i, j+2);
        }else{
            memo[i][j] =  first_match && dfs(i+1, j+1);
        }
        
        return memo[i][j];
    }
    
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        memo = vector<vector<int>>(s.size()+1, vector(p.size()+1, -1));
        return dfs(0, 0);
    }
};
