class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        unordered_set<int> set;
        stack<int> stack;
        int i = 0;
        for(int e: pushed){
            stack.push(e);
            set.insert(e);

            while(i < popped.size() && !stack.empty() && popped[i] == stack.top()){
                stack.pop();
                set.erase(e);
                i ++;
            }

            if(i < popped.size() && !stack.empty()
               && popped[i] != stack.top() && set.count(popped[i]))
                return false;
        }
        return stack.empty();
    }
};
