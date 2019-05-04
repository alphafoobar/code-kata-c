int chop(int key, int *array, int offset, int length) {
    const int remaining = length - offset;

    if (remaining == 0) {
        return -1;
    }
    if (remaining == 1) {
        return array[offset] == key ? offset : -1;
    }

    int mid_point = remaining / 2;

    int point = offset + mid_point;
    if (array[point] == key) {
        return point;
    }
    if (array[point] > key) {
        return chop(key, array, offset, point);
    }
    return chop(key, array, point, length);
}
