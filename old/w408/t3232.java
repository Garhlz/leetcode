class Solution {
    public boolean canAliceWin(int[] nums) {
        int t1 = 0,t2 = 0,sum = 0;
        for(int x : nums){
            sum+=x;
            if(x<10)t1+=x;
            else if(x<100)t2+=x;
        }
        // System.out.println(t1+" "+t2+" "+sum);
        if(t1>sum-t1)return true;
        else if(t2>sum-t2)return true;
        else return false;
    }
}