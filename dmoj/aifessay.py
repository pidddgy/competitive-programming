# https://dmoj.ca/problem/gfssoc16j3
for i in range(input() * 2):
    # Line 4 is the pinnacle of my programming career
    newLine = ' '.join([word.replace(word, '!!!'+word+'!!!') if word.isupper() else word for word in [word.replace('.','!!!') for word in raw_input().split(' ')]])
    if newLine.isdigit() == False:
        print(newLine)