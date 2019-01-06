# https://dmoj.ca/problem/ccc02j2

while True:
    word = raw_input()
    if word[-3] in 'bcdfghjklmnpqrstvxzw' and word[-2:] == 'or' and len(word) > 4:
        print(word[:-2] + 'our')
    elif word == 'quit!':
        break
    else:
        print(word)
