class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0){
            return 0;
        }
        int i =0;

        while(s[i]==' '){
            i++;
        }
        
        bool ispositive = true;

        if(s[i]=='-' || s[i] =='+'){
            ispositive = (s[i]=='+' ? true:false);
            i++;
        }
        if(s[i]-'0'<0 ||s[i]-'0'>9){
            return 0;
        }
        int num=0;

        while(s[i]>='0' && s[i] <='9'){
            if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]-'0'>7)){
                return ispositive? INT_MAX:INT_MIN;
            }
            num = num*10 + (s[i]-'0');
            i++;
        }
        return ispositive? num: num*-1;
    }
};
