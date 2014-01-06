#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

#include "../src/SageAccounts50.h"


int main() {

  set_root("/Volumes/2013/COMPANY.001/ACCDATA/");

  printf("Enter an Invoice Number: ");
  int invoice_number;
  scanf("%d", &invoice_number);

  TableInvoiceRow *invoice = find_invoice_by_number(invoice_number);
  if (invoice == NULL) {
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
  printf("    Created on: %s", ctime(&date2));
  printf("Date Processed: %s", ctime(&date3));

  printf("       Printed: %s\n", (invoice->IS_PRINTED ? "Yes" : "No"));
  printf("       Emailed: %s\n", (invoice->IS_EMAILED ? "Yes" : "No"));
  printf("        Posted: %s\n", (invoice->IS_POSTED  ? "Yes" : "No"));



  return 0;
}