N = int(input())
A = [int(x) for x in input().split()]
count = [0] * 10

for i in A:
    count[i-1] += 1
  
maxNum = max(count)

for i in range(10):
    if count[i] == maxNum:
        print(i+1)
        break
