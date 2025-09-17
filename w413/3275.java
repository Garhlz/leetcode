import java.util.*;

class Solution {
    public int[] resultsArray(int[][] queries, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collection.reverseOrder());
        int[] ans = new int[queries.length];
        for(int i = 0;i<queries.length;i++){
            pq.offer(Math.abs(queries[i][0]) + Math.abs(queries[i][1]));
            if(pq.size() > k)pq.poll();
            if(pq.size()==k)ans[i] = pq.peek();
            else ans[i] = -1;
        }
        return ans;
    }
}
