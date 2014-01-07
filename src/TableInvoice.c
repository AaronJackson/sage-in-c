
#include "TableInvoice.h"

TableInvoiceRow* sage_find_invoice_by_number(int invoice_number) {
  Table *invoice = sage_table_open("INVOICE.DTA", sizeof(TableInvoiceRow));
  TableInvoiceRow *row = malloc(sizeof(TableInvoiceRow));

  while (1) {
    row = sage_table_read_next_row(invoice);
    if (row == NULL) break;
    if (row->INVOICE_NUMBER == invoice_number) break;
  }

  sage_table_close(invoice);

  return row;
}
