// 2235. Add Two Integes
// Source: https://leetcode.com/problems/add-two-integers/
// Author: Sanjit Raman

struct Solution;

impl Solution {
    pub fn sum(num1: i32, num2: i32) -> i32 {
        return num1 + num2;
    }
}

// test
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_sum() {
        assert_eq!(Solution::sum(1, 2), 3);
    }
}

fn main() {
    println!("{}", Solution::sum(1, 2));
}
