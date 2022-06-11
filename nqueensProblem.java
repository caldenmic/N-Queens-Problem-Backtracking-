import java.io.*;
import java.util.*;

public class nqueensProblem {
    
    public static void main(String args[]) {
        Nqueens n = new Nqueens(7);
        n.solve(0);
    }

    static class Nqueens {
        
        static int n;
        static int board[][];
        static int row_flag[];
        static int col_flag[];

        public Nqueens(int row) {
            this.n = row;
            board = new int[n][n];
            col_flag = new int[n];
        }

        static void print() {
            // System.out.println(n);
            // System.out.println(m);
            // System.out.println(queens);
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }
        }

        static void placeQueen(int row, int col, int count) {
            board[row][col] = 1;
            col_flag[col] = 1;
            solve(++count);
            board[row][col] = 0;
            col_flag[col] = 0;
        }

        static void solve(int count) {
            if(count == n) {
                print();
                System.out.println("-------");
                return;
            }
            for(int i=0; i<n; i++) {
                if(count != 0 && i > 0 && i < n-1) {
                    if(col_flag[i] == 1 || board[count-1][i-1] == 1 || board[count-1][i+1] == 1) {
                        continue;
                    }
                    else {
                        placeQueen(count, i, count);
                    }
                }
                else if(count != 0 && i == 0) {
                    if(col_flag[i] == 1 || board[count-1][i+1] == 1) {
                        continue;
                    }
                    else {
                        placeQueen(count, i, count);
                    }
                }
                else if(count != 0 && i == (n-1)) {
                    if(col_flag[i] == 1 || board[count-1][i-1] == 1) {
                        continue;
                    }
                    else {
                        placeQueen(count, i, count);
                    }
                }
                else {
                    placeQueen(count, i, count);
                }
            }
            return;
        }
    }
}