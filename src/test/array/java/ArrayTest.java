package array;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertFalse;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class ArrayTest {

	private Array array_1 = new Array(10);
	private Array array_2 = new Array(10);

	@BeforeEach
	void prepareTest() {
		array_2.setElement(12, 0);
		array_2.setElement(18, 1);
		array_2.setElement(24, 3);
		array_2.setElement(32, 9);
	}

	@Test
	void setElement() {
		assertEquals(null ,array_1.getElement(0));
		assertTrue(array_1.setElement(23, 0));
		assertEquals(null ,array_1.getElement(9));
		assertTrue(array_1.setElement(48, 9));
		assertFalse(array_1.setElement(54, 10));
	}

	@Test
	void getElement() {
		assertEquals(12, array_2.getElement(0));
		assertNotEquals(12, array_2.getElement(1));
	} 

	@Test
	void rmElement() {
		assertTrue(array_2.rmElement(0));
		assertEquals(null, array_2.getElement(0));
	}

}
