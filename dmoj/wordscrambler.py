import itertools # ayy lmao
output = []
word = input()
for permutation in itertools.permutations(word, len(word)):
  output.append(''.join(permutation)) 

for combo in sorted(output):
  print(combo)
