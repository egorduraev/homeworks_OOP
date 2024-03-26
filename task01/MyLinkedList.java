package homework03.task01;
import java.util.Iterator;
import java.util.LinkedList;

public class MyLinkedList<T> implements Iterable<T> {
    private LinkedList<T> list;
    
    public MyLinkedList() {
        list = new LinkedList<>();
    }
    
    public void add(T item) {
        list.add(item);
    }

    public void remove(T item) {
        list.remove(item);
    }

    public T get(Integer item) {
        return list.get(item);
    }
    
    @Override
    public Iterator<T> iterator() {
        return list.iterator();
    }
}
