# O mais próximo que existe de um array em Python são Tuplas, que ainda assim 
# tem suas diferenças que comentarei quando chegar a hora
class ArrayList:
    def __init__(self, initial_data=()):
        self.tupla = tuple(initial_data)  # Garante que é uma tupla

    def isEmpty(self):
        return len(self.tupla) == 0

    def outOfBounds(self, index):
        if index < 0 or index >= len(self.tupla):
            raise IndexError(f"Index {index} fora dos limites (tamanho: {len(self.tupla)})")

    def addLast(self, elemento):
        return self.tupla + (elemento,)

    def addFirst(self, elemento):
        return (elemento,) + self.tupla

    def addIndex(self, elemento, index):
        self.outOfBounds(index)  
        return self.tupla[:index] + (elemento,) + self.tupla[index:]

    def rmvLast(self):
        if self.isEmpty():
            raise AttributeError("A lista está vazia")
        return self.tupla[:-1]

    def rmvFirst(self):
        if self.isEmpty():
            raise AttributeError("A lista está vazia")
        return self.tupla[1:]

    def rmvIndex(self, index):
        if self.isEmpty():
            raise AttributeError("A lista está vazia")
        self.outOfBounds(index)
        return self.tupla[:index] + self.tupla[index+1:]

    def contains(self, elemento):
        return elemento in self.tupla  

    def getFirst(self):
        if self.isEmpty():
            raise AttributeError("A lista está vazia")
        return self.tupla[0]

    def getLast(self):
        if self.isEmpty():
            raise AttributeError("A lista está vazia")
        return self.tupla[-1]

    def get(self, index):
        self.outOfBounds(index)
        return self.tupla[index]

    def size(self):
        return len(self.tupla)
