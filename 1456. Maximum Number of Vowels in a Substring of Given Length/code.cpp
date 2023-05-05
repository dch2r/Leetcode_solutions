class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0, cur = 0;
        for(int i = 0; i < k - 1 && i < s.size(); i ++)
            cur += is_vowel(s[i]);

        for(int i = k - 1; i < s.size(); i ++){
            cur += is_vowel(s[i]);
            res = max(res, cur);
            cur -= is_vowel(s[i - (k - 1)]);
        }
        return res;
    }

private:
    bool is_vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
    }
};
