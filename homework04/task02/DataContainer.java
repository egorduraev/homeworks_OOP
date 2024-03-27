package homework04.task02;

import java.util.ArrayList;

public class DataContainer<T> {
    private ArrayList<T> items;

    public DataContainer() {
        this.items = new ArrayList<>();
    }

    public void add(T item) {
        items.add(item);
    }

    public T get(int index) {
        if (index >= 0 && index < items.size()) {
            return items.get(index);
        } else {
            return null;
        }
    }

    public void remove(int index) {
        if (index >= 0 && index < items.size()) {
            items.remove(index);
        }
    }

    public int getSize() {
        return items.size();
    }
}
