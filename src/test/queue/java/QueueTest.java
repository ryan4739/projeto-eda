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
	void addLastInAListWithSpace() {
		assertDoesNotThrow(() -> s1.addLast(12));
		assertEquals(12, s1.getLast());
		s3.addLast(16);
		assertDoesNotThrow(() -> s3.addLast(18));
		assertEquals(18, s3.getLast());
		assertDoesNotThrow(() -> s2.addLast(20));
		assertEquals(20, s2.getLast());
	} 

	@Test
	void addLastInAListWithoutSpace() {
		s2.addLast(12);
		assertThrows(IllegalStateException.class, () -> s2.addLast(22));
		assertEquals(12, s2.getLast());
	}

	@Test
	void addFirstInAListWithSpace() {}

	@Test
	void addFirstInAListWithoutSpace() {}

}
