class node:
    def __init__(self, valor=None):
        self.valor = valor
        self.next = None

class linked_list:
    def __init__(self):
        self.head = node()


    def adiciona_no_inicio(self, valor):
        novo_node = node(valor, self.head)
        self.head = novo_node


    def adiciona_no_indice(self, valor, indice):
        if indice == 0:
            self.adiciona_no_inicio(valor)
            return
        
        node_atual = self.head
        posicao = 0
        while node_atual != None and posicao + 1 != indice:
            posicao += 1
            node_atual = node_atual.next

        if node_atual != None:
            novo_node = node(valor)
            novo_node.next = node_atual.next
            node_atual.next = novo_node
        else:
            print("Índice não existe!")


    def adiciona_no_final(self, valor):
        novo_node = node(valor)

        no_atual = self.head
        while no_atual.next != None:
            no_atual = no_atual.next
        
        no_atual.next = novo_node

    def altera_node(self, valor, indice):
        node_atual = self.head
        posicao = 0
        if posicao == indice:
            node_atual.valor = valor
        else:
            while node_atual != None and posicao != indice:
                posicao += 1
                node_atual = node_atual.next

            if node_atual != None:
                node_atual.valor = valor
            else:
                print("Índice não existe!")
            

    def remove_primeiro_node(self):
        if self.head == None:
            return
        
        self.head = self.head.next

    def remove_node_indice(self, indice):
        if self.head == None:
            return
        
        node_atual = self.head
        posicao = 0

        if indice == 0:
            self.remove_primeiro_node()
        else:
            while node_atual != None and posicao < indice - 1:
                posicao += 1
                node_atual = node_atual.next
            
            if node_atual is None or node_atual.next is None:
                print("Índice não existe!")
            else:
                node_atual.next = node_atual.next.next 


    def remove_ultimo_node(self):
        if self.head.next == None:  
            return
        
        node_atual = self.head
        while node_atual != None and node_atual.next.next != None:
            node_atual = node_atual.next
        
        node_atual.next = None

    
    def remove_node(self, valor):
        node_atual = self.head

        if node_atual.valor == valor:
            self.remove_primeiro_node()
            return
        
        while node_atual != None and node_atual.next.valor != valor:
            node_atual = node_atual.next

        if node_atual is None:
            return
        else:
            node_atual.next = node_atual.next.next
        

    def tamanho_linked_list(self):
        size = 0
        node_atual = self.head
        while node_atual:
            tamanho += 1
            node_atual = node_atual.next
        return size


    def imprime_linked_list(self):
        node_atual = self.head
        while node_atual:
            print(node_atual.valor)
            node_atual = node_atual.next
