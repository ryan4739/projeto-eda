import unittest

from main.deque.python.deque import Deque

class TestDeque(unittest.TestCase):

    def setUp(self):
        self.deque = Deque(20)

    def test_append_left(self):
        self.deque.append_left(10)
        self.assertEqual(self.deque.peek_left(), 10)
        self.deque.append_left(20)
        self.assertEqual(self.deque.peek_left(), 20)
        self.deque.append_left(3)
        self.assertEqual(self.deque.peek_left(), 3)
        self.assertEqual(self.deque.cap, 3)
        self.deque.append_left(9)
        self.assertEqual(self.deque.cap, 6)

    def test_append_right(self):
        self.deque.append_right(10)
        self.assertEqual(self.deque.peek_right(), 10)
        self.deque.append_right(20)
        self.assertEqual(self.deque.peek_right(), 20)
        self.deque.append_right(3)
        self.assertEqual(self.deque.peek_right(), 3)
        self.assertEqual(self.deque.cap, 3)
        self.deque.append_right(9)
        self.assertEqual(self.deque.cap, 6)

    def test_pop_right(self):
        with self.assertRaises(IndexError):
            self.deque.pop_right()

        self.deque.append_left(10)
        self.deque.append_right(7)
        self.deque.append_left(20)
        self.deque.append_right(9)

        self.assertEqual(self.deque.pop_right(), 9)
        self.assertEqual(self.deque.pop_right(), 7)
        self.assertEqual(self.deque.pop_right(), 10)
        self.assertEqual(self.deque.pop_right(), 20)

    def test_pop_left(self):
        with self.assertRaises(IndexError):
            self.deque.pop_left()

        self.deque.append_left(10)
        self.deque.append_right(7)
        self.deque.append_left(20)
        self.deque.append_right(9)

        self.assertEqual(self.deque.pop_left(), 20)
        self.assertEqual(self.deque.pop_left(), 10)

    def test_peek_left_and_right(self):
        with self.assertRaises(IndexError):
            self.deque.peek_left()

        with self.assertRaises(IndexError):
            self.deque.peek_right()

        self.deque.append_left(10)
        self.deque.append_left(20)
        self.deque.append_right(7)
        self.deque.append_right(9)

        self.assertEqual(self.deque.peek_left(), 20)
        self.assertEqual(self.deque.peek_right(), 9)

        self.deque.pop_left()
        self.deque.pop_right()

        self.assertEqual(self.deque.peek_left(), 10)
        self.assertEqual(self.deque.pop_right(), 7)

    def test_is_empty(self):
        self.assertTrue(self.deque.is_empty())
        self.deque.append_right(10)
        self.assertFalse(self.deque.is_empty())
        self.deque.pop_left()
        self.assertTrue(self.deque.is_empty())

    def test_contains(self):
        self.deque.append_right(5)
        self.deque.append_right(10)
        self.deque.append_right(15)

        self.assertTrue(self.deque.contains(10))
        self.assertFalse(self.deque.contains(20))

        self.deque.pop_left()
        self.deque.pop_left()

        self.assertFalse(self.deque.contains(10))

    def test_resize(self):
        deque = Deque(2)
        deque.append_right(1)
        deque.append_right(2)
        self.assertEqual(deque.cap, 2)
        self.assertEqual(deque.size, 2)

        deque.append_right(3)
        self.assertEqual(deque.cap, 4)
        self.assertEqual(deque.size, 3)

        self.assertEqual(deque.pop_left(), 1)
        self.assertEqual(deque.pop_left(), 2)
        self.assertEqual(deque.pop_left(), 3)
        self.assertTrue(deque.is_empty())

if __name__ == "__main__":
    unittest.main()
