# https://dmoj.ca/problem/valentines18j3

import math

n = int(input())
people = []

for i in range(n):
    name, cuteness = raw_input().split(' ')
    people.append((name, int(cuteness)))

for person in people:
    numberOfPeopleWhoPersonIsCuterThan = 0
    for cutenessCompetitor in people:
        if person[1] > cutenessCompetitor[1]:
            numberOfPeopleWhoPersonIsCuterThan += 1
    if numberOfPeopleWhoPersonIsCuterThan > n / 2:
        print(person[0] + ' is cute! <3')
    else:
        print(person[0] + ' is not cute. </3') 
