# 4.	Por consola, el usuario debe digitar un número entre 0 y 99,
#  imprimir si el número es par o impar, e imprimir la suma de sus dígitos.

print("\nnumeros pares e impares y suma de sus digitos")
a=int(input("digite un numero entre 0 y 99: "))
while a<0 or a>99:
    print("\nha escrito un numero negativo o mayor a 99 intentelo nuevamente")
    a=int(input("escriba un numero positivo y menor que 99: "))
if a % 2 == 0:
    print("\nel numero {} es par".format(a))
else:
    print("\nel numero {} es impar".format(a))
s=a % 10 + a//10
print("la suma de los digitos es igual a: ",s,"\n")

