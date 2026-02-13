# 3.	Por consola, el usuario debe digitar una fecha:
#  digitar el día, el mes y el año. Imprimir si la fecha digitada es correcta o incorrecta.
#   Contemplar para el ejercicio, los meses de 28, 30 y 31 días.

print("\ndigite una fecha (dia/mes/año)")
print("los años negativos seran tomados como años antes de la escritura.")
a=int(input("\ndigite el dia: "))
b=int(input("digite el mes: "))
c=int(input("digite el año: "))

if b in [1,3,5,7,8,10,12]:
    if a<0 or a>31:
        print("la fecha introducida es incorrecta intente nuevamente.")
    else:
        print("la fecha introducida es correcta {}/{}/{}".format(a,b,c))
elif b in [4,6,9,11]:
    if a<0 or a>30:
        print("la fecha introducida es incorrecta intente nuevamente.")
    else:
        print("la fecha introducida es correcta {}/{}/{}".format(a,b,c))
elif b==2:
    if a<0 or a>28:
        print("la fecha introducida es incorrecta intente nuevamente.")
    else:
        print("la fecha introducida es correcta {}/{}/{}".format(a,b,c))
else:
    print("la fecha introducida es incorrecta intente de nuevo")
