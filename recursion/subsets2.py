# Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

# The solution set must not contain duplicate subsets. Return the solution in any order.

 

# Example 1:

# Input: nums = [1,2,2]
# Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
# Example 2:

# Input: nums = [0]
# Output: [[],[0]]

# https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=11


class Solution:
    
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        
        temp = []
        ans = []
        nums.sort()
        
    
        def solve(ans,temp,nums,idx):
        
            if(idx == len(nums)):
                ans.append(temp[::])
                return

            #taking the number
            temp.append(nums[idx])
            solve(ans,temp,nums,idx+1)
            temp.pop()

            while( (idx < len(nums)-1) and nums[idx] == nums[idx+1]): 
                idx += 1
            solve(ans,temp,nums,idx+1)
            return
        
        solve(ans,temp,nums,0)
        return ans