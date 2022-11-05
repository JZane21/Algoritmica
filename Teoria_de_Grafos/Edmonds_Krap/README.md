# Algoritmo de Edmonds Krap - Máximo flujo

En cualquier ciudad, se tiene estructurado un sistema de alcantarillado moderno o tradicional, los cuales ayudan a circular tanto el agua usada como la limpia las veinticuatro horas del día. Sin embargo, durante ese proceso es importante conocer la cantidad de agua que circula a través de este sistema de flujo de agua, además de conocer la cantidad máxima de agua que puede llegar de un punto a otro. Debido a ese problema, Edmonds Krap desarrolló una solución optima a este problema.

### Algoritmo

La forma en que funciona este algoritmo, radica en los siugientes pasos:

* Utilizando el algoritmo de BFS para realizar el recorrido por todo el grafo, será posible obtener todas las aristas desde el punto inicial que se tome como la fuente de agua, hasta el punto final donde se desea encontrar el máximo flujo de agua que llega a tal lugar. Esto quiere decir que las aristas serán guardadas en una cola como lo establece en principio el algoritmo de BFS.

$Nota:$ Cabe mencionar que las aristas tienen peso, y además son dirigidas. En otras palabras, el grafo con el que se aplicará el algoritmo es dirigido y tiene peso en sus aristas.

* Se debe sacar una conexión de una arista junto con el nodo de la cola, para luego introducir a las conexiones que tenga con nodos vecinos que no hayan sido agregados a la cola. Por supuesto, esto se debe hacer mientras se guarda el camino que se forma de una conexión a otra.

* Este proceso debe repetirse hasta llegar al nodo final donde se desea evaluar el máximo flujo.

* Al llegar al nodo donde se desea evaluar el máximo flujo, se verifica el camino de nodos que se usó para llegar hasta ahí. Luego, se halla la arista con menor peso de dicho camino, ya que este peso se sumará a la cantidad del máximo flujo de agua que habrá llegado al nodo final. Sin embargo, hay que restarle a todos los pesos de las aristas el peso menor, con el fin de reducir la cantidad de agua que puede circular a través de esas aristas. Si el peso de una arista llega a ser $0$, ya no se la debe usar como parte de un camino cualquiera para llegar al nodo final, debido a que el objetivo del algoritmo es evaluar la cantidad de agua que va desde un punto inicial a uno final a través de "cañerías" con espacio limitado.

* Una vez terminado este proceso, se lo deberá repetir las veces que sean necesarias, hasta que todas las aristas por las cuales se pueda viajar al nodo final tengan peso $0$. Llegado ese momento, se deberá mostrar la cantidad del máximo flujo de agua que llegó al nodo final.

De esta forma, es en la que el algoritmo de Edmonds Krap halla el máximo flujo que puede llegar de un nodo inicial (fuente de agua), hasta un nodo final (punto en donde llegará el máximo flujo).

La complejidad algorítmica de este proceso resulta en:

$$ O(n) = V*E^2 $$

Donde $V$ : número de vertices

Donde $E$ : número de aristas

### Conclusión

Si se deseara encontrar la cantidad de agua que puede llegar desde una presa de agua hasta las distintas edificaciones que puede tener una ciudad de forma eficiente, se utilizaría el algoritmo de Edmonds Krap para cumplir ese cometido.

### Ejercicio

* [FASTFLOW - Fast Maximum Flow](https://www.spoj.com/problems/FASTFLOW/en/)

### Bibliografía

* Geeks for Geeks. Actualizado el: 21 de Junio del 2022. Ford-Fulkerson Algorithm for Maximum Flow Problem. Obtenido de: https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/?ref=gcse
* Complex Systems Ai. Consultado el: 2 de Noviembre del 2022. Algoritmo de Edmonds-Karp. Obtenido de: https://complex-systems-ai.com/es/problema-de-flujo-maximo/algoritmo-dedmonds-karp/
