import unittest

from main.linkedlist.python.linked_list import LinkedList


class LinkedListTest(unittest.TestCase):
    def setUp(self):
        self.ll = LinkedList()

    def tearDown(self):
        while not self.ll.is_empty():
            self.ll.remove_last()

    def test_is_empty(self):
        self.assertTrue(self.ll.is_empty())
        self.assertEqual(0, self.ll.size_ll())

        self.ll.add_first(10)
        self.assertFalse(self.ll.is_empty())
        self.assertEqual(1, self.ll.size_ll())

        self.ll.remove_first()
        self.assertTrue(self.ll.is_empty())

        self.ll.add_last(10)
        self.assertFalse(self.ll.is_empty())

        self.ll.remove_last()
        self.assertTrue(self.ll.is_empty())

        self.ll.add_last(10)
        self.ll.add_last(20)
        self.ll.add_last(30)
        self.assertFalse(self.ll.is_empty())

    def test_add_first(self):
        self.ll.add_first(10)
        self.assertEqual(10, self.ll.get_first())
        self.assertEqual(1, self.ll.size_ll())

        self.ll.add_first(20)
        self.assertEqual(20, self.ll.get_first())
        self.assertEqual(2, self.ll.size_ll())
        self.assertEqual("20 -> 10", self.ll.to_string())

        self.ll.add_first(30)
        self.assertEqual(30, self.ll.get_first())
        self.assertEqual(3, self.ll.size_ll())
        self.assertEqual("30 -> 20 -> 10", self.ll.to_string())

        self.ll.remove_first()
        self.ll.remove_first()
        self.ll.remove_first()
        self.assertEqual(0, self.ll.size_ll())

        self.ll.add_first(15)
        self.assertEqual(15, self.ll.get_first())

    def test_add_last(self):
        self.ll.add_last(10)
        self.assertEqual(10, self.ll.get_last())
        self.assertEqual(1, self.ll.size_ll())

        self.ll.add_last(20)
        self.assertEqual(20, self.ll.get_last())
        self.assertEqual(2, self.ll.size_ll())
        self.assertEqual("10 -> 20", self.ll.to_string())

        self.ll.add_last(30)
        self.assertEqual(30, self.ll.get_last())
        self.assertEqual(3, self.ll.size_ll())
        self.assertEqual("10 -> 20 -> 30", self.ll.to_string())

        self.ll.remove_last()
        self.ll.remove_last()
        self.ll.remove_last()
        self.assertTrue(self.ll.is_empty())

        self.ll.add_last(15)
        self.assertEqual(15, self.ll.get_first())
        self.assertEqual(15, self.ll.get_last())

    def test_add(self):
        try:
            self.ll.add(20, 12)
        except Exception as e:
            self.assertEqual(str(e), "Índice inválido")

        self.ll.add(30, 0)
        self.ll.add(40, 1)
        self.assertEqual("30 -> 40", self.ll.to_string())

        self.ll.add(50, 2)
        self.assertEqual("30 -> 40 -> 50", self.ll.to_string())
        self.ll.add(60, 3)
        self.assertEqual("30 -> 40 -> 50 -> 60", self.ll.to_string())
        self.ll.add(70, 2)
        self.assertEqual("30 -> 40 -> 70 -> 50 -> 60", self.ll.to_string())

    def test_contains(self):
        try:
            self.ll.contains(5)
        except Exception as e:
            self.assertEqual(str(e), "Lista vazia")

        self.ll.add_last(10)
        self.ll.add_last(20)
        self.ll.add_last(30)
        self.assertTrue(self.ll.contains(10))
        self.assertTrue(self.ll.contains(20))
        self.assertTrue(self.ll.contains(30))
        self.assertFalse(self.ll.contains(50))

    def test_get(self):
        self.ll.add_last(10)
        self.assertEqual(10, self.ll.get(0))

        self.ll.add_last(20)
        self.assertEqual(20, self.ll.get(1))

        self.ll.add_last(30)
        self.ll.add_last(40)
        self.ll.add_last(50)

        self.assertEqual(50, self.ll.get(4))
        self.assertEqual(40, self.ll.get(3))
        self.assertEqual(30, self.ll.get(2))

        try:
            self.ll.get(20)
        except Exception as e:
            self.assertEqual(str(e), "Índice inválido")

    def test_update_node(self):
        try:
            self.ll.update_node(5, 0)
        except Exception as e:
            self.assertEqual(str(e), "Índice inválido")

        self.ll.add_first(10)
        self.assertEqual(10, self.ll.get(0))

        self.ll.update_node(15, 0)
        self.assertEqual(15, self.ll.get(0))

    def test_remove_first(self):
        self.ll.add_first(10)
        self.ll.add_first(20)
        self.ll.add_first(30)
        self.assertEqual("30 -> 20 -> 10", self.ll.to_string())

        self.ll.remove_first()
        self.assertEqual("20 -> 10", self.ll.to_string())

        self.ll.remove_first()
        self.assertEqual("10", self.ll.to_string())

        self.ll.remove_first()
        self.assertEqual("", self.ll.to_string())

    def test_remove_last(self):
        self.ll.add_first(10)
        self.assertEqual(10, self.ll.get_last())

        self.ll.remove_last()
        self.assertTrue(self.ll.is_empty())

        self.ll.add_last(30)
        self.ll.add_last(45)
        self.assertEqual(45, self.ll.get_last())
        self.ll.remove_last()
        self.assertEqual(30, self.ll.get_last())

    def test_remove_by_index(self):
        try:
            self.ll.remove_by_index(0)
        except Exception as e:
            self.assertEqual(str(e), "Índice inválido")

        self.ll.add_last(10)
        self.ll.add_last(20)
        self.ll.add_last(30)
        self.ll.add_last(40)
        self.ll.add_last(50)
        self.assertEqual("10 -> 20 -> 30 -> 40 -> 50", self.ll.to_string())

        self.ll.remove_by_index(1)
        self.assertEqual("10 -> 30 -> 40 -> 50", self.ll.to_string())

        self.ll.remove_by_index(0)
        self.assertEqual("30 -> 40 -> 50", self.ll.to_string())

        self.ll.remove_by_index(2)
        self.assertEqual("30 -> 40", self.ll.to_string())

    def test_remove_by_value(self):
        self.ll.add_last(10)
        self.ll.add_last(20)
        self.ll.add_last(10)
        self.ll.add_last(30)
        self.ll.remove_by_value(10)
        self.assertEqual("20 -> 10 -> 30", self.ll.to_string())

        self.ll.add_last(10)
        self.assertEqual("20 -> 10 -> 30 -> 10", self.ll.to_string())
        self.ll.remove_by_value(10)
        self.assertEqual("20 -> 30 -> 10", self.ll.to_string())

    def test_size_ll(self):
        self.assertEqual(0, self.ll.size_ll())

        self.ll.add_last(10)
        self.assertEqual(1, self.ll.size_ll())

        self.ll.remove_first()
        self.assertEqual(0, self.ll.size_ll())

        self.ll.add_last(10)
        self.ll.add_last(20)
        self.ll.add_last(30)
        self.assertEqual(3, self.ll.size_ll())

    def test_to_string(self):
        self.assertEqual("", self.ll.to_string())

        self.ll.add_first(10)
        self.assertEqual("10", self.ll.to_string())

        self.ll.add_last(20)
        self.assertEqual("10 -> 20", self.ll.to_string())

        self.ll.add_first(5)
        self.assertEqual("5 -> 10 -> 20", self.ll.to_string())

        self.ll.add(15, 1)
        self.assertEqual("5 -> 15 -> 10 -> 20", self.ll.to_string())

        self.ll.update_node(5, 1)
        self.assertEqual("5 -> 5 -> 10 -> 20", self.ll.to_string())

    def test_index_of(self):
        try:
            self.ll.index_of(10)
        except Exception as e:
            self.assertEqual(str(e), "Lista vazia")

        self.ll.add_last(10)
        self.assertEqual(0, self.ll.index_of(10))

        self.ll.add_last(20)
        self.ll.add_last(10)
        self.assertEqual(0, self.ll.index_of(10))

        self.ll.remove_first()
        self.assertEqual(1, self.ll.index_of(10))

    def test_last_index_of(self):
        try:
            self.ll.last_index_of(10)
        except Exception as e:
            self.assertEqual(str(e), "Lista vazia")

        self.ll.add_last(10)
        self.assertEqual(0, self.ll.last_index_of(10))

        self.ll.add_last(10)
        self.ll.add_last(10)
        self.ll.add_last(10)
        self.assertEqual(3, self.ll.last_index_of(10))


if __name__ == '__main__':
    unittest.main()
