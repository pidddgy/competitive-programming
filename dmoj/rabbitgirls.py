# https://dmoj.ca/problem/halloween14p1

n = int(input())
k = int(input())

# Not sure how to describe this but for example if you put in 5 it would return 6, 4, 7, 3 and so on
def getSurroundingNumbers(num, difference=0):
  while True:
    difference += 1
    yield (num + difference, difference)
    yield (num - difference, difference)

def main(numOfRabbitGirls, groupSize):
  if numOfRabbitGirls % groupSize == 0:
    return(0)

  # Value[0] is the number of rabbitGirls and the value[1] is the number of seconds needed
  for value in getSurroundingNumbers(numOfRabbitGirls): 
    if value[0] % groupSize == 0:
      return(value[1])

print(main(n,k))
  