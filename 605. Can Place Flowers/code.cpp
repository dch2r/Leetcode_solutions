class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      if(n == 0) return true;
        int count = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i]) continue;
            if((i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)){
                flowerbed[i] = 1;
                if(++count == n) return true;
            }
        }
        return false;    
    }
};
