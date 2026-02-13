# 5.	Pedir al usuario nombre completo, imprimir por cada caracter de su nombre,
#  las veces que se repite en la cadena de texto.
#  Permitir el ingreso de espacios en blanco, pero no tenerlos en cuenta en el conteo.

var1= str(input("digite su nombre completo"))
conjunto=set()

for i in var1:
    if i !=" ":
        conjunto.add(i)

diccionario={}
lista_nom=list(conjunto)

#agregar valor y clave al diccionario
for i in range(len(lista_nom)):
    valor=0
    for j in range(len(var1)):
        clave=lista_nom[i]
        repet=var1[j]
        
        if clave==repet:
            valor+=1
            diccionario[clave]=valor
           
    

print(diccionario)


