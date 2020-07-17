
public void mergeArrays(int[] a, int[] b, int aLength, int bLength) {
    if (aLength + bLength > a.length) throw new IllegalArgumentException();
 
    int aIndex = aLength - 1;
    int bIndex = bLength - 1;
    int mergeIndex = aLength + bLength - 1;
 
    while (aIndex >= 0 && bIndex >= 0) {
        if (a[aIndex] > b[bIndex]) {
            a[mergeIndex] = a[aIndex];
            aIndex--;
        } else {
            a[mergeIndex] = b[bIndex];
            bIndex--;
        }
 
        mergeIndex--;
    }
 
    while (bIndex >= 0) {
        a[mergeIndex] = b[bIndex];
        bIndex--;
        mergeIndex--;
    }
}