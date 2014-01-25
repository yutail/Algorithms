void permutation(char *a, int i, int n) {
    int j;
    if (i == n)
        printf("%s\n", a);
    else {
        for (j =i; j<=n; i++) {
            swap(a, i, j);
            permutation(a, i+1, n);
            swap(a, j, i);
        }
    }
}

void swap(char *a, int i, int j) {
    char tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}