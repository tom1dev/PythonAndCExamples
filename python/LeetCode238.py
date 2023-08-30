from typing import Self
#Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

#The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

#You must write an algorithm that runs in O(n) time and without using the division operation.

class Solution:
    a =[-1,1,0,-3,3]
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        prefix = [1]
        suffix = [1]

        sums =[]
        for i in range(1,len(nums)):
            prefix.append(prefix[i-1]*nums[i-1])
        for k in range(len(nums)-1 , 0,-1):
            suffix.append(suffix[len(nums) - k-1] * nums[k])
        
        for l in range(len(nums)):
            sums.append(suffix[len(nums) - l-1] * prefix[l])
        return sums
    b =  productExceptSelf(Self, a)
    print(b)
