# Sage-in-C

A small C library designed to allow read only access to Sage Accounts 50 data without having to use the ODBC driver. This is particularly useful if you need to access the data from a none-Windows machine. 

One possible application of this library might be a tool to synchronise invoices from Sage to an SQL server.

## Demonstration 

`demo/main.c` is a simple demonstration which asks for an invoice number and then prints out a few details about the invoice. For example:

```
$ make
mkdir -p build
gcc src/*.c demo/*.c -o build/main

$ ./build/main
Enter an Invoice Number: 10756
You entered: 10756

Invoice Number: 10756
  Company Name: A RANDOM COMPANY 
       Creator: tom   
```

## Further Work!

This is by no means complete. It hardly does anything at all in fact. A lot of the work was simply trying to reverse engineer the structure of the database file. I still haven't cracked parsing dates yet, so hang in there. 

## Contributions

I would love contributions. If you find a bug or merely an improvement, please send a pull request. I am not a very good C programmer so I'm sure there are many problems with my code. 