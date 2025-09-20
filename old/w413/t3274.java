class Solution {
    public boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        int t1 = coordinate1.charAt(0) - 'a' + 1,t2 = coordinate1.charAt(1) - '0';
        int t3 = coordinate2.charAt(0) - 'a' + 1,t4 = coordinate2.charAt(1) - '0';
        if((t1+t2+t3+t4)%2==0){
            return true;
        }
        else return false;
        
    }
}