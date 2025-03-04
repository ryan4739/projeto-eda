package queue;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.Test;


public class QueueTest {

	@Test
    public void testQueueCreation() {
        Queue<Integer> queue = new Queue<>(5);
        assertTrue(queue.isEmpty());
        assertEquals(0, queue.size());
    }

    @Test
    public void testAddLast() {
        Queue<Integer> queue = new Queue<>(5);
        queue.addLast(1);
        queue.addLast(2);
        queue.addLast(3);

        assertFalse(queue.isEmpty());
        assertEquals(3, queue.size());
        assertEquals(1, queue.getFirst());
        assertEquals(3, queue.getLast());
    }

    @Test
    public void testAddFirst() {
        Queue<Integer> queue = new Queue<>(5);
        queue.addLast(1);
        queue.addLast(2);
        queue.addFirst(0);

        assertEquals(3, queue.size());
        assertEquals(0, queue.getFirst());
        assertEquals(2, queue.getLast());
    }

    @Test
    public void testAddAtIndex() {
        Queue<Integer> queue = new Queue<>(5);
        queue.addLast(1);
        queue.addLast(3);
        queue.add(2, 1);

        assertEquals(3, queue.size());
        assertEquals(1, queue.getFirst());
        assertEquals(3, queue.getLast());
        assertEquals(2, queue.get(1));
    }

    @Test
    public void testRemoveFirst() {
        Queue<Integer> queue = new Queue<>(5);
        queue.addLast(1);
        queue.addLast(2);
        queue.addLast(3);

        assertEquals(1, queue.removeFirst());
        assertEquals(2, queue.size());
        assertEquals(2, queue.getFirst());
    }

    @Test
    public void testRemoveLast() {
        Queue<Integer> queue = new Queue<>(5);
        queue.addLast(1);
        queue.addLast(2);
        queue.addLast(3);

        assertEquals(3, queue.removeLast());
        assertEquals(2, queue.size());
        assertEquals(2, queue.getLast());
    }

    @Test
    public void testRemoveAtIndex() {
        Queue<Integer> queue = new Queue<>(5);
        queue.addLast(1);
        queue.addLast(2);
        queue.addLast(3);

        assertEquals(2, queue.remove(1));
        assertEquals(2, queue.size());
        assertEquals(1, queue.getFirst());
        assertEquals(3, queue.getLast());
    }

    @Test
    public void testIndexOf() {
        Queue<Integer> queue = new Queue<>(5);
        queue.addLast(1);
        queue.addLast(2);
        queue.addLast(3);

        assertEquals(1, queue.indexOf(2));
        assertEquals(-1, queue.indexOf(4));
    }

    @Test
    public void testLastIndexOf() {
        Queue<Integer> queue = new Queue<>(5);
        queue.addLast(1);
        queue.addLast(2);
        queue.addLast(2);
        queue.addLast(3);

        assertEquals(2, queue.lastIndexOf(2));
        assertEquals(-1, queue.lastIndexOf(4));
    }

    @Test
    public void testIsFull() {
        Queue<Integer> queue = new Queue<>(3);
        queue.addLast(1);
        queue.addLast(2);
        queue.addLast(3);

        assertTrue(queue.isFull());
        assertThrows(IllegalStateException.class, () -> queue.addLast(4));
    }

    @Test
    public void testIsEmpty() {
        Queue<Integer> queue = new Queue<>(3);
        assertTrue(queue.isEmpty());
        queue.addLast(1);
        assertFalse(queue.isEmpty());
    }

    @Test
    public void testSize() {
        Queue<Integer> queue = new Queue<>(5);
        queue.addLast(1);
        queue.addLast(2);
        queue.addLast(3);

        assertEquals(3, queue.size());
        queue.removeFirst();
        assertEquals(2, queue.size());
    }

}
