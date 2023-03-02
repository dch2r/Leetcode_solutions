class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for(int i=0; i<s.length(); i++){
            char top = str.empty() ? '#': str.top();

            if(top=='(' && s[i] == ')'){
                str.pop();
            }
            else if(top == '{' && s[i]== '}')  {
                str.pop();
            }
            else if(top == '[' && s[i]== ']'){
                str.pop();
            } 
            else{
                str.push(s[i]);
            } 
        }
        return str.empty();
    }
};
