# Descripción del Problema

A C-3IC se le ha ocurrido una nueva hipótesis, él cree que para todo entero positivo $n$, y todo par de enteros $(i, j)$, tal que $1 \leq i \leq j \leq n$ se cumple que $\gcd {(i, n)} \cdot \gcd {(j , n)} = \gcd {(i \cdot j, n)}$.

C-3IC corrió hacia su PC para probar si su hipótesis era verdadera probando muchos casos, rápidamente notó que para un entero $n$ su hipótesis era válida solo en algunos pares $(i, j)$, decepcionado por no descubrir un nuevo teorema, quiere analizar las propiedades de los pares de números que cumplen su hipótesis, para lo cual le pide que resuelva la siguiente tarea:

Dado un entero positivo $n$, cuente el número de pares de enteros $(i, j)$ tales que $1 \leq i \leq j \leq n$ y $\gcd {(i, n)} \cdot \gcd {(j , n)} = \gcd {(i \cdot j, n)}$.

Habrá $T$ casos de prueba, en cada uno se le dará un entero $n$.

Nota: $gcd(i,j)$ significa el máximo común divisor entre $i$ y $j$.

# Entrada

La primera línea de entrada contendrá la cantidad de casos $T$ a procesar.

A partir de ahí, seguirán $T$ líneas, cada una con un entero $n$.

# Salida

Debe imprimir $T$ líneas, cada una con un entero, la solución del problema para cada caso.

# Ejemplo

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

# Restricciones

- $1 \leq T \leq 10 ^ 6$
- $1 \leq n \leq 4 \cdot 10 ^ 6$

# Subtareas

1. (5 puntos) $1 \leq T \leq 40$, $1 \leq n \leq 40$.

2. (19 puntos) $1 \leq T \leq 100$, $1 \leq n \leq 10 ^ 5$, se garantiza que el divisor más pequeño de $n$ es mayor que $100$.

3. (22 puntos) $1 \leq T \leq 10^4$, $1 \leq n \leq 10 ^ 5$, se garantiza que existe un primo $p$, tal que $p^k = n$ para un entero positivo $k$.

4. (25 puntos) $1 \leq T \leq 10 ^ 5$, $1 \leq n \leq 10 ^ 5$.

5. (29 puntos) $1 \leq T \leq 10 ^ 6$, $1 \leq n \leq 4 \cdot 10 ^ 6$.
