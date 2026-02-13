
# #excepciones eje 1
# num1=int(input("ingrese num1: "))
# num2=int(input("ingrese num2: "))
# resultado=0
# try:
#     resultado = num1/num2
# #en caso de que la linea 3 falle.... se el resto de lineas
# except ZeroDivisionError:
#     print("no se puede dividir por cero")
# try:
#     print(resultado)
# except NameError:
#     print("variable resultado no esta definida")

# #que se ejecute asi tenga un error
# print("lineas de codigo importantes")

#crear un error (edad negativa)
edad=int(input("ingrese su edad: "))
if edad<0:
    try:
            raise TypeError("edad negativa")
    except:
        print("ocurrio un error por edades negativas")

print(edad)#no se ejecuta si es negativa, porque se detiene el codigo por el error

print("lineas de codigo importantes")
