numOfPpl = input("")
pplList = []

for i in range(1,int((numOfPpl)) + 1):
    pplList.append(i)

rounds = int(input(""))

for i in range(rounds):
    multiple = int(input(""))
    currentSubIndex = 1
    toRemove = []

    for x in pplList:
        if currentSubIndex == multiple:
            toRemove.append(x)
            currentSubIndex = 1
        else:
            currentSubIndex += 1

    for x in toRemove:
        pplList.remove(x)

print(*pplList, sep="\n")
