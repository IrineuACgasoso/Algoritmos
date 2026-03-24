lista_positivos = []


def binary_Search(procurado, size_list):
    front, rear = 0, size_list - 1 

    while (front <= rear):
        
        ponteiro = (front + rear) // 2

        if procurado == lista_positivos[ponteiro]:
            return ponteiro

        elif procurado < lista_positivos[ponteiro]:
            rear = ponteiro - 1
        
        else:
            front = ponteiro + 1

    return -1
            

def main():
    print("Digite os valores positivos em ordem do seu array: ")
    entrada = int(input())
    entrada_anterior = entrada

    while (entrada >= 0):
        entrada = int(input())

        if entrada < entrada_anterior:
            print("Lista não ordenada.")
            break

        lista_positivos.append(entrada)

        entrada_anterior = entrada

    print("Digite o valor procurado: ")
    procurado = int(input())
    resultado = binary_Search(procurado, len(lista_positivos))

    if resultado > 0:
        print(f"O número está na posição: {resultado}")
    else:
        print("O valor não está na lista.")

    return

    
main()



