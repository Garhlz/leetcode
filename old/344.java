class Solution {
    public void reverseString(char[] s) {
        int l = 0,r = s.length - 1;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
}