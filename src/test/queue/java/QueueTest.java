package queue;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertFalse;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;


public class QueueTest {
	
	private Queue seq_1;
	private Queue seq_2;

	@BeforeEach
	void prepareTest() {
		seq_1 = new Queue(10);
		seq_2 = new Queue(0);
	}

	@Test
	void insertElementIntoAFullQueue() {
			
	} 

}
