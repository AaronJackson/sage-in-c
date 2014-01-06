#ifndef __TABLEINVOICE_H__
#define __TABLEINVOICE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "Table.h"

enum InvoiceType {
  INVOICE = 0,
  CREDIT = 3,
  PROFORMER = 5
};

#pragma pack(push, 1)
typedef struct TableInvoiceRow {
  /* Offset 0    */ int INVOICE_NUMBER;
  /* Offset 4    */ char TAG[9];
  /* Offset 13   */ char COMPANY_NAME[61];
  /* Offset 74   */ char COMPANY_ADDRESS_LINE_1[61];
  /* Offset 135  */ char COMPANY_ADDRESS_LINE_2[61];
  /* Offset 196  */ char COMPANY_ADDRESS_TOWN[61];
  /* Offset 257  */ char COMPANY_ADDRESS_COUNTY[61];
  /* Offset 318  */ char COMPANY_ADDRESS_POST_CODE[61];
  /* Offset 379  */ char DELIVERY_COMPANY_NAME[61];
  /* Offset 440  */ char DELIVERY_ADDRESS_LINE_1[61];
  /* Offset 501  */ char DELIVERY_ADDRESS_LINE_2[61];
  /* Offset 562  */ char DELIVERY_ADDRESS_TOWN[61];
  /* Offset 623  */ char DELIVERY_ADDRESS_COUNTY[61];
  /* Offset 684  */ char DELIVERY_ADDRESS_POST_CODE[61];
  /* Offset 745  */ char CONTACT_NAME[31];
  /* Offset 776  */ char CUSTOMER_NUMBER[11];
  /* Offset 787  */ char ORDER_NUMBER[8];
  /* Offset 795  */ char USERNAME[61];
  /* Offset 856  */ char CUSTOMER_ORDER_NUMBER[61];
  /* Offset 917  */ char CUSTOMER_TELEPHONE[31];
  /* Offset 948  */ char NOTES_1[61];
  /* Offset 1009 */ char NOTES_2[61];
  /* Offset 1070 */ char NOTES_3[61];
  /* Offset 1131 */ char PAYMENT_REFERENCE[31];
  /* Offset 1162 */ char COURIER_NC[9];
  /* Offset 1171 */ char PAYMENT_BANK_ACCOUNT[9];
  /* Offset 1180 */ char GLOBAL_NC[9];
  /* Offset 1189 */ char GLOBAL_DETAILS[61];
  /* Offset 1250 */ enum InvoiceType INVOICE_TYPE;
  /* Offset 1254 */ char _u_1[31];
  /* Offset 1285 */ double FOREIGN_CARRIAGE_NET;
  /* Offset 1293 */ double FOREIGN_CARRIAGE_TAX;
  /* Offset 1301 */ double CUSTOMER_DISCOUNT_RATE;
  /* Offset 1309 */ double NET_AMOUNT_1;
  /* Offset 1317 */ double TAX_AMOUNT_1;
  /* Offset 1325 */ double SETTLEMENT_DISCOUNT;
  /* Offset 1333 */ double _______________;
  /* Offset 1341 */ double CARRIAGE_NET;
  /* Offset 1349 */ double CARRIAGE_TAX;
  /* Offset 1357 */ char _u_2[10];
  /* Offset 1367 */ int SETTLEMENT_DUE_DAYS;
  /* Offset 1371 */ short CARRIAGE_TAX_CODE;
  /* Offset 1373 */ short CARRIAGE_DEPARTMENT;
  /* Offset 1375 */ short GLOBAL_TAX_CODE;
  /* Offset 1377 */ int GLOBAL_DEPARTMENT;
  /* Offset 1381 */ int _u_2_1;
  /* Offset 1385 */ short _u_2_2;
  /* Offset 1387 */ char CARRIAGE_CONSIGN_NUMBER[31];
  /* Offset 1418 */ char _u_3[20];
  /* Offset 1438 */ double GROSS;
  /* Offset 1446 */ char _u_4[16];
  /* Offset 1462 */ char _u_4_1[3];
  /* Offset 1465 */ char _u_6[61];
  /* Offset 1526 */ char _u_7[36];
  /* Offset 1562 */ char _u_8[12];
  /* Offset 1574 */ char _u_9;
  /* Offset 1575 */ char _u_10;
  /* Offset 1576 */ char DUNS_NUMBER[10];
  /* Offset 1586 */ char _u_11[16];
  /* Offset 1602 */ char NET_DISCOUNT_DESCRIPTION[61];
  /* Offset 1663 */ char NET_DISCOUNT_COMMENT_1[61];
  /* Offset 1724 */ char NET_DISCOUNT_COMMENT_2[61];
  /* Offset 1785 */ double NET_DISCOUNT_VALUE;
  /* Offset 1793 */ char _u_12[61];
  /* Offset 1854 */ char _u_13[64];
  /* Offset 1918 */ char VAT_NUMBER[31];
  /* Offset 1949 */ char IS_PRINTED;
  /* Offset 1950 */ char IS_POSTED;
  /* Offset 1951 */ char _u_14[4]; /* no idea */
  /* Offset 1955 */ char IS_EMAILED;
  /* Offset 1956 */ int _u_15; /* no idea */
  /* Offset 1960 */ double DATE_MODIFIED;
  /* Offset 1968 */ double DATE_CREATED;
  /* Offset 1976 */ double DATE_PROCESSED;
  /* Offset 1984 */ char __END_OF_RECORD__;
} TableInvoiceRow;
#pragma pack(pop)

TableInvoiceRow* find_invoice_by_number(int invoice_number);

#endif