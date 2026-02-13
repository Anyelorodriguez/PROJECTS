# # 1. conocer como funciona el sistema binario y decimal.
# # 2. problema sistema binario de 15 bits a exadecimal
# # 3. crear calculadora de convercion de sistema binario a exadecimal
# # 4. pedir informacion binaria
# 5. convercion
# 6. funciona? si = 9. resultado 
# 7. no = revisar programa 
# 8. repetir de 4 a 6.


binari=int(input("digite el numero binario que quiera convertir a decimal: "))
def bina(binario):
    s=0
    i=0
    while(binario>=1):
        d=binario%10
        binario=int(binario/10)
        s=s+d*pow(2,i)
        print("binario fragmentado: ",d)
        i=i+1
    print("el numero ingresado es en decimal: ",s)
bina(binari)





