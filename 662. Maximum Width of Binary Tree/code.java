class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        List<Integer> leftMost = new ArrayList<Integer>();
        return dfs(root, 1, 0, leftMost);
    }
    
    private int dfs(TreeNode node, Integer idx, Integer depth, List<Integer> leftMost) {
        if (node == null) return 0;
        if (depth >= leftMost.size()) leftMost.add(idx);
        int cur = idx - leftMost.get(depth) + 1;
        int left = dfs(node.left, idx * 2, depth+1, leftMost);
        int right = dfs(node.right, idx*2+1, depth+1, leftMost);
        return Math.max(cur, Math.max(left, right));
    }
    
}
