#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

#include "../src/SageAccounts50.h"

char *rtrim(char *string) {
  int i;
  for (i=strlen(string); i != 0; --i)
    if (string[i] > 0x40) break;
  char *n = malloc(i + 1);
  memcpy(n, string, i+1);
  return n;
}

void new_invoice_row(TableInvoiceRow *i) {
  printf("| %06d | %-50s | %8.2f |\n", 
    i->INVOICE_NUMBER,
    rtrim(i->COMPANY_NAME),
    i->GROSS);
}

int main() {
  sage_set_root("/Volumes/SageData/");

  printf("+--------+----------------------------------------------------+----------+\n");
  printf("| INV NO | COMPANY NAME                                       |    GROSS |\n");
  printf("+--------+----------------------------------------------------+----------+\n");
  sage_find_invoices(new_invoice_row);
  printf("+--------+----------------------------------------------------+----------+\n");
  
  return 1;
}