# https://dmoj.ca/problem/ccc02s1

prices = []
for i in range(4):
  prices.append(int(input()))
target = int(input())
combos = []

def subset_sum(numbers, target, partial=[]):
    s = sum(partial)
    if s == target: 
        combos.append(sorted(partial))
    if s >= target:
        return
    for i in range(len(numbers)):
        n = numbers[i]
        subset_sum(numbers, target, partial + [n]) 

subset_sum(prices, target)
validCombos = set(tuple(combo) for combo in combos)
for validCombo in validCombos:
  print('# of PINK is ' + str(validCombo.count(prices[0])) + \
  ' # of GREEN is ' + str(validCombo.count(prices[1])) + \
  ' # of RED is ' + str(validCombo.count(prices[2])) + \
  ' # of ORANGE is ' + str(validCombo.count(prices[3])))

print('Total combinations is '+ str(len(validCombos)) + '.')
print('Minimum number of tickets to print is '+ str(min([len(i) for i in validCombos])) +'.')
