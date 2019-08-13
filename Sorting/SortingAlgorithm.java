public interface SortingAlgorithm<T extends Comparable> {
    void sort(T[] arr);

    default void swap(T[] arr, int a, int b){
        T temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}
