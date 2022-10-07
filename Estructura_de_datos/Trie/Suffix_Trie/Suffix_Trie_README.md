# Suffix - Trie

### ¿Qué es?

Se trata de una evolución del trie, el cual se define en base de una cadena base en varias sub-cadenas.

También se lo puede describir como una estructura de datos, la cual es el resultado de la compresión de la idea original que proponían los tries, teniendo la capacidad de almacenar una lista de cadenas.

### Aplicación

Su aplicación consiste en reducir las extensiones de las ramas, haciendo que la transición entre nodos ya no sea por letras, sino por palabras completas que logren satisfacer un conjunto predeterminado de palabras. Esto quiere decir, que no se puede crear un Suffix Trie para todos los posibles casos, pero es posible lograrlo para un grupo de palabras o conjunto de caracteres en específico.

De las palabras que se deben tomar en cuenta, se debe buscar un sufijo o letra que una o más palabras puedan tener en común, para luego tomar ese sufijo e iniciarlo como si fuese un solo nodo. De esta forma se llegarían a acortar las ramas de los tries que se requerían originalmente.

### Algoritmo

Obteniendo un trie normal, el cual ya a sido dividido en varios nodos y letras, se debe agarrar y verificar que nodos pueden tomar dos rumbos diferentes, y debajo de dichos nodos, se debe crear un solo nodo que tenga todas las letras dentro de un solo sufijo, y lo mismo se deberá de hacer teniendo a los nodos que sean la representación de una palabra o un sufijo.

Implementando esta lógica en un algoritmo, se obtendría el resultado expresado en el archivo Suffix_Trie.cpp.

Analizando la forma en que funciona el algoritmo, podemos concluir que la complejidad algoritmica del Suffix-Tree es:

$$O(n) = n*log(k)$$

Donde **'n'** = Tamaño de la palabra dada
Donde **'k'** = Tamaño del alfabeto que se utiliza en el Suffix-Trie

### Conclusión

Utilizando esta mejora del algoritmo Trie, será posible acortar la complejidad algorítmica al buscar una de las palabras dentro de la estructura de datos, pero no la velocidad que le toma al programa para introducir las palabras requeridas. Esto quiere decir que el uso de esta estructura de datos es más beneficioso para casos que se conocen el conjunto de palabras a colocar.

### Bibliografía

* Pkacprzak. 2022. Trie, Suffix Tree, Suffix Array. Hackerearth. https://www.hackerearth.com/practice/notes/trie-suffix-tree-suffix-array/
* Harún, R. 2022. ¿Qué es un árbol de sufijos?. Educative. https://www.educative.io/answers/what-is-a-suffix-tree
* Natraj, L. 2019. Suffix Tries. https://www.youtube.com/watch?v=qh2leThTv0Y
* Sanfoundry. Consultado el: 09-17-2022. C++ Program to Implement Suffix Tree. Obtenido de: https://www.sanfoundry.com/cpp-program-implement-suffix-tree/
* Algorithms for Competitive Programming. Consultado el: 09-17-2022. Suffix Tree. Ukkonen's Algorithm. Obtenido de: https://cp-algorithms.com/string/suffix-tree-ukkonen.html
