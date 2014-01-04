#ifndef __TABLEINVOICE_H__
#define __TABLEINVOICE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "Table.h"

#pragma pack(push, 1)
typedef struct TableInvoiceRow {
  int INVOICE_NUMBER;
  char TAG[9];
  char COMPANY_NAME[61];
  char COMPANY_ADDRESS_LINE_1[61];
  char COMPANY_ADDRESS_LINE_2[61];
  char COMPANY_ADDRESS_TOWN[61];
  char COMPANY_ADDRESS_COUNTY[61];
  char COMPANY_ADDRESS_POST_CODE[61];
  char DELIVERY_COMPANY_NAME[61];
  char DELIVERY_ADDRESS_LINE_1[61];
  char DELIVERY_ADDRESS_LINE_2[61];
  char DELIVERY_ADDRESS_TOWN[61];
  char DELIVERY_ADDRESS_COUNTY[61];
  char DELIVERY_ADDRESS_POST_CODE[61];
  char CONTACT_NAME[31];
  char CUSTOMER_NUMBER[11];
  char ORDER_NUMBER[8];
  char USERNAME[61];
  char CUSTOMER_ORDER_NUMBER[61];
  char CUSTOMER_TELEPHONE[31];
  char NOTES_1[61];
  char NOTES_2[61];
  char NOTES_3[61];
  char PAYMENT_REFERENCE[31];
  char COURIER_NC[9];
  char PAYMENT_BANK_ACCOUNT[9];
  char GLOBAL_NC[9];
  char GLOBAL_DETAILS[61];
  char _unknown_1[137];
  char COSIGN_NUMBER[31];
  char _unknown_2[20];
  double GROSS;
  char _53[16];
  char _54[3];
  char _58[61];
  char _59[36];
  char _68[12];
  char _69;
  char _70;
  char DUNS_NUMBER[10];
  char _81[16];
  char NET_DISCOUNT_DESCRIPTION[61];
  char NET_DISCOUNT_COMMENT_1[61];
  char NET_DISCOUNT_COMMENT_2[61];
  double NET_DISCOUNT_VALUE;
  char _90[61];
  char _91[64];
  char VAT_NUMBER[31];
  char _92[36];
} TableInvoiceRow;
#pragma pack(pop)

TableInvoiceRow* find_invoice_by_number(int invoice_number);

#endif