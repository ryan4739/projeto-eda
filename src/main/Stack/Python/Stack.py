
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
    def esquerda(valor):
      for i in range(valor,len(self.array)):
         self.array[i-1] = self.array[i]
    def direita(valor):
      for i in range((len(self.array))-1,valor):
         self.array[i+1] = self.array[i]
    def removeLast(self):
      esquerda(1)
      self.tail+=-1
    def removeIndex(index):
      esquerda (index)
      self.tail+=-1
    def pushIndex(index):
        direita(index)
        self.index+=1
    def peek(self,index):
        return self.array[index]
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
   stack1.push(6)
   stack1.pop()
   stack1.push(4)
   print(stack1.size())
   print(stack1.indexOf(4))
   print(stack1.peek(1))
   print(stack1.toString())
