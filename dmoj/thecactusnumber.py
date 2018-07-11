# https://dmoj.ca/problem/valentines18j1

insignificantCarolNums = []
numberOfVals = int(input())
for val in range(numberOfVals):
  insignificantCarolNums.append(input())

def getHighestCarolNum(insignificantCarolNums):
  currentHighest = 0
  for num in insignificantCarolNums:
    carolNum = int(num) / 1000
    if carolNum > currentHighest:
      currentHighest = carolNum
  return(currentHighest)

if getHighestCarolNum(insignificantCarolNums) > 10:
  print("Something is wrong with these cuteness values")
elif getHighestCarolNum(insignificantCarolNums) > 1:
  print("Cuteness by definition is similarity to Cactus")
else:
  print("Cuteness by definition is similarity to Carol")