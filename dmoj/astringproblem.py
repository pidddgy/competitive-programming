#!python
# https://dmoj.ca/problem/nccc3j3s1

word = raw_input()
counts = []
for uniqueLetter in 'abcdefghijklmnopqrstuvwxyz':
    counts.append(word.count(uniqueLetter))
counts.sort()

if len(counts) <= 2:
    print("0")
else:
    mostFreq = counts[-1]
    secondmostFreq = counts[-2]
    print(len(word) - (mostFreq + secondmostFreq))
