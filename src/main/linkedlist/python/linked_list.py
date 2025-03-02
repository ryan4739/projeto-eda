class linked_list:
    """
    Representação de uma lista encadeada
    """
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0


    def is_empty(self):
        """
        Verifica se a lista está vazia

        Returns:
                boolean: true, caso a lista esteja vazia, false caso não
        """
        return self.size == 0


    def add_first(self, value):
        """
        Adiciona um elemento na primeira posiçao da lista

        Args:
            value (int): o valor a ser adicionado
        """
        new_node = node(value, self.head)
        
        if self.size == 0:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        
        self.size += 1


    def add_last(self, value):
        """
        Adiciona um elemento na última posiçao da lista

        Args:
            value (int): o valor a ser adicionado
        """
        new_node = node(value)

        if self.size == 0:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        
        self.size += 1


    def add(self, value, index):
        """
        Adiciona um elemento em um índice específico da lista

        Args:
            value (int): o valor a ser adicionado
            index (int): a posição na qual ele será adicionado
        """
        if index == 0:
            self.add_first(value)
        elif (index == self.size)
            self.add_last(value)
        else:
            if index < 0 or index > self.size-1: raise IndexError("Índice inválido")

            new_node = node(value)
            prev_node = self.__get_node_by_index(index-1)

            new_node.next = prev_node.next
            prev_node.next = new_node

            self.size += 1

    
    def get_first(self):
        """
        Informa o valor do primeiro elemento da lista

        Returns:
                int: o valor do primeiro elemento da lista
        """
        return self.head.value


    def get_last(self):
        """
        Informa o valor do primeiro elemento da lista

        Returns:
                int: o valor do último elemento da lista
        """
        return self.tail.value


    def get(self, index):
        """
        Informa o valor do node a partir de seu índice

        Args:
            index (int): o índice do node
        Returns:
                int: o valor contido no node
        """
        if index < 0 or index > self.size-1: raise IndexError("Índice inválido")

        if index == 0:
            return self.get_first()
        elif index == self.size-1:
            return self.get_last()
        
        return self.__get_node_by_index(index).value


    def update_node(self, value, index):
        """
        Altera o valor de um nó na lista

        Args:
            value (int): o valor a ser alterado
            index (int): o índice do valor a ser alterado
        """
        if index < 0 or index > self.size-1: raise IndexError("Índice inválido")

        node = self.__get_node_by_index(index)
        node.value = value


    def remove_first(self):
        """Remove o primeiro elemento da lista"""
        if self.is_empty(): raise Exception("Lista vazia")
        
        if self.size == 1:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next

        self.size -= 1


    def remove_last(self):
        """Remove o último elemento da lista"""
        if self.is_empty(): raise Exception("Lista vazia")
        
        if self.size == 1:
            self.head = None
            self.tail = None
        else:
            prev_node = self.__get_node_by_index(self.size-2)
            prev_node.next = None
            self.tail = prev_node
        
        self.size -= 1
    

    def remove_by_index(self, index):
        """
        Remove um elemento da lista a partir de seu índice

        Args:
            index (int): o índice do elemento a ser removido
        """
        if index < 0 or index > self.size-1: raise IndexError("Índice inválido")

        if index == 0:
            self.remove_first()
        elif index == self.size-1:
            self.remove_last()
        else:
            prev_node= self.__get_node_by_index(index-1)
            prev_node.next = prev_node.next.next

            self.size -= 1


    def remove_by_value(self, value):
        """
        Remove o primeiro elemento da lista que tiver o valor informado

        Args:
            value (int): o valor a ser removido
        """
        index = self.index_of(value)

        if index != -1:
            self.remove_by_index(index)    


    def index_of(self, value):
        """
        Informa o índice da primeira ocorrência de um valor. Se não estiver presente na lista, retornará -1

        Args:
            value (int): o valor a ser encontrado

        Returns:
            int: o índice da primeira ocorrência do valor, caso esteja na lista, -1 caso não.
        """
        if self.is_empty(): raise Exception("Lista vazia")

        node = self.head
        for i in range(self.size):
            if node.value == value:
                return i
        
            node = node.next
        
        return -1


    def last_index_of(self, value):
        """
        Informa o índice da última ocorrência de um valor. Se não estiver presente na lista, retornará -1

        Args:
            value (int): o valor buscado

        Returns:
            int: o índice da última ocorrência do valor, caso esteja na lista, -1 caso não
        """
        if self.is_empty(): return

        index = -1

        node = self.head
        for i in range(self.size):
            if node.value == value:
                index = i
            
            node = node.next
        
        return index


    def __get_node_by_index(self, index):
        """
        Pega o node em um índice informado

        Args:
            index (int): o índice do node
        
        Returns:
            node: o node
        """
        if index < 0 or index > self.size-1: return

        node = self.head
        for i in range(index):
            node = node.next
        
        return node


    def size_ll(self):
        """
        Informa o tamanho da lista

        Returns:
                int: o tamanho da lista
        """
        return self.size


    def contains(self, value):
        """
        Verifica se um valor está contido ou não na lista
        
        Args:
            value (int): o valor a ser buscado

        Returns:
                boolean: true caso o valor esteja contido, false caso não
        """
        return self.index_of(value) != -1


    def toString(self):
        """Representação textual da lista no formato "a -> b -> c [...]"""
        llString = ""   
        node = self.head
        for i in range(self.size):
            llString += node.value
            if node.next != None:
                llString += " -> "
            
            node = node.next
        
        return llString
    

class node:
    """Representação de um Nó da lista"""
    def __init__(self, value=None):
        self.value = value
        self.next = None
