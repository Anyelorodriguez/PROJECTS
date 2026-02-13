# 2.	Pedirle al usuario que ingrese las 5 notas (0.0 - 5.0) de un estudiante.
#  Averiguar su promedio y si está aprobado o no y si tiene derecho a habilitación o no.
#  Se aprueba con nota igual o mayor a 3.0 y se habilita con una nota igual 
#  o mayor a 2.0 y menor a 3.0
print("promedio de notas del estudiante")
x= float(input("escriba la primera nota de 0.0 a 5.0: "))
while x<0 or x>5.0:
    print("ha escrito un nota negativa o mayor a 5.0 intentelo nuevamente")
    x= float(input("escriba la primera nota positiva y menor que 5.0: "))
y= float(input("escriba el segundo nota: "))
while y<0 or y>5.0:
    print("ha escrito un nota negativa o mayor a 5.0 intentelo nuevamente")
    y= float(input("escriba la segunda nota nota positiva y menor que 5.0: "))
z= float(input("escriba el tercer nota: "))
while z<0 or z>5.0:
    print("ha escrito un nota negativa o mayor a 5.0 intentelo nuevamente")
    z=float(input("escriba la tercera nota positiva y menor que 5.0: "))
a= float(input("escriba la cuarta nota: "))
while a<0 or a>5.0:
    print("ha escrito un nota negativa o mayor a 5.0 intentelo nuevamente")
    a=float(input("escriba la cuarta nota positiva y menor que 5.0: "))
b= float(input("escriba la quinta nota: "))
while b<0 or b>5.0:
    print("ha escrito un nota negativa o mayor a 5.0 intentelo nuevamente")
    b=float(input("escriba la quinta nota positiva y menor que 5.0: "))
res=(x+y+z+a+b)/5
print("el promedio del estudiante es de: {}".format(res))
if res<3.0:
    print("el estudiante no aprobo.")
    if res<2.0:
        print("el estudiante no tiene derecho a habilitar.")
    else:
        print("el estudiante tiene derecho a habilitar")
else:
    print("el estudiante aprobo satisfactoriamente la meteria ")



