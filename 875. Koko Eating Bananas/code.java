class Solution {
    private int[] p;
    private boolean canEat(int H, int K){
        int res = 0;
        for(int pp : p){
            res += ((pp / K) + (((pp % K) == 0) ? 0: 1));
        }
        return res <= H;
    }
    public int minEatingSpeed(int[] piles, int H) {
        this.p = piles;
        int slow = 1, fast = 1000000000;
        while(slow <= fast){
            int mid = slow + (fast - slow) / 2;
            if(canEat(H, mid)) fast = mid - 1;
            else slow = mid + 1;
        }
        return slow;
    }
}
