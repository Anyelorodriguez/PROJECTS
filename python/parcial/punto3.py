# 3.	Pedir por teclado una cadena de texto (palabra o frase).
#  Decir si la cadena ingresada es palíndroma o no.
#   Implementar listas para su resolución.
print("saber si una cadena de texto es palindroma.")
var1=str(input("digite una palabra o frese: "))

list_cadena=[]
def listarcadena(cadena):
        for n in cadena:
            list_cadena.append(n)
        return list_cadena
listarcadena(var1)
list_cadena_reverso=[]
for i in reversed(list_cadena):
    list_cadena_reverso.append(i)

if list_cadena==list_cadena_reverso:
    print("la cadena de texto es palindroma")
    print(list_cadena)
    print(list_cadena_reverso)
else:
    print("la cadena no es palindroma")
    print(list_cadena,"\n",list_cadena_reverso)
