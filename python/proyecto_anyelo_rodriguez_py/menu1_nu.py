from tkinter import *
from tkinter import messagebox
import menu1
import sqlite3

def crear_():
    raiz_nu=Tk()
    raiz_nu.iconbitmap('icono.ico')
    raiz_nu.geometry('930x600')

    #funciones menu.
    def salir_programa():
        salida=messagebox.askquestion("Salir del programa","¿Desea salir del programa?")
        if salida == "yes":
            raiz_nu.destroy()

    def ver_info():
        messagebox.showinfo("informacion del programa","Programa de control bioseguridad para el centro comercial Anyel Mort\n\nCreado por: Anyelo Rodriguez Lancheros.\nEstudiante UPTC.\nContacto: brayan.rodriguez08@uptc.edu.co\nVersion 0.0.1\nFecha: Mayo de 2021 \n\n Gracias por ver la informacion tkm <3")

    #menu interfaz
    barra_menu=Menu(raiz_nu)
    raiz_nu.config(menu=barra_menu)
    archivo_menu= Menu(barra_menu,tearoff=0)
    barra_menu.add_cascade(label="Archivo",menu=archivo_menu)
    archivo_menu.add_command(label="salir",command=salir_programa)

    ayuda_menu= Menu(barra_menu,tearoff=0)
    barra_menu.add_cascade(label="Ayuda",menu=ayuda_menu)
    ayuda_menu.add_command(label="info",command=ver_info)

    imagen_inicio=PhotoImage(file="bojack1.png")
    Label(raiz_nu,image=imagen_inicio).place(x=0,y=0,relwidth=1,relheight=1)
    Label(raiz_nu,text="Anyel mort",font=("Times",50),bg="#E2BC63").place(x=310,y=40)
    
    #variables
    correo=StringVar()
    contrasena=StringVar()
    contrasena2=StringVar()

    mi_frame=Frame(raiz_nu)
    mi_frame.pack(expand=1)
    mi_frame.config(bg="white",bd=8,relief="groove")


    label_correo=Label(mi_frame,text="usuario: ",font=25,bg="white")
    label_correo.grid(row=0,column=0,pady="10",padx="5",columnspan=2)

    entry_correo=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=correo)
    entry_correo.grid(row=1,column=0,ipadx=40,columnspan=2,pady="10")

    label_password=Label(mi_frame,text="Contraseña: ",font=25,bg="white")
    label_password.grid(row=2,column=0,pady="10",padx="5",columnspan=2)

    entry_password=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=contrasena)
    entry_password.grid(row=3,column=0,pady="10",ipadx=40,columnspan=2)

    label_password2=Label(mi_frame,text="Confirme la contraseña",font=25,bg="white")
    label_password2.grid(row=4,column=0,pady="10",padx="5",columnspan=2)

    entry_password2=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=contrasena2)
    entry_password2.grid(row=5,column=0,pady="10",ipadx=40,columnspan=2)

    def buscar():
        contrasena_=StringVar()
        contrasena_=contrasena.get()
        contrasena2_=StringVar()
        contrasena2_=contrasena2.get()
        if contrasena_==contrasena2_:
            mi_conexion_usuarios=sqlite3.connect("BD1_correos_proyecto")
            #buscar en base de datos correo y contraseña
            mi_cursor=mi_conexion_usuarios.cursor()
            mi_cursor.execute("CREATE TABLE IF NOT EXISTS USUARIOS(USUARIO VARCHAR(20) NOT NULL,PASSWORD VARCHAR(20) NOT NULL, PRIMARY KEY(USUARIO)) ")
            datos=(correo.get(),contrasena.get())
            mi_cursor.execute("INSERT INTO USUARIOS VALUES(?,?);",datos)
            mi_conexion_usuarios.commit()
            mi_conexion_usuarios.close()
            messagebox.showinfo("informacion","se creo el usuario correctamente")
            raiz_nu.destroy()
            menu1.menu1_()
            return mi_cursor.fetchall
            #guardar en base de datos
        else:
            label_busqueda.config(text="las contraseñas no coinciden",fg="red")
    
    label_busqueda=Label(mi_frame,text="",bg="white")
    label_busqueda.grid(row=6,column=0,columnspan=3)

    boton_crear=Button(mi_frame,text="Crear",command=buscar,font=25)
    boton_crear.grid(row=7,column=0,padx="20",columnspan=2)

    def regresar():
        raiz_nu.destroy()
        menu1.menu1_()

    boton_regresar=Button(raiz_nu,text="Regresar",command=regresar,font=("Arial",10),cursor="hand2",bd=3,relief="ridge").place(x=10,y=10)

    raiz_nu.mainloop()


# crear_()