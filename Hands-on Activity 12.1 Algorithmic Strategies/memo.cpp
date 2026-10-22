#include <iostream>
#include <algorithm>

const int n = 10;
int memo[n+1];

int getMinSteps(int n){
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n];
    int r = 1 + getMinSteps(n - 1);
    if (n % 2 == 0) r = std::min(r, 1 + getMinSteps(n / 2));
    if (n % 3 == 0) r = std::min(r, 1 + getMinSteps(n / 3));
    memo[n] = r;
    return r;
}

int main(){
    std::fill(memo, memo + n + 1, -1);
    std::cout << getMinSteps(n) << std::endl;
    return 0;
}