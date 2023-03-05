class Solution {
    public int minJumps(int[] arr) {
        if(arr.length==1)
        return 0;

    int count = 0;
    int length = arr.length;
        Map<Integer, List<Integer>> graph = new HashMap<>();
            for (int i = 0; i<length; i++)
            graph.computeIfAbsent(arr[i], x->new LinkedList<>()).add(i);
            boolean [] visited = new boolean [length];
            visited[0] = true;
            Queue<Integer> queue = new LinkedList<>();
               queue.offer(0);
            while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i=size; i>0; i--) {
                       int current = queue.poll();
                       if (current == length - 1)
                       return count;
            List<Integer> next = graph.get(arr[current]);
            next.add(current-1);
            next.add(current+1);
            for (Integer j:next) {
                if (j >= 0 && j<length && !visited[j]) {
                    visited[j] = true;
                    queue.offer(j);
                }
            }
                next.clear(); 
                }
                count += 1;
            }
                return 0;
    }
}
