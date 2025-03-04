class Queue:

    def __init__(self, capacity):
        """
        Representação de uma fila.

        Args:
            capacity (int): a capacidade da fila.
        """
        self.capacity = capacity
        self.queue = [None] * capacity
        self.head = -1
        self.tail = -1
        self.size = 0

    def is_empty(self):
        """
        Verifica se a fila está vazia.

        Returns:
            boolean: true, caso a fila esteja vazia, e false, caso não esteja.
        """
        return self.head == - 1 and self.tail == -1

    def is_full(self):
        """
        Verifica se a fila está cheia.

        Returns:
            boolean: true, caso a fila esteja cheia, e false, caso não esteja.
        """
        return (self.tail + 1) % self.capacity == self.head

    def add_last(self, element):
        """
        Adiciona um elemento no final da fila.

        Args:
            element (Any): elemento a ser adicionado.
        """
        if self.is_full():
            raise Exception("Fila está cheia.")
        if self.is_empty():
            self.head = 0
            self.tail = 0
        else:
            self.tail = (self.tail + 1) % self.capacity
        self.queue[self.tail] = element
        self.size += 1

    def add_first(self, element):
        """
        Adiciona um elemento no começo da fila.

        Args:
            element (Any): elemento a ser adicionado.
        """
        if self.is_full():
            raise Exception("Fila está cheia.")
        self.add_last(element)
        for i in range(self.size):
            self.add_last(self.remove_first())

    def add(self, element, index):
        #TODO

    def remove_first(self):
        #TODO

    def remove_last(self):
        #TODO

    def remove(self, index):
        #TODO

    def get_first(self):
        #TODO

    def get_last(self):
        #TODO

    def get(self, index):
        #TODO

    def index_of(self, element):
        #TODO

    def last_index_of(self, element):
        #TODO
