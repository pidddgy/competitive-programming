def find_duplicate_items(list_numbers):
  duplicates = []
  list_numbers.sort()

  for prevNum, num in zip(list_numbers, list_numbers[1:]):
    if num == prevNum:
      duplicates.append(num)
  return(duplicates)