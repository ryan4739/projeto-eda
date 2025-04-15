class Deque:
    """
    Implementação de um deque (fila dupla) circular dinâmica.
    """

    def __init__(self, capacity):
        """
        Inicializa o deque com a capacidade especificada.

        :param capacity: Capacidade inicial do deque.
        """
        self.dq = [None] * capacity  # Array para armazenar os elementos
        self.cap = capacity  # Capacidade total
        self.size = 0  # Número de elementos no deque
        self.head = 0  # Índice do primeiro elemento
        self.tail = -1  # Índice do último elemento

    def add_first(self, value):
        """
        Insere um elemento no início do deque.

        :param value: Valor a ser inserido.
        """
        if self.is_full():
            self.resize()
        self.head = (self.head - 1 + self.cap) % self.cap
        self.dq[self.head] = value
        self.size += 1
        if self.size == 1:
            self.tail = self.head

    def add_last(self, value):
        """
        Insere um elemento no final do deque.

        :param value: Valor a ser inserido.
        """
        if self.is_full():
            self.resize()
        self.tail = (self.tail + 1) % self.cap
        self.dq[self.tail] = value
        if self.size == 0:
            self.head = self.tail
        self.size += 1

    def add(self, value, index):
        """
        Insere um valor em uma posição arbitrária do deque      
        :param value: Valor a ser inserido.
        :param index: Índice (relativo ao início lógico) onde inserir.
        :raises IndexError: Se o índice for inválido.
        """
        if index < 0 or index > self.size:
            raise IndexError("Index fora do intervalo válido")

        if self.is_full():
            self.resize()

        insert_pos = (self.head + index) % self.cap

        # Decide se é melhor mover os elementos da esquerda ou da direita
        if index < self.size // 2:
            # Move elementos da esquerda (para a esquerda)
            self.head = (self.head - 1 + self.cap) % self.cap
            for i in range(index):
                from_idx = (self.head + i + 1) % self.cap
                to_idx = (self.head + i) % self.cap
                self.dq[to_idx] = self.dq[from_idx]
            self.dq[insert_pos] = value
        else:
            # Move elementos da direita (para a direita)
            for i in range(self.size, index, -1):
                from_idx = (self.head + i - 1) % self.cap
                to_idx = (self.head + i) % self.cap
                self.dq[to_idx] = self.dq[from_idx]
            self.dq[insert_pos] = value
            self.tail = (self.tail + 1) % self.cap

        self.size += 1

        
    def remove_first(self):
        """
        Remove e retorna o elemento do início do deque.

        :return: Valor removido.
        :raises IndexError: Se o deque estiver vazio.
        """
        if self.is_empty():
            raise IndexError("Deque está vazio")
        value = self.dq[self.head]
        self.head = (self.head + 1) % self.cap
        self.size -= 1
        if self.size == 0:
            self.head = 0
            self.tail = -1
        return value

    def remove_last(self):
        """
        Remove e retorna o elemento do final do deque.

        :return: Valor removido.
        :raises IndexError: Se o deque estiver vazio.
        """
        if self.is_empty():
            raise IndexError("Deque está vazio")
        value = self.dq[self.tail]
        self.tail = (self.tail - 1 + self.cap) % self.cap
        self.size -= 1
        if self.size == 0:
            self.head = 0
            self.tail = -1
        return value

    def remove(self, index):
        """
        Remove e retorna o elemento em uma posição arbitrária do deque.

        :param index: Índice (relativo ao início lógico) do elemento a ser removido.
        :raises IndexError: Se o índice for inválido.
        """
        if self.is_empty():
            raise IndexError("Deque está vazio")
        if index < 0 or index >= self.size:
            raise IndexError("Índice fora do intervalo válido")

        remove_pos = (self.head + index) % self.cap
        value = self.dq[remove_pos]

        # Decide se é melhor mover os elementos da esquerda ou da direita
        if index < self.size // 2:
            # Move elementos da esquerda (para a direita)
            for i in range(index, 0, -1):
                from_idx = (self.head + i - 1) % self.cap
                to_idx = (self.head + i) % self.cap
                self.dq[to_idx] = self.dq[from_idx]
            self.dq[self.head] = None
            self.head = (self.head + 1) % self.cap
        else:
            # Move elementos da direita (para a esquerda)
            for i in range(index, self.size - 1):
                from_idx = (self.head + i + 1) % self.cap
                to_idx = (self.head + i) % self.cap
                self.dq[to_idx] = self.dq[from_idx]
            self.dq[self.tail] = None
            self.tail = (self.tail - 1 + self.cap) % self.cap

        self.size -= 1
        if self.size == 0:
            self.head = 0
            self.tail = -1

        return value
        

    def get_first(self):
        """
        Retorna o elemento do início do deque sem removê-lo.

        :return: Valor no início do deque.
        :raises IndexError: Se o deque estiver vazio.
        """
        if self.is_empty():
            raise IndexError("Deque está vazio")
        return self.dq[self.head]

    def get_last(self):
        """
        Retorna o elemento do final do deque sem removê-lo.

        :return: Valor no final do deque.
        :raises IndexError: Se o deque estiver vazio.
        """
        if self.is_empty():
            raise IndexError("Deque está vazio")
        return self.dq[self.tail]

    def get(self, index):
        """
        Retorna o elemento na posição especificada do deque sem removê-lo.
    
        :param index: Índice (relativo ao início lógico) do elemento.
        :return: Valor encontrado.
        :raises IndexError: Se o índice for inválido.
        """
        if self.is_empty():
            raise IndexError("Deque está vazio")
        if index < 0 or index >= self.size:
            raise IndexError("Índice fora do intervalo válido")
    
        return self.dq[(self.head + index) % self.cap]
    
    def is_full(self):
        """
        Verifica se o deque está cheio.

        :return: True se o deque estiver cheio, False caso contrário.
        """
        return self.size == self.cap

    def is_empty(self):
        """
        Verifica se o deque está vazio.

        :return: True se o deque estiver vazio, False caso contrário.
        """
        return self.size == 0

    def contains(self, value):
        """
        Verifica se um valor está presente no deque.

        :param value: Valor a ser procurado.
        :return: True se o valor estiver presente, False caso contrário.
        """
        for i in range(self.size):
            if self.dq[(self.head + i) % self.cap] == value:
                return True
        return False

    def __str__(self):
        """
        Retorna uma representação em string do deque.

        :return: String formatada com os elementos do deque.
        """
        if self.is_empty():
            return "[]"
        result = [str(self.dq[(self.head + i) % self.cap]) for i in range(self.size)]
        return "[" + ", ".join(result) + "]"

    def resize(self):
        """
        Redimensiona o deque para o dobro da capacidade atual.
        """
        new_cap = self.cap * 2
        new_dq = [None] * new_cap
        for i in range(self.size):
            new_dq[i] = self.dq[(self.head + i) % self.cap]
        self.dq = new_dq
        self.head = 0
        self.tail = self.size - 1
        self.cap = new_cap
