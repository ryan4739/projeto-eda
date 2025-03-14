import unittest
import sys
import os
project_root = os.path.abspath(os.path.join(os.path.dirname(__file__), "../../../../"))

sys.path.insert(0, os.path.join(project_root, "src/main/Stack/python"))

from Stack import Stack

class TestMathOperations(unittest.TestCase):
    def test_isEmpty_isFull(self):
        stack1 = stack(10)
        self.assertTrue(isEmpty())
        self.assertFalse(isFull())
        stack1.push(2)
        self.assertFalse(isEmpty())
        self.assertFalse(isFull())
        stack1.pop()
        self.assertTrue(isEmpty())
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
        self.assertEqual(stacks1.toString(), "0, 10, 20, 30, 40, 50, 60, 70, 80, 100")
        try:
            stack1.push(90)
        except ZeroDivisionError:
            print("Está cheia!")
        self.assertTrue(isFull())
    
    def test_pop_push(self):
        stacks1 = stack(5)
        self.assertTrue(isEmpty())
        try:
            stacks1.pop()
        except NullPointerException:
            print("Não ah o que popar")
        stacks1.push(2)
        stacks1.push(10)
        stacks1.pop()
        self.assertEqual(stacks.toString, "2")
        stacks1.push(123)
        stacks1.push(421)
        stacks1.push(53)
        stacks1.push(56)
        try:
            stacks1.push(1)
        except IndexOutOfBoundries:
            print("Deu erro")
        stacks.pop()
        stacks.pop()
        stacks.pop()
        self.assertEqual(stacks.toString, "2, 123")
    
    def test_pushFirst_RemoveLast(self):
        stacks = Stack(3)
        stacks.push(3)
        stacks.push(2)
        stacks.pushFirst(1)
        self.assertEqual(stacks.toString(), "1, 2, 3")
        stacks.removeLast();
        self.assertEqual(stacks.toString(), "2, 3")
        stacks.pushFirst(1)
        try:
            stacks.pushFirst(0)
        except IndexOutOfBoundries:
            print("Erro")
        stacks.pop()
        stacks.pop()
        stacks.pop()
        try:
            stacks.removeLast();
        except IndexOutOfBoundries:
            print("erro")
    
    def test_pushIndex_peek_indexOf(self):
        stacks = Stack(4)
        stacks.pushIndex(1,0)
        self.assertEqual(stacks.toString(), "1")
        stacks.pushIndex(2,0)
        self.assertEqual(stacks.toString(), "2")
        try:
            stacks.pushIndex(3,1)
        except IndexOutOfBoundries:
            print("erro")
        stacks.push(1)
        stacks.push(3)
        self.AssertEqual(stacks.peekIndex(1), 1)
        self.AssertEqual(stacks.peekIndex(2), 3)
        try:
            stacks.peekIndex(3)
        except IndexOutOfBoundries:
            print("erro")
        self.AssertEqual(stacks.indexOf(1), 1)
        self.AssertNotEqual(Stacks.indexOf(3), 3)
        self.AssertEqual(stacls.indexOf(4), -1)
    def test_peek_peekLast(self):
        stacks = stack(3)
        self.AssertTrue(stacks.isEmpty())
        stacks.push(1)
        stacks.push(2)
        self.AssertEqual(stacks.peek(),1)
        stacks.pop()
        self.AssertEqual(stacks.peek(),2)
        self.AssertEqual(stacks.peek(), stacks.peekLast())
        stacks.push(3)
        self.AssertNotEqual(stacks.peek(), stacks.peekLast())
        self.AssertEqual(stacks.peekLast(), 1)

    def test_RemoveIndex_PushINdex(self):
        stack = stack(3)
        try:
            stack.removeIndex(3)
        except NullPointerException:
            print("NÃO DEU")
        stack.PushIndex(1,0)
        stack.PushIndex(2,1)
        try:
            stack.PushIndex(4,3)
        except NullPointerException:
            print("Não deu")
        stack.PushIndex(3,2)
        self.assertEqual(stack.toString(), "1, 2, 3")
        try:
            stack.PushIndex(3,-1)
        except IndexOutOfBoundries:
            print("NÃO DEU")
        stack.removeIndex(2)
        self.assertEqual(stack.toString(), "1, 2")


if __name__ == "__main__":
    unittest.main()
