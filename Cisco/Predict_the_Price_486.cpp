#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

bool predict_the_winner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Base case: when the subarray has only one element.
    for (int i = 0; i < n; i++) {
        dp[i][i] = nums[i];
    }
    
    // Fill the dp table for larger subarrays.
    for (int length = 2; length <= n; length++) {  // length = j - i + 1
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    
    // Check if Player 1 can win.
    return dp[0][n - 1] >= 0;
}

int main(){
    vector<int> nums = {456789, 987654, 123456, 654321, 789123, 345678, 
                    901234, 567890, 876543, 234567, 890123, 765432, 
                    432198, 678901, 543210, 210987, 999999, 100001, 
                    777777, 888888};

    
    auto start1 = chrono::high_resolution_clock::now();  // Start timer
    cout << "Test Case 1: " << (predict_the_winner(nums) ? "Player 1 Wins" : "Player 2 Wins") << endl;
    auto end1 = chrono::high_resolution_clock::now();  // End timer
    chrono::duration<double, milli> elapsed1 = end1 - start1;
    cout << "Runtime: " << elapsed1.count() << " ms\n" << endl;
    return 0;
}

