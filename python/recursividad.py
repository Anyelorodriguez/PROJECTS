#simular un temporizador --->10,9,8,7,6..... 0.

def temporiza(valor):
    print(valor)
    valor -=1
    if valor>=0:
        temporiza(valor)

temporiza(10)