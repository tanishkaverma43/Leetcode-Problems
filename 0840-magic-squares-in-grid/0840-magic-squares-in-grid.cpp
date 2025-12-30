class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c){
      vector<int>freq(10, 0);

      for(int i = r; i < r+3; i++){
        for(int j = c; j< c+3; j++){
          if(grid[i][j] == 0 || grid[i][j] > 9) return false;
          freq[grid[i][j]]++;
        }
      }
    // Check values are 1–9 and distinct
      for(int i = 1; i<= 9 ; i++){
        if(freq[i] != 1)return false;
      }

      // check row
      for(int i =r; i < r+3; i++){
        if(grid[i][c] + grid[i][c+1] + grid[i][c+2] != 15)return false;
      }

      for(int j = c; j< c+3; j++){
        if(grid[r][j] + grid[r+1][j] + grid[r+2][j] != 15) return false;
      }

      return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        if( n < 3 || m < 3 ) return 0;
        for(int i = 0; i<= n-3; i++){
          for(int j = 0; j<= m-3; j++){
            if(grid[i+1][j+1] == 5 && isMagic(grid, i, j)) ans++;
          }
        }
        return ans;
    }
};