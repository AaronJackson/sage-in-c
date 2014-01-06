
#include "TableInvoice.h"

TableInvoiceRow* find_invoice_by_number(int invoice_number) {
  Table *invoice = table_open("INVOICE.DTA", sizeof(TableInvoiceRow));
  TableInvoiceRow *row = malloc(sizeof(TableInvoiceRow));

  while (1) {
    row = table_read_next_row(invoice);
    if (row == NULL) break;
    if (row->INVOICE_NUMBER == invoice_number) break;
  }

  table_close(invoice);

  return row;
}
