#3. Escriba un programa que pida el año actual y un año cualquiera y que escriba cuántos años han pasado desde ese año o cuántos años faltan para llegar a ese año.
print("diferencia entre años (solo escriba numeros).")
a = int(input("ingrese el año actual: "))
b = int(input("ingrese un año cualquiera: "))
if a>b:
    z=a-b
    print(a,">",b)
    print(" años que han pasado: ",z," años" )
elif a<b:
    z=b-a
    print(a,"<",b)
    print(" faltan para llegar a ese año: ",z," años" )
elif a==b:
    print("las 2 fechas son iguales")
    print(a,"==",b)
else:
    print("datos erroneos")