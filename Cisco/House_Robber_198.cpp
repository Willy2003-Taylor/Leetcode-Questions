#include <iostream>
#include <vector>
#include <algorithm>

// Function to calculate the maximum amount of money that can be robbed
int rob(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    std::vector<int> dp(n, 0);
    // Define dp[i] as the maximum amount of money from the first i houses

    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
        dp[i] = std::max(dp[i - 1], nums[i] + dp[i - 2]);

    // Case 1: Rob ith house -> cannot rob (i-1)th house since these two houses are adjacent
    // (Don't consider the (i+1)th house since dynamic programming is developed from base case)

    // Case 2: Don't rob ith house -> dp[i] = dp[i-1]

    return dp[n - 1];
}

int main() {
    std::vector<int> houses = {2, 7, 9, 3, 1}; // Example input
    int maxMoney = rob(houses);
    std::cout << "Maximum amount of money that can be robbed: " << maxMoney << std::endl;
    return 0;
}
