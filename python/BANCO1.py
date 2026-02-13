S=5
def LISTANUEVA(numbers, S):
    def filter_digits(number, S):
        # Convierte el número a string, filtra los dígitos y luego vuelve a convertirlo a entero
        return int("".join([digit for digit in str(number) if int(digit) < S])) if any(int(digit) < S for digit in str(number)) else None

    # Aplica la función de filtrado y elimina los None
    processed_numbers = [filter_digits(num, S) for num in numbers if filter_digits(num, S) is not None]

    # Implementa el cambio de posiciones en tiempo O(n)
    for i in range(len(processed_numbers) // 2):
        processed_numbers[i], processed_numbers[-i-1] = processed_numbers[-i-1], processed_numbers[i]

    return processed_numbers

# Ejemplos
examples = [
    ([1, 2, 3, 4, 5, 6], 6),
    ([10, 20, 30, 40], 6),
    ([6], 6),
    ([66], 6),
    ([65], 6),
    ([6, 2, 1], 6),
    ([60, 6, 5, 4, 3, 2, 7, 7, 29, 1], 6)
]

for example in examples:
    print(f"Original: {example[0]} -> Procesado: {LISTANUEVA(example[0], S)}")
