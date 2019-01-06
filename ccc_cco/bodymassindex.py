# https://dmoj.ca/problem/ccc08j1

weight = float(input())
height= float(input())

aqt = weight/(height*height)

if aqt > 25:
    print("Overweight")
elif aqt < 18.5:
    print("Underweight")
else:
    print("Normal weight")