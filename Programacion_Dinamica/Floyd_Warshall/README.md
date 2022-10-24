# Algoritmo de Floyd Warshall
En la teoría de grafos, se encuentra el problema de hallar el camino más corto entre un vértice “A” y un vértice “B”, sin embargo, también es posible encontrarse con el problema de hallar el camino más corto entre todos los nodos, algo que incremente la complejidad algorítmica a gran escala. Y debido a ello, Floyd Warshall desarrolló una solución usando el paradigma de resolución DP.
La forma en que se funciona este algoritmo, se lo puede observar a través de los siguientes pasos:

*	Inicialmente, se inicializan los caminos en una matriz donde originalmente se encontraba llena de Infinitos y 0’s en su diagonal. De esta forma, los pesos de las aristas que conectan a los nodos podrán ser medidos a través de coordenadas. Sin embargo, la inicialización de estos caminos en esta matriz será únicamente con los vértices más cercanos que tenga individualmente cada vértice del grafo.
*	Luego, a través del uso de bucles “for”, se revisa si en la coordenada de un peso que se encontraba previamente ahí, es mayor al nuevo peso que lo une a un vértice.
*	Una vez hallado el camino más corto, se marcará en otra matriz al nodo el cual está dirigido dicho camino corto.

Esto se realizará hasta haber logrado calcular todas las rutas más cortas entre todos los nodos.

La complejidad algorítmica de este proceso es de:

$$ O(n) = n^3 $$

Donde n: número de vértices

Esto se debe a que:

![f0](https://user-images.githubusercontent.com/82000556/197447636-93c76a1d-7191-4325-9ddb-49b511328782.jpg)

### Bibliografía
*	Cormen, T. 2009. Introduction to Algorithms. Massachusetts Institute of Technology. https://drive.google.com/file/d/1IlIbcGDqnAZe442uNAvw2xHkDCjqn5jV/view
*	Cimat. Consultado el: 23-10-2022. Algoritmos para caminos más cortos para todos los pares de vértices comp-420. Obtenido de: https://www.cimat.mx/~cesteves/cursos/algoritmos/pdf/ASSP_FloydWarshall.pdf
*	Geeks for Geeks. Actualización: 31 agosto de 2022. Floyd Warshall Algorithm | DP-16. Obtenido de: https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
*	Hmong. Consultado el: 23-10-2022. Algoritmo de Floyd-Warshall. Obtenido de: https://hmong.es/wiki/Floyd%E2%80%93Warshall_algorithm
