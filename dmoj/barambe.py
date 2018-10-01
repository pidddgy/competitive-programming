# https://dmoj.ca/problem/bts17p1

capitalLetters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
text = input().split(' ')
print(text[0], end='')
for word in text[1:]:
    if word[0] in capitalLetters:
        print('. ', end='')
    else:
        print(' ', end='')
    print(word, end='')
print('.')
