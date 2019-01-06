def duplicate_items(list_numbers):
    duplicates = []
    list_numbers.sort()
    for number in list_numbers:
      if list_numbers[number] != number:
        print('aa')

print(duplicate_items([1, 3, 4, 2, 1]))