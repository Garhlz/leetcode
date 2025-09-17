class Solution {
    public boolean backspaceCompare(String s, String t) {
        char[] a = new char[s.length()];
        char[] b = new char[t.length()];
        int idx1 = 0,idx2 = 0;
        for(int i = 0;i<s.length();i++){
            if(s.charAt(i)!='#'){
                a[idx1++] = s.charAt(i);
            }
            else if(idx1>=1){
                idx1--;
            }   
        }
        for(int i = 0;i<t.length();i++){
            if(t.charAt(i)!='#'){
                b[idx2++] = t.charAt(i);
            }
            else if(idx2>=1){
                idx2--;
            }   
        }
        if(idx1!=idx2)return false;
        for(int i = 0;i<idx1;i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
}
//用两次双指针即可，注意如果第一次退格的时候还慢指针为0，需要特判