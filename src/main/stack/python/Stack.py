class Stack: 
    tail = -1 
    array = [0]
    def __init__(self, capacidade):
        self.array = [0 for x in range (capacidade)]

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

    def toString(self):
        stregyro= ""
        valor = self.tail+1
        for i in range (valor):
            stregyro+= str(self.array[i])
            self.tail+=-1
            if(not (self.isEmpty())):
                stregyro+= ", "
        self.tail += valor
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
        for i in range(valor,len(self.array)):
            self.array[i-1] = self.array[i]

    def direita(self, valor):
        for i in range((len(self.array))-1,valor):
            self.array[i+1] = self.array[i]

    def removeLast(self):
        if(isEmpty()):
            raise TypeError("Não tem o que remover")
        self.esquerda(1)
        self.tail+=-1

    def removeIndex(index):
        if(isEmpty() or index>tail or index < 0):
            raise TypeError("Não tem nada a remover")
        self.esquerda (index)
        self.tail+=-1

    def pushIndex(self, valor, index):
        if(index > self.tail+1 or index < 0 ):
            raise TypeError("Num deu")
        self.direita(index)
        self.array[index] = valor
        self.tail+=1;

    def peekIndex(self,index):
        if(index>self.tail):
            raise TypeError("Num deu")
        return self.array[index]
    def peek(self):
        if(isEmpty()):
            raise TypeError("Nãp deu")
        return self.array[self.tail]

    def peekLast(self):
        if(isEmpty()):
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
class main:
   stack1 = Stack(9)
   stack1.push(1)
   stack1.pushIndex(6,1)
   stack1.pop()
   stack1.push(4)
   print(stack1.size())
   print(stack1.indexOf(4))
   print(stack1.peekIndex(0))
   print(stack1.toString())
