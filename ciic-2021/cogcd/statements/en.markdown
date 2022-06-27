# Problem Description

C-3IC has come up with a new hypothesis, he believes that for every positive integer $n$, and every pair of integers $(i, j)$, such that $1 \leq i \leq j \leq n$ the following statement it's true:

$\gcd {(i, n)} \cdot \gcd {(j, n)} = \gcd {(i \cdot j, n)}$.

C-3IC ran to his PC to test his hypothesis by stress testing, he quickly noticed that for an integer $n$ his hypothesis was valid only in some pairs $(i, j)$, disappointed for not discovering a new theorem, he wants to analyze the properties of the pairs of numbers that satisfy his hypothesis for some integers $n$, and asks you to solve the following task:

Given a positive integer $n$, find the number of pairs of integers $(i, j)$ such that $1 \leq i \leq j \leq n$ and $\gcd {(i, n)} \cdot \gcd {(j , n)} = \gcd {(i \cdot j, n)}$.

There will be $T$ test cases per file, in each one of them will be given an integer $n$.

Note: $gcd(i,j)$ represents the greatest common divisor between $i$ and $j$.

# Input

The first line of input will contain an integer $T$, the number of test cases.

Then there will be $T$ lines, each one with an integer $n$.

# Output

Output $T$ lines, each one with an integer, the solution of the problem for each case.

# Sample Data

||input
6
1
2
3
4
5
10000
||output
1
2
5
8
14
46047940

||end

# Constraints

- $1 \leq T \leq 10 ^ 6$
- $1 \leq n \leq 4 \cdot 10 ^ 6$

# Subtasks

1. (5 points) $1 \leq T \leq 40$, $1 \leq n \leq 40$.

2. (19 points) $1 \leq T \leq 100$, $1 \leq n \leq 10 ^ 5$, The smallest divisor of $n$ is guaranteed to be greater than $100$.

3. (22 points) $1 \leq T \leq 10^4$, $1 \leq n \leq 10 ^ 5$, It is guaranteed that there will be a prime number $p$, such that $p^k = n$ for a positive integer $k$.

4. (25 points) $1 \leq T \leq 10 ^ 5$, $1 \leq n \leq 10 ^ 5$.

5. (29 points) $1 \leq T \leq 10 ^ 6$, $1 \leq n \leq 4 \cdot 10 ^ 6$.
