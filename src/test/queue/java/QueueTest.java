package queue;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;


public class QueueTest {
	
	private Queue s1;
	private Queue s2;
	private Queue s3;

	@BeforeEach
	void prepareTest() {
		s1 = new Queue(10);
		s2 = new Queue(1);
		s3 = new Queue(10);
	}

	@Test
	void addLastWithSpace() {
		assertDoesNotThrow(() -> s1.addLast(12));
		assertEquals(12, s1.getLast());
		s3.addLast(16);
		assertDoesNotThrow(() -> s3.addLast(18));
		assertEquals(18, s3.getLast());
		assertDoesNotThrow(() -> s2.addLast(20));
		assertEquals(20, s2.getLast());
	} 

	@Test
	void addLastWithoutSpace() {
		s2.addLast(12);
		assertThrows(IllegalStateException.class, () -> s2.addLast(22));
		assertEquals(12, s2.getLast());
	}

	@Test
	void addFirstWithSpace() {
		s1.addFirst(10);
		assertEquals(10, s1.getFirst());
		s1.addFirst(20);
		assertEquals(20, s1.getFirst());
	}

	@Test
	void addFirstWithoutSpace() {
		s2.addFirst(10);
		assertThrows(IllegalStateException.class, () -> s2.addFirst(20));
	}

	@Test
	void addWithSpace() {
		s1.addLast(10);
		s1.addLast(20);
		s1.add(15, 1);
		assertEquals(15, s1.get(1));
	}

	@Test
	void addWithoutSpace() {
		s2.addLast(10);
		assertThrows(IllegalStateException.class, () -> s2.add(20, 1));
	}

	@Test
	void addInvalidIndex() {
		assertThrows(IndexOutOfBoundsException.class, () -> s1.add(10, -1));
		assertThrows(IndexOutOfBoundsException.class, () -> s1.add(10, 11));
	}

	@Test
	void removeFirstNotEmptyQueue() {
		s1.addLast(10);
		s1.addLast(20);
		assertEquals(10, s1.removeFirst());
		assertEquals(20, s1.getFirst());
	}

	@Test
	void removeFirstEmptyQueue() {
		assertThrows(IllegalStateException.class, () -> s1.removeFirst());
	}

	@Test
	void removeLastNotEmptyQueue() {
		s1.addLast(10);
		s1.addLast(20);
		assertEquals(20, s1.removeLast());
		assertEquals(10, s1.getLast());
	}

	@Test
	void removeLastEmptyQueue() {
		assertThrows(IllegalStateException.class, () -> s1.removeLast());
	}

	@Test
	void removeNotEmptyQueue() {
		s1.addLast(10);
		s1.addLast(20);
		s1.addLast(30);
		assertEquals(20, s1.remove(1));
		assertEquals(30, s1.get(1));
	}

	@Test
	void removeEmptyQueue() {
		assertThrows(IllegalStateException.class, () -> s1.remove(0));
	}

	@Test
	void removeInvalidIndex() {
		s1.addLast(10);
		s1.addLast(20);
		assertThrows(IndexOutOfBoundsException.class, () -> s1.remove(-1));
		assertThrows(IndexOutOfBoundsException.class, () -> s1.remove(10));
	}

	@Test
	void getFirstNotEmptyQueue() {
		s1.addLast(10);
		s1.addLast(20);
    assertEquals(10, s1.getFirst());
	}

	@Test
	void getFirstEmptyQueue() {
		assertThrows(IllegalStateException.class, () -> s1.getFirst());
	}

}
