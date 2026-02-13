# #pertenencia de un objeto (f,v)
# conjunto_estudiante={"juan","pedro","camilo"}
# print("juan" in conjunto_estudiante)


# conjuntoA_pares={0,2,4,6,8,10}
# conjuntoB_impares={1,3,5,7,9,11}

#union de conjuntos
# #manera 1
# conjunto_union_A_B=conjuntoA_pares | conjuntoB_impares
# print(conjunto_union_A_B)
# #manera 2
# conjunto_union_A_B=conjuntoA_pares.union(conjuntoB_impares)
# print(conjunto_union_A_B)

# #interseccion de conjuntos
# conjunto_interseccion=conjuntoA_pares.intersection(conjuntoB_impares)
# print(conjunto_interseccion)

# #Diferencia entre conjuntos
# conjunto_diferencia_A_B=conjuntoA_pares-conjuntoB_impares
# conjunto_diferencia_B_A=conjuntoB_impares-conjuntoA_pares
# print(conjunto_diferencia_A_B)
# print(conjunto_diferencia_B_A)

#diferencia simetrica que se entiende como la union del conjunto
#menos la interseccion
# #forma1
# conjunto_diferencia_simetrica=conjuntoA_pares.symmetric_difference(conjuntoB_impares)
# print(conjunto_diferencia_simetrica)
# #forma 2
# conjunto_union_A_B=conjuntoA_pares | conjuntoB_impares
# conjunto_interseccion=conjuntoA_pares.intersection(conjuntoB_impares)
# conjunto_diferencia_simetrica2=conjunto_union_A_B-conjunto_interseccion
# print(conjunto_diferencia_simetrica2)


#-------------------------------------------------------

# conjuntoA_pares={0,2,4,6,8,10}
# conjuntoB={2,4,6}

# #saber si es sub conjunto o super conjunto
# #es super conjunto?
# print(conjuntoA_pares.issuperset(conjuntoB))
# #es sub conjunto?
# print(conjuntoB.issubset(conjuntoA_pares))

# #no tienen ningun elemento en comun, o son totalmente ajenos entre si?
# print(conjuntoA_pares.isdisjoint(conjuntoB))

# def disjunto_anyelo(A,B):
#     conjunto_interseccion = conjuntoA_pares.intersection(conjuntoB)
#     if conjunto_interseccion==set():
#         print(True)
#     else:
#         print(False)
# disjunto_anyelo(conjuntoA_pares,conjuntoB)
