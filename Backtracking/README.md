# Backtracking

### ¿Qué es?

Backtracking es una forma distinta de plantear nuestros algoritmos, de forma de que la ejecución del programa no llegue a trabajar con datos que sabe que son incorrectos, y que además lo conducirán a una solución errónea. En otras palabras, estamos asignándole al programa restricciones que debe considerar para evitar que el mismo no llegue a perderse en una solución incorrecta.

La forma en que lo hace es a través de la recursividad, solo que esta se encuentra bajo una o más condiciones, las cuales evitan que el mismo programa ejecute procesos innecesarios, como lo es aplicar el llamado recursivo con datos que se sabe que darán una solución incorrecta al final. Pero los llamados recursivos que se consideren correctos generarán un árbol con el pasar del tiempo, el cual representará el o los caminos que el programa siguió para encontrar la solución. Una vez que se encuentra la solución esperada, el algoritmo se detendrá y empezará a subir por el árbol, indicando el proceso que siguió para encontrar la solución que se esperaba.


### ¿Cúando usar Backtracking?

Su uso se encuentra enfocado en problemas específicos que requieran una gran optimización para llegar a una solución. En algunos ejemplos de su uso, podemos encontrarnos con el problema de enumeración, el juego de sudoku, o los movimientos de una reina en la tabla de ajedrez, ya que los tres problemas necesitan encontrar una solución que podría demorar un tiempo exponencial en hallarse en caso de que no se use backtracking correctamente.

Un uso mejor reflejado se lo encuentra en el archivo GoodMorning.cpp, el cual ayuda a resolver un problema algorítmico que puede ser encontrado [aquí](https://open.kattis.com/problems/goodmorning).

### Conclusión

El uso de la técnica de Backtracking para optimizar problemas que usen recursividad y que puedan tener una complejidad algorítmica de $O(n) = C^n$, debe ser considerado por cualquier desarrollador llegado el momento de aplicar soluciones que requieran Fuerza Bruta, pero que al mismo tiempo se tengan las restricciones del programa, para llegar a reducir de una forma significativa el tiempo que requerirá el programa para llegar a la solución del problema.

### Bibliografía

* Datta, S. 2020. Backtracking Algorithms. Baeldung. https://www.baeldung.com/cs/backtracking-algorithms
