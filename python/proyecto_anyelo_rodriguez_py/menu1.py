from tkinter import *
from tkinter import messagebox
import menu2
import menu1_nu
import menu1_rec
import sqlite3

mostrar=True
def menu1_():
    raiz = Tk()
    raiz.iconbitmap('icono.ico')
    raiz.geometry('930x600')

    #funciones menu.
    def salir_programa():
        salida=messagebox.askquestion("Salir del programa","¿Desea salir del programa?")
        if salida == "yes":
            raiz.destroy()

    def ver_info():
        messagebox.showinfo("informacion del programa","Programa de control bioseguridad para el centro comercial Anyel Mort\n\nCreado por: Anyelo Rodriguez Lancheros.\nEstudiante UPTC.\nContacto: brayan.rodriguez08@uptc.edu.co\nVersion 0.0.1\nFecha: Mayo de 2021 \n\n Gracias por ver la informacion tkm <3")

    #menu interfaz
    barra_menu=Menu(raiz)
    raiz.config(menu=barra_menu)
    archivo_menu= Menu(barra_menu,tearoff=0)
    barra_menu.add_cascade(label="Archivo",menu=archivo_menu)
    archivo_menu.add_command(label="salir",command=salir_programa)

    ayuda_menu= Menu(barra_menu,tearoff=0)
    barra_menu.add_cascade(label="Ayuda",menu=ayuda_menu)
    ayuda_menu.add_command(label="info",command=ver_info)

    imagen_inicio=PhotoImage(file="bojack1.png")
    Label(raiz,image=imagen_inicio).place(x=0,y=0,relwidth=1,relheight=1)
    Label(raiz,text="Anyel mort",font=("Times",50),bg="#E2BC63").place(x=310,y=50)
    #variables
    correo=StringVar()
    contraseña=StringVar()
    
    mi_frame=Frame(raiz)
    mi_frame.pack(expand=1)
    mi_frame.config(bg="white",bd=8,relief="groove")

    

    label_correo=Label(mi_frame,text="usuario: ",font=25,bg="white")
    label_correo.grid(row=0,column=0,pady="10",padx="5",columnspan=2)

    entry_correo=Entry(mi_frame,cursor="hand2",font=25,bd=3,relief="groove",textvariable=correo)
    entry_correo.grid(row=1,column=0,ipadx=40,columnspan=2,pady="10")

    label_password=Label(mi_frame,text="Contraseña: ",font=25,bg="white")
    label_password.grid(row=2,column=0,pady="10",padx="5",columnspan=2)

    entry_password=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=contraseña)
    entry_password.config(show="*",font=25)
    entry_password.grid(row=3,column=0,pady="10",ipadx=40,columnspan=2)

    def mostrar_password():
        global mostrar
        if mostrar:
            entry_password.config(show="")
            mostrar=False
        else:
            entry_password.config(show="*")
            mostrar = True

    def buscar():
        mi_conexion_usuarios=sqlite3.connect("BD1_correos_proyecto")
        #buscar en base de datos correo y contraseña
        mi_cursor=mi_conexion_usuarios.cursor()
        mi_cursor.execute("SELECT * FROM USUARIOS")
        lista_usurios=[]
        lista_usurios=mi_cursor.fetchall()
        mi_conexion_usuarios.commit()
        mi_conexion_usuarios.close()
        lista_ingreso=[]
        lista_ingreso.append(correo.get())
        lista_ingreso.append(contraseña.get())
        x=len(lista_usurios)
        busqueda=False
        for i in range(x):
            tupla_acceder=tuple(lista_ingreso)
            if lista_usurios[i]==tupla_acceder:
                busqueda=True
        if busqueda:
            label_busqueda.config(text="Encontrado con exito")
            raiz.destroy()
            menu2.menu2_()
        else:
            label_busqueda.config(text="La informacion ingresada no corresponde a ningun usuario",fg="red")
    def crear_usuario():
        raiz.destroy()
        menu1_nu.crear_()
    def recup_contraseña():
        raiz.destroy()
        menu1_rec.recuperar_()
    boton_mostrar=Button(mi_frame,text="Ver",command=mostrar_password,font=25)
    boton_mostrar.grid(row=3,column=2)

    label_busqueda=Label(mi_frame,text="",bg="white")
    label_busqueda.grid(row=5,column=0,columnspan=3)

    boton_entrar=Button(mi_frame,text="Entrar",command=buscar,font=25)
    boton_entrar.grid(row=6,column=0,padx="20",columnspan=2)

    boton_recuperar=Button(mi_frame,text="recuperar contraseña",command=recup_contraseña,font=25)
    boton_recuperar.grid(row=7,column=1,padx="5",pady="10",columnspan=1)

    boton_crear=Button(mi_frame,text="crear usuario",command=crear_usuario,font=25)
    boton_crear.grid(row=7,column=0,padx="5",pady="10",columnspan=1)

    raiz.mainloop()

# menu1_()