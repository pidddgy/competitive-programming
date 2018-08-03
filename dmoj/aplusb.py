# https://dmoj.ca/problem/aplusb

numberOfProblems = int(input())
for n in range(numberOfProblems):
    a, b = [int(num) for num in input().split(' ')]
    print(a + b)
