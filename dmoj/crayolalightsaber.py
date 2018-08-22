# https://dmoj.ca/problem/bfs17p2

numOfMarkers = int(input())
markerColors = input().split(' ')

mostFreqColor = int(markerColors.count(max(set(markerColors), key=markerColors.count)))
otherColors = numOfMarkers - mostFreqColor

print(min([mostFreqColor, otherColors + 1]) + otherColors)
