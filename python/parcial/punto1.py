# 1.	Por consola, el usuario debe digitar un número entre 0 y 999.
#  Si el número digitado es de 1 cifra, imprimir el dígito elevado a sí mismo.
#  Si el número es de 2 cifras,
#  imprimir la multiplicación de sus dígitos y si es de 3 cifras,
#  imprimir la suma de sus dígitos. 
list_num=[]
def listarNum(num):
        num = str(num)
        for n in num:
            n = int(n)
            list_num.append(n)
        return list_num

var1=int(input("digite un numero entre 0 y 999. "))
if var1<10:
    x=var1**var1
    print("resultado de la variable elevada a si misma: ",x)
elif var1>9 and var1<100:
    listarNum(var1)
    y=list_num[0]*list_num[1]
    print("el resultado de multiplicar los digitos de la variable es: ", y)
elif var1>99 and var1<1000:
    listarNum(var1)
    z=list_num[0]+list_num[1]+list_num[2]
    print("el resultado de la suma de los digitos es de: ",z)
else:
    print("el numero ingresado no esta en el rango que se pide.")
