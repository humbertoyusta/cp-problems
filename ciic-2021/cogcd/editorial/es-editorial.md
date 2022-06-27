## Subtarea 1:

Note que se puede recorrer todos los pares con fuerza bruta y preguntar si son válidos, complejidad $O(T\cdot n^2 \cdot log{n})$, $(T\cdot n^3)$ o un poco más dependiendo como se calcule el $gcd$.

## Subtarea 2:

Primero note que:

* Un par $(i, j)$ es válido si y solo si $gcd(i, n) * gcd(j, n)$ es un divisor de $n$.

Note que como el menor primo es mayor que $100$, y los números son hasta $10^5$, $n$ solo puede ser:

1. Un primo, en cuyo caso la respuesta es $\frac{n\cdot{(n+1)}}{2}-1$, o sea, todos los pares $(i, j)$ menos $(n, n)$.

2. La multiplicación de dos primos $p$ y $q$, en cuyo caso debemos contar todos los pares, y luego descontar los pares $(i, j)$ tal que cumplan una de las siguientes condiciones:

    * $gcd(i,n) = p$ y $gcd(j,n) = p$, estos pares la podemos contar como $(\frac{n}{p}-1) \cdot (\frac{n}{p}-1)$.

    * $gcd(i,n) = q$ y $gcd(j,n) = q$, los podemos contar de manera similar a los anteriores.

    * $gcd(i,n) = p \cdot q$ y $gcd(j,n) = p$, estos los podemos contar como $\frac{n}{p}$.

    * $gcd(i,n) = p \cdot q$ y $gcd(j,n) = q$, estos los podemos contar como $\frac{n}{q}$.

3. El cuadrado de un primo $p$, aquí podemos contar todos los pares y descontar los que $gcd(i,n) \neq 1$ y $gcd(j,n) = n$, que podemos hacerlo de manera similar al caso anterior, o como $n - \phi{n}$.

Complejidad $O(T \cdot \sqrt{n})$ o  quizá menos dependiendo de la factorización.

## Subtarea 3

Como en esta subtarea $n$ es la potencia de un primo podemos contar la cantidad de elementos con $gcd(i, n) = p^x$ como $\frac{n}{p^x} - \frac{n}{p^{x+1}}$.

Podemos recorrer los pares $(a, b)$ tal que $p^{a+b}$ no divide a $n$, y para cada uno de ellos contar la cantidad de pares que tienen $gcd(i,n) = p^a$ y $gcd(j,n) = p^b$ como se explica en el texto anterior, así contamos los pares malos y se los restamos al total.

Complejidad $O(T \cdot \sqrt {n} + T \cdot \log^2 n)$, quizá menos dependiendo de la factorización.

## Subtarea 4

Note que:

* La cantidad de números $x$ tales que $1 \leq x \leq n$ y $gcd(x,n) = d$ es igual a $\phi{\frac{n}{d}}$ (donde $\phi{m}$ es la cantidad de números de $1$ a $m$ coprimos con $m$), si y solo si $d$ es un divisor de $n$, de lo contrario es $0$. Esto se puede intuir como si dividieramos cada elemento por $d$, los que no sean divisibles no influyen de los restantes nos interesan los que son iguales a $1$, o sea, los que son coprimos con $\frac{n}{d}$.

Denotemos como $F(x, y)$ a la cantidad de pares $(i, j)$ tales que:

* $1 \leq i \leq n$
* $1 \leq j \leq n$
* $gcd(i, n) = x$ 
* $gcd(j, n) = y$
* $x \neq y$.
* $x * y$ es un divisor de $n$.

$F(x, y)$ puede ser calculado como $\phi{\frac{n}{x}} \cdot \phi{\frac{n}{y}}$.

Además denotemos $E(x)$ como la cantidad de pares $(i, j)$ tales que:

* $1 \leq i \leq n$
* $1 \leq j \leq n$
* $gcd(i, n) = x$ 
* $gcd(j, n) = x$
* $x^2$ es un divisor de $n$.

$E(x)$ puede ser calculado como $\frac{\phi{\frac{n}{x}} \cdot (\phi{\frac{n}{x} + 1)}}{2}$

Ahora $\sum_{x,y \in d(n)} F(x,y)$ (donde $d(n)$ es la lista que contiene a todos los divisores de $n$) contaría todos los pares en la respuesta dos veces, excepto los que tienen igual gcd, los cuales serían $\sum_{x \in d(n)} E(x)$, denotemos $f(n)$ como $\sum_{x,y \in d(n)} F(x,y)$ y $g(n)$ como $\sum_{x \in d(n)} E(x)$, la respuesta del problema sería $\frac{f(n) + 2\cdot g(n)}{2}$.

En esta subtarea se puede calcular las soluciones simplemente chequeando cada par de divisores de cada número y calculando $F(x, y)$ y $E(x)$ como se explica anteriormente.

Puede guardar las soluciones, ya que la suma de la cantidad de divisores de cada número hasta $n$ es $O(n\cdot \log n)$ y la cantidad de divisores de un número $n$ es $O(n^{\frac{1}{3}})$.

Complejidad: $O(\sum_{i=1}^{n} d(i)^2)$ con baja constante. (donde $d(i)$ es la cantidad de divisores del número $i$)

## Subtarea 5

Se puede notar que las funciones $f$ y $g$ son multiplicativas, calcular para las potencias de primos similar a la subtarea 3, y para el resto usar el hecho de que son multiplicativas.

El hecho de que $g$ sea multiplicativa no es muy importante, ya que se puede calcular en $O(n\log{n})$ sin dificultad, en el caso de $f$ si es importante.

Se puede intuir que $f$ es multiplicativa, por el hecho de que si separamos el problema en potencias de primos, un par será valido en la multiplicación de las potencias de primos si y solo si es válido en cada una de estas potencias de primos.

Complejidad: $O(n\cdot \log{n})$ o $O(n)$ dependiendo de la implementación.
