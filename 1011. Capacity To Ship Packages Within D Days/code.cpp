class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for(int w: weights){
            left=max(left,w);
            right+=w;
        }
        while(left<right){
            int mid = (left+right)/2, req = 1, tillnow=0;
            for(int w:weights){
                if(tillnow + w > mid){
                    req += 1;
                    tillnow = 0;
                }
                tillnow +=w;
            }
            if(req>days) left = mid+1;
            else right = mid;
        }

        return left;
        
    }
};
