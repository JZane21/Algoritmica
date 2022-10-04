# Trie Array - Trie Map

La estructura de datos Trie nos a permitido solucionar el problema de realizar la búsqueda de un patrón dentro de una lista de cadenas de caracteres, sin embargo, hay dos formas en las que esta estructura puede implementarse:

### Trie Array

La forma básica para implementar esta estructura de datos es a través del uso de arreglos, los cuales guardarán los nodos que se utilicen en el Trie. Pero como se sabe, los arreglos tienen un espacio limitado estático, por lo que siempre será necesario generar espacio innecesario que podría llegar a ser o no falta dentro de la ejecución del programa. Debido a ello, esta implementación consumirá una gran cantidad de recursos cuando el número de palabras dentro de la lista se haga masivo.

Se crea una clase o estructura que tenga las características y atributos requeridos de un nodo, con el fin de instanciar múltiples de ellos en cualquier momento del programa con facilidad. Entre sus atributos, se deberá instancias un arreglo vacío o nulo, el cual nos permitirá crear y guardar nodos dentro de un nodo. De esta forma los nodos estarán conectados a través de otros nodos, ya que se encontrarán dentro del arreglo de un nodo, y por lo tanto serán parte del atributo de un nodo, por lo que seremos capaces de acceder a ese atributo cada vez que queramos.

La desventaja de unir nodos de esa forma consta en que, si tenemos una estructura de nodos que tenga espacio para 100 posibles nodos, y queremos conectar tantos nodos como se nos permite en el array, el espacio en memoria ocupado por todos esos nodos creados junto con sus arreglos de tamaño 100, llegarían a ocupar 100^n de memoria. Y debido a ello, esta implementación de Trie a través de arreglos se la considera ineficiente debido a la cantidad de recursos que consume.

Teniendo en cuenta esos elementos, se puede implementar el Trie Array en C++, como se lo muestra en el archivo Trie_Array.cpp.

Y tomando en cuenta la velocidad con la que se accede a los nodos de una palabra en concreto, se obtiene que la complejidad algoritmica del Trie Array es:

$$O(n) = n$$

Donde **'n'** = tamaño de la palabra a buscar

### Trie Map

A diferencia de la implementación por arreglos, el Trie Map utiliza mapas para conectar los nodos entre sí, dándole la capacidad al programa de poder ahorrar recursos durante su ejecución.

Al crear un nodo, se le asignará como atributo un mapa vacío, el cual tendrá como llave la letra que se desea asignarle, y esta apuntará a un nuevo nodo que se desee instanciar. De esta forma, se logrará conservar una mayor cantidad de recursos, debido a que el mapa desde un inicio se instancia vacío, y esto se debe gracias a que los mapas son estructuras de datos dinámicas.

Implementando el Trie Map en código C++, se obtendría un código eficiente que se encuentra en el archivo Trie_Map.

Y al igual que en el Trie Array, la complejidad algoritmica con la que se accede a un dato es:

$$O(n) = n*log(n)$$

Donde **'n'** = tamaño de la palabra a buscar

### Conclusión

Dependiendo de la situación en la que queramos usar la estructura de datos Trie, tendremos que analizar tanto las ventajas como desventajas que nos ofrecen el Trie Array y Trie Map
