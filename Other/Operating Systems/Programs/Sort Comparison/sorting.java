import java.util.*;

public class sorting {

    public static void countingSort(int[] arr) {
        int max = Arrays.stream(arr).max().orElse(0);
        int min = Arrays.stream(arr).min().orElse(0);
        int range = max - min + 1;

        int[] count = new int[range];
        for (int num : arr) {
            count[num - min]++;
        }

        int index = 0;
        for (int i = 0; i < range; i++) {
            while (count[i] > 0) {
                arr[index++] = i + min;
                count[i]--;
            }
        }
    }

    // 3-way partition quicksort
    public static void quickSort(int[] arr, int low, int high) {
        if (low >= high) return;

        // Choose a random pivot to avoid worst-case
        int pivotIndex = low + new Random().nextInt(high - low + 1);
        int pivot = arr[pivotIndex];

        int lt = low;    // arr[low..lt-1] < pivot
        int i  = low;    // arr[lt..i-1] == pivot
        int gt = high;   // arr[gt+1..high] > pivot

        while (i <= gt) {
            if (arr[i] < pivot) {
                int tmp = arr[lt]; arr[lt] = arr[i]; arr[i] = tmp;
                lt++; i++;
            } else if (arr[i] > pivot) {
                int tmp = arr[i]; arr[i] = arr[gt]; arr[gt] = tmp;
                gt--;
            } else { // arr[i] == pivot
                i++;
            }
        }

        quickSort(arr, low, lt - 1);
        quickSort(arr, gt + 1, high);
    }

    public static void main(String[] args) {
        final int SIZE = 100000000;
        int[] arr = new int[SIZE];
        Random rand = new Random();
        for (int i = 0; i < SIZE; i++) {
            arr[i] = rand.nextInt(50);
        }

        // Counting Sort
        long startTime = System.currentTimeMillis();
        countingSort(arr);
        long endTime = System.currentTimeMillis();
        System.out.println("Counting Sort took: " + (endTime - startTime) + " ms");

        // Refill array for quicksort test
        for (int i = 0; i < SIZE; i++) {
            arr[i] = rand.nextInt(50);
        }

        // Quick Sort
        long startTimeQS = System.currentTimeMillis();
        quickSort(arr, 0, arr.length - 1);
        long endTimeQS = System.currentTimeMillis();
        System.out.println("Quick Sort took: " + (endTimeQS - startTimeQS) + " ms");
    }
}
