# 	Sumar las matrices usando tuplas
# A=   ■(2&1&-3@6&0&-1) 			B=   ■(-1&4&-5@3&-4&7)
matriz_A= ((2,1,-3),(6,0,-1))
matriz_B= ((-1,4,-5),(3,-4,7))

suma_matrices=[[0,0,0],[0,0,0]]
for j in range (-1,1):
        for i in range (-1,2):
            suma_matrices[j][i]=matriz_A[j][i]+matriz_B[j][i]
print(suma_matrices)




