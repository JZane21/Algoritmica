# Segment - Tree

Si quisieramos hallar una forma eficiente de encontrar una operación básica(a excepción de la división), los máximos o mínimos, o incluso los GCD's de una lista de números, deberemos recurrir al uso de la estructura de datos conocida como Segment-Tree.

El Segment-Tree es una estructura de datos enfocada a crear un árbol basado en una lista de dos o más números, con el fin de hallar los resultados de las operaciones ya mencionadas en un rango determinado.

## Algoritmo

### Creación

La forma en que se genera un Segment tree es a través de un método de creación del árbol, el cual se enfocará en crecer de una forma orientada a $2^n$, esto quiere decir que desde un punto en el árbol, se deben generar 0 o dos hijos correspondientes a ese punto. Esto lo hará a través de los elementos que posea el arreglo inicial. Este proceso continuará hasta alcanzar un tamaño casi 2 veces al del arreglo.

La forma en que se generan estos puntos donde se encuentran nuestros datos numéricos es a través de nodos, como si se tratará de un grafo.

Si consideramos que el tamaño total del árbol generado es casi el doble del arreglo origina, se puede deducir que la complejidad algoritmica del Método de creación del Segment Tree será:

$$O(n) = n*log(n)$$

Donde **'n'** = tamaño del arreglo de valores numéricos

### Actualización

Si requirieramos actualizar un valor de nuestro arreglo, pero que al mismo tiempo ese cambio se vea reflejado en nuestro Segment-Tree, necesitariamos actualizar únicamente los nodos que se encuentren conectado entre el nodo inicial de nuestro segment tree y los valores del nodo base que se está cambiando, con el fin de que la complejidad algorítmica no aumente.

Considerando que solo cambiarémos una rama de nuestro Segment-Tree, la complejidad algoritmica de este proceso será de:

$$O(n) = log(n)$$

Donde **'n'** = tamaño del arreglo de valores numéricos

### Consultas

Al englobar los resultados en un 'árbol', resulta sencillo hallar los valores de las operaciones que queríamos realizar con anterioridad sobre nuestro arreglo.

La forma en que lo hace es a través de un Método de Consultas o Query, el cual toma dos valores base del Segment-Tree, para luego hallar el nodo en el cual ambos comparten uno o más resultados de las operaciones matemáticas que se observaron anteriormente.

La complejidad algoritmica de este proceso resultaría en:

$$O(n) = Q*log(n)$$

Donde **'n'** = tamaño del arreglo de valores numéricos

Donde **'Q'** = número de consultas que se desean realizar

Todas estas implementaciones se encuentran en el archivo SegmentTree.cpp.

## Conclusión

Si deseamos hallar una suma, resta, u otra operación que haya sido mencionada previamente en un rango determinado de elementos de un arreglo, podremos decir que el uso del Segment Tree ayudará a resolver este problema de forma eficiente y rápida

## Bibliografía

* ProgComp. Consultado el: 04-10-2022. Segment Tree. Obtenido de: https://progcomp.cl/segmenttree
