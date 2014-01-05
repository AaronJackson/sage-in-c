#ifndef __TABLEINVOICEITEM_H__
#define __TABLEINVOICEITEM_H__

#include "Table.h"

#pragma pack(push, 1)
typedef struct TableInvoiceItemRow {
  char CODE[31];
  char DESCRIPTION[61];
  char COMMENT_1[61];
  char COMMENT_2[61];
  char UNIT_NAME[9];
  double QUANTITY;
  double _unknown_1;
  double _unknown_2;
  double _unknown_3;
  double PRICE;
  char _unknown_4[362];
} TableInvoiceItemRow;
#pragma pack(pop)

TableInvoiceItemRow* find_invoice_items_by_invoice_number(int invoice_number);

#endif
