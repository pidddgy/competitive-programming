# https://dmoj.ca/problem/ccc06j3

while True:
    word = raw_input()
    if word == 'halt':
        break
    else:
        totalSeconds = 0
        previousLetter = ' '

        # Each string is its own button.
        phone = [
            # Row 1
            'abc',
            'def',

            # Row 2
            'ghi',
            'jkl',
            'mno',

            # Row 3
            'pqrs',
            'tuv',
            'wxyz',
        ]

        for letter in word:
            for button in phone:
                if letter in button:
                    totalSeconds += button.find(letter) + 1
                    if previousLetter in button:
                        totalSeconds += 2
            previousLetter = letter
        print(totalSeconds)
