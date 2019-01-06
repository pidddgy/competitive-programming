# https://dmoj.ca/problem/ccc04j3
numOfAdjectives = int(raw_input())
numOfNouns = int(raw_input())

adjectives = []
nouns = []

for i in range(numOfAdjectives):
    adjectives.append(raw_input())
for j in range(numOfNouns):
    nouns.append(raw_input())

for adjective in adjectives:
    for noun in nouns:
        print(adjective + ' as ' + noun)
