import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class LinkedListTest {
    LinkedList ll;

    @BeforeEach
    void setup() {
        this.ll = new LinkedList();
    }

    @Test
    void testIsEmpty() {
        assertTrue(ll.isEmpty());
        assertEquals(0, ll.sizeLL());

        ll.addFirst(10);
        assertFalse(ll.isEmpty());
        assertEquals(1, ll.sizeLL());

        ll.removeFirst();
        assertTrue(ll.isEmpty());

        ll.addLast(10);
        assertFalse(ll.isEmpty());

        ll.removeLast();
        assertTrue(ll.isEmpty());

        ll.addLast(10);
        ll.addLast(20);
        ll.addLast(30);
        assertFalse(ll.isEmpty());
    }

    @Test
    void testAddFirst() {
        ll.addFirst(10);
        assertEquals(10, ll.getFirst());
        assertEquals(1, ll.sizeLL());

        ll.addFirst(20);
        assertEquals(20, ll.getFirst());
        assertEquals(2, ll.sizeLL());
        assertEquals("20 -> 10", ll.toString());

        ll.addFirst(30);
        assertEquals(30, ll.getFirst());
        assertEquals(3, ll.sizeLL());
        assertEquals("30 -> 20 -> 10", ll.toString());

        ll.removeFirst();
        ll.removeFirst();
        ll.removeFirst();
        assertEquals(0, ll.sizeLL());

        ll.addFirst(15);
        assertEquals(15, ll.getFirst());
    }

    @Test
    void testAddLast() {
        ll.addLast(10);
        assertEquals(10, ll.getLast());
        assertEquals(1, ll.sizeLL());

        ll.addLast(20);
        assertEquals(20, ll.getLast());
        assertEquals(2, ll.sizeLL());
        assertEquals("10 -> 20", ll.toString());

        ll.addLast(30);
        assertEquals(30, ll.getLast());
        assertEquals(3, ll.sizeLL());
        assertEquals("10 -> 20 -> 30", ll.toString());

        ll.removeLast();
        ll.removeLast();
        ll.removeLast();
        assertTrue(ll.isEmpty());

        ll.addLast(15);
        assertEquals(15, ll.getFirst());
        assertEquals(15, ll.getLast());
    }

    @Test
    void testAdd() {
        try {
            ll.add(20, 12);
        } catch (Exception e) {
            assertEquals(e.getMessage(), "Índice inválido");
        }

        ll.add(30, 0);
        ll.add(40, 1);
        assertEquals("30 -> 40", ll.toString());

        ll.add(50, 2);
        assertEquals("30 -> 40 -> 50", ll.toString());
        ll.add(60, 3);
        assertEquals("30 -> 40 -> 50 -> 60", ll.toString());
        ll.add(70, 2);
        assertEquals("30 -> 40 -> 70 -> 50 -> 60", ll.toString());
    }

    @Test
    void testContains() {
        try {
            ll.contains(5);
        } catch (Exception e) {
            assertEquals(e.getMessage(), "Lista vazia");
        }

        ll.addLast(10);
        ll.addLast(20);
        ll.addLast(30);
        assertTrue(ll.contains(10));
        assertTrue(ll.contains(20));
        assertTrue(ll.contains(30));
        assertFalse(ll.contains(50));

    }

    @Test
    void testGet() {
        ll.addLast(10);
        assertEquals(10, ll.get(0));

        ll.addLast(20);
        assertEquals(20, ll.get(1));

        ll.addLast(30);
        ll.addLast(40);
        ll.addLast(50);

        assertEquals(50, ll.get(4));
        assertEquals(40, ll.get(3));
        assertEquals(30, ll.get(2));

        try {
            ll.get(20);
        } catch (Exception e) {
            assertEquals(e.getMessage(), "Índice inválido");
        }
    }

    @Test
    void testUpdateNode() {
        try {
            ll.updateNode(5, 0);
        } catch (Exception e) {
            assertEquals(e.getMessage(), "Índice inválido");
        }

        ll.addFirst(10);
        assertEquals(10, ll.get(0));

        ll.updateNode(15, 0);
        assertEquals(15, ll.get(0));
    }

    @Test
    void testRemoveLast() {
        ll.addFirst(10);
        assertEquals(10, ll.getLast());

        ll.removeLast();
        assertTrue(ll.isEmpty());

        ll.addLast(30);
        ll.addLast(45);
        assertEquals(45, ll.getLast());
        ll.removeLast();
        assertEquals(30, ll.getLast());
    }

    @Test
    void testRemoveByIndex() {
        try {
            ll.removeByIndex(0);
        } catch (Exception e) {
            assertEquals(e.getMessage(), "Índice inválido");
        }

        ll.addLast(10);
        ll.addLast(20);
        ll.addLast(30);
        ll.addLast(40);
        ll.addLast(50);
        assertEquals("10 -> 20 -> 30 -> 40 -> 50", ll.toString());

        ll.removeByIndex(1);
        assertEquals("10 -> 30 -> 40 -> 50", ll.toString());

        ll.removeByIndex(0);
        assertEquals("30 -> 40 -> 50", ll.toString());

        ll.removeByIndex(2);
        assertEquals("30 -> 40", ll.toString());
    }

    @Test
    void testRemoveByValue() {
        ll.addLast(10);
        ll.addLast(20);
        ll.addLast(10);
        ll.addLast(30);
        ll.removeByValue(10);
        assertEquals("20 -> 10 -> 30", ll.toString());

        ll.addLast(10);
        assertEquals("20 -> 10 -> 30 -> 10", ll.toString());
        ll.removeByValue(10);
        assertEquals("20 -> 30 -> 10", ll.toString());
    }

    @Test
    void testRemoveFirst() {
        ll.addFirst(10);
        ll.addFirst(20);
        ll.addFirst(30);
        assertEquals("30 -> 20 -> 10", ll.toString());

        ll.removeFirst();
        assertEquals("20 -> 10", ll.toString());

        ll.removeFirst();
        assertEquals("10", ll.toString());

        ll.removeFirst();
        assertEquals("", ll.toString());
    }

    @Test
    void testSizeLL() {
        assertEquals(0, ll.sizeLL());

        ll.addLast(10);
        assertEquals(1, ll.sizeLL());

        ll.removeFirst();
        assertEquals(0, ll.sizeLL());

        ll.addLast(10);
        ll.addLast(20);
        ll.addLast(30);
        assertEquals(3, ll.sizeLL());
    }

    @Test
    void testToString() {
        assertEquals("", ll.toString());

        ll.addFirst(10);
        assertEquals("10", ll.toString());

        ll.addLast(20);
        assertEquals("10 -> 20", ll.toString());

        ll.addFirst(5);
        assertEquals("5 -> 10 -> 20", ll.toString());

        ll.add(15, 1);
        assertEquals("5 -> 15 -> 10 -> 20", ll.toString());

        ll.updateNode(5, 1);
        assertEquals("5 -> 5 -> 10 -> 20", ll.toString());
    }

    @Test
    void testIndexOf() {
        try {
            ll.indexOf(10);
        } catch (Exception e) {
            assertEquals(e.getMessage(), "Lista vazia");
        }

        ll.addLast(10);
        assertEquals(0, ll.indexOf(10));

        ll.addLast(20);
        ll.addLast(10);
        assertEquals(0, ll.indexOf(10));

        ll.removeFirst();
        assertEquals(1, ll.indexOf(10));
    }

    @Test
    void testLastIndexOf() {
        try {
            ll.lastIndexOf(10);
        } catch (Exception e) {
            assertEquals(e.getMessage(), "Lista vazia");
        }

        ll.addLast(10);
        assertEquals(0, ll.lastIndexOf(10));

        ll.addLast(10);
        ll.addLast(10);
        ll.addLast(10);
        assertEquals(3, ll.lastIndexOf(10));
    }
}
