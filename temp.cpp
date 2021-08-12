#include<iostream>

using namespace std;

//board for solving nqueens problem
//it is just a 2D array
int board[100][100];

//to find if a previoously kept queen is in the same column
int col_sum(int y, int col) {
    int sum = 0;
    for(int k=0; k<y; k++) {
        sum += board[k][col];
    }
    //either returns 1 or 0
    return sum;
}


void nqueens(int y, int n) {
    int i;
    
    //if n queens are placed on the board then it prints the board
    //along with each queen's position 
    if(y == n) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    //iterates through each n columns for each queen(y) to check safe position
    for(i=0; i<n; i++) {
        if((y != 0) && (i>0) && (i<=n-2)) {
            //if it isnt a safe position then continue the loop to the next column
            if(col_sum(y, i) || board[y-1][i-1] || board[y-1][i+1]) {
                continue;
            }
            //if it is a safe position then place the queen
            else {
                //place the queen
                board[y][i] = 1;
                //call the function to place the next queen(y+1)
                nqueens(y+1, n);
                //backtrack if there are no safe position for queen(y+1)
                board[y][i] = 0;
            }
        }
        else if((y != 0) && (i == 0)) {
            if(col_sum(y, i) || board[y-1][i+1]) {
                continue;
            }
            //if it is a safe position then place the queen
            else {
                //place the queen
                board[y][i] = 1;
                //call the function to place the next queen(y+1)
                nqueens(y+1, n);
                //backtrack if there are no safe position for queen(y+1)
                board[y][i] = 0;
            }
        }
        else if((y != 0) && (i == (n-1))) {
            if(col_sum(y, i) || board[y-1][i-1]) {
                continue;
            }
            //if it is a safe position then place the queen
            else {
                //place the queen
                board[y][i] = 1;
                //call the function to place the next queen(y+1)
                nqueens(y+1, n);
                //backtrack if there are no safe position for queen(y+1)
                board[y][i] = 0;
            }
        }
        else {
            //place the queen
            board[y][i] = 1;
            //call the function to place the next queen(y+1)
            nqueens(y+1, n);
            //backtrack if there are no safe position for queen(y+1)
            board[y][i] = 0;
        }
    }
    return;
}

int main() {

    int n;
    cin>>n;

    //Initializing the board to all zeros
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ::board[i][j] = 0;
        } 
    }

    //calling the nqueens function
    nqueens(0, n);

    return 0;
}