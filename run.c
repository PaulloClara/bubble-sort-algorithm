#include "stdio.h"
#include "stdlib.h"

int error(char *error_msg) {
  printf("\n\t\033[1;93m%s\033[0;0m\n", error_msg);
  return 1;
}

void load(const char *input_array[], int *array, size_t array_size) {
  array[array_size-1] = atoi(input_array[array_size]);

  if (array_size == 1) return;
  load(input_array, array, --array_size);
}

void show(int *array, const size_t array_size, size_t i) {
  printf("%d, ", array[i++]);

  if (i >= array_size) return;
  show(array, array_size, i);
}

void sort(int *array, size_t i, size_t j) {
  if (i <= j) return;
  printf("%d ", j);

  if (array[j] > array[j + 1]) {
    int aux = array[j];
    array[j] = array[j + 1];
    array[j + 1] = aux;
  }

  sort(array, i, ++j);
}

void bubble_sort(int *array, size_t i) {
  if (i <= 0) return;
  printf("\ni%d: ", i);

  sort(array, i, 0);
  bubble_sort(array, --i);
}

int main(const int argc, const char *argv[]) {
  if (argc < 3) return error("Array not found!");

  const size_t array_size = argc - 1;
  int array[array_size];

  load(argv, array, array_size);

  bubble_sort(array, array_size - 1);

  printf("\n\n\t[");
  show(array, array_size, 0);
  printf("\b\b]\n\n");

  return 0;
}
