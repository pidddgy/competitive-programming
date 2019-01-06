# https://dmoj.ca/problem/ccc98s1

N = int(input())
for i in range(N):
    cuteee = input().split(' ')
    for cuteeeeeeeeeee in cuteee:
        if len(cuteeeeeeeeeee) == 4:
            print('****', end=' ')
        else:
            print(cuteeeeeeeeeee, end=' ')
    print()
