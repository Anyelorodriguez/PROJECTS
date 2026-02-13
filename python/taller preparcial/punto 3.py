# 3.	Pedirle al usuario una lista de números separados por espacio en blanco,
#  compararlos contra una lista de números primos del 1 al 100 debidamente 
# creada y decir cuales son primos de los números ingresados por el usuario.

lista_primos=((2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,97))
lista_ingr=input("digite todos los numeros que desea saber si son primos separados por un espacio:")
comparacion=[]

coverlist_ingr=lista_ingr.split()
for j in range(len(coverlist_ingr)):
    coverlist_ingr[j] = int(coverlist_ingr[j])

for item in lista_primos:
  if item in coverlist_ingr:
    comparacion.append(item)

if len(comparacion) > 0:
  print('Ambas listas contienen estos elementos')
  print(comparacion)
else:
  print('No existe ningun elemento igual en las listas')

