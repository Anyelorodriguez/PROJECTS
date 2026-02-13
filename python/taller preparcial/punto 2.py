# 2.	Definir una función que me permita decir si un número es primo o no.


num=int(input("digite un numero que quiera saber si es primo: "))

def es_primo(num):
    for i in range(2,num):
        if num % i==0:
            return "el numero ingresado no es primo"
    return "el numero ingresado es primo"

print(es_primo(num))
