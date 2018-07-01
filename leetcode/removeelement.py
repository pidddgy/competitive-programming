def removeElement(nums, val):
    """
    :type nums: List[int]
    :type val: int
    :rtype: int
    """
    
    output = 0
    nums = list(nums)
    for i in range(len(nums)):
        if nums[i] != val:
            output += 1
            print(output)
            print(nums[i])
            print(val)
    return output

print(removeElement(input(),input()))