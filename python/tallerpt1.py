# 1.	Se le pide al usuario el ingreso 
# por teclado de 3 números, imprimir por consola los 3 números ordenados de menor a mayor.

print ("comparacion de 3 numeros positivos de mayor a menor no mayores a 99")

numero1= int(input("escriba un numero positivo no mayor a 99: "))
while numero1<0 or numero1>99:
    print("ha escrito un numero negativo o mayor a 99 intentelo nuevamente")
    numero1= int(input("escriba un numero positivo: "))
numero2= int(input("escriba el segundo numero: "))
while numero2<0 or numero2>99:
    print("ha escrito un numero negativo o mayor a 99 intentelo nuevamente")
    numero2= int(input("escriba un numero positivo: "))
numero3= int(input("escriba el tercer numero: "))
while numero2<0 or numero2>99:
    print("ha escrito un numero negativo o mayor a 99 intentelo nuevamente")
    numero3= int(input("escriba un numero positivo"))

a=min(numero1,numero2,numero3)
b=max(numero1,numero2,numero3)
c=(numero1+numero2+numero3)-a-b
print("los numeros ordenados son: {} < {} < {}".format(a,c,b))
