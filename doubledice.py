aPoints = 100
dPoints = 100

rounds = int(input(""))

for i in range(rounds):
    currentGame = input("")
    gameStr = str(currentGame)

    a = int(gameStr[0])  # antonia score
    d = int(gameStr[2])  # david score

    # if tie
    if a == d:
        pass

    # if antonia wins
    elif a > d:
        dPoints -= a

    elif d > a:
        aPoints -= d

print(aPoints)
print(dPoints)


