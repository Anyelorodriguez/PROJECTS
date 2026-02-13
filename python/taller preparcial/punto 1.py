# 1.	Pedir un número por teclado y guardar en una lista
#  su tabla de multiplicar hasta el 10. 

num=int(input("digite un numero que quiera saber la tabla de multiplicar: "))
lista=list()

for i in range (1,11):
    lista.append(num*i)

print(lista)






