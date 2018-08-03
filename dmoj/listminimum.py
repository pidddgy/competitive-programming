sizeOfList = int(input())
nums = []

for element in range(sizeOfList):
    nums.append(int(input()))
for num in sorted(nums):
    print(num)