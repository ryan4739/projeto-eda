class linked_list:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0


    def is_empty(self):
        return self.size == 0


    def add_first(self, value):
        new_node = node(value, self.head)
        
        if self.size == 0:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        
        self.size += 1


    def add_last(self, value):
        new_node = node(value)

        if self.size == 0:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        
        self.size += 1

        


    def add(self, value, index):
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
        return self.head.value


    def get_last(self):
        return self.tail.value


    def get(self, index):
        if index < 0 or index > self.size-1: raise IndexError("Índice inválido")

        if index == 0:
            return self.get_first()
        elif index == self.size-1:
            return self.get_last()
        
        return self.__get_node_by_index(index).value


    def update_node(self, value, index):
        if index < 0 or index > self.size-1: raise IndexError("Índice inválido")

        node = self.__get_node_by_index(index)
        node.value = value


    def remove_first(self):
        if self.is_empty(): raise Exception("Lista vazia")
        
        if self.size == 1:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next

        self.size -= 1


    def remove_last(self):
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
        index = self.index_of(value)

        if index != -1:
            self.remove_by_index(index)    


    def index_of(self, value):
        if self.is_empty(): raise Exception("Lista vazia")

        node = self.head
        for i in range(self.size):
            if node.value == value:
                return i
        
            node = node.next
        
        return -1


    def last_index_of(self, value):
        if self.is_empty(): return

        index = -1

        node = self.head
        for i in range(self.size):
            if node.value == value:
                index = i
            
            node = node.next
        
        return index


    def __get_node_by_index(self, index):
        if index < 0 or index > self.size-1: return

        node = self.head
        for i in range(index):
            node = node.next
        
        return node


    def size_ll(self):
        return self.size


    def contains(self, value):
        return self.index_of(value) != -1


    def toString(self):
        llString = ""   
        node = self.head
        for i in range(self.size):
            llString += node.value
            if node.next != None:
                llString += " -> "
            
            node = node.next
        
        return llString
    

class node:
    def __init__(self, value=None):
        self.value = value
        self.next = None
