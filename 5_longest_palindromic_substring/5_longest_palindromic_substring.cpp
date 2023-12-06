#include "../tools/leetcode_helper.h"

class Solution {
private:
    bool is_palindrome(const std::string& s) {
        std::string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
public:
    // brute force algorithm
    // O(n^3)
    // std::string longestPalindrome(std::string s) {
    //     int n = s.length();
    //     std::string best_s = "";
    //     int best_len = 0;
    //     for(int L = 0; L < n; L++) {
    //         for(int R = L; R < n; R++) {
    //             int len = R-L+1;
    //             std::string subs = s.substr(L,len);
    //             if(n > best_len && is_palindrome(subs)) {
    //                 best_len = len;
    //                 best_s = subs;
    //             }
    //         }
    //     }
    // }

    // O(N^2) time and O(n) extra space.
    std::string longestPalindrome(std::string s) {
        int n = s.length();
        std::string best_s = "";
        int best_len = 0;

        for (int mid = 0; mid < n; mid++) {
            for (int x = 0; mid - x >= 0 && mid + x < n; x++) {
                if(s[mid-x] != s[mid+x]) break;

                int len = 2 * x + 1;
                if(len > best_len) {
                    best_len = len;
                    best_s = s.substr(mid-x, len);
                }
            }
        }

        for(int mid = 0; mid < n - 1; mid++) {
            // e.g. s = abbba
            // mid denotes a|b|ba
            for(int x = 1; mid-x +1 >= 0 && mid + x < n; x++) {
                // x = 1 -> mid, mid+1
                // x = 2 -> mid-1, mid+2
                if(s[mid-x+1] != s[mid+x]) break;

                int len = 2 * x;
                if(len > best_len) { // this is done at most n times.
                    best_len = len;
                    best_s = s.substr(mid-x+1, len);
                }
            }
        }
        return best_s;
    }
};

int main() {
  Solution s;
  LeetcodeInput li;

  std::string in_s;
  while(li.read_leetcode_string(in_s)) {
    li.print_string(s.longestPalindrome(in_s));
  }
  return 0;
}