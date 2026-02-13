def min_unmakeable_change(coins):
    # Ordenar las monedas
    coins.sort()
    
    # Inicializar el cambio máximo que podemos hacer
    current_change_created = 0
    
    for coin in coins:
        # Si la moneda actual es mayor que el cambio máximo + 1,
        # entonces hay un hueco en el cambio que podemos crear
        if coin > current_change_created + 1:
            return current_change_created + 1
        
        # Sumar la moneda actual al cambio máximo creado
        current_change_created += coin
    
    # Si podemos crear todos los cambios posibles con las monedas dadas,
    # entonces el próximo cambio no creable es el cambio máximo + 1
    return current_change_created + 1

# Ejemplos
examples = [
    [5, 7, 1, 1, 2, 3, 22,20],
    [1, 1, 1, 1, 1,2],
    [1, 5, 1, 1, 1, 10, 15, 20, 100]
]

for example in examples:
    result = min_unmakeable_change(example)
    print(f"El mínimo cambio no creable para {example} es {result}")
