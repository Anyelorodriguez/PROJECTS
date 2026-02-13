from tkinter import *
from tkinter import messagebox
import menu2
import sqlite3


genero="m"
def menu3_():
    raiz3= Tk()
    raiz3.iconbitmap('icono.ico')
    raiz3.geometry('930x600')

    #funciones menu.
    def salir_programa():
        salida=messagebox.askquestion("Salir del programa","¿Desea salir del programa?")
        if salida == "yes":
            raiz3.destroy()

    def ver_info():
        messagebox.showinfo("informacion del programa","Programa de control bioseguridad para el centro comercial Anyel Mort\n\nCreado por: Anyelo Rodriguez Lancheros.\nEstudiante UPTC.\nContacto: brayan.rodriguez08@uptc.edu.co\nVersion 0.0.1\nFecha: Mayo de 2021 \n\n Gracias por ver la informacion tkm <3")

    #menu interfaz
    barra_menu=Menu(raiz3)
    raiz3.config(menu=barra_menu)
    archivo_menu= Menu(barra_menu,tearoff=0)
    barra_menu.add_cascade(label="Archivo",menu=archivo_menu)
    archivo_menu.add_command(label="salir",command=salir_programa)

    ayuda_menu= Menu(barra_menu,tearoff=0)
    barra_menu.add_cascade(label="Ayuda",menu=ayuda_menu)
    ayuda_menu.add_command(label="info",command=ver_info)

    imagen_inicio=PhotoImage(file="bojack1.png")
    Label(raiz3,image=imagen_inicio).place(x=0,y=0,relwidth=1,relheight=1)

    #variables
    cedula=StringVar()
    nombre=StringVar()
    apellido=StringVar()
    edad=StringVar()
    opciones_genero=IntVar(value=1)
    telefono=StringVar()
    direccion=StringVar()
    Temperatura=StringVar()
    

    mi_frame=Frame(raiz3)
    mi_frame.pack(expand=1)
    mi_frame.config(bg="white",bd=8,relief="groove")

    label_cedula=Label(mi_frame,text="Cedula: ",font=25,bg="white")
    label_cedula.grid(row=0,column=0,pady="10",padx="5",sticky="w")

    entry_cedula=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=cedula)
    entry_cedula.grid(row=0,column=1,pady="10",ipadx=40)

    label_nombre=Label(mi_frame,text="Nombre: ",font=25,bg="white")
    label_nombre.grid(row=1,column=0,pady="10",padx="5",sticky="w")

    entry_nombre=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=nombre)
    entry_nombre.grid(row=1,column=1,pady="10",ipadx=40)

    
    label_apellido=Label(mi_frame,text="Apellido: ",font=25,bg="white")
    label_apellido.grid(row=2,column=0,pady="10",padx="5",sticky="w")

    entry_apellido=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=apellido)
    entry_apellido.grid(row=2,column=1,pady="10",ipadx=40)
    
    label_edad=Label(mi_frame,text="Edad: ",font=25,bg="white")
    label_edad.grid(row=3,column=0,pady="10",padx="5",sticky="w")

    entry_edad=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=edad)
    entry_edad.grid(row=3,column=1,pady="10",ipadx=40)

    label_telefono=Label(mi_frame,text="telefono: ",font=25,bg="white")
    label_telefono.grid(row=0,column=4,pady="10",padx="5",sticky="w")

    entry_telefono=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=telefono)
    entry_telefono.grid(row=0,column=5,pady="10",ipadx=40)

    label_direccion=Label(mi_frame,text="direccion: ",font=25,bg="white")
    label_direccion.grid(row=1,column=4,pady="10",padx="5",sticky="w")

    entry_direccion=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=direccion)
    entry_direccion.grid(row=1,column=5,pady="10",ipadx=40)

    label_temperatura=Label(mi_frame,text="Temperatura: ",font=25,bg="white")
    label_temperatura.grid(row=2,column=4,pady="10",padx="5",sticky="w")

    entry_temperatura=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=Temperatura)
    entry_temperatura.grid(row=2,column=5,pady="10",ipadx=40,sticky="w")

    label_comentarios= Label(mi_frame,text="Observaciones generales: ",font=25,bg="white")
    label_comentarios.grid(row=5,column=0,pady=10,padx=5,sticky="w",columnspan=3)

    text_comentarios = Text(mi_frame,width="80",height="6",bd=3,relief="groove")
    text_comentarios.grid(row=6,column=0,columnspan=6,pady="10")

    #barra de desplazamiento
    mi_scroll_y=Scrollbar(mi_frame, command=text_comentarios.yview)
    mi_scroll_y.grid(row=6,column=6,sticky="nsew")
    #configurar que guarde en que lugar del texto esta.
    text_comentarios.config(yscrollcommand=mi_scroll_y.set)
    #--------------radio button----------

    def ver_genero():
        global genero
        if opciones_genero.get()==1:
            genero="m"
        else:
            genero="f"

    label_genero=Label(mi_frame,text="genero: ",bg="white",font=25)
    label_genero.grid(row=3,column=4,sticky="w",rowspan=2)

    #mostrar genero seleccionado, label variable

    radio_boton_masculino=Radiobutton(mi_frame,text="masculino",variable=opciones_genero,value=1,command=ver_genero,bg="white",font=25)
    radio_boton_masculino.grid(row=3,pady =10,column=5,sticky="w")

    radio_boton_femenino=Radiobutton(mi_frame,text="femenino",variable=opciones_genero,value=2,command=ver_genero,bg="white",font=25)
    radio_boton_femenino.grid(row=4,column=5,pady =10,sticky="w")

    def registro_nuevo():
        conexion=sqlite3.connect("BD1_correos_proyecto")
        #buscar en base de datos correo y contraseña
        cursor=conexion.cursor()
        cursor.execute("CREATE TABLE IF NOT EXISTS clientes(Cedula VARCHAR(20), Nombre TEXT, Apellido TEXT, Edad TEXT, Genero TEXT, Observaciones TEXT, Telefono TEXT, Direccion TEXT, Temperatura Text,PRIMARY KEY(Cedula))")
        datos=(cedula.get(),nombre.get(),apellido.get(),edad.get(),genero,text_comentarios.get(1.0,"end-1c"),telefono.get(),direccion.get(),Temperatura.get())
        cursor.execute("INSERT INTO clientes VALUES(?,?,?,?,?,?,?,?,?);",datos)
        conexion.commit()
        conexion.close()
        # return mi_cursor.fetchall
        messagebox.showinfo("informacion","se registro el cliente correctamente")
        raiz3.destroy()
        menu2.menu2_()

    boton_registro_nuevo=Button(mi_frame,text="Registrar",command=registro_nuevo,font=25)
    boton_registro_nuevo.grid(row=9,column=0,padx="20",pady="20",columnspan=6)
    
    def regresar():
        raiz3.destroy()
        menu2.menu2_()
    
    boton_regresar=Button(raiz3,text="Regresar",command=regresar,font=("Arial",10),cursor="hand2",bd=3,relief="ridge").place(x=10,y=10)
    
    
    raiz3.mainloop()

# menu3_()

