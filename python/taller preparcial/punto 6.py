# 6.	Definir un menú iterativo para simular una agenda telefónica.
#  Debe permitirle al usuario realizar las siguientes acciones:
# a.	Agregar Contactos
# b.	Imprimir Contactos
# c.	Buscar Número de un contacto
# d.	Cantidad de contactos en mi agenda
# e.	Salir del programa
#diccionario
agenda={}
i=0
while i==0:
    print ("a.	Agregar Contactos")
    print ("b.	Imprimir Contactos")
    print ("c.	Buscar Número de un contacto")
    print ("d.	Cantidad de contactos en mi agenda")
    print ("e.	Salir del programa")
    x=str(input("digite la opcion que desea: "))
    if x=="a":
        clave=str(input("digite el nombre del contacto: "))
        valor=(input("digite el numero de telefono de su contacto: "))
        agenda[clave]=valor
    elif x=="b":
        print(agenda)
    elif x=="c":
        y=input("digite el nombre de su contacto: ")
        if y in agenda:
            print("el numero de su contacto es: ",agenda[y])
        else:
            print("no se encuentra su contacto.")
    elif x=="d":
        contactos=list(agenda.keys())
        print ("usted tiene ",len(contactos), "contactos")
    elif x=="e":
        i=18
    else:
        print("opcion no reconocida, intende de nuevo")