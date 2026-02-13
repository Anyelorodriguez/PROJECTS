# # diccionarios pueden entrar muchos datos sin importar el orden
# # para entrar a un elemento hay que hacerlo por la clave
# # esta es mutable, se puede cambiar, editar,agregar, etc.
# # los diccionarios USAN CORCHETES {}
# #NO PONER CLAVES IGUALES

#paises={"colombia":"bogota","venezuela":"caracas","argentina":"buenos aires"}

##llamar con claves
# print(paises["venezuela"])
# print(paises["colombia"])

# #como saber todas las claves para ingresar
# print(paises.keys())

# #para saber todos los valores
# print(paises.values())

# #agregar o reemplazar en el diccionario
# paises["peru"]="lima"
# print(paises)

# #agregar por teclado
# pais=input("ingrese un nuevo pais al diccionario: ")
# capital = input("ingrese la respectiva capital")
# paises={"colombia":"bogota","venezuela":"caracas","argentina":"buenos aires",pais:capital}
# print(paises)

# # meter listas en el diccionario
# pais=input("ingrese un nuevo pais al diccionario: ")
# capital = input("ingrese la respectiva capital")
# lista_paises=["bolivia","francia","alemania"]
# lista_capitales=["la paz","paris","berlin"]
# paises={"colombia":"bogota","venezuela":"caracas","argentina":"buenos aires",pais:capital, lista_paises[0]:lista_capitales[0]}
# print(paises)

# #eliminar elementos
# del paises["colombia"]
# #tambien se puede usar pop
# paises.pop("venezuela")
# # se puede almacenar
# pais_eliminado=paises.pop("argentina")
# print(pais_eliminado)
# print(paises)

# #diccionario con valores normales y una tupla
# mi_horario={"lunes":"electiva","martes":"calculo","miercoles":("algebra lineal","metodologia")}
# print(mi_horario["miercoles"][0])

# #tupla clave del diccionario listas no se puede porque son mutables
# mi_horario={"lunes":"electiva","martes":"calculo","miercoles":("algebra lineal","metodologia"),("jueves","viernes"):"sistemas operativos"}
# print(mi_horario["jueves","viernes"])

# #imprimir claves y valores
# mi_horario={("lunes","domingo"):"electiva","martes":"calculo","miercoles":("algebra lineal","metodologia"),("jueves","viernes"):"sistemas operativos"}
# for clave in mi_horario:
#     print(clave, ":", mi_horario[clave])
# print("\n")
# for clave,valor in mi_horario.items():
#     print(clave,":", valor)
# print("\n")
# print(mi_horario.items())

# #funcion dict (las claves no deben ir entre comillas.)
# diccionario = dict(colombia="bogota", venezuela="caracas",argentina="buenos aires")
# print(diccionario)

# #zip() deben tener el mismo numero de elementos
# #relaciona cada elemento de la cadena de texto
# diccionario = dict(zip("abcdef",[1,2,3,4,5,6]))
# print(diccionario)
# print("\n")
# diccionario1 =dict(zip((1,2,3,4,5,6),[1,2,3,4,5,6]))
# print(diccionario1)

# #vaciar diccionario
# diccionario = dict(zip("abcdef",[1,2,3,4,5,6]))
# diccionario.clear()
# print(diccionario)

# #get()
# paises={"colombia":"bogota","venezuela":"caracas","argentina":"buenos aires"}
# print(paises.get("argentina"))

# #update()
# mi_horario_actual={"lunes":"python","martes":"calculo","miercoles":"metodologia"}
# mi_horario_nuevo={"lunes":"algebra","martes":"metodologia","miercoles":"fisica"}
# mi_horario_actual.update(mi_horario_nuevo)
# print(mi_horario_actual)

