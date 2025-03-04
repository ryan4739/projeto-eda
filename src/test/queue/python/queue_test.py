import unittest
from src.main.queue.python.queue import Queue

class QueueTest(unittest.TestCase):

    def test_initialization(self):
        q = Queue(5)
        self.assertEqual(q.capacity, 5)
        self.assertEqual(q.size, 0)
        self.assertTrue(q.is_empty())
        self.assertFalse(q.is_full())

if __name__ == '__main__':
    unittest.main()
