class Solution {
    public String stringHash(String s, int k) {
        StringBuffer s1 = new StringBuffer();
        for(int i = 0;i<s.length();i+=k){
            char now = 0;
            for(int j = 0;j<k;j++){
                int x = i+j;
                char a = s.charAt(x) - 'a';
                now+=a;
            }
            now%=26;
            char c = now+'a';
            s1.append(c);
        }
        return s1.toString();
    }
}