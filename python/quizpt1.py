#en base al ejercicio de bucles anidados vaciar el interior del rectangulo
# es decir, solo dibujar el perimetro del rectangulo

alto=int(input("digite el alto del rectangulo: "))
ancho=int(input("digite el ancho del rectangulo: "))
for i in range(alto):
    for j in range(ancho):
        if i==0:
            print("*",end=" ")
        elif j==0:
            print("*",end=" ")
        elif i==alto-1:
            print("*",end=" ")
        elif j==ancho-1:
            print("*",end=" ")
        else:
            print(" ",end=" ")
    print("\n")