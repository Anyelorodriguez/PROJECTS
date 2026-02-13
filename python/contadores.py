
# contadores: cuantas veces a ocurrido algo 
# testigos: indican si a ocurrido algo
# acumuladores: acumulan valores por operaciones, etc.

#contador
# par = 0
# for i in range (1,11):
#     if i % 2 == 0:
#         par +=1
# print("hay ", par,"numeros pares")

# testigo variables logicas (true) (false)

# encontrado = False
# for i in range(1,11):
#     if i % 4 == 0:
#         encontrado = True
# if encontrado:
#     print("se encontro numero divisible por 4")
# else: 
#     print("no se encontro numero divisible por 4")

#acumuladores:

suma=0
for i in [1,2,3,4,5,6,7]:
    suma += i

print("la suma de los numeros es", suma)
