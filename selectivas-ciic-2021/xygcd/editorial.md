## Subtarea 1

Revisar y preguntar bruto para todos los pares, use la función __gcd o el algoritmo de euclides para el máximo común divisor.

Complejidad ~O(T\cdot{n^2}\cdot{\log{n}})~.

## Subtarea 2

Lo mismo de la subtask anterior pero guardando las soluciones en un arreglo de frecuencia para no calcularlas todas cada vez.

Complejidad ~O(n^2 \cdot{\log{n}})~.

## Subtarea 3

Esta subtarea está para que las soluciones de la subtarea 4 con alta complejidad en la factorización o en el cómputo de ~\phi_n~ pasen

## Subtarea 4

Modifiquemos un poco la ecuación inicial del problema:

Sea ~g = gcd(x, y)~, ~x \cdot g + y \cdot g = n~

Sean ~a = \frac{x}{g}~ y ~b = \frac{y}{g}~:

~a \cdot g \cdot g + b \cdot g \cdot g = n~

~a + b = \frac{n}{g^2}~

Por lo cual se puede reducir el problema a contar la cantidad de números coprimos que suman ~n~. Lo cual es igual a:

~\sum_{i=1}^{n}{[\gcd(i,n-i) = 1]}~

Lo cual aplicando propiedades del gcd como la del algoritmo de euclides o por simple prueba, puede notarse que es igual a la cantidad de números ~x~ con ~1 \leq x \leq n~ coprimos con ~n~, más conocido como ~\phi_n~.

## Subtarea 5

La misma solución que la subtarea anterior pero como ~n~ es un cuadrado perfecto basta con factorizar ~\sqrt{n}~ y usar solo esos factores como posibles a la hora de calcular los ~\phi~.
