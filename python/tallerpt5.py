# 5.	Una máquina expendedora de refrigerios posee los siguiente productos
#  con sus respectivos precios y el código de máquina:
# a.	Papas fritas  2000        6a
# b.	Galletas 	650	     1b
# c.	Coca-cola     1500	     3c
# d.	Maní salado  2300       7d
# Ofrecer al usuario dichos productos en un mensaje legible,
#  preguntarle por su presupuesto y pedirle el código de su producto.
#   Evaluar si su presupuesto alcanza o no para el ítem seleccionado,
#    imprimir el ítem seleccionado y mostrarle el dinero que le sobra al usuario.

print("\nlista de productos")
print("\na.	Papas fritas --- precio 2000      codigo: 6a")
print("b.	Galletas    ---- precio 650	      codigo: 1b")
print("c.	Coca-cola   ---- precio 1500	  codigo: 3c")
print("d.	Maní salado  --- precio 2300      codigo: 7d\n")
a=int(input("digite su presupuesto: "))
while a<0:
    print("\nERROR. a digitado un numero negativo")
    a=int(input("digite su presupuesto: "))
b=str(input("digite el codigo del producto que desea: "))
codigos=["6a","1b","3c","7d"]
while not(b in codigos):
    print("codigo no valido intente de nuevo")
    b=str(input("digite el codigo del producto que desea: "))
if b == "6a":
    z=a-2000
    if z<0:
        print("su presupuesto no es suficiente para comprar este producto")
    else:
        print("su presupuesto es suficiente.")
        print("su producto son Papas fritas, su cambio es:",z)
elif b == "1b":
    z=a-650
    if z<0:
        print("su presupuesto no es suficiente para comprar este producto")
    else:
        print("su presupuesto es suficiente.")
        print("su producto son galletas, su cambio es:",z)
elif b == "3c":
    z=a-1500
    if z<0:
        print("su presupuesto no es suficiente para comprar este producto")
    else:
        print("su presupuesto es suficiente.")
        print("su producto es coca-cola, su cambio es:",z)
elif b == "7d":
    z=a-2300
    if z<0:
        print("su presupuesto no es suficiente para comprar este producto")
    else:
        print("su presupuesto es suficiente.")
        print("su producto es Mani salado, su cambio es:",z)






