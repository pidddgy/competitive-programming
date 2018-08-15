# https://dmoj.ca/problem/ccc02s1

options = [0,1,2,3,4]
prices = []
for i in range(4):
  prices.append(int(input()))
target = int(input())

def getPermutations(nums, data, last, index):
  length = len(nums)
  for i in range(length):
    data[index] = nums[i]
    # If the current permutation is already 4 long
    if index == last:
      # Check if the ticket prices add up to the target or not
      temp = [data[j] * prices[j] for j in range(length - 1)]
      if sum(temp) == target:
        yield[data[0], data[1], data[2], data[3]]
    else:
      for permutation in getPermutations(nums,data,last,index+1):
        yield(permutation)

def printPermutations(nums):
  # Create a temp list for getPermutations to use
  length = len(nums) - 1
  data = [None] * (length)

  # Keep track of total combinations
  totalCombinations = 0

  for permutation in getPermutations(nums, data, length-1, 0):
    if totalCombinations == 0:
      minimumTickets= sum(permutation)
    elif sum(permutation) < minimumTickets:
      minimumTickets = sum(permutation)
    totalCombinations += 1
    print("# of PINK is "+str(permutation[0])+" # of GREEN is "+str(permutation[1])+" # of RED is "+str(permutation[2])+" # of ORANGE is "+str(permutation[3]))
  
  print("Total combinations is " +str(totalCombinations)+".")
  print("Minimum number of tickets to print is "+ str(minimumTickets)+".")

printPermutations(options)
