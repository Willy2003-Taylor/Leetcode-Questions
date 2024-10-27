#include <iostream>
#include <string>

// Function to expand around the center and find the longest palindrome
std::string expand_center(const std::string& s, int left, int right) {
    // Expand while the characters on both sides are the same
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }

    // Return the longest palindromic substring found
    return s.substr(left + 1, right - left - 1);
}

// Function to find the longest palindromic substring in the given string
std::string longestPalindrome(const std::string& s) {
    std::string longest = s.substr(0, 1);

    // Check for empty string
    if (s.empty()) return "";

    // Iterate through each character and expand around it
    for (int i = 0; i < s.size(); ++i) {
        // Check for odd-length palindromes
        std::string odd = expand_center(s, i, i);
        if (odd.size() > longest.size())
            longest = odd;

        // Check for even-length palindromes
        std::string even = expand_center(s, i, i + 1);
        if (even.size() > longest.size())
            longest = even;
    }

    // Return the longest palindromic substring found
    return longest;
}

int main() {
    std::string input = "babad"; // Example input
    std::string longestPal = longestPalindrome(input);
    std::cout << "Longest palindromic substring: " << longestPal << std::endl;
    return 0;
}
