#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

#include "../src/SageAccounts50.h"

void invoice_item_found(TableInvoiceItemRow *item) {
  printf("| %s | %s | %.00f |\n", 
    item->STOCK_CODE, 
    item->DESCRIPTION,
    item->QUANTITY);
}

int main() {

  // set_root("/Volumes/2013/COMPANY.001/ACCDATA/");
  set_root("/Volumes/SageData/");

  printf("Enter an Invoice Number: ");
  int invoice_number;
  scanf("%d", &invoice_number);

  TableInvoiceRow *invoice = find_invoice_by_number(invoice_number);
  if (invoice == NULL) {
    printf("\nSize of TableInvoiceRow %lu\n\n", sizeof(TableInvoiceRow));
    printf("Could not find an Invoice with that number.\n");
    return 0;
  }

  printf("Invoice Number: %d\n", invoice->INVOICE_NUMBER);
  printf("  Company Name: %s\n", invoice->COMPANY_NAME);
  printf("       Creator: %s\n", invoice->USERNAME);

  long date1 = mstime_to_unixtime(invoice->DATE_MODIFIED);
  long date2 = mstime_to_unixtime(invoice->DATE_CREATED);
  long date3 = mstime_to_unixtime(invoice->DATE_PROCESSED);

  printf("   Modified On: %s", ctime(&date1));
  printf("    Created On: %s", ctime(&date2));
  printf("  Processed On: %s", ctime(&date3));

  printf("       Printed: %s\n", (invoice->IS_PRINTED ? "Yes" : "No"));
  printf("       Emailed: %s\n", (invoice->IS_EMAILED ? "Yes" : "No"));
  printf("        Posted: %s\n", (invoice->IS_POSTED  ? "Yes" : "No"));

  free(invoice);

  printf("| PRODUCT CODE                   | DESCRIPTION                                                  | Q |\n");
  find_invoice_items(invoice->INVOICE_NUMBER, &invoice_item_found);

  return 0;
}
