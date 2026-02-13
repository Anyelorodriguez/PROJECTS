##tupla es con parentesis normales ()
##una tupla es inmutable
# # 1) declaracion de una tupla
# mi_tupla=(1,2,3)
# mi_lista=(1,2,3)
# print(mi_tupla)
# print(mi_lista)

# # 2)tupla vacia (no sirve para nada)
# tupla_vacia=()
# tupla_vacia2=tuple()
# print(tupla_vacia)
# print(tupla_vacia2)

# # ejemplo: tengo una fecha de nacimiento
# fecha_nacimiento=(23,"febrero",1990)#no cambia la fecha de nacimiento
# print(fecha_nacimiento)

# # tupla unitaria
# tupla_unitaria=(3,)#para que py lo tome como una tupla se debe poner una coma
# print(tupla_unitaria)

# tamaño de la tupla igual que en listas --- con lend

# #4) format string
# nombre = "anyelo"
# apellido = "rodriguez"
# tupla_nombre=("anyelo","rodriguez")
# print("mi primer nombre es {0} y mi apellido es {1}")
# print("mi primer nombre es {nombre} y mi apellido es {apellido}")
# print("mi primer nombre es %s"% nombre) #sale error si fueran ambas variables
# print("mi primer nombre es %s y mi apellido es %s"% tupla_nombre )

# #convertir entre listas y tuplas
# fecha_nacimiento=[23,"febrero",1990]
# mi_tupla=(1,2,3)
# fecha_nacimiento_tupla=tuple(fecha_nacimiento)
# mi_tupla_lista=list(mi_tupla)

# #6)empaquetado y desempaquetado de tuplas
# #empaquetado variables dentro de una tupla
# dia= 23
# mes="febrero"
# anio=2021
# tupla_fecha= dia,mes,anio
# print(tupla_fecha)
# #desempaquetado asignar a variables cada valor de la tupla
# #debe ser igual el tamaño de la tupla con el nuemro de variables.
# datos_docente=("diego",1001898752,"tunja")
# nombre,cedula,ciudad_nacimiento=datos_docente
# print(nombre)
# print(cedula)
# print(ciudad_nacimiento)

# # 7)tuplas anidadas
# datos_docente=("diego",1001898752,"tunja",(23,"febrero",1990))
# print(datos_docente[3][1])

# #extraer porcion de tupla
# datos_docente=("diego",1001898752,"tunja",(23,"febrero",1990))
# print(datos_docente[0:3])