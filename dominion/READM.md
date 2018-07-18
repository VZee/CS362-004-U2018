Author: Louisa Katlubeck
Onid: katlubel

Introduction:
This is the README for assignment 3, unit testing. There are four unit tests for functions, and four card tests.
This code is testing buggy code, with a focus on finding where the code fails to execute as expected.

Makefile:
This project uses a Makefile. To execute, first ensure permissions are set by using chmod +x Makefile.
Then run the tests using:

make unittestresults

Output:
The output of the code is sent to the file unittestresults.out

The output file contains the full cat of the gcov results for each test. It is possible to search for individual tests using "unittest#.c" or "cardtest#.c", with # ranging from 1 to 4 inclusive.