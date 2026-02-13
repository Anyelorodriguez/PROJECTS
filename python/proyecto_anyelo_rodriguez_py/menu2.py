from tkinter import *
from tkinter import messagebox
import menu3
import menu1
import menu4_actuali
import menu5_eliminar
import menu6_consultar
import menu7_evaluar
import sqlite3

def menu2_():
    raiz2= Tk()
    raiz2.iconbitmap('icono.ico')
    raiz2.geometry('930x600')

    #funciones menu.
    def salir_programa():
        salida=messagebox.askquestion("Salir del programa","¿Desea salir del programa?")
        if salida == "yes":
            raiz2.destroy()

    def ver_info():
        messagebox.showinfo("informacion del programa","Programa de control bioseguridad para el centro comercial Anyel Mort\n\nCreado por: Anyelo Rodriguez Lancheros.\nEstudiante UPTC.\nContacto: brayan.rodriguez08@uptc.edu.co\nVersion 0.0.1\nFecha: Mayo de 2021 \n\n Gracias por ver la informacion tkm <3")

    #menu interfaz
    barra_menu=Menu(raiz2)
    raiz2.config(menu=barra_menu)
    archivo_menu= Menu(barra_menu,tearoff=0)
    barra_menu.add_cascade(label="Archivo",menu=archivo_menu)
    archivo_menu.add_command(label="salir",command=salir_programa)

    ayuda_menu= Menu(barra_menu,tearoff=0)
    barra_menu.add_cascade(label="Ayuda",menu=ayuda_menu)
    ayuda_menu.add_command(label="info",command=ver_info)

    imagen_inicio=PhotoImage(file="bojack1.png")
    Label(raiz2,image=imagen_inicio).place(x=0,y=0,relwidth=1,relheight=1)
    Label(raiz2,text="Anyel mort",font=("Times",50),bg="#E2BC63").place(x=310,y=50)

    mi_frame=Frame(raiz2)
    mi_frame.pack(expand=1)
    mi_frame.config(bg="white",bd=8,relief="groove")


    def regist_cliente():
        raiz2.destroy()
        menu3.menu3_()
    def actualizar_inf():
        raiz2.destroy()
        menu4_actuali.menu4_()
    def eliminar_cliente ():
        raiz2.destroy()
        menu5_eliminar.menu5_()
    def consultar():
        raiz2.destroy()
        menu6_consultar.menu6_()
    def evaluar():
        raiz2.destroy()
        menu7_evaluar.menu7_()
    def regresar():
        raiz2.destroy()
        menu1.menu1_()
    


    boton_registrar=Button(mi_frame,text="Registrar nuevo cliente",command=regist_cliente,font=("Arial",15),cursor="hand2",bd=3,relief="ridge",height = 2, width = 20)
    boton_registrar.grid(row=0,column=0,padx="5",pady="10",columnspan=1)

    boton_actualizar=Button(mi_frame,text="Actualizar informacion",command=actualizar_inf,font=("Arial",15),cursor="hand2",bd=3,relief="ridge",height = 2, width = 20)
    boton_actualizar.grid(row=0,column=1,padx="5",pady="10",columnspan=1)

    boton_eliminar=Button(mi_frame,text="Eliminar cliente",command=eliminar_cliente,font=("Arial",15),cursor="hand2",bd=3,relief="ridge",height = 2, width = 20)
    boton_eliminar.grid(row=1,column=0,padx="5",pady="10",columnspan=1)

    boton_consultar=Button(mi_frame,text="Consultar",command=consultar,font=("Arial",15),cursor="hand2",bd=3,relief="ridge",height = 2, width = 20)
    boton_consultar.grid(row=1,column=1,padx="5",pady="10",columnspan=1)

    boton_ingreso=Button(mi_frame,text="Evaluar Ingreso",command=evaluar,font=("Arial",15),cursor="hand2",bd=3,relief="ridge",height = 2, width = 20)
    boton_ingreso.grid(row=2,column=0,padx="5",pady="10",columnspan=2)

    boton_regresar=Button(raiz2,text="Regresar",command=regresar,font=("Arial",10),cursor="hand2",bd=3,relief="ridge").place(x=10,y=10)

    raiz2.mainloop()
# menu2_()
