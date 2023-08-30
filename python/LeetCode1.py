from ast import List
from typing import Self

#Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

#You may assume that each input would have exactly one solution, and you may not use the same element twice.

class Solution:
    a = [3,3]

    def twoSum(self, nums: list[int], target: int) -> list[int]:
        indexs = []
        for index in range(len(nums)):
            neededNum = target - nums[index]
            if neededNum in nums[index+1:]:
                indexs.append(index) 
                indexs.append(nums[index+1:].index(neededNum)+index+1)
                return indexs
        return indexs
    
    b = twoSum(Self,a,6)
    print(b)