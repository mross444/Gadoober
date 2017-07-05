// memory allocation example

int n;
TYPE * data;

n = 42; /* n is given some value */

data = (TYPE *) malloc(n * sizeof(TYPE)); /* array of size n is allocated */
assert (data != 0);  /*check that allocation worked */

free (data);