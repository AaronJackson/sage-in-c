#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

#include "../src/SageAccounts50.h"


int main() {

  set_root("/Volumes/SageData/");

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

  return 0;
}