import unittest
from src.main.queue.python.queue import Queue

class QueueTest(unittest.TestCase):

    def test_initialization(self):
        q = Queue(5)
        self.assertEqual(q.capacity, 5)
        self.assertEqual(q.size, 0)
        self.assertTrue(q.is_empty())
        self.assertFalse(q.is_full())
        print('Testes de inicialização da fila passaram!\n')

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
        print('Testes de adição no final da fila passaram!')

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
        print('Testes de adição no começo da fila passaram!')

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
        print('Testes de adição em índice determinado da fila passaram!')

    def test_remove_first(self):
        q = Queue(3)
        q.add_last(10)
        q.add_last(20)
        q.add_last(30)
        self.assertEqual(q.remove_first(), 10)
        self.assertEqual(q.size, 2)
        self.assertEqual(q.remove_first(), 20)
        self.assertEqual(q.remove_first(), 30)
        self.assertTrue(q.is_empty())
        with self.assertRaises(Exception): q.remove_first()
        print('Testes de remoção no começo da fila passaram!')

    def test_remove_last(self):
        q = Queue(3)
        q.add_last(10)
        q.add_last(20)
        q.add_last(30)
        self.assertEqual(q.remove_last(), 30)
        self.assertEqual(q.size, 2)
        self.assertEqual(q.remove_last(), 20)
        self.assertEqual(q.remove_last(), 10)
        self.assertTrue(q.is_empty())
        with self.assertRaises(Exception): q.remove_last()
        print('Testes de remoção no final da fila passaram!')

    def test_remove(self):
        q = Queue(5)
        q.add_last(10)
        q.add_last(20)
        q.add_last(30)
        q.add_last(40)
        self.assertEqual(q.remove(2), 30)
        self.assertEqual(q.size, 3)
        self.assertEqual(q.get(2), 40)
        with self.assertRaises(Exception): q.remove(5)
        print('Testes de remoção em determinado índice da fila passaram!')

    def test_get_first(self):
        q = Queue(3)
        q.add_last(10)
        q.add_last(20)
        q.add_last(30)
        self.assertEqual(q.get_first(), 10)
        q.remove_first()
        self.assertEqual(q.get_first(), 20)
        q.remove_first()
        self.assertEqual(q.get_first(), 30)
        q.remove_first()
        with self.assertRaises(Exception): q.get_first()
        print('Testes de busca no começo da fila passaram!')

    def test_get_last(self):
        q = Queue(3)
        q.add_last(10)
        q.add_last(20)
        q.add_last(30)
        self.assertEqual(q.get_last(), 30)
        q.remove_last()
        self.assertEqual(q.get_last(), 20)
        q.remove_last()
        self.assertEqual(q.get_last(), 10)
        q.remove_last()
        with self.assertRaises(Exception): q.get_last()
        print('Testes de busca no final da fila passaram!')

    def test_get(self):
        q = Queue(5)
        q.add_last(10)
        q.add_last(20)
        q.add_last(30)
        q.add_last(40)
        self.assertEqual(q.get(0), 10)
        self.assertEqual(q.get(2), 30)
        self.assertEqual(q.get(3), 40)
        with self.assertRaises(Exception): q.get(5)
        print('Testes de busca em determinado índice da fila passaram!')

    def test_index_of(self):
        q = Queue(5)
        q.add_last(10)
        q.add_last(20)
        q.add_last(30)
        q.add_last(20)
        self.assertEqual(q.index_of(20), 1)
        self.assertEqual(q.index_of(30), 2)
        self.assertEqual(q.index_of(40), -1)
        print('Testes de busca por primeiro elemento passaram!')

    def test_last_index_of(self):
        q = Queue(5)
        q.add_last(10)
        q.add_last(20)
        q.add_last(30)
        q.add_last(20)
        self.assertEqual(q.last_index_of(20), 3)
        self.assertEqual(q.last_index_of(30), 2)
        self.assertEqual(q.last_index_of(40), -1)
        print('Testes de busca por último elemento passaram!')

if __name__ == '__main__':
    unittest.main()
