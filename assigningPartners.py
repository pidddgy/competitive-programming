ppl = input()

output = "good"

list1 = input().split()
list2 = input().split()

taken = set() # list of taken people

bigList = zip(list1, list2)

for x,y in bigList:
    if x in taken and y in taken:
        pass
    elif x in taken or y in taken or x == y:
        output = "bad"
        break
    else:
        taken.update(x)
        taken.update(y)

print(output)
