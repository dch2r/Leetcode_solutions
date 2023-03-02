class Solution {
public:
    int compress(vector<char>& chars) {
         int nw_idx = 0;     
        int nr_idx = 1;    
        int cnt = 1;       
        char prev_char = chars[0];  
        chars.push_back('\0');      

        while(nr_idx != chars.size()) {
            if(chars[nr_idx] != prev_char) {
                chars[nw_idx++] = prev_char;
                if(cnt > 1) {
                    string cnt_str = to_string(cnt);
                    for(char c : cnt_str) chars[nw_idx++] = c;
                    cnt = 1;
                }
            } else {
                cnt++;
            }
            prev_char = chars[nr_idx++];
        }
        return nw_idx;
    }
};
