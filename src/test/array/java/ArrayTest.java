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
		array_2.insertElement(12, 0);
		array_2.insertElement(18, 1);
		array_2.insertElement(24, 3);
		array_2.insertElement(32, 9);
	}

	@Test
	void insertElement() {
		//assertEquals(null ,array_1.getElement(0));
		assertTrue(array_1.insertElement(23, 0));
		//assertEquals(null ,array_1.Element(9));
		assertTrue(array_1.insertElement(48, 9));
		assertFalse(array_1.insertElement(54, 10));
	}

	@Test
	void searchElement() {
		assertEquals(0, array_2.searchElement(12));
		assertEquals(-1, array_2.searchElement(77));
	} 

	@Test
	void removeElement() {
		assertTrue(array_2.removeElement(0));
		//assertEquals(null, array_2.getElement(0));
	}

}
