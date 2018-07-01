def flip_vertical_axis(matrix):
    output = []
    for row in matrix:
        rowButReversed = row[::-1]  
        output.append(rowButReversed)
        print(output)
    return(output)

print(flip_vertical_axis(input()))