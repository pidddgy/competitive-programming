#!python3



q = int(input())
for tc in range(1, q+1):
    n, m = map(int, input().split())

    tensum = 0
    ans = 0
    for i in range(1, 11):
        tensum += ((m%10) * i) % 10
    
    # print("tensum is " + str(tensum))

    divis = n//m
    # print("divis is " + str(divis))

    ans += (divis//10) *  tensum
    
    # print("ans is now" + str(ans))

    for i in range(1, (divis%10)+1):
        ans += ((m%10) * i) % 10
    
    print(ans)

