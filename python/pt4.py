#4., otro mensaje diferente si es viernes, otro mensaje diferente si es sábado o domingo. Si el día ingresado no es ninguno de esos, imprimir otro mensaje.

print("ingrese un día de la semana (solo letras)")
a = str(input("ingrese el dia que quiera: "))
a.lower
print(a)
if a=="lunes":
    print("el dia lunes hay que ir al cine")
elif a=="viernes":
    print("hay que salir de farra!")
elif a=="sabado" or a=="domingo":
    print("dias de descanso")
elif a=="martes" or a=="miercoles" or  a=="jueves":
    print("hoy se trabaja")
else:
    print("datos erroneos")