# Presentar la solución en python de serie de 
# Taylor para la funcion Cos(x), implementando RECURSIVIDAD

x=float(input("calcular coseno de: "))
n=int(input("precision del calculo (numero de iteraciones): "))


def factorial(numero):
    if (numero>1):
        numero= numero*factorial(numero-1)
    return numero

def signo_sum(signo):
    if signo%2 ==0:
        signo=(1)
    else:
        signo=(-1)
    return signo

def calcular_coseno(valor=0.0,rep=0,coseno=0.0):
    if valor>1:
        numerador = (rep**2*valor)
        denominador=(factorial(2*valor))
        signo1=signo_sum(valor)
        coseno= ((numerador/denominador)*signo1)+calcular_coseno(n-1)
    return coseno

print(calcular_coseno(n,x))


