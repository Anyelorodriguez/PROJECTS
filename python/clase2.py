import os
# libreria o modulo dotenv
from dotenv import load_dotenv

load_dotenv()

usuario= os.getenv("USUARIO")
password= os.getenv("PASSWORD")

print (usuario)
print (password)

if usuario == "Electiva":
    print("usuario correcto")
    if password == "123456":
        print("password correcto")
        print("acceso concedido")
    else:
        print("contraseña incorrecta")
else:
    print("datos erroneos")
