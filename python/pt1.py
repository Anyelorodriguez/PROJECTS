#1. Escriba un programa que pida dos números enteros y que calcule su división, escribiendo si la división es exacta o no. tenga en cuenta que no se puede dividir por cero.



print("division entre a/b (solo escriba numeros).")
a =int(input("ingrese el valor de a: "))
b =int(input("ingrese el valor de b: "))
if b == 0:
    print("ERROR -- no se puede dividir por cero")
else:
    z=a/b
    if (a%b)==0 :
        print("la division es exacta")
        print(z)
    else:
        print("la division no es exacta")
        print(z)
