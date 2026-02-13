#definir una funcion recursiva para encontrar el factorial de un numero 
def fact(valor):
    print(valor)
    a=valor
    valor -=1
    z=a*valor
    if valor>=0:
        z=a*valor
        print(z)
        fact(valor)

fact(5)