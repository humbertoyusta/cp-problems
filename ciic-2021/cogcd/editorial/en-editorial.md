## Subtask 1:

Note that you can go through all the pairs with brute force and ask if they are valid, complexity $O (T \cdot n^2 \cdot \log {n})$, $(T \cdot n^3)$ or a little more depending on how the $gcd$ is calculated.

## Subtask 2:

First notice that:

* A $(i, j)$ pair is valid if and only if $gcd (i, n) \cdot gcd (j, n)$ is a divisor of $n$.

Note that since the lowest prime is greater than $100$, and the numbers are up to $10 ^ 5$, $n$ can only be:

1. A prime, in which case the answer is $\frac{n \cdot {(n + 1)}}{2} -1$, that is, all pairs $(i, j)$ minus $(n , n)$.

2. The multiplication of two primes $p$ and $q$, in which case we must count all the pairs, and then discount the pairs $(i, j)$ such that they meet one of the following conditions:

    * $gcd (i, n) = p$ and $gcd (j, n) = p$, these pairs can be counted as $(\frac {n} {p} -1) \cdot (\frac {n} {p} -1)$.

    * $gcd (i, n) = q$ and $gcd (j, n) = q$, we can count them in a similar way to the previous ones.

    * $gcd (i, n) = p \cdot q$ and $gcd (j, n) = p$, these can be counted as $\frac {n} {p}$.

    * $gcd (i, n) = p \cdot q$ and $gcd (j, n) = q$, we can count these as $\frac {n} {q}$.

3. The square of a prime $p$, here we can count all the pairs and subtstract those that $gcd (i, n) \neq 1$ and $gcd (j, n) = n$, which we can do in a similar way to the previous case, or as $n - \phi {n}$.

Complexity $O (T \cdot \sqrt {n})$ or maybe less depending on the factorization.

## Subtask 3

In this subtask $n$ is the power of a prime, using that fact we can count the number of elements with $gcd (i, n) = p ^ x$ as $\frac{n}{p^x} - \frac{n}{p^{x+1}}$.

We can go through the pairs $(a, b)$ such that $p ^ {a + b}$ does not divide $n$, and for each of them count the number of pairs that have $gcd (i, n) = p ^ a$ ans $gcd (j, n) = p ^ b$ as explained in the previous text, so we count the bad pairs and subtract them from the total.

Complexity $O(T \cdot \sqrt {n} + T \cdot \log^2 n)$, maybe less depending on the factorization.

## Subtask 4

It can be shown that:

* The quantity of numbers $x$ such that $1 \leq x \leq n$ and $gcd (x, n) = d$ is equal to $\phi {\frac {n} {d}}$ (here $\phi {m}$ is the quantity of numbers from $1$ to $m$ which are coprime with $m$), if and only if $d$ is a divisor of $n$, otherwise it is $0$. This can be thought as if we divided each element by $d$, those that are not divisible doesn't matter, we are interested in those that are equal to $1$, which are coprime with $\frac{n}{d}$.

Let us denote as $F (x, y)$ the number of pairs $(i, j)$ such that:

* $1 \leq i \leq n$
* $1 \leq j \leq n$
* $gcd (i, n) = x$
* $gcd (j, n) = y$
* $x \neq y$.
* $x \cdot y$ is a divisor of $n$.

$F (x, y)$ can be calculated as $\phi {\frac {n} {x}} \cdot \phi {\frac {n} {y}}$.

Furthermore, let's denote $E (x)$ as the number of pairs $(i, j)$ such that:

* $1 \leq i \leq n$
* $1 \leq j \leq n$
* $gcd (i, n) = x$
* $gcd (j, n) = x$
* $x ^ 2$ is a divisor of $n$.

$E (x)$ can be calculated as $\frac {\phi {\frac {n} {x}} \cdot (\phi {\frac {n} {x} + 1)}} {2}$

Now $\sum_{x, y \in d (n)} F (x, y)$ (here $d (n)$ is the list that contains all the divisors of $n$) would count all the pairs in the answer twice, except for those that have the same gcd, which would be $\sum_{x \in d (n)} E (x)$, let's denote $f (n)$ as $\sum_{x, y \in d (n)} F (x, y)$ and $g (n)$ as $\sum_ {x \in d (n)} E (x)$, the answer to the problem would be $\frac {f (n) + 2 \cdot g (n)} {2}$.

In this subtask you can calculate the solutions simply by checking each pair of divisors of each number and calculating $F (x, y)$ and $E (x)$ as explained above.

You can save the solutions, since the sum of the number of divisors of each number up to $n$ is $(n \cdot \log n)$ and the number of divisors of a number $n$ is $O (n ^ {\frac {1} {3}})$.

Complexity: $O (\sum_{i = 1}^{n} d(i) ^ 2)$ with a low constraint. (here $d (i)$ is the number of divisors of the number $i$)

## Subtask 5

It can be shown that the functions $g$ and $h$ are multiplicative, compute them for the powers of primes similar to subtask 3, and for the rest use the fact that they are multiplicative.

The fact that $h$ is multiplicative is not very important, since it can be computed in $O (n \log {n})$ without any trouble without noticing that is multiplicative, but the fact that $g$ is multiplicative is important.

It can be shown that $g$ is multiplicative, due to the fact that if we separate the problem into powers of primes, a pair will be valid in the multiplication of the powers of primes if and only if it is valid in each of these powers of primes.

Complexity: $O (n \cdot \log {n})$ or $O (n)$ depending on the implementation. 