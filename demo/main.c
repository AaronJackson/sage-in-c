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

  printf("You entered: %d\n\n", invoice_number);

  TableInvoiceRow *invoice = find_invoice_by_number(invoice_number);
  if (invoice == NULL) {
    printf("Could not find an Invoice with that number.");
    return 0;
  }

  printf("Invoice Number: %d\n", invoice->INVOICE_NUMBER);
  printf("  Company Name: %s\n", invoice->COMPANY_NAME);
  printf("       Creator: %s\n", invoice->USERNAME);

  long date1 = mstime_to_unixtime(invoice->DATE_MODIFIED);
  long date2 = mstime_to_unixtime(invoice->DATE_CREATED);
  long date3 = mstime_to_unixtime(invoice->DATE_3);

  printf("   Modified On: %s", ctime(&date1));
  printf("    Created on: %s", ctime(&date2));
  printf("        Date 3: %s", ctime(&date3));

  return 0;
}