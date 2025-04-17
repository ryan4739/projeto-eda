class Stack: 
    def __init__(self, capacidade):
        self.array = [None for _ in range (capacidade)]
        self.tail=-1
    def pop(self):
        if(self.isEmpty()):
            raise TypeError("Only integers are allowed")
        V= self.array[self.tail]
        self.tail+=-1
        return V

    def isEmpty(self):
       if(self.tail<0):
           return True
       return False
    def pushFirst(self,valor):
        if(self.isFull()):
            raise TypeError("Only integers are allowed")
        self.direita(0)
        self.tail+=1
        self.array[0] = valor
    def toString(self):
        stregyro= ""
        valor1 = self.tail
        valor = self.tail+1
        for i in range(valor):
            if(self.array[i]==None):
                break
            stregyro+= str(self.array[i])
            self.tail-=1
            if((not (self.isEmpty())) and not(self.array[i+1]==None)):
                stregyro+= ", "
        self.tail+=valor
        return stregyro

    def isFull(self):
        if((self.tail+1)==len(self.array)):
            return True
        return False

    def push(self,valor):
        if(self.isFull()):
            raise TypeError("Only integers are allowed")
        self.tail+=1
        self.array[self.tail] = valor

    def esquerda(self, valor):
        for i in range(valor+1,len(self.array)):
            self.array[i-1] = self.array[i]

    def direita(self, valor):
        for i in range(self.tail,valor -1, -1):
            self.array[i+1] = self.array[i]

    def removeLast(self):
        if(self.isEmpty()):
            raise TypeError("Não tem o que remover")
        self.esquerda(0)
        self.tail+=-1

    def removeIndex(self,index):
        if(self.isEmpty() or index>self.tail or index < 0):
            raise TypeError("Não tem nada a remover")
        self.esquerda (index)
        self.tail+=-1

    def pushIndex(self, valor, index):
        if self.isFull():        
            raise OverflowError("Stack cheia")     
        if index > self.tail + 1 or index < 0:
            raise IndexError("Índice fora do limite")
        self.direita(index)
        self.array[index] = valor
        self.tail+=1;

    def peekIndex(self,index):
        if(index>self.tail):
            raise TypeError("Num deu")
        return self.array[index]
    def peek(self):
        if(self.isEmpty()):
            raise TypeError("Nãp deu")
        return self.array[self.tail]

    def peekLast(self):
        if(self.isEmpty()):
            raise TypeError("Nãp deu")
        return self.array[0]
        
    def size(self):
        return self.tail+1

    def indexOf(self,valor):
        primeiro = -1
        for i in range(self.tail+1):
            if(not(primeiro==-1)):
                break
            if(self.array[i]==valor):
                primeiro=i
        return primeiro
