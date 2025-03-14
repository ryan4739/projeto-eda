import org.junit.Test;
import static org.junit.Assert.*;

public class Stacktest {
    
    public void test_isEmpty_isFull() {
        Stack stack = new Stack(3);
        assertTrue(stack.isEmpty());
        assertFalse(stack.isFull());
        stack.push(1);
        stack.push(2);
        stack.push(3);
        try{
            stack.push(4);
        }catch (Exception e){
            System.out.prinln(e);
        }
        assertTrue(stack.isFull());
        assertFalse(stack.isEmpty());
        assertEquals(stack.toString(), "1, 2, 3, 4");
    @Test

    public void test_push_pop_toString(){
        Stack stack = new Stack(4);
        try{
            Stack.pop()
        }catch(Exception e){
            System.out.println(e);
        }
        assertTrue(stack.isEmpty());
        assertFalse(stack.isFull());
        stack.push(1);
        stack.push(2);
        stack.push(3);
        assertEquals(stack.toString(), "1, 2, 3");
        stack.pop();
        stack.pop();
        assertEquals(stack.toString(), "1");
        stack.pop();
        assertEquals(stack.toString(), "");
    @Test

    public void test_pushIndex_PushLast(){
        Stack stack = new Stack(5);
        stack.pushIndex(2,0);
        try{
            stack.pushIndex(3,2);
        }catch (Exception e){
            System.out.prinln(e);
        }
        try{
            stack.pushIndex(4,-1);
        }catch (Exception e){
            System.out.prinln(e);
        }
        stack.pushLast(1);
        assertEquals(stack.toString(),"1, 2");
        stack.pushLast(2);
        stack.pushLast(3);
        assertEquals(stack.toString(), "3, 2, 1, 2");
        stack.pushIndex(3,1);
        stack.pushIndex(1,2);
        assertEquals(stack.toString(), "3, 3, 1, 2");
    }
    @Test

    public void test_popIndex_popLast(){
        Stack stack = new Stack(5);
        try{
            stack.popLast();
        }catch (Exception e){
            System.out.prinln(e);
        }    
        try{
            stack.popIndex(1);
        }catch (Exception e){
            System.out.prinln(e);
        }      
        stack.push(2);
        stack.push(3);
        try{
            stack.popIndex(-1);
        }catch (Exception e){
            System.out.prinln(e);
        }
        try{
            stack.popIndex(5);
        }catch (Exception e){
            System.out.prinln(e);
        }
        assertEquals(stack.toString(),"2, 3");
        stack.popIndex(0);
        assertEquals(stack.toString(), "3");
        stack.popLast();
        assertEquals(stack.toString(), "");
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.popLast();
        assertEquals(stack.toString(), "3, 4");
    }
    @Test
    public void test_peek(){
        Stack stack = new Stack(5);
        try{
            stack.peek();
        }catch (Exception e){
            System.out.prinln(e);
        }    
        try{
            stack.peekLast();
        }catch (Exception e){
            System.out.prinln(e);
        }    
        try{
            stack.peekIndex(0);
        }catch (Exception e){
            System.out.prinln(e);
        }    
        stack.push(3);
        stack.push(4);
        stack.push(5);
        assertEquals(stack.peek(), "5");
        stack.pop();
        assertEquals(stack.peek(), "4");
        stack.push(5);
        assertEquals(stack.peekLast(), "3");
        stack.push(6);
        assertEquals(stacl.peekIndex(2), "5");
        assertEquals(stacl.peekIndex(3), "6");
        try{
            stack.peekIndex(-1);
        }catch (Exception e){
            System.out.prinln(e);
        }    
        try{
            stack.peekIndex(5);
        }catch (Exception e){
            System.out.prinln(e);
        }    
    }
    @Test
    public void test_peek(){
        Stack stack = new Stack(5);
        
        stack.push(3);
        stack.push(4);
        stack.push(5);
        assertEquals(stack.peek(), "5");
        stack.pop();
        assertEquals(stack.peek(), "4");
        stack.push(5);
        assertEquals(stack.peekLast(), "3");
        stack.push(6);
        assertEquals(stacl.peekIndex(2), "5");
        assertEquals(stacl.peekIndex(3), "6");
        try{
            stack.peekIndex(-1);
        }catch (Exception e){
            System.out.prinln(e);
        }    
        try{
            stack.peekIndex(5);
        }catch (Exception e){
            System.out.prinln(e);
        }    
    }
    @Test
}
