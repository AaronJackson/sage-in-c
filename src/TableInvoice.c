
#include "TableInvoice.h"

void sage_find_invoices(void (*callback)(TableInvoiceRow*)) {
  Table *invoice = sage_table_open("INVOICE.DTA", sizeof(TableInvoiceRow));

  while (1) {
    TableInvoiceRow *row = malloc(sizeof(TableInvoiceRow));
    row = sage_table_read_next_row(invoice);
    if (row == NULL) break;
    if (row->INVOICE_NUMBER < 1) continue;
    callback(row);
  }

  sage_table_close(invoice);
}

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
