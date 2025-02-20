
class Stack: 
   tail = -1 
   array= [0]
   def __init__(self, capacidade):
        self.array = [0 for x in range capacidadd]
   def pop():
       V= array[tail]
       tail--
       return V
   def isEmpty():
       if(self.tail<0):
           return True
       return False
   def toString():
       stregyro= ""
      for i in range(array.length):
         stregyro+= str(array[i])
         if(!isEmpty()):
            Stregyro+= ", "
            tail--
         return stregyro
   def isFull():
       if(tail+1==self.capacidade.length):
           return True
       return False
   def push(valor):
      array[++tail] = valor
   def esquerda(valor):
      for i in range(valor,array.length):
         array[i-1] = array[i]
   def esquerda(valor):
      for i in range(array.length-1,valor):
         array[i+1] = array[i]
   def removeLast():
      esquerda(1)
      tail--
   def removeIndex(index):
      esquerda (index)
      tail--
   def pushIndex(index):
      
    def peek(index):
        return array[index]
    def size():
        return self.tail+1

   def indexOf():
       return False
class main:
   stack1 = Stack(9)
   print(stack1.capacidade)
