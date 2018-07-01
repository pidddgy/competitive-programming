def isPerfectSquare(num):
    """
    :type num: int
    :rtype: bool
    """
    i = 0
    while True:
      i += 1
      multiplied = i * i
      if multiplied == num:
        return True
      if multiplied > num:
        return False
print(isPerfectSquare(int(input())))