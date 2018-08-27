#!/usr/bin/python3
# https://dmoj.ca/problem/nccc5j5s3

class Airport:
  def __init__(self, hasFlightsTo, num):
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

# Create graph (without edges)
for i in range(1, max(x[1] for x in edges) + 1):
  airports.append(Airport([], i))

# Add edges to graph
for airport in airports:
  for edge in edges:
    if airport.num == edge[0]:
      airport.addFlight(airports[edge[1] - 1])

# Breadth first traversal
for edge in edges:
  canGetToAirport = False

  firstAirport = airports[0]

  # List to keep track of which nodes we've already visited
  visited = [False] * len(airports)
  queue = []

  visited[0] = True
  queue.append(firstAirport)

  while queue:
    s = queue[0]
    queue.pop(0) 
    for airport in s.hasFlightsTo:
      if not visited[airport.num - 1]:
        if s.num != edge[0] or airport.num != edge[1]:
          if airport.num == n:
            canGetToAirport = True
          visited[airport.num - 1] = True
        if s.num != edge[0] or airport.num != edge[1]:
          queue.append(airport)

  if canGetToAirport:
    print("YES")
  else:
    print("NO")
