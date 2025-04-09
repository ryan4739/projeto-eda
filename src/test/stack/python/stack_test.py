import unittest
import sys
import os
project_root = os.path.abspath(os.path.join(os.path.dirname(__file__), "../../../../"))

sys.path.insert(0, os.path.join(project_root, "src/main/stack/python"))

from Stack import Stack

class TestMathOperations(unittest.TestCase):
    def test_isEmpty_isFull(self):
        stack1 = Stack(10)
        self.assertTrue(stack1.isEmpty())
        self.assertFalse(stack1.isFull())
        stack1.push(2)
        self.assertFalse(stack1.isEmpty())
        self.assertFalse(stack1.isFull())
        stack1.pop()
        self.assertTrue(stack1.isEmpty())
        stack1.push(0)
        stack1.push(10)
        stack1.push(20)
        stack1.push(30)
        stack1.push(40)
        stack1.push(50)
        stack1.push(60)
        stack1.push(70)
        stack1.push(80)
        stack1.push(100)
        self.assertEqual(stack1.toString(), "0, 10, 20, 30, 40, 50, 60, 70, 80, 100")
        try:
            stack1.push(90)
        except Exception as e:
            print("Está cheia!")
        self.assertTrue(stack1.isFull())
    
    def test_pop_push(self):
        stacks1 = Stack(5)
        self.assertTrue(stacks1.isEmpty())
        try:
            stacks1.pop()
        except Exception as e:
            print("Não ah o que popar")
        stacks1.push(2)
        stacks1.push(10)
        stacks1.pop()
        self.assertEqual(stacks1.toString(), "2")
        stacks1.push(123)
        stacks1.push(421)
        stacks1.push(53)
        stacks1.push(56)
        try:
            stacks1.push(1)
        except Exception as e:
            print("Deu erro")
        stacks1.pop()
        stacks1.pop()
        stacks1.pop()
        self.assertEqual(stacks1.toString(), "2, 123")
    
    def test_pushFirst_RemoveLast(self):
        stacks = Stack(3)
        stacks.push(3)
        stacks.push(2)
        stacks.pushFirst(1)
        self.assertEqual(stacks.toString(), "1, 3, 2")
        stacks.removeLast();
        self.assertEqual(stacks.toString(), "3, 2")
        stacks.pushFirst(1)
        try:
            stacks.pushFirst(0)
        except Exception as e:
            print("Erro")
        stacks.pop()
        stacks.pop()
        stacks.pop()
        try:
            stacks.removeLast();
        except Exception as e:
            print("erro")
    
    def test_pushIndex_peek_indexOf(self):
        stacks4 = Stack(6)
        stacks4.pushIndex(1,0)
        self.assertEqual(stacks4.toString(), "1")
        stacks4.pushIndex(2,0)
        self.assertEqual(stacks4.toString(), "2, 1")
        try:
            stacks4.pushIndex(3,1)
        except Exception as e:
            print("erro")
        stacks4.push(1)
        stacks4.push(3)
        self.assertEqual(stacks4.peekIndex(0), 2)
        self.assertEqual(stacks4.peekIndex(1), 3)
        try:
            stacks4.peekIndex(3)
        except Exception as e:
            print("erro")
        self.assertEqual(stacks4.indexOf(1), 2)
        self.assertNotEqual(stacks4.indexOf(3), 3)
        self.assertEqual(stacks4.indexOf(4), -1)
    def test_peek_peekLast(self):
        stacks = Stack(3)
        self.assertTrue(stacks.isEmpty())
        stacks.push(1)
        stacks.push(2)
        self.assertEqual(stacks.peek(),2)
        stacks.pop()
        self.assertEqual(stacks.peek(),1)
        self.assertEqual(stacks.peek(), stacks.peekLast())
        stacks.push(3)
        self.assertNotEqual(stacks.peek(), stacks.peekLast())
        self.assertEqual(stacks.peekLast(), 1)

    def test_RemoveIndex_PushINdex(self):
        stack3 = Stack(4)
        try:
            stack3.removeIndex(3)
        except Exception as e:
            print("NÃO DEU")
        stack3.pushIndex(1,0)
        stack3.pushIndex(2,1)
        #try:
        #    stack3.PushIndex(4,3)
        #except Exception as e:
        #    print("Não deu")
        stack3.pushIndex(3,2)
        self.assertEqual(stack3.toString(), "1, 2, 3")
        try:
            stack.PushIndex(3,-1)
        except Exception as e:
            print("NÃO DEU")
        stack3.removeIndex(2)
        self.assertEqual(stack3.toString(), "1, 2")


if __name__ == "__main__":
    unittest.main()
