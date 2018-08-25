#!/usr/bin/python3
# https://dmoj.ca/problem/nccc5j5s3
class Airport:
  def __init__(self, hasFlightsTo, num = None):
    self.num = num
    self.hasFlightsTo = hasFlightsTo
  def addFlight(self, destination):
    self.hasFlightsTo.append(destination)

airports = []
edges = []

n, m = input().split()
n, m = int(n), int(m)

# Get edges
for i in range(m):
  s, t = input().split()
  edges.append((int(s), int(t)))
print()

# Create graph (without edges)
for i in range(1, m+1):
  airports.append(Airport([], i))

# Add edges to graph
for airport in airports:
  for edge in edges:
    if airport.num == edge[0]:
      airport.addFlight(edge[1])

for airport in airports:
  print(str(airport.num) + ' has flights to ' + str(airport.hasFlightsTo))
