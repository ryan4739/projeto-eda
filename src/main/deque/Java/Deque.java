import java.util.*;

public class Deque {

    public static void appendLeft(Deque<Integer> dq, int entrada) {
        for (int i = 0; i < entrada; i++) {
            dq.addFirst(i);
        }
    }

    public static void appendRight(Deque<Integer> dq, int entrada) {
        for (int i = 0; i < entrada; i++) {
            dq.addLast(i);
        }
    }

    public static void extendLeft(Deque<Integer> dq, Deque<Integer> valores) {
        dq.addAll(0, valores);
    }

    public static void extendRight(Deque<Integer> dq, Deque<Integer> valores) {
        dq.addAll(valores);
    }

    public static void popLeft(Deque<Integer> dq) {
        while (!dq.isEmpty()) {
            dq.removeFirst();
        }
    }

    public static void popRight(Deque<Integer> dq) {
        while (!dq.isEmpty()) {
            dq.removeLast();
        }
    }

    public static Integer accessLeft(Deque<Integer> dq) {
        return dq.peekFirst();
    }

    public static Integer accessRight(Deque<Integer> dq) {
        return dq.peekLast();
    }

    public static Integer accessRandom(Deque<Integer> dq) {
        if (dq.isEmpty()) return null;
        int index = new Random().nextInt(dq.size());
        int i = 0;
        for (Integer elem : dq) {
            if (i == index) {
                return elem;
            }
            i++;
        }
        return null;
    }

    public static void rotateDeque(Deque<Integer> dq, int n) {
        for (int i = 0; i < n; i++) {
            Integer last = dq.removeLast();
            dq.addFirst(last);
        }
    }

    public static void removeValue(Deque<Integer> dq, Integer value) {
        dq.remove(value);
    }

    public static int countValue(Deque<Integer> dq, Integer value) {
        int count = 0;
        for (Integer elem : dq) {
            if (elem.equals(value)) {
                count++;
            }
        }
        return count;
    }

    
}
