#include "TableInvoiceItem.h"

void find_invoice_items(int invoice_number, void (*callback)(TableInvoiceItemRow*)) {
  Table *invitem = table_open("INVITEM.DTA", sizeof(TableInvoiceItemRow));
  TableInvoiceItemRow *row = malloc(sizeof(TableInvoiceItemRow));

  while (1) {
    row = table_read_next_row(invitem);
    if (row == NULL) break;
    if (row->INVOICE_NUMBER == invoice_number) callback(row);
  }

  table_close(invitem);
}
