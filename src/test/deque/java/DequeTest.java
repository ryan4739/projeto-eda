package test.deque.java;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.NoSuchElementException; 


public class DequeTest {

    Deque deque;
    @BeforeEach
    void setup() {
        deque = new Deque();
    }
    @Test
    public void testAppendLeft() {
        deque = new Deque(3);
        deque.appendLeft(10);
        assertEquals(10, deque.peekLeft());
        deque.appendLeft(20);
        assertEquals(20, deque.peekLeft());
        deque.appendLeft(3);
        assertEquals(3, deque.peekLeft());
        assertEquals(3,deque.getCapacity());
        deque.appendLeft(9);
        assertEquals(6,deque.getCapacity());

    }

    @Test
    public void testAppendRight() {
        
        deque = new Deque(3);
        deque.appendRight(10);
        assertEquals(10, deque.peekRight());
        deque.appendRight(20);
        assertEquals(20, deque.peekRight());
        deque.appendRight(3);
        assertEquals(3, deque.peekRight());
        assertEquals(3,deque.getCapacity());
        deque.appendRight(9);
        assertEquals(6,deque.getCapacity());

    }

    @Test
    public void testPopRight() {
        try {
            deque.popRight();
        } catch (NoSuchElementException e) {
            assertEquals("O Deque está vazio", e.getMessage());  
        }
        deque.appendLeft(10);
        deque.appendRight(7);
        deque.appendLeft(20);
        deque.appendRight(9);
        assertEquals(9, deque.popRight());
        assertEquals(7, deque.popRight());
        assertEquals(10, deque.popRight());
        assertEquals(20, deque.popRight());
    }

    @Test
    public void testPopLeft() {
        try {
            deque.popLeft();
        } catch (NoSuchElementException e) {
            assertEquals("O Deque está vazio", e.getMessage()); 
        }
        deque.appendLeft(10);
        deque.appendRight(7);
        deque.appendLeft(20);
        deque.appendRight(9);
        assertEquals(20, deque.popLeft());
        assertEquals(10, deque.popLeft());
        assertEquals(7, deque.popLeft());
        assertEquals(9, deque.popLeft());
    }

    @Test
    public void testPeekLeftAndRight() {
        try {
            deque.peekLeft();
        } catch (NoSuchElementException e) {
            assertEquals("O Deque está vazio", e.getMessage()); 
        }
        try {
            deque.peekLeft();
        } catch (NoSuchElementException e) {
            assertEquals("O Deque está vazio", e.getMessage()); 
        }
        deque.appendLeft(10);
        deque.appendLeft(20);
        deque.appendRight(7);
        deque.appendRight(9);
        assertEquals(20, deque.peekLeft());
        assertEquals(9, deque.peekRight());
        deque.popLeft();
        deque.popRight();
        assertEquals(10, deque.peekLeft());
        assertEquals(7, deque.popRight());

    }

    @Test
    public void testIsEmpty() {
        
        assertTrue(deque.isEmpty());
        deque.appendRight(10);
        assertFalse(deque.isEmpty());
        deque.popLeft();
        assertTrue(deque.isEmpty());
    }

    @Test
    public void testContains() {
        
        deque.appendRight(5);
        deque.appendRight(10);
        deque.appendRight(15);
        assertTrue(deque.contains(10));
        assertFalse(deque.contains(20));
        deque.popLeft();
        deque.popLeft();
        assertFalse(deque.contains(10));

    }
    
    @Test
    public void testResize() {
        Deque deque = new Deque(2);
        deque.appendRight(1);
        deque.appendRight(2);
        assertEquals(2, deque.getCapacity());        
        assertEquals(2, deque.getSize());
        deque.appendRight(3);
        assertEquals(4, deque.getCapacity());        
        assertEquals(3, deque.getSize());
        assertEquals(1, deque.popLeft());
        assertEquals(2, deque.popLeft());
        assertEquals(3, deque.popLeft());
        assertTrue(deque.isEmpty());
    }
    
}