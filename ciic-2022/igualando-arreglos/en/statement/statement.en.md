##### Time Limit: 1 second.

##### Memory limit: 256MB.

### Making Arrays Equal

Given two arrays $A$ and $B$, of $n$ elements each, you can perform any of the following operations any number of times:

* Select an index $i$, such that $2 \leq i \leq n-1$, add $1$ to $A_{i-1}$, subtract $1$ from $A_{i}$ and add $1$ to $A_{i + 1}$.

* Select an index $i$, such that $2 \leq i \leq n-1$, subtract $1$ from $A_{i-1}$, add $1$ to $A_{i}$ and subtract $1$ from $A_ {i + 1}$.

You will have to process $q$ updates in the form $(l, r, x)$, which consists of adding $x$ to $A_{l}, A_{l + 1}, ..., A_{r}$.

After each update you will have to say if you can convert A to B using the given operations, note that the operations you do will not be saved for future updates, but the elements that were added by the update will be saved for future updates.

### Restrictions:

- $3 \leq n \leq 2 \cdot 10 ^ 5$

- $0 \leq q \leq 2 \cdot 10 ^ 5$

- $1 \leq A_i, B_i \leq 10 ^ 6$ for each $i$ such that $1 \leq i \leq n$

- $1 \leq l_i \leq r_i \leq n$

- $-10 ^ 6 \leq x_i \leq 10 ^ 6$ for each $i$ such that $1 \leq i \leq q$

### Input format:

First a line with $n$ and $q$, the size of the arrays $A$ and $B$, and the number of updates respectively.

Then a line with $n$ integers $A_1, A_2, ..., A_n$ separated by a space.

Then a line with $n$ integers $B_1, B_2, ..., B_n$ separated by a space.

Then $q$ lines, the $i$ -th of them describing the $i$ -th update, $l_i, r_i, x_i$, separated by a space.

### Output format:

You should print $q + 1$ lines, each one should contain the answer after each update, the first line contains the answer before the first update is done. You should print $YES$ if the $B$ array can be reached from $A$ using the required operations or $NO$ otherwise.

#### Example of input 1:

    5 0
    1 2 3 2 2
    2 3 5 1 5

#### Example of output 1:

    YES

#### Example of input 2:

    12 12
    17 23 2 35 32 8 24 4 28 18 4 28
    20 19 8 31 34 5 26 3 23 20 2 28
    2 6 8
    4 4 -10
    9 9 -1
    11 12 7
    10 10 -7
    3 9 10
    9 9 4
    3 9 8
    3 3 -8
    3 5 4
    10 10 -8
    5 11 6

#### Example of output 2:

    NO
    NO
    NO
    YES
    NO
    NO
    NO
    YES
    NO
    YES
    NO
    YES
    NO 
