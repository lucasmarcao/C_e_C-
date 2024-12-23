def imprimir_triangulo(x):
    if (x<0):
        x = -x
    concatenador = """"""
    for i in range(0,x):
        print("*"*i)
        

def main():
    verifica = 0
    while (verifica!=2):
        x = int(input("\n digite \n"))
        imprimir_triangulo(x)
        if (x==0):
            print("impussivel")
            verifica = 2
    print("\b") ;   
    
main()

    