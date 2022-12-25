class Solution {
public:
    int uniquePaths(int m, int n) {
    if (m == 1 || n == 1){
        return 1;
    }
    int** arr = new int*[m + 1]{};
    for(int i = 0; i < m + 1; ++i){arr[i] = new int[n + 1]{};}
    arr[1][1] = 1;
    arr[2][1] = 1;
    arr[1][2] = 1;
    for(int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j) {
            if (i == 1 || j == 1){
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
            }
        }
    }
    return arr[m][n];
}
};