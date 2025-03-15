package stack;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.Test;

public class StackTest {
    @Test
    public void test_isEmpty_isFull() {
        Stack stack = new Stack(3);
        
        // Verifica se a pilha está vazia no início
        assertTrue(stack.isEmpty());
        assertFalse(stack.isFull());

        // Adiciona elementos
        stack.push(1);
        stack.push(2);
        stack.push(3);

        // Tenta adicionar além do limite (deve gerar uma exceção)
        try {
            stack.push(4);
        } catch (Exception e) {
            System.out.println(e);
        }

        // Agora a pilha deve estar cheia
        assertTrue(stack.isFull());
        assertFalse(stack.isEmpty());

        // Verifica se a pilha contém os elementos corretos
        assertEquals("1, 2, 3", stack.toString()); // Removido o "4" que não deveria estar
    }

    @Test
    public void test_push_pop_toString() {
        Stack stack = new Stack(4);

        // Tenta remover de uma pilha vazia (deve gerar uma exceção)
        try {
            stack.pop();
        } catch (Exception e) {
            System.out.println(e);
        }

        // Confere se a pilha ainda está vazia
        assertTrue(stack.isEmpty());
        assertFalse(stack.isFull());

        // Adiciona elementos
        stack.push(1);
        stack.push(2);
        stack.push(3);

        // Verifica se a conversão para string está correta
        assertEquals("1, 2, 3", stack.toString());

        // Remove elementos e verifica
        stack.pop();
        stack.pop();
        assertEquals("1", stack.toString());

        stack.pop();
        assertEquals("", stack.toString()); // Pilha vazia
    }

    @Test
    public void test_peek() {
        Stack stack = new Stack(5);

        // Testa operações de `peek()` em pilha vazia
        try {
            stack.peek();
        } catch (Exception e) {
            System.out.println(e);
        }

        try {
            stack.peekLast();
        } catch (Exception e) {
            System.out.println(e);
        }

        try {
            stack.peekIndex(0);
        } catch (Exception e) {
            System.out.println(e);
        }

        // Adiciona elementos e testa `peek()`
        stack.push(3);
        stack.push(4);
        stack.push(5);
        assertEquals(5, stack.peek()); // `peek()` deve retornar o topo da pilha

        stack.pop();
        assertEquals(4, stack.peek());

        stack.push(5);
        assertEquals(3, stack.peekLast()); // Último elemento adicionado

        stack.push(6);
        assertEquals(5, stack.peekIndex(2));
        assertEquals(6, stack.peekIndex(3));

        // Testa índices inválidos
        try {
            stack.peekIndex(-1);
        } catch (Exception e) {
            System.out.println(e);
        }

        try {
            stack.peekIndex(5);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    
}
