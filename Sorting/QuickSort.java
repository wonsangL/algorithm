import com.sun.istack.internal.NotNull;

public class QuickSort<T extends Comparable> implements SortingAlgorithm<T> {
    public void sort(@NotNull T[] arr){
        doSort(arr, 0, arr.length - 1);
    }

    private void doSort(T[] arr, int head, int tail){
        if(head >= tail){
            return;
        }

        int pivot = (head + tail) / 2, l_cursor = head, r_cursor = tail;

        while(l_cursor < r_cursor){
            while(l_cursor <= r_cursor && arr[l_cursor].compareTo(arr[pivot]) <= 0){
                l_cursor++;
            }

            while(r_cursor >= l_cursor && arr[r_cursor].compareTo(arr[pivot]) > 0){
                r_cursor--;
            }

            if(l_cursor < r_cursor){
                swap(arr, l_cursor, r_cursor);
            }
        }

        swap(arr, pivot, r_cursor);
        doSort(arr, head, r_cursor - 1);
        doSort(arr, r_cursor + 1, tail);
    }
}