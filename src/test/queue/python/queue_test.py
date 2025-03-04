import unittest
from src.main.queue.python.queue import Queue

class QueueTest(unittest.TestCase):

    def test_initialization(self):
        q = Queue(5)
        self.assertEqual(q.capacity, 5)
        self.assertEqual(q.size, 0)
        self.assertTrue(q.is_empty())
        self.assertFalse(q.is_full())

    def test_add_last(self):
        q = Queue(3)
        q.add_last(10)
        self.assertEqual(q.get_last(), 10)
        q.add_last(20)
        self.assertEqual(q.get_last(), 20)
        q.add_last(30)
        self.assertEqual(q.get_last(), 30)
        self.assertEqual(q.size, 3)
        self.assertTrue(q.is_full())
        with self.assertRaises(Exception): q.add_last(40)
        self.assertEqual(q.get_last(), 30)

    def test_add_first(self):
        q = Queue(3)
        q.add_first(10)
        self.assertEqual(q.get_first(), 10)
        q.add_first(20)
        self.assertEqual(q.get_first(), 20)
        q.add_first(30)
        self.assertEqual(q.size, 3)
        self.assertEqual(q.get_first(), 30)
        self.assertEqual(q.get_last(), 10)
        self.assertTrue(q.is_full())
        with self.assertRaises(Exception): q.add_first(40)
        self.assertEqual(q.get_first(), 30)

    def test_add(self):
        q = Queue(5)
        q.add_last(10)
        q.add_last(20)
        q.add_last(30)
        q.add(15, 1)  # Adiciona 15 na posição 1
        self.assertEqual(q.size, 4)
        self.assertEqual(q.get(1), 15)
        self.assertEqual(q.get(2), 20)
        with self.assertRaises(Exception): q.add(40, 5)

if __name__ == '__main__':
    unittest.main()
