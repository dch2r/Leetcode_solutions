class Solution {
    public int lengthOfLongestSubstring(String str) {
        String test = "";
        int maxlength = -1;
        if (str.isEmpty()){
            return 0;
        }
        else if(str.length()==1){
            return 1;
        }
        for(char c: str.toCharArray()){
            String current = String.valueOf(c);
            if (test.contains(current)){
                test = test.substring(test.indexOf(current)+1);
            }
            test=test + String.valueOf(c);
            maxlength = Math.max(test.length(), maxlength);
        }
        return maxlength;
    }
};
