# 2.	Realice la simulación de un Temporizador mediante bucles anidados,
#  se le debe pedir al usuario los valores iniciales de hora,
#  minuto y segundo del temporizador,
#  al llegar a 00:00:00 Imprimir mensaje de temporizador finalizado.
print("temporizador minutos segundos. ")
m=int(input("ingrese los minutos: "))
s=int(input("ingrese los segundos: "))

def segundos(num):
    for j in range (-num,1):
        print(m,":",num)
        num-=1
segundos(s)
m-=1
for i in range (-m,1):
    y=59 
    for i in range (-y,1):
        print(m,":",y)
        y-=1
        if m==0 and y==0:
            print("00:00 \ntemporizador finalizado")     
    m-=1

