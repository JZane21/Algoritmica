# Digit DP

Si se quisiera verificar si un número tiene un carácter específico dentro de él, lo más sencillo que se podría hacer para verificar si se encuentra o no, sería a través de la navegación del numero como si se tratase de un arreglo de caracteres y ver si uno de sus dígitos coincide o no con el número que buscamos. Pero si este problema pasara de ser la búsqueda de un dígito en un número en una lista de números, la complejidad sería mucho mayor, y debido a ello, se desarrolló el algoritmo de Digit DP para resolver este problema.

### Algoritmo

La forma en que trabaja este algoritmo se basa en establecer condiciones sobre los números a analizar, es decir, si tienen algún dígito par en ellos, si estos dígitos son divisibles por un determinado número, etc. De esta forma, Digit DP podrá obtener variantes en su código, dependiendo del tipo de condición que se planté en un inicio para realizar la búsqueda en los dígitos de la lista de números. Y la forma en que se da este proceso, es a través de los siguientes puntos:

* Inicialmente, se toma el número máximo hasta el cual se generarán los números requeridos 

* Se representa el número máximo en una matriz de dígitos, de la cual se debe tomar como el digito más significativo aquel que se encuentra más a la izquierda. Luego de ello, se debe generar los números que sean menores al número dado previamente. Al mismo tiempo, se debe verificar si los dígitos de cada número generado cumplen con la condición establecida desde un inicio en el algoritmo.

La forma en que se generan los números junto con sus dígitos se dará en base a la cantidad de dígitos del límite máximo establecido. Por ejemplo, si tuviéramos el límite $’173’$, los números a generar deberían resultar en:

$$n = 000 – 001 – 002 – … – 173 $$

Esto se da debido a que el algoritmo evalúa respecto a la cantidad de dígitos que tenga el número máximo, por lo que siempre hay que generar números que tengan la misma cantidad de dígitos que tenga el número base.

De esta forma, se lograría encontrar la cantidad de números, cuyos dígitos cumplen con las condiciones preestablecidas del programa.

La complejidad algorítmica de este proceso es de:

$$ O(n) = (log(n))^2 $$

Donde $n$: número máximo

### Uso

Entre las posibles aplicaciones que podría tener el algoritmo Digital DP en nuestro día a día, podría ser en la implementación de métodos que verifiquen si una contraseña cumple o no con ciertos requisitos en sus dígitos numéricos.

### Conclusión

En el caso de que quisiéramos encontrar alguna coincidencia de algún dígito de un documento, cuya identificación se basa en valores numéricos, podríamos hacer el uso de Digit DP para lograr ese cometido. De igual forma, si se quisiera realizar un buscador que pueda buscar coincidencias en base a valores numéricos, podríamos usar este algoritmo con el fin de optimizar ese proceso de búsqueda.

### Bibliografía

Hegde, S. 2020. Programación dinámica de dígitos. Medium. https://medium.com/@sachinhegde0411/digit-dynamic-programming-c526dbfcbd74

Bawkar, S. 2019. Introducción a Digit DP. Medium. https://sim017bawkar.medium.com/introduction-to-digit-dp-40f0e6c9a77d
