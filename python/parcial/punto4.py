# 4.	Simular una lotería donde:
# -Se deben generar 5 números al azar del 1 al 10 (Sin repetirse). 
# -Pedirle al usuario ingresar sus 5 números de la suerte del 1 al 10.
#  El método de ingreso de los números es a libre elección.
# -Mostrarle al usuario cuántos y cuáles números acertó en la lotería.
# -Dependiendo del número de aciertos, mostrarle su premio:
# 	5 aciertos – 20 millones de pesos
# 	4 aciertos – 10 millones de pesos
# 	3 aciertos – 5 millones de pesos
# 	2 aciertos – 3 millones de pesos
#           1 acierto – 1 millón
# 	0 aciertos – Mala suerte! 
import random
lista_num=[]
def numeros_perso(num):
    if num>10 or num<1:
        print("intentelo de nuevo")
        var2=int(input("digite sus numero de la suerte de 1 hasta el 10 sin repetirse: "))
        numeros_perso(var2)
    else:
        lista_num.append(num)

for i in range (5):
    var1=int(input("digite sus numero de la suerte de 1 hasta el 10 sin repetirse: "))
    if var1>10 or var1<1:
        numeros_perso(var1)
    else:
        lista_num.append(var1)

lista_aleatoria= []
for j in range(5):
    var1=random.randrange(1,11)
    lista_aleatoria.append(var1)

print(lista_num)
print(lista_aleatoria)

if lista_aleatoria==lista_num:
    print("tuvo 5 aciertos su premio es 20 millones de pesos")
else:
    print("0 aciertos, ¡sigue intentandolo!")


