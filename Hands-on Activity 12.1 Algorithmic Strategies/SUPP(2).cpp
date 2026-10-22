#include <iostream>

const int M = 4;
const int N = 4;

int mat[M][N] = {
    {4, 7, 1, 6},
    {5, 7, 3, 9},
    {3, 2, 1, 2},
    {7, 1, 6, 3}};

int countPaths(int i, int j, int cost){
    if (cost < 0 || i < 0 || j < 0) return 0;
    if (i == 0 && j == 0){
        if (mat[0][0] == cost)
            return 1;
        else
            return 0;
    }
    return countPaths(i - 1, j, cost - mat[i][j]) +
           countPaths(i, j - 1, cost - mat[i][j]);
}

int main(){
    int cost = 25;
    std::cout << "Number of paths: " << countPaths(M - 1, N - 1, cost) << std::endl;
    return 0;
}