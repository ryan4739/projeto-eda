import unittest
import sys
import os

# Adicionando o diretório raiz do projeto ao sys.path para importação do módulo Stack
project_root = os.path.abspath(os.path.join(os.path.dirname(__file__), "../../../../"))
sys.path.insert(0, os.path.join(project_root, "src/main/Stack/python"))

from Stack import Stack  # Importando a classe Stack

class TestMathOperations(unittest.TestCase):  # Classe de testes unitários
    def test_isEmpty_isFull(self):
        stack1 = stack(10)  # ERRO: 'stack' deveria ser 'Stack' (case-sensitive)
        self.assertTrue(isEmpty())  # ERRO: isEmpty() deveria ser stack1.isEmpty()
        self.assertFalse(isFull())  # ERRO: isFull() deveria ser stack1.isFull()
        
        stack1.push(2)
        self.assertFalse(isEmpty())  # ERRO: Novamente deveria ser stack1.isEmpty()
        self.assertFalse(isFull())  # ERRO: Deveria ser stack1.isFull()
        
        stack1.pop()
        self.assertTrue(isEmpty())  # ERRO: stack1.isEmpty()

        # ERRO: 'stacks1' não foi declarado antes, deveria ser 'stack1'
        stacks1.push(0)
        stacks1.push(10)
        stacks1.push(20)
        stacks1.push(30)
        stacks1.push(40)
        stacks1.push(50)
        stacks1.push(60)
        stacks1.push(70)
        stacks1.push(80)
        stacks1.push(100)
        
        # Corrigindo a verificação
        self.assertEqual(stack1.toString(), "0, 10, 20, 30, 40, 50, 60, 70, 80, 100")
        
        try:
            stack1.push(90)
        except ZeroDivisionError:  # ERRO: A exceção correta seria IndexError (ou outra específica)
            print("Está cheia!")
        
        self.assertTrue(isFull())  # ERRO: deveria ser stack1.isFull()

    def test_pop_push(self):
        stacks1 = stack(5)  # ERRO: 'stack' deveria ser 'Stack'
        self.assertTrue(isEmpty())  # ERRO: stacks1.isEmpty()
        
        try:
            stacks1.pop()
        except NullPointerException:  # ERRO: Em Python, deveria ser IndexError
            print("Não há o que popar")
        
        stacks1.push(2)
        stacks1.push(10)
        stacks1.pop()
        
        # ERRO: 'stacks' está incorreto, deveria ser 'stacks1' e 'toString' deveria ser chamado com ()
        self.assertEqual(stacks.toString, "2") 
        
        stacks1.push(123)
        stacks1.push(421)
        stacks1.push(53)
        stacks1.push(56)
        
        try:
            stacks1.push(1)
        except IndexOutOfBoundries:  # ERRO: Exceção inválida, deveria ser IndexError
            print("Deu erro")
        
        stacks.pop()  # ERRO: deveria ser stacks1.pop()
        stacks.pop()
        stacks.pop()
        
        self.assertEqual(stacks.toString, "2, 123")  # ERRO: novamente stacks1.toString()

    def test_pushFirst_RemoveLast(self):
        stacks = Stack(3)
        stacks.push(3)
        stacks.push(2)
        stacks.pushFirst(1)  # ERRO: Método 'pushFirst' pode não existir na implementação
        self.assertEqual(stacks.toString(), "1, 2, 3")
        
        stacks.removeLast()  # ERRO: pode ser que o nome correto do método seja 'popLast'
        self.assertEqual(stacks.toString(), "2, 3")
        
        stacks.pushFirst(1)
        try:
            stacks.pushFirst(0)
        except IndexOutOfBoundries:  # ERRO: Exceção incorreta, deveria ser IndexError
            print("Erro")
        
        stacks.pop()
        stacks.pop()
        stacks.pop()
        
        try:
            stacks.removeLast()
        except IndexOutOfBoundries:
            print("erro")

    def test_pushIndex_peek_indexOf(self):
        stacks = Stack(4)
        stacks.pushIndex(1, 0)  # ERRO: O método pode não existir, verificar implementação
        self.assertEqual(stacks.toString(), "1")
        
        stacks.pushIndex(2, 0)
        self.assertEqual(stacks.toString(), "2")
        
        try:
            stacks.pushIndex(3, 1)
        except IndexOutOfBoundries:  # ERRO: IndexError seria mais apropriado
            print("erro")
        
        stacks.push(1)
        stacks.push(3)
        
        self.AssertEqual(stacks.peekIndex(1), 1)  # ERRO: 'AssertEqual' deveria ser 'assertEqual'
        self.AssertEqual(stacks.peekIndex(2), 3)

        try:
            stacks.peekIndex(3)
        except IndexOutOfBoundries:
            print("erro")

        self.AssertEqual(stacks.indexOf(1), 1)
        self.AssertNotEqual(Stacks.indexOf(3), 3)  # ERRO: 'Stacks' com maiúscula está incorreto
        self.AssertEqual(stacls.indexOf(4), -1)  # ERRO: 'stacls' tem um erro de digitação

    def test_peek_peekLast(self):
        stacks = stack(3)  # ERRO: 'stack' deveria ser 'Stack'
        self.AssertTrue(stacks.isEmpty())  # ERRO: 'AssertTrue' deveria ser 'assertTrue'
        
        stacks.push(1)
        stacks.push(2)
        
        self.AssertEqual(stacks.peek(), 1)  # ERRO: 'assertEqual'
        
        stacks.pop()
        self.AssertEqual(stacks.peek(), 2)
        self.AssertEqual(stacks.peek(), stacks.peekLast())
        
        stacks.push(3)
        self.AssertNotEqual(stacks.peek(), stacks.peekLast())
        self.AssertEqual(stacks.peekLast(), 1)

    def test_RemoveIndex_PushINdex(self):
        stack = stack(3)  # ERRO: 'stack' deveria ser 'Stack'
        
        try:
            stack.removeIndex(3)
        except NullPointerException:  # ERRO: deveria ser IndexError
            print("NÃO DEU")
        
        stack.PushIndex(1, 0)  # ERRO: método provavelmente deveria ser 'pushIndex'
        stack.PushIndex(2, 1)
        
        try:
            stack.PushIndex(4, 3)
        except NullPointerException:
            print("Não deu")
        
        stack.PushIndex(3, 2)
        self.assertEqual(stack.toString(), "1, 2, 3")
        
        try:
            stack.PushIndex(3, -1)
        except IndexOutOfBoundries:  # ERRO: IndexError seria mais correto
            print("NÃO DEU")
        
        stack.removeIndex(2)
        self.assertEqual(stack.toString(), "1, 2")


if __name__ == "__main__":
    unittest.main()
