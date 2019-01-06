# https://dmoj.ca/problem/ccc00j2

startingNumber = input()
endNumber = input()

numsThatLookSameWhenRotated = {'0','1','8'}
numsThatArentTurnable = {'2','3','4','5','7'}

output = 0

for num in range(int(startingNumber),int(endNumber)):
  originalNum = str(num)
  num = str(num)
  
  # Replace 6 with 9 and 9 with 6
  num = num.replace('6', '%temp%').replace('9', '6').replace('%temp%', '9')

  # Reverse string
  num = num[::-1]

  # If the flipped number equals the original number and doesn't contain any numbers that don't look like
  # anothern umber when flipped
  if num == originalNum and not any(notTurnableNum in num for notTurnableNum in numsThatArentTurnable):
    output += 1
  
print(output)
  