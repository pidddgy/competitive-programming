def plusOne(digits):
    for digit in reversed(range(len(digits))):
        if digits[digit] < 9:
            digits[digit] += 1
            return digits
        digits[digit] = 0

    digits = [1] + digits
    return digits

print(plusOne([9]))

