#ifndef __TABLE_H__
#define __TABLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Table {
  FILE *file;
  size_t row_length;
  void *field_lookup;
} Table;

char *root;
void sage_set_root(char* r);

/**
 * @brief Opens the table
 * 
 * @param filename The path to the file, e.g. ../INVOICE.DTA
 */
Table* sage_table_open(const char *filename, size_t row_length);

/**
 * @brief Closes the table
 */
void sage_table_close(Table *t);

/**
 * @brief Returns a byte array of one row 
 * @details Returns a pointer to a byte array containing the data
 *          from the next row. This can then be cast to the 
 *          struct of your choice. For example, InvoiceRow.
 * 
 * @param rowLength The length of a single row in this table
 * @return Pointer to the byte array
 */
void* sage_table_read_next_row(Table *t);

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param t [description]
 * @return [description]
 */
void* sage_table_find_row(Table *t);

#endif
