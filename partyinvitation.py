# NOT FINISHED

numOfPpl = input("")
pplList = []

for i in range(1,int((numOfPpl)) + 1):
    pplList.append(i)

rounds = int(input(""))

for i in range(rounds):
    multiple = int(input(""))
    currentSubIndex = 0

    for x in range(0,len(pplList) + 1):
        if currentSubIndex == multiple:
            pplList.remove(x)
            currentSubIndex = 0

        currentSubIndex += 1

print(pplList)

