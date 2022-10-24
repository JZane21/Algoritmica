# Rod Cutting
En los problemas de la informática, el problema del corte de varilla, el cual consiste en darle valor a una varilla dependiendo del tamaño que tiene. Por ende, una varilla puede ser dividida en cierta cantidad, y tener la posibilidad de aumentar su valor. Y en este problema, el objetivo principal consta en encontrar las posibles variantes de estas divisiones que generen la mayor ganancia posible.
La forma en que se funciona este algoritmo, se lo puede observar a través de los siguientes pasos:

*	Se pide inicialmente los valores que se les asignará a los distintos tamaños de varillas que puedan existir o no. 
*	Se guardan en dos nuevos arreglos valores que deberán ir desde “0” a “n+1”
*	Utilizando los arreglos ya creados, se hace una comparación de si la suma entre el valor del arreglo donde estaban dirigidos los datos que se pedían junto con un valor previo del nuevo arreglo que hayamos creado, sea mayor a un valor muy pequeño que podría no tomarse en cuenta en los casos de prueba.
*	Una vez echa la comparación, se le debe asignar al valor pequeño una posición de uno de nuestros dos nuevos arreglos la suma entre el valor del arreglo donde estaban dirigidos los datos que se pedían junto con un valor previo del nuevo arreglo que hayamos creado. De esta forma, en las siguientes iteraciones, se nos garantizará registrar aquellos valores que consideremos como los que tienen mayor valor.

La complejidad algorítmica de este proceso es de:

$$ O(n) = n^2 $$

Donde n: número de vértices

### Bibliografía

* Techie Delight. Consultado el: 23-10-2022. Problema de corte de varilla. Obtenido de: https://www.techiedelight.com/es/rod-cutting/
* Cormen, T. 2009. Introduction to Algorithms. Massachusetts Institute of Technology. https://drive.google.com/file/d/1IlIbcGDqnAZe442uNAvw2xHkDCjqn5jV/view
