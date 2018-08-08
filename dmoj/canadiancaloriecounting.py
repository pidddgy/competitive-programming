# https://dmoj.ca/problem/ccc06j1a
# ok look I know a dictionary isn't really needed but I think it's more readable ok dont attack me

burgerChoice = int(input())
burgerOptions = {
    1: 461,
    2: 431,             
    3: 420,
    4: 0
}

sideOrderChoice = int(input())
sideOrderOptions = {
    1: 100,
    2: 57,
    3: 70,
    4: 0
}

drinkChoice = int(input())
drinkOptions = {
    1: 130,
    2: 160,
    3: 118,
    4: 0
}

dessertChoice = int(input())
dessertOptions = {
    1: 167,
    2: 266,
    3: 75,
    4: 0
}
print("Your total Calorie count is " + str(burgerOptions[burgerChoice] + drinkOptions[drinkChoice] + sideOrderOptions[sideOrderChoice] + dessertOptions[dessertChoice]) + ".")
