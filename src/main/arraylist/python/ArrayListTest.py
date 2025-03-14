import unittest
from ArrayList import isEmpty, outOfBounds, addLast, addFirst, addIndex, rmvLast, rmvFirst, rmvIndex, contains, size

class TestArrayList(unittest.TestCase):

    def test_isEmpty(self):
        # Testa se a função isEmpty levanta uma exceção para uma tupla vazia
        with self.assertRaises(AttributeError):
            isEmpty(())
        
        # Testa se a função isEmpty não levanta exceção para uma tupla não vazia
        try:
            isEmpty((1, 2, 3))
            self.assertTrue(True)  # Se não levantar exceção, o teste passa
        except AttributeError:
            self.fail("isEmpty levantou AttributeError para uma tupla não vazia")

    def test_outOfBounds(self):
        # Testa se a função outOfBounds levanta uma exceção para índices fora dos limites
        with self.assertRaises(IndexError):
            outOfBounds((1, 2, 3), 3)  # Índice 3 está fora dos limites
        with self.assertRaises(IndexError):
            outOfBounds((1, 2, 3), -1)  # Índice -1 está fora dos limites
        
        # Testa se a função outOfBounds não levanta exceção para índices válidos
        try:
            outOfBounds((1, 2, 3), 0)
            outOfBounds((1, 2, 3), 2)
            self.assertTrue(True)  # Se não levantar exceção, o teste passa
        except IndexError:
            self.fail("outOfBounds levantou IndexError para índices válidos")

    def test_addLast(self):
        # Testa adicionar um elemento no final da tupla
        tupla = (1, 2, 3)
        nova_tupla = addLast(tupla, 4)
        self.assertEqual(nova_tupla, (1, 2, 3, 4))

    def test_addFirst(self):
        # Testa adicionar um elemento no início da tupla
        tupla = (1, 2, 3)
        nova_tupla = addFirst(tupla, 0)
        self.assertEqual(nova_tupla, (0, 1, 2, 3))

    def test_addIndex(self):
        # Testa adicionar um elemento em um índice específico
        tupla = (1, 2, 3)
        nova_tupla = addIndex(tupla, 10, 1)
        self.assertEqual(nova_tupla, (1, 10, 2, 3))

        # Testa se a função levanta exceção para índices fora dos limites
        with self.assertRaises(IndexError):
            addIndex(tupla, 10, 5)

    def test_rmvLast(self):
        # Testa remover o último elemento da tupla
        tupla = (1, 2, 3)
        nova_tupla = rmvLast(tupla)
        self.assertEqual(nova_tupla, (1, 2))

        # Testa se a função levanta exceção para uma tupla vazia
        with self.assertRaises(AttributeError):
            rmvLast(())

    def test_rmvFirst(self):
        # Testa remover o primeiro elemento da tupla
        tupla = (1, 2, 3)
        nova_tupla = rmvFirst(tupla)
        self.assertEqual(nova_tupla, (2, 3))

        # Testa se a função levanta exceção para uma tupla vazia
        with self.assertRaises(AttributeError):
            rmvFirst(())

    def test_rmvIndex(self):
        # Testa remover um elemento em um índice específico
        tupla = (1, 2, 3)
        nova_tupla = rmvIndex(tupla, 1)
        self.assertEqual(nova_tupla, (1, 3))

        # Testa se a função levanta exceção para índices fora dos limites
        with self.assertRaises(IndexError):
            rmvIndex(tupla, 5)

        # Testa se a função levanta exceção para uma tupla vazia
        with self.assertRaises(AttributeError):
            rmvIndex((), 0)

    def test_contains(self):
        # Testa se a função contains retorna True para um elemento presente na tupla
        tupla = (1, 2, 3)
        self.assertTrue(contains(tupla, 2))

        # Testa se a função contains retorna False para um elemento ausente na tupla
        self.assertFalse(contains(tupla, 4))

        # Testa se a função levanta exceção para uma tupla vazia
        with self.assertRaises(AttributeError):
            contains((), 1)

    def test_size(self):
        # Testa o tamanho da tupla
        self.assertEqual(size(()), 0)
        self.assertEqual(size((1, 2, 3)), 3)

if __name__ == '__main__':
    unittest.main()
