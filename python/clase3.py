usuario = input("ingrese usuario: ")
password = input("ingrese password: ")

if usuario == "Electiva":
    print("usuario correcto")
    if password == "123456":
        print("password correcto")
        print("acceso concedido")
    else:
        print("contraseña incorrecta")
else:
    print("datos erroneos")