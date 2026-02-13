#2. Escriba un programa que pida dos números y que conteste cuál es el menor y cuál el mayor o que escriba que son iguales.
print("comparacion entre 2 numeros a y b (solo escriba numeros)")
a = int(input("ingrese el valor de a comparar a: "))
b = int(input("ingrese el valor de a comparar b: "))

if a>b:
    print("el numero a es mayor que b")
    print(a,">",b)
elif a<b:
    print("el numero a es menor que b")
    print(a,"<",b)
elif a==b:
    print("los numero son iguales")
    print(a,"==",b)
else:
    print("datos erroneos")