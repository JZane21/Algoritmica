# Método delete word en trie

La estructura de datos Trie ayudó a solucionar el problema de realizar la búsqueda de un patrón dentro de una lista de cadenas de texto, haciendo que la complejidad algorítmica de encontrar una coincidencia de ese patrón sea baja. Sin embargo, en ciertas ocasiones es necesario remover una cadena de caracteres de esa estructura de datos, y debido a ello, se idearon distintas soluciones a este problema, de las cuales se presentará una ahora.

### Algoritmo

Suponiendo que se tiene una lista de cadenas de caracteres ‘L’, y se compone de una cadena ‘xkz’ y ‘xkzc’, pero se desea eliminar la cadena ‘xkzc’, se debería realizar el siguiente procedimiento:
 
* Se identifica el nodo inicial, el cual pertenece a la primera letra de la cadena que se desea eliminar.
* Se recorre el árbol, mientras se verifica que los nodos por los que se pase pertenezcan a la cadena que se desea eliminar.
* Al llegar al nodo final, se elimina el nodo y se retorna al nodo anterior.
* Se debe verificar que el nodo anterior no sea el nodo final de otra cadena que no deseamos eliminar, y de ser así, no se elimina el nodo.

De esta forma, se eliminaría la cadena ‘xkzc’ de la estructura de datos ‘L’. Sin embargo, este método básico no funcionaría en todos los casos, debido a que se pueden presentar cadenas como ‘ab’ y ‘abc’, de los cuales se desea eliminar la primera cadena. Afortunadamente, el nodo final que forma parte de una cadena de caracteres, se lo identifica como ‘nodo final’ o ‘fin de palabra’. Con ello, tan solo se tendría que quitar el identificador que lo establece como el final de una cadena, para que únicamente quede la cadena ‘abc’ dentro de la lista.

Tomando en cuenta el caso anterior, se debe aplicar el siguiente procedimiento:

* Se identifica el nodo inicial, el cual pertenece a la primera letra de la cadena que se desea eliminar.
* Se recorre el árbol, mientras se verifica que los nodos por los que se pase pertenezcan a la cadena que se desea eliminar.
* Al llegar al nodo de final de cadena o palabra, se verifica que el nodo no tenga otras conexiones con otros nodos. De ser ese el caso, se debe quitar el identificador que lo establece como palabra final.

De esta manera, se eliminaría la palabra o cadena dentro de la estructura de datos. Y la implementación resultante del algoritmo sería aquella que se encuentra en el archivo 'Delete_Word_Trie.cpp': 

Y por la forma en que el esta implementación del Método Delete elimína una palabra, podemos concluir que la complejidad algorítmica de esta implementación es:

**O(n) = n+m**
* **'n'** = tamaño de la palabra a eliminar
* **'m'** = cantidad de letras a eliminar de la palabra, la cual puede llegar a ser igual a **'n'**

### Conclusión
Con la ayuda de este algoritmo, se tendrá la capacidad de eliminar cadenas de texto dentro de la lista sin alterar al resto del contenido. De esta forma, se tendría la posibilidad de insertar y quitar elementos de esta estructura de datos.
### Bibliografía
* Mallik, S. 2022. Delete nodes from trie. Codingninjas. https://www.codingninjas.com/codestudio/library/delete-nodes-from-trie
