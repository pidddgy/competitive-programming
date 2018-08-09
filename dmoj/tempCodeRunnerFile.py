# https://dmoj.ca/problem/gfssoc16j3
import re
numOfLines = input()

for i in range(numOfLines * 2):
    line = raw_input().split(' ')
    newLine = ' '.join([word.replace(word, '!!!'+word+'!!!') if word.isupper() else word for word in [word.replace('.','!!!') for word in line]])
    if newLine.isdigit() == False:
        print(newLine)
