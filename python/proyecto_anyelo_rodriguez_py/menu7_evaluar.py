from tkinter import *
from tkinter import messagebox
import menu2
import menu3
import sqlite3
import arduino

def menu7_():
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
    cedula=StringVar()

    mi_frame=Frame(raiz_nu)
    mi_frame.pack(expand=1)
    mi_frame.config(bg="white",bd=8,relief="groove")


    label_cedula=Label(mi_frame,text="Cedula del cliente que desea ingresar al centro comercial:",font=25,bg="white")
    label_cedula.grid(row=0,column=0,pady="10",padx="5",columnspan=2)

    entry_cedula=Entry(mi_frame,cursor="hand2",bd=3,relief="groove",textvariable=cedula)
    entry_cedula.grid(row=1,column=0,ipadx=40,columnspan=2,pady="10")


    def buscar():
        cedula1=StringVar()
        cedula1=cedula.get()
        conexion= sqlite3.connect("BD1_correos_proyecto")
        cursor= conexion.cursor()
        cursor.execute("CREATE TABLE IF NOT EXISTS clientes(Cedula VARCHAR(20), Nombre TEXT, Apellido TEXT, Edad TEXT, Genero TEXT, Observaciones TEXT, Telefono TEXT, Direccion TEXT, Temperatura Text,PRIMARY KEY(Cedula))")
        conexion.commit()
        cursor.execute(f"SELECT Cedula,* FROM clientes WHERE Cedula = '{cedula1}'")
        lista=cursor.fetchall()
        conexion.close()
        Temperatura=float(lista[0][9])
        print(Temperatura)
        if Temperatura >= 41:
            arduino.nopasa()
            messagebox.showinfo("Informacion cliente","El cliente tiene HIPERMETRIA.\n\n Al hospital, no puede entrar.")
            #arduino
            

        elif 39.5<=Temperatura<41:
            arduino.nopasa()
            messagebox.showinfo("Informacion cliente","El cliente tiene fiebre alta.\n\nAl hospital, no puede entrar.")
            #arduino
            

        elif 39.5>Temperatura>=37.5:
            arduino.nopasa()
            messagebox.showinfo("Informacion cliente","El cliente tiene fiebre.\n\nCuidese, no puede entrar.")
            #arduino
            

        elif 37.5>Temperatura>=36:
            arduino.pasa()
            messagebox.showinfo("Informacion cliente","El cliente esta normal.\n\nPuede entrar.")
            #arduino
            

        elif Temperatura<36:
            arduino.nopasa()
            messagebox.showinfo("Informacion cliente","El cliente tiene HIPOTERMIA.\n\nAl hospital, no puede entrar.")
            #arduino
            
        else:
            pass

        
    label_busqueda=Label(mi_frame,text="Si no aparece ningun mensaje el cliente no esta registrado",bg="white")
    label_busqueda.grid(row=6,column=0,columnspan=3)

    boton_crear=Button(mi_frame,text="Evaluar",command=buscar,font=25)
    boton_crear.grid(row=7,column=0,padx="20",columnspan=2,pady=10)

    def regresar():
        raiz_nu.destroy()
        menu2.menu2_()
        arduino.close()

    boton_regresar=Button(raiz_nu,text="Regresar",command=regresar,font=("Arial",10),cursor="hand2",bd=3,relief="ridge").place(x=10,y=10)

    raiz_nu.mainloop()
# menu7_()