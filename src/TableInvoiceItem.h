#ifndef __TABLEINVOICEITEM_H__
#define __TABLEINVOICEITEM_H__

#include "Table.h"

#pragma pack(push, 1)
typedef struct TableInvoiceItemRow {
  /* Offset 0   */ char STOCK_CODE[31];
  /* Offset 31  */ char DESCRIPTION[61];
  /* Offset 92  */ char COMMENT_1[61];
  /* Offset 153 */ char COMMENT_2[61];
  /* Offset 214 */ char UNIT_NAME[9];
  /* Offset 223 */ double QUANTITY;
  /* Offset 231 */ double _unknown_1;
  /* Offset 239 */ double _unknown_2;
  /* Offset 247 */ double _unknown_3;
  /* Offset 255 */ double FOREIGN_UNIT_PRICE;
                   double UNIT_PRICE;
                   double _unkown_4;
                   double DISCOUNT_RATE;
                   char _unknown_5[18];
                   int INVOICE_NUMBER;
                   char _unknown_6[15];
                   double FOREIGN_FULL_NET_AMOUNT;
                   double FOREIGN_NET_AMOUNT;
                   char _unknown_7[16];
                   double FULL_NET_AMOUNT;
                   double NET_AMOUNT;
                   double TAX_AMOUNT;
                   char NOMINAL_CODE[9];
                   char _unknown_8_bool;
                   short DEPT_NUMBER;
                   char _unknown_9[10];
                   char JOB_NUMBER[61];
                   double _unknown_12;
                   char EXT_ORDER_REF[31];
                   char _unknown_10[38];
                   int ITEM_ID;
                   char _unknown_11[20];
                   int EX_VAR_DESCRIPTION_1;
                   double __UNUSED_0;
                   double DATE_CREATED;
                   double DATE_UPDATED;
                   char __END_OF_RECORD__;
} TableInvoiceItemRow;
#pragma pack(pop)

void find_invoice_items(int invoice_number, void (*callback)(TableInvoiceItemRow*));

#endif
