#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "Table.h"

void set_root(char* r) {
  root = r;
}

Table* table_open(const char *filename, size_t row_length) {
  char *path = malloc(200);
  strcat(path, root);
  strcat(path, filename);

  Table *t = malloc(sizeof(Table));

  t->row_length = row_length;
  t->file = fopen(path, "rb");

  free(path);
  
  return t;
}

void table_close(Table *t) {
  fclose(t->file);
  free(t);
}

void* table_read_next_row(Table *t) {
  if (feof(t->file)) return NULL;
  
  char *d = malloc(t->row_length);
  fread(d, 1, t->row_length, t->file);

  return d;
}
