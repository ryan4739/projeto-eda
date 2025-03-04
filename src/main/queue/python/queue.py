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
        if self.is_full(): raise Exception("Fila está cheia.")
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
        if self.is_full(): raise Exception("Fila está cheia.")
        self.add_last(element)
        for i in range(self.size):
            self.add_last(self.remove_first())

    def add(self, element, index):
        """
        Adiciona um elemento na posição indicada da fila.

        Args:
            element (Any): elemento a ser adicionado.
            index (int): posição para incluir o elemento.
        """
        if self.is_full(): raise Exception("Fila está cheia.")
        if (index < 0 or index >= self.size): raise Exception("Índice inválido.")
        if index == 0: add_first(element)
        elif index == self.size: add_last(element)
        else:
            aux = Queue(self.capacity)
            for _ in range(index):
                aux.add_last(self.remove_first())
            aux.add_last(element)
            for _ in range(self.size):
                aux.add_last(self.remove_first())
            for _ in range(aux.size()):
                self.add_last(aux.remove_first())

    def remove_first(self):
        """
        Remove e retorna o primeiro elemento da fila.

        Returns:
            any: elemento removido.
        """
        if self.is_empty(): raise Exception("Fila está vazia.")
        element = self.queue[self.head]
        self.size -= 1
        if self.head == self.tail:
            self.head = -1
            self.tail = -1
        else:
            self.head = (self.head + 1) % self.capacity
        return element

    def remove_last(self):
        """
        Remove e retorna o último elemento da fila.

        Returns:
            any: elemento removido.
        """
        if self.is_empty(): raise Exception("Fila está vazia.")
        for _ in range(self.size - 1):
            self.add_last(self.remove_first())
        return self.remove_first()

    def remove(self, index):
        """
        Remove e retorna o elemento do índice indicado da fila.

        Returns:
            any: elemento removido.
        """
        if self.is_empty(): raise Exception("Fila está vazia.")
        if index < 0 or index >= self.size: raise Exception("Índice inválido.")
        if index == 0: return self.remove_first()
        elif index == self.size - 1: return self.remove_last()
        else:
            aux = Queue(self.capacity)
        for _ in range(index):
            aux.add_last(self.remove_first())
        element = self.remove_first()
        for _ in range(self.size):
            aux.add_last(self.remove_first())
        for _ in range(aux.size):
            self.add_last(aux.remove_first())
        return element

    def get_first(self):
        """
        Retorna o primeiro elemento da fila.

        Returns:
            any: primeiro elemento da fila.
        """
        if self.is_empty(): raise Exception("Fila está vazia.")
        return self.queue[self.head]

    def get_last(self):
        """
        Retorna o último elemento da fila.

        Returns:
            any: último elemento da fila.
        """
        if self.is_empty(): raise Exception("Fila está vazia.")
        for _ in range(self.size - 1):
            self.add_last(self.remove_first())
        element = self.get_first()
        self.add_last(self.remove_first())
        return element

    def get(self, index):
        """
        Retorna o elemento do índice indicado da fila.

        Returns:
            any: elemento do índice indicado da fila.
        """
        if index < 0 or index >= self.size: raise Exception("Índice inválido.")
        if index == 0: return self.get_first()
        elif index == self.size - 1: return self.get_last()
        else:
            aux = Queue(self.capacity)
        for _ in range(index):
            aux.add_last(self.remove_first())
        element = self.get_first()
        for _ in range(self.size):
            aux.add_last(self.remove_first())
        for _ in range(aux.size):
            self.add_last(aux.remove_first())
        return element

    def index_of(self, element):
        """
        Retorna o índice da primeira ocorrência do elemento na fila.

        Args:
            element (Any): elemento a ser procurado.

        Returns:
            int: índice da primeira ocorrência do elemento, ou -1 se não encontrado.
        """
        if self.is_empty(): raise Exception("Fila está vazia.")
        aux = Queue(self.capacity)
        index = 0
        found = False
        while not self.is_empty():
            current_element = self.remove_first()
            aux.add_last(current_element)
            if not found and current_element == element:
                found = True
                result = index
            index += 1
        while not aux.is_empty():
            self.add_last(aux.remove_first())
        return result if found else -1

    def last_index_of(self, element):
        """
        Retorna o índice da última ocorrência do elemento na fila.

        Args:
            element (Any): elemento a ser procurado.

        Returns:
            int: índice da última ocorrência do elemento, ou -1 se não encontrado.
        """
        if self.is_empty(): raise Exception("Fila está vazia.")
        aux = Queue(self.capacity)
        index = 0
        last_index = -1
        while not self.is_empty():
            current_element = self.remove_first()
            aux.add_last(current_element)
            if current_element == element:
                last_index = index
            index += 1
        while not aux.is_empty():
            self.add_last(aux.remove_first())
        return last_index
