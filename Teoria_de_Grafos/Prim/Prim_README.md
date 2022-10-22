# Prim

En los árboles de expansión, se debe conectar a todos los nodos de un grafo, sin importar que una o más aristas puedan ser eliminadas para encontrar todos los posibles árboles de expansión de dicho grafo. Entre estos árboles, podemos encontrarnos con los de expansión mínima, es decir, que todos los nodos se encuentran conectados a través de aristas, cuya suma de pesos es la más pequeña que pueda existir. Por supuesto, en todo grafo pueden existir muchas variantes del árbol de expansión mínimo, y precisamente el algoritmo de Prim nos ayuda a encontrar todas esas posibles soluciones del árbol de expansión mínimo.

### Algoritmo

Los pasos que sigue el algoritmo para hallar uno de los posibles árboles de expansión mínimo son los siguientes:

* Paso 1: Se debe seleccionar un nodo cualquiera de los nodos que se encuentren dentro del grafo, además de marcarlos como “visitado”.

* Paso 2: Se agregan todos los nodos vecinos junto con sus aristas del nodo seleccionado en una cola de prioridad, y la forma en que se agregarán las aristas junto con los nodos se hará a través del peso de estas.

* Paso 3: Luego, se debe sacar de la cola el elemento que se encuentra en la cabeza de esta, al mismo tiempo que se marca como “visitado”. Aparte, se deberá marcar la conexión con el nodo que comparte el nodo junto con su arista.

* Paso 4: Finalmente, se deben repetir el 2do y 3er paso, tomando en cuenta que no se debe agregar a la cola de prioridad artistas que ya fueron agregadas, además de no tomar en cuenta las conexiones de aristas con nodos que ya fueron marcados como “visitado”.

Si repetimos este proceso con todas las aristas que se encuentren dentro del grafo, obtendremos uno de los muchos árboles de expansión mínimo que puedan existir dentro del grafo.

La complejidad algorítmica de este proceso consta de:

$$ O(n) = m·log(m) $$

Donde $m$: cantidad de aristas del grafo

### Uso

En las posibles implementaciones de este algoritmo, podríamos encontrarnos con lo siguiente:

Si tuviéramos un sistema de distribución de agua, el cual brinda agua a todas las viviendas de una comunidad local, y se desea optimizar dicho sistema desde un punto principal (por donde el sistema obtiene agua) para que el agua que se requiera utilizar para sustentar al barrio se reduzca en lo más mínimo, podríamos utilizar el algoritmo de Prim para darle una solución a este problema.

### Conclusión

Si se desea encontrar varias opciones de conectar a todos los elementos de un sistema, de forma que las conexiones entre estos sea la más sencilla de implementar llegado el momento de construir o reconstruir el sistema, el algoritmo Prim debería ser considerada como la mejor alternativa en estas situaciones.

### Bibliografía

* Fredy Reconocer. 2020. Algoritmo de PRIM en problemas reales. https://www.youtube.com/watch?v=Bk2vvnJX5Ug
* Hmong. Consultado el: 22-10-2022. Algoritmo de Prim. Obtenido de: https://hmong.es/wiki/Prim%27s_algorithm
