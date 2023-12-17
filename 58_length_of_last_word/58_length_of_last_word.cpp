#include "../tools/leetcode_helper.h"

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int length = 0;
        int tail = s.length()-1;

        // Ignore trailing spaces
        while (tail >= 0 && s[tail] == ' ') tail--;

        // Calculate the length of the last word
        while (tail >= 0 && s[tail] != ' ') {
            length++;
            tail--;
        }

        return length;
    }
};

int main() {
  Solution s;
  LeetcodeInput li;

  std::string in_s;
  while(li.read_leetcode_string(in_s)) {
    li.print_integer(s.lengthOfLastWord(in_s));
  }
  return 0;
}