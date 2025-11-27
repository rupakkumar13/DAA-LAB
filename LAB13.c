#include<stdio.h>
int board[20][20] ;
int isSafe( int row , int col , int n ){
    for( int i = 0 ; i< row ; i++){
        if( board[i][col] == 1 ){
            return 0;
        }
     
    }
    for( int i = row , j = col ; i>=0 && j>=0 ; i-- , j--){
        if( board[i][j]==1){
            return 0 ;
        }
    }
    for(int  i = row, j = col; i >= 0 && j < n; i--, j++){
        if( board[i][j]==1){
            return 0 ;
        }

    }
    return 1;
}
int  solveQueen(int row ,int n){
    if( row == n){
        for( int i = 0 ; i< n ;i++){
            for( int j = 0 ;j<n ;j++){
                printf("%d",board[i][j]);
            }
            printf("\n");
        }
       printf("\n");
    }
    for( int col = 0 ; col<n ; col++){
        if(isSafe(row , col , n)){
            board[row][col]=1;
            solveQueen(row+1,  n);
            board[row][col]=0;
        }
    }
}
int main(){
    int n ;
    printf("enter the size of the board :");
    scanf("%d",&n);
    solveQueen( 0 , n);
    return 0 ;
}