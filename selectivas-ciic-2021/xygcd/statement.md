En un futuro lejano en el cual la inteligencia artificial acabó con la humanidad, C-3BA, un robot reparador que vive en una isla del Caribe, decide ir a reparar robots a los confines de la Tierra para así brindar una mejor atención de reparación a robots de otros países que lo necesitan.

Existen infinitas partes de robot, numeradas ~1, 2, 3, ...~, C-3BA necesita una parte ~n~, no dispone de ninguna actualmente, pero es posible crear una parte de tamaño ~n~ a partir de dos partes ~x~ y ~y~ si ~x \cdot \gcd(x, y) + y \cdot \gcd(x, y) = n~, aquí ~\gcd(x, y)~ denota el máximo común divisor de ~x~ y ~y~.

C-3BA dispone de un ejemplar de cada una parte de ~1, 2, 3, ..., n-1~, quiere cuántos pares de partes puede escoger que le permitan crear una parte de tamaño ~n~, **n siempre es un cuadrado perfecto**.

Formalmente, dado un número ~n~, debe contar la cantidad de pares ~(x, y)~ tales que ~1 \leq x, y < n~ y ~x \cdot \gcd(x, y) + y \cdot \gcd(x, y) = n~. 

Note que ~(x, y)~ y ~(y, x)~ son considerados distintos si y solo si ~x \neq y~. 

Debe resolver ~T~ casos de prueba.

**Como la respuesta puede ser muy grande, imprímala módulo ~1000000007~ ~(10^9+7)~**.

## Restricciones

* ~1 \leq T \leq 100~

* ~1 \leq n \leq 10^{18}~

* **n siempre es un cuadrado perfecto**

## Subtareas

### Subtarea 1 [10 puntos]

* ~1 \leq n \leq 100~

### Subtarea 2 [15 puntos]

* ~1 \leq n \leq 3000~

### Subtarea 3 [30 puntos]

* ~1 \leq n \leq 200000~

### Subtarea 4 [20 puntos]

* ~1 \leq n \leq 4 \cdot 10^{10}~

### Subtarea 5 [25 puntos]

* ~1 \leq n \leq 4 \cdot 10^{18}~

## Especificación de entrada

    T
    n [1]
    n [2]
    .
    .
    .
    n [T]
    
## Ejemplo de entrada

    6
    1
    4
    9
    16
    1000000000000
    
## Ejemplo de salida

    0
    2
    6
    10
    623368965
