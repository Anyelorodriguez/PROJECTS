from tkinter import *
from tkinter import messagebox
from tkinter import ttk
import menu2
import sqlite3

def menu6_():
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
    Label(raiz_nu,text="Anyel mort",font=("Times",50),bg="#E2BC63").place(x=310,y=10)
    
    #variables
    cedula=StringVar()

    mi_frame=Frame(raiz_nu)
    mi_frame.pack(expand=1)
    mi_frame.config(bg="white",bd=8,relief="groove")


    label_cedula=Label(mi_frame,text="Cedula del cliente que desea consultar:",font=25,bg="white")
    label_cedula.grid(row=0,column=0,pady="10",padx="5",columnspan=2)

    entry_cedula=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=cedula)
    entry_cedula.grid(row=1,column=0,ipadx=30,columnspan=1,pady="10",sticky="e")
#____________--------------------------------------------------------------------
    def buscartodos():
        clientestr=tree.get_children()
        for i in clientestr:
            tree.delete(i)
        conexion= sqlite3.connect("BD1_correos_proyecto")
        cursor= conexion.cursor()
        cursor.execute("CREATE TABLE IF NOT EXISTS clientes(Cedula VARCHAR(20), Nombre TEXT, Apellido TEXT, Edad TEXT, Genero TEXT, Observaciones TEXT, Telefono TEXT, Direccion TEXT, Temperatura Text,PRIMARY KEY(Cedula))")
        conexion.commit()
        cursor.execute("SELECT * FROM clientes")
        lista=cursor.fetchall()
        conexion.close()
        for i in lista:
            tree.insert("",0,text=i[0],values=(i[1],i[2],i[3],i[4],i[5],i[6],i[7],i[8]))

    def buscar():
        cedula1=StringVar()
        cedula1=cedula.get()
        clientestr=tree.get_children()
        for i in clientestr:
            tree.delete(i)
        conexion= sqlite3.connect("BD1_correos_proyecto")
        cursor= conexion.cursor()
        cursor.execute("CREATE TABLE IF NOT EXISTS clientes(Cedula TEXT, Nombre TEXT, Apellido TEXT, Edad TEXT, Genero TEXT, Observaciones TEXT, Telefono TEXT, Direccion TEXT, Temperatura Text)")
        conexion.commit()
        cursor.execute(f"SELECT Cedula,* FROM clientes WHERE Cedula = '{cedula1}'")
        lista=cursor.fetchall()
        conexion.close()
        for i in lista:
            tree.insert("",0,text=i[1],values=(i[2],i[3],i[4],i[5],i[6],i[7],i[8],i[9]))
    tree = ttk.Treeview(mi_frame,height=10,columns=('#0','#1','#2','#3','#4','#5',"#6","#7"))
    tree.grid(row=2,column=0,ipadx=40,pady=0,columnspan=2)

    tree.column('#0', width=100)
    tree.column('#1', width=100)
    tree.column('#2', width=100)
    tree.column('#3', width=25)
    tree.column('#4', width=25)
    tree.column('#5', width=150)
    tree.column('#6', width=60)
    tree.column('#7', width=150)
    tree.column('#8', width=50)

    tree.heading('#0', text="Cedula", anchor=CENTER)
    tree.heading('#1', text="Nombre", anchor=CENTER)
    tree.heading('#2', text="Apellido", anchor=CENTER)
    tree.heading('#3', text="Edad", anchor=CENTER)
    tree.heading('#4', text="Sexo", anchor=CENTER)
    tree.heading('#5', text="Observacion", anchor=CENTER)
    tree.heading('#6', text="Telefono", anchor=CENTER)
    tree.heading('#7', text="Direccion", anchor=CENTER)
    tree.heading('#8', text="T(°C)", anchor=CENTER)
#-------------------------------------------------------------------------

    boton_crear=Button(mi_frame,text="Consultar",command=buscar,font=25)
    boton_crear.grid(row=1,column=1,padx="20",columnspan=1,sticky="w")

    boton_buscartodos=Button(mi_frame,text="Consultar Todos",command=buscartodos,font=25)
    boton_buscartodos.grid(row=8,column=0,padx="20",pady=10,columnspan=2)

    def regresar():
        raiz_nu.destroy()
        menu2.menu2_()

    boton_regresar=Button(raiz_nu,text="Regresar",command=regresar,font=("Arial",10),cursor="hand2",bd=3,relief="ridge").place(x=10,y=10)

    raiz_nu.mainloop()
# menu6_()