import java.util.Map;

class Solution {
    public boolean cmp(int[] a,int[] b){
        //比较a是否包含了b,即a每一项都大于等于b
        for(int i = 0;i<a.length;i++){
            if(a[i]<b[i])return false;
        }
        return true;
    }

    public String minWindow(String S, String T) {
        int a[] = new int[128];
        int b[] = new int[128];//所有ascii码，因为大小写都有
        char[] s = S.toCharArray();
        char[] t = T.toCharArray();
        for(char now:t){
            b[now]++;
        }
        int l = 0,ansL =-1,ansR = s.length-1;
        for(int r = 0;r<s.length;r++){
            a[s[r]]++;
            while(cmp(a,b)){
                if(r-l<ansR-ansL){
                    ansR = r;
                    ansL = l;
                }
                a[s[l]]--;
                l++;
            }
        }
        if(ansL<0)return "";
        else return S.substring(ansL,ansR+1);
    }
}