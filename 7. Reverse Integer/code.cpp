class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        if(x<0){
            neg=true;
            long long temp = x * -1LL;
            if(temp>INT_MAX)
              return 0;
              x=temp;
        }

        int ans=0;

        while(x){
            long long temp = ans*10LL + x%10;
            if(temp>INT_MAX)
            return 0;

            ans=temp;
            x/=10;
        }

        if(neg){
            ans*=-1;
        }
        return ans;
        
    }
};
