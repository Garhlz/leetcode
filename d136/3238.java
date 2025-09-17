class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        Map<Integer,Map<Integer,Integer>> mp = new HashMap<>();
        
        for(int i = 0;i<pick.length;i++){
            int a = pick[i][0],b = pick[i][1];
            if(mp.containsKey(a)){
                Map<Integer,Integer> now = mp.get(a);
                if(now.containsKey(b)){
                    int num = now.get(b);
                    now.put(b,num+1);
                }
                else now.put(b,1);
            }
            else{
                Map<Integer,Integer> now = new HashMap<>();//注意now的类型要确定
                now.put(b,1);
                mp.put(a,now);
            }
        }
        int cnt = 0;
        for(Integer key : mp.keySet()){
            Map<Integer,Integer> now = mp.get(key);
            for(Integer i : now.keySet()){
                int num = now.get(i);
                if(num>key){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
}
/*
 * 改了半天语法终于过了
 * 注意容器类如何创建和使用
 */