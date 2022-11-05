# Geometría Computacional

Si quisieramos resolver problemas desde un punto de vista matemático, se tendrían que modificar los métodos convencionaleslos métodos convencionales para usarlos, debido a que si se los usaran como de costumbre, se tendría que adaptar para cada caso en específico como el declarar las funciones de forma matemática una por una. Para optimizar ese proceso, se desarrolló la teoría de geometría computacional, que se basa en el uso de puntos en el espacio para facilitar la resolución de estos problemas.

## Teoría

### Puntos

En un plano cartesiano, se tiene la capacidad de trazar vectores, formas geométricas, entre otras operaciones matemáticas en base a los puntos que hay en ese espacio. La forma en que se construyen esos puntos en ese espacio 2d del plano cartesiano, se tienen coordenadas que son parte tanto del eje $x$ como del eje $y$.

### Vectores

El conjunto de 1 o varios puntos, pueden formar (como ya se lo había mencionado) rectas. Estas representaciones matemáticas, pueden ser descritas como:

$$ L = (B.x - A.x, B.y - A.y) $$

Donde $A$ y $B$ son las coordenadas de dos puntos en el plano cartesiano, pero se toma la diferencia de sus coordenadas para formar el vector.

Para realizar operaciones entre rectas, se tendría lo siguiente:

#### Suma de vectores:

Para ello, debemos basarnos en la formula de:

$$ V = a + b $$

Donde $a$ y $b$ son vectores y $V$ es el vector resultante

Debido a que tomamos como referencia solo puntos dentro de un plano cartesiano, se tendría lo siguiente:

$$ V = (a.x + b.x, a.y + b.y) $$

Si tenemos que el vector $a$ viene de: $(punto2.x - punto1.x , punto2.y - punto1.y)$

Si tenemos que el vector $b$ viene de: $(punto3.x - punto1.x , punto3.y - punto1.y)$

Esto daría como resultado:

$$ V = ( (punto2.x - punto1.x) + (punto3.x - punto1.x) , (punto2.y - punto1.y) + (punto3.y - punto1.y) )$$

De esta forma, se tendría de forma satisfactoria la suma de dos vectores, la cual formaría un producto nuevo.

#### Multiplicación de un escalar por un vector:

Si desearamos multiplicar un escalar por un vector cualquiera, se tendría lo siguiente:

$$ Resultado = V*escalar = (V.x,V.y)*escalar $$

Cabe recordar que las coordenadas del vector se basan en la diferencia de las coordenadas de dos puntos en el plano cartesiano, lo cual resultaría en:

$$ V*escalar = ((punto2.x - punto1.x)*escalar , (punto2.y - punto1.y)*escalar) $$

#### Módulo de un vector:

Al igual que en la matemática, para hallar el módulo de un vector, deberíamos usar la siguiente fórmula:

$$ módulo = \sqrt ((vector.x)^2 + (vector.y)^2) $$

Transformándo las coordenadas en base a la diferencia de dos puntos, se obtendría que:

$$ módulo = \sqrt ((punto2.x - punto1.x)^2 + (punto2.y - punto1.y)^2) $$

#### Ángulo de un vector:

Para hallar el ángulo de un vector, es necesario recordar la siguiente fórmula:

$$ ángulo = \arctan (V.y/V.x) $$

Transformando las coordenadas a puntos, se obtendría que:

$$ ángulo = \arctan ((punto2.y - punto1.y) / (punto2.x - punto1.x)) $$

#### Producto Vectorial o Cruz:

Para encontrar el producto cruz entre dos vectores, es necesario la fórmula de:

$$ productoVectorial = módulo(vector1)*módulo(vector2)* \sin(ánguloEntreVectores) $$

Sin embargo, hay una forma de simplificar esta expresión, esta simplifación resultaría en:

$$ productoVectorial = vector1.x * vector2.y - vector1.y * vector2.x $$

Y transformando las coordenadas de los vectores a puntos, se obtendría lo siguiente:

$$ productoVectorial = (punto2_Vector1.x - punto1.x) * (punto3_Vector2.y - punto1.y) - (punto2_Vector1.y - punto1.y) * (punto3_Vector2.x - punto1.x) $$

De esta forma, se obtendría el producto cruz de dos vectores usando coordenadas.

## Ejercicio

* [UVA PROBLEM 10432 – POLYGON INSIDE A CIRCLE SOLUTION](https://quickgrid.wordpress.com/2015/12/12/uva-problem-10432-polygon-inside-a-circle-solution/)

## Bibliografía

* Las Matemáticas de Jalón. 2017. Como sacar un vector a partir de 2 puntos. https://www.youtube.com/watch?v=2kLZgScz6As
* Gaussianos. Actualizado el: 27-6-2011. Una interesante introducción a la Geometría Computacional. Obtenido de: https://www.gaussianos.com/una-interesante-introduccion-a-la-geometria-computacional/
* ck-12. Actualizado el: 13-6-2021. 4.17 Puntos en el plano cartesiano. Obtenido de: https://flexbooks.ck12.org/cbook/ck-12-conceptos-de-matem%C3%A1ticas-de-la-escuela-secundaria-grado-7-en-espa%C3%B1ol/section/4.17/primary/lesson/puntos-en-el-plano-cartesiano/
* Superprof. Consultado el: 2-11-2022. Suma y resta de vectores, y sus propiedades. Obtenido de: https://www.superprof.es/apuntes/escolar/matematicas/analitica/vectores/suma-y-resta-de-vectores.html
* Física Práctica. Consultado el: 2-11-2022. Producto de un escalar por un vector. Obtenido de: https://www.fisicapractica.com/producto-escalar-vector.php#:~:text=El%20producto%20de%20un%20escalar,negativo%20cambia%20tambi%C3%A9n%20el%20sentido.
* Superprof. Consultado el: 2-11-2022. Qué significa módulo de un vector en Matemáticas. Obtenido de: https://www.superprof.es/diccionario/matematicas/analitica/modulo-vector.html#:~:text=El%20m%C3%B3dulo%20de%20un%20vector%20es%20la%20longitud%20del%20segmento,vector%20nulo%20tiene%20m%C3%B3dulo%20cero.
* Matemáticas profe Alex. 2019. Ángulo de un vector conociendo sus componentes rectangulares. https://www.youtube.com/watch?v=j6Qj17hzuKE
* Superprof. Consultado el: 2-11-2022. Producto vectorial. Obtenido de: https://www.superprof.es/apuntes/escolar/matematicas/analitica/vectores/producto-cruz.html
