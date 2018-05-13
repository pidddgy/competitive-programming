def isValid(s):
    stack = []

    for char in s:
        if len(stack) == 0:
            stack.append(char)
        else:
            topChar = stack[-1]
            if topChar == '(' and char == ')' or \
               topChar == '[' and char == "]" or \
               topChar == '{' and car == "}":
               stack.pop()
            else:
                stack.append(char)
    if len(stack) == 0:
        return True
    else:
        return False

print(isValid(input("")))