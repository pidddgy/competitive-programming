
cities = [int(x) for x in [0] + input().split()]
output = []

for i in range(len(cities)):
    line = []
    diff = 0

    for x in reversed(cities[:i]):
        if i == x:
            line.append(0)
        else:
            diff += x
            line.append(diff)

    for x in cities[i:]:
        if i == x:
            line.append(0)
        else:
            diff += x
            line.append(diff)
    output.append(line)

print(output)




