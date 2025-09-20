func findCircleNum(isConnected [][]int) int {
    vis := make([]bool, len(isConnected))
    var dfs func(int)
    dfs = func(from int) {
        vis[from] = true
        for to,conn := range isConnected[from] {
            if conn == 1 && !vis[to]{
                dfs(to)
            }
        }
    }
    ans := 0
    for i, v := range vis{
        if !v{
            ans++
            dfs(i)
        }
    }
    return ans
}