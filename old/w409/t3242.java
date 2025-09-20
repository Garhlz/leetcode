class NeighborSum {
    private static final int[][] DIRS = {{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,1},{-1,-1},{1,-1}};
    private final int[][] s;

    public NeighborSum(int[][] grid) {
        int n = grid.length;
        s = new int[n*n][2];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int v = grid[i][j];
                for(int k = 0;k<8;k++){
                    int x = i+DIRS[k][0];
                    int y = j+DIRS[k][1];
                    if(x>=0&&x<n&&y>=0&&y<n){
                        s[v][k/4] += grid[x][y];
                    }
                }
            }
        }
    }
    
    public int adjacentSum(int value) {
        return s[value][0];
    }
    
    public int diagonalSum(int value) {
        return s[value][1];
    }
}

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum obj = new NeighborSum(grid);
 * int param_1 = obj.adjacentSum(value);
 * int param_2 = obj.diagonalSum(value);
 */