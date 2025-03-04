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

if __name__ == '__main__':
    unittest.main()
