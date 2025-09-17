import java.util.List;

class Solution {
    public int finalPositionOfSnake(int m, List<String> commands) {
        int i = 0,j = 0;
        int n = commands.size();
        for(int k = 0;i<n;i++){
            if(commands.get(k).equals("UP")){
                i--;
            }
            else if(commands.get(k).equals("DOWN")){
                i++;
            }
            else if(commands.get(k).equals("RIGHT")){
                j++;
            }
            else if(commands.get(k).equals("LEFT")){
                j--;
            }
        }
        return i*m+j;
    }
}