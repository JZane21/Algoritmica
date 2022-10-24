# Longest Increasing Subsequence

En los problemas que se tienen que resolver con estructuras de datos como lo es el arreglo, podemos encontrarnos con el problema de LIS (Longest Increasing Subsequence). Este consta en tener un arreglo de números, de los cuales siempre vamos a tener una secuencia de números que van de menor a mayor, sin la necesidad de que el arreglo se encuentre ordenado. Y el objetivo de este algoritmo, se basa en hallar la cantidad de números que conforman la secuencia más grande en todo el arreglo.

Entre las formas que hay para implementar una solución para este problema, se pensó en el algoritmo de LIS, el cual sonta del siguiente proceso para llevar a cabo su buen funcionamiento:

* Con la ayuda de dos punteros, se recorrerá todo el arreglo para lograr hallar la secuencia más grande que haya. La forma en que se mueven los punteros consta de lo siguiente: el primer puntero se moverá por el arreglo de inicio a fin, pero el segundo puntero se encargará de recorrer el arreglo desde el inicio hasta alcanzar al primer puntero.

* Con cada cambio de posición de los punteros, se compara el número que tiene el puntero 2 en dicha posesión, con el número al cual apunta el “ puntero 1 + ‘1’ ”, de forma que podamos reemplazar el valor del puntero 2 con el valor más grande que exista entre: “el puntero 2” y el “ puntero 1 + ‘1’ ”.

La complejidad algorítmica de este proceso es de:

$$ O(n) = n^2 $$

Donde n: tamaño del arreglo

Esto debido a que:

![alg1](https://user-images.githubusercontent.com/82000556/197447485-4221fd82-fa8e-420e-b538-377669b9e72b.jpg)

### Bibliografía
* Laaksonen, A. 2017. Guide to Competitive Programming. Springer International Publishing AG, part of Springer Nature 2017. https://drive.google.com/file/d/1TZ0TgUv76ZltUEMZIuBV4ZE5eGF39xAc/view
* Techie Delight. Consultado el: 23-10-2022. Problema de corte de varilla. Obtenido de: https://www.techiedelight.com/longest-increasing-subsequence-using-dynamic-programming/
