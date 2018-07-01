class Solution(object):
    def twoSum(self, nums, target):

        for num in range(len(nums)):
            for num1 in range(len(nums)):
                if nums[num] + nums[num1] == target and num != num1:
                    return [num, num1]
