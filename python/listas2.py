
mi_lista=[]
mi_lista=list()
mi_lista=["python-texto",10, True, 2, "D",False,2,2,2,3,4,5,False]
mi_lista3=[7,8,34,53,45,34,534,5,345]

#se puede imprimir toda la lista por un bucle

#for i in mi_lista:
#    print(i)


#tambien se puede con while pero la i debe estar declarada
#i=0
#while i<len(mi_lista):
#    print(mi_lista[i])
#    i +=1

#for i<len(mi_lista):
#    print(mi_lista[i])

#ordenamiento de listas deben ser de un solo tipo de variable
# mi_lista2 =["2","holaquehace","a","m","n"," joven","Mip"]
# mi_lista2.sort()
# print(mi_lista2)
#para ordenar del ultimo al primero
# mi_lista2.sort(reversed)

#agregar una nueva variable a la lista. (el numero es en la posicion que se quiera)
# mi_lista.insert(1,"anyelo rodriguez")
# print(mi_lista[:])

# lista dentro de otra lista 
# mi_lista.append(["a","b","c"])
# print(mi_lista[:])
# # acceder a los elementos de la lista dentro de la lista
# print(mi_lista.index(["a","b","c"]))
# print(mi_lista[10][2])

#concatenacion de listas
# mi_lista.extend(mi_lista3)
# print(mi_lista[:])

# multiplicacion de listas
# print(mi_lista*3)

# eliminacion de listas o elementos de listas
# mi_lista.remove("python-texto")
# print(mi_lista[:])
# si hay repetidos elimina el primero que encuentra
# mi_lista.remove(2)
# print(mi_lista[:])
# para eliminar el ultimo dato o el numero que se quiera
# mi_lista.pop()
# mi_lista.pop(0)
# print(mi_lista[:])

lista_asignaturas=["calculo", "programacion","metodologia"]
lista_notas=list()

for asignatura in lista_asignaturas:
    nota= float(input("cual es su nota en la asignatura: " + asignatura))
    lista_notas.append(nota)

for i in range(len(asignatura)):
    print(f'su nota en {lista_asignaturas[i]} es: {lista_notas[i]}')


