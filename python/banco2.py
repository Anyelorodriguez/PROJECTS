S = 3

def sorted_squares(numbers, S):
    max_value = int(str(S) + str(S))
    squares = []
    
    # Calcular los cuadrados y filtrar por el rango [0, SS]
    for num in numbers:
        square = num * num
        if 0 <= square <= max_value:
            squares.append(square)
    
    # Ordenar los números cuadrados manualmente
    sorted_squares = [0] * len(squares)
    left, right = 0, len(squares) - 1
    index = len(squares) - 1
    
    while left <= right:
        if squares[left] > squares[right]:
            sorted_squares[index] = squares[left]
            left += 1
        else:
            sorted_squares[index] = squares[right]
            right -= 1
        index -= 1
    
    return sorted_squares

# Ejemplos
examples = [
    [1, 2, 3, 5, 6, 8, 9],
    [-2, -1],
    [-6, -5, 0, 5, 6],
    [-10, 9]
]

for example in examples:
    result = sorted_squares(example, S)
    print(result)
