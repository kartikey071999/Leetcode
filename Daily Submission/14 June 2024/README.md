# [Minimum Increment to Make Array Unique](https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/?envType=daily-question&envId=2024-06-14)
**Leetcode Problem 945 - Medium**

## Topics
- Arrays
- Greedy
- Sorting

## Companies
- [Company tags from the Leetcode problem page]

## Description
You are given an integer array `nums`. In one move, you can pick an index `i` where `0 <= i < nums.length` and increment `nums[i]` by 1.

Return the minimum number of moves to make every value in `nums` unique.

The test cases are generated so that the answer fits in a 32-bit integer.

## Examples

### Example 1:
**Input:** `nums = [1,2,2]`  
**Output:** `1`  
**Explanation:** After 1 move, the array could be `[1, 2, 3]`.

### Example 2:
**Input:** `nums = [3,2,1,2,1,7]`  
**Output:** `6`  
**Explanation:** After 6 moves, the array could be `[3, 4, 1, 2, 5, 7]`.  
It can be shown with 5 or fewer moves that it is impossible for the array to have all unique values.

## Constraints:
- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`