package arraylist;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class ArrayListTest {

    private ArrayList list;

    @BeforeEach
    public void setUp() {
        list = new ArrayList();
    }

    @Test
    public void testAddLast() {
        assertTrue(list.addLast(10));
        assertEquals(10, list.getLast());
        assertTrue(list.addLast(20));
        assertEquals(20, list.getLast());
    }

    @Test
    public void testAddFirst() {
        assertTrue(list.addFirst(10));
        assertEquals(10, list.getFirst());
        assertTrue(list.addFirst(20));
        assertEquals(20, list.getFirst());
        assertEquals(10, list.get(1));
    }

    @Test
    public void testAddIndex() {
        list.addLast(10);
        list.addLast(30);
        assertTrue(list.addIndex(20, 1));
        assertEquals(20, list.get(1));
        assertEquals(30, list.get(2));
    }

    @Test
    public void testAddIndexOutOfBounds() {
        assertThrows(IndexOutOfBoundsException.class, () -> list.addIndex(10, 1));
    }

    @Test
    public void testContains() {
        list.addLast(10);
        list.addLast(20);
        assertTrue(list.contains(10));
        assertTrue(list.contains(20));
        assertFalse(list.contains(30));
    }

    @Test
    public void testRmvLast() {
        list.addLast(10);
        list.addLast(20);
        assertTrue(list.rmvLast());
        assertFalse(list.contains(20));
        assertTrue(list.rmvLast());
        assertTrue(list.isEmpty());
    }

    @Test
    public void testRmvLastEmptyList() {
        assertThrows(NullPointerException.class, () -> list.rmvLast());
    }

    @Test
    public void testRmvFirst() {
        list.addLast(10);
        list.addLast(20);
        assertTrue(list.rmvFirst());
        assertFalse(list.contains(10));
        assertEquals(20, list.getFirst());
    }

    @Test
    public void testRmvIndex() {
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);
        assertTrue(list.rmvIndex(1));
        assertFalse(list.contains(20));
        assertEquals(30, list.get(1));
    }

    @Test
    public void testRmvIndexEmptyList() {
        assertThrows(NullPointerException.class, () -> list.rmvIndex(0));
    }

    @Test
    public void testIsEmpty() {
        assertTrue(list.isEmpty());
        list.addLast(10);
        assertFalse(list.isEmpty());
    }

    @Test
    public void testIsFull() {
        for (int i = 0; i < 20; i++) {
            list.addLast(i);
        }
        assertTrue(list.isFull());
    }

    @Test
    public void testResize() {
        for (int i = 0; i < 25; i++) {
            list.addLast(i);
        }
        assertEquals(25, list.size());
    }

    @Test
    public void testShiftDireita() {
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);
        list.shiftDireita(1);
        assertEquals(10, list.get(0));
        assertEquals(20, list.get(2));
        assertEquals(30, list.get(3));
    }

    @Test
    public void testShiftEsquerda() {
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);
        list.shiftEsquerda(1);
        assertEquals(10, list.get(0));
        assertEquals(30, list.get(1));
    }

    @Test
    public void testGetFirst() {
        list.addLast(10);
        list.addLast(20);
        assertEquals(10, list.getFirst());
    }

    @Test
    public void testGetFirstEmptyList() {
        assertThrows(NullPointerException.class, () -> list.getFirst());
    }

    @Test
    public void testGetLast() {
        list.addLast(10);
        list.addLast(20);
        assertEquals(20, list.getLast());
    }

    @Test
    public void testGetLastEmptyList() {
        assertThrows(NullPointerException.class, () -> list.getLast());
    }

    @Test
    public void testSize() {
        assertEquals(0, list.size());
        list.addLast(10);
        assertEquals(1, list.size());
        list.addLast(20);
        assertEquals(2, list.size());
    }

    @Test
    public void testGet() {
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);
        assertEquals(10, list.get(0));
        assertEquals(20, list.get(1));
        assertEquals(30, list.get(2));
    }

    @Test
    public void testGetOutOfBounds() {
        assertThrows(IndexOutOfBoundsException.class, () -> list.get(0));
    }

}
