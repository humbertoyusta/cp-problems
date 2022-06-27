#### Tiempo límite: 4 segundos.

#### Memoria límite: 512 MB.

## Texto Del Problema

A C-3IC se le ha ocurrido una nueva hipótesis, él cree que para todo entero positivo $n$, y todo par de enteros $(i, j)$, tal que $1 \leq i \leq j \leq n$ se cumple que $\gcd {(i, n)} \cdot \gcd {(j , n)} = \gcd {(i \cdot j, n)}$.

C-3IC corrió hacia su PC para probar si su hipótesis era verdadera probando muchos casos, rápidamente notó que para un entero $n$ su hipótesis era válida solo en algunos pares $(i, j)$, decepcionado por no descubrir un nuevo teorema, quiere analizar las propiedades de los pares de números que cumplen su hipótesis, para lo cual le pide que resuelva la siguiente tarea: 

Dado un entero positivo $n$, cuente el número de pares de enteros $(i, j)$ tales que $1 \leq i \leq j \leq n$ y $\gcd {(i, n)} \cdot \gcd {(j , n)} = \gcd {(i \cdot j, n)}$.

Habrá $T (1 \leq T \leq 10 ^ 6)$ casos de prueba, en cada uno se le dará un entero $n (1 \leq n \leq 4 \cdot 10 ^ 6)$.

### Subtareas:

* Subtarea 1: $1 \leq T \leq 40$, $1 \leq n \leq 40$. ( 5 puntos )

* Subtarea 2: $1 \leq T \leq 100$, $1 \leq n \leq 10 ^ 5$, se garantiza que el divisor más pequeño de $n$ es mayor que $100$. (19 puntos)

* Subtarea 3: $1 \leq T \leq 10^4$, $1 \leq n \leq 10 ^ 5$, se garantiza que existe un primo $p$, tal que $p^k = n$ para un entero positivo $k$. (22 puntos)

* Subtarea 4: $1 \leq T \leq 10 ^ 5$, $1 \leq n \leq 10 ^ 5$. (25 puntos)

* Subtarea 5: $1 \leq T \leq 10 ^ 6$, $1 \leq n \leq 4 * 10 ^ 6$. (29 puntos)

### Formato de Entrada:

La primera línea contendrá la cantidad de casos $T$ a procesar.

A partir de ahí, seguirán $T$ líneas, cada una con un entero $n$.

### Formato de Salida:

Debe imprimir $T$ líneas, cada una con un entero, la solución del problema para cada caso.

### Ejemplo de entrada:
    
    6
    1
    2
    3
    4
    5
    10000

### Ejemplo de salida:

    1
    2
    5
    8
    14
    46047940
