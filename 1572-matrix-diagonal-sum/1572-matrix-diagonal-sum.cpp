class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int dsum=0;
        for(int i=0;i<mat.size();i++){
            dsum+=mat[i][i];
            if(i!=n-i-1){
                dsum+=mat[i][n-i-1];
            }
        }
        return dsum;
    }
};