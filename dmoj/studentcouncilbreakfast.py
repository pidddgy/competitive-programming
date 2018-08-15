options = [0,1,2,3,4]
prices = []
for i in range(4):
  prices.append(int(input()))
target = int(input())

def getPermutations(nums, data, last, index):
  length = len(nums)
  for i in range(length):
    data[index] = nums[i]
    if index == last:
      temp = []
      for j in range(length - 1):
        temp.append(data[j] * prices[j])
      if sum(temp) == target:
        print(f"# of PINK is {data[0]} # of GREEN is {data[1]} # of RED is {data[2]} # of ORANGE is {data[3]}")
    else:
      getPermutations(nums,data,last,index+1)

def printPermutations(nums):
  length = len(nums) - 1
  data = [None] * (length)

  getPermutations(nums, data, length-1, 0)

printPermutations(options)