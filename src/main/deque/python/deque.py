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

    def append_left(self, value):
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

    def append_right(self, value):
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

    def pop_left(self):
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

    def pop_right(self):
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

    def peek_left(self):
        """
        Retorna o elemento do início do deque sem removê-lo.

        :return: Valor no início do deque.
        :raises IndexError: Se o deque estiver vazio.
        """
        if self.is_empty():
            raise IndexError("Deque está vazio")
        return self.dq[self.head]

    def peek_right(self):
        """
        Retorna o elemento do final do deque sem removê-lo.

        :return: Valor no final do deque.
        :raises IndexError: Se o deque estiver vazio.
        """
        if self.is_empty():
            raise IndexError("Deque está vazio")
        return self.dq[self.tail]

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
