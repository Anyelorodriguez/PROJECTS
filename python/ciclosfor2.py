animales = ['halcon','perro','gato', 'delfin','loro']

for animal in animales:
    if animal=="leon":
        break
    print("el animal es:{0}, el tamaño de la palabra es: {1}".format(animal,len(animal)))
else:
    print("no se encontro el animal leon")

print("salida de bucle")