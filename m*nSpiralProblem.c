vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int>ret;
    double odd = A.size();
    double term = odd /2.0;
    int leftColumn=0;
    int rightColumn=A[0].size();
    int top=0;
    int bottom=A.size()-1;
    for(int i=0;i<round(term) && leftColumn < rightColumn;i++) {
        // firstRow
        for(int j=i;j<A[0].size()-i;j++) {
            ret.push_back(A[i][j]);
        }
        // right
        int lastColumn = A[0].size()-1-i;
        for(int j=i+1;j<A.size()-i;j++){
            ret.push_back(A[j][lastColumn]);
        }
        
        //bottom
        int lastRow = A.size()-1-i;
        for(int j=A[0].size()-i-2;j>i && top!=bottom;j--){
            ret.push_back(A[lastRow][j]);
        }
        //left column
        for(int j=A.size()-1-i;j>i && leftColumn!=rightColumn-1 ;j--){
            ret.push_back(A[j][i]);
        }
        leftColumn++;
        rightColumn--;
        top++;
        bottom--;
    }
    
    return ret;
        
}
