def removeElement(nums, val):
    """
    :type nums: List[int]
    :type val: int
    :rtype: int
    """

    for num in range(len(nums)):
        if nums[num] = val:
            del nums[num]
    return len(nums)

print(removeElement([0,1,2,2,3,0,4,2],))
        