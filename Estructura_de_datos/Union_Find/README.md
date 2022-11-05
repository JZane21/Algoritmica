# Union - Find

Si quisieramos conectar elementtos entre sí, con el fin de hallar con mayor facilidad que elemento se encuentra relacionado con otro, deberíamos abrir la mente y hacer el uso de la estructura de datos conocida como: Union - Find.

## Algoritmo

### Inicialización

La forma en la que se crea desde un inicio la estructura de Union-Find es a través de conectar un nodo $A$ y un nodo $B$, de los cuales uno de ellos se lo considerará como el padre del nodo vecino, esto quiere decir que el nodo hijo se encontraría directamente relacionado con él y viceversa. Pero de igual forma, se debe tener en cuenta que un conjunto de nodos que se encuentren conectados entre si, deben ser parte de un único nodo que los conecte a todos, como si se tratara de un nodo maestro.

En un principio realizar la conexión entre varios elementos, resulta que puede demorar en el peor de los casos una complejidad algoritmica de:

$$O(n) = n$$

Donde **'n'** = número de elementos a agregar

### Encontrar el nodo maestro

Si quisieramos encontrar el nodo que conecta a todos los nodos como si se tratase de la cabeza misma de la estrucutra de datos, debemos considerar que todos los nodos deben hacer una referencia directa a él y no al nodo que tengan como vecino. Esto quiere decir que se debe hacer una modificación al mismo método, con el fin de que pueda unir a todos los nodos directamente con el nodo maestro, y de esta forma reducir de forma exorbitante el tiempo requerido para hallar el nodo con el que se encuentra relacionado un nodo menor o hijo.

Tomando en cuenta esa consideración, la complejidad algorítmica de ese método en principio pasaría de ser $O(n) = n$ a:

$$O(n) = C$$

Esto quiere decir que hallaríamos siempre a la misma velocidad al nodo maestro que conecta a todos los nodos de la estructura de datos.

Todas estas implementaciones, se encuentran representadas en el documento Union_Find.cpp.

## Conclusión

Si queremos que varios elementos se encuentren entre sí, y queremos hallarlos a través del nodo principal al que se encuentran conectados, podemos deducir que la mejor opción para llevar a cabo esa hazaña es la estructura de datos Union-Find.

## Bibliografía

* Programdor clic. Consultado el: 04-10-2022. Explicación detallada del algoritmo Union-Find. Obtenido de: https://programmerclick.com/article/43171057033/

## Ejercicio

* [11987 - Almost Union-Find - answer](http://uva.outsbook.com/problemhints/problemdetails/119/11987)
* [11987 - Almost Union-Find](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3138)
