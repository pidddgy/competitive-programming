# https://dmoj.ca/problem/mockccc15j1

numbers = input()
numbers = numbers.split(' ')
if numbers[0] == '416':
  print('valuable')
elif numbers[0] == '647' or numbers[0] == '437':
  print('valueless')
else:
  print('invalid')