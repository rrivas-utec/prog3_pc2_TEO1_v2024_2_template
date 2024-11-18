# Task #PC2: Practica Calificada 2  
**course:** Programación III  
**unit:** 2, 3, 5  
**cmake project:** prog3_pc2_TEO1_v2024_2
## Indicaciones Específicas
- El tiempo límite para la evaluación es 100 minutos.
- Cada pregunta deberá ser respondida en un archivo cabecera (`.h`) con el número de la pregunta:
    - `outer.h`
    - `outer_parallel.h`
    - `complejidad_algoritmica.txt`
- Deberás subir estos archivos directamente a [www.gradescope.com](https://www.gradescope.com) o se puede crear un `.zip` que contenga todos ellos y subirlo.
- 
## Question #1 - `outer` (7 points)

El producto exterior es una operación que toma dos conjuntos de valores y genera una matriz donde cada elemento es el producto de un elemento del primer conjunto con uno del segundo. Esta operación es ampliamente utilizada en álgebra lineal, machine learning y cálculos científicos.

Implementar la función template genérica llamada `outer` que, mediante el uso de iteradores y contenedores genéricos, calcule el producto exterior entre dos conjuntos.

### Requerimientos:
La función debe recibir:
- Un tipo de contenedor genérico para almacenar el resultado (`ResultContainer`).
- Iteradores que definan el rango de los dos conjuntos de entrada (uno para filas y otro para columnas).
- La función debe calcular el producto exterior entre los elementos de los dos conjuntos y devolver un contenedor genérico bidimensional que almacene los resultados.

Firma esperada de la función:
```cpp
template <
        template <typename ...> typename ResultContainer = std::vector,
        typename IteratorRows,
        typename IteratorCols,
        typename T = std::common_type_t<IteratorRows::value_type, IteratorCols::value_type>
    >
ResultContainer<ResultContainer<T>> outer(
      IteratorRows start_rows, IteratorRows stop_rows,
      IteratorCols start_cols, IteratorCols stop_cols
  );
```

### Validaciones:
Si el rango definido por los iteradores es inválido (por ejemplo, `start_rows == stop_rows`), la función debe devolver un contenedor vacío.
Consideraciones de diseño:

La función debe ser completamente genérica y trabajar con cualquier tipo de contenedor (por ejemplo, `std::list`, `std::deque`, etc.).
Se puede usar `std::transform` para calcular los valores de cada fila.

### Use Case #1: Producto exterior entre dos vectores de enteros.
Entrada:
```cpp
std::vector<int> a = {1, 2};
std::vector<int> b = {3, 4, 5, 7};
auto result = outer(a.begin(), a.end(), b.begin(), b.end());
```
`result` esperado:
```cpp
{
    {3, 4, 5, 7},
    {6, 8, 10, 14}
}
```
### Use Case #2: Producto exterior entre un std::list y un std::deque.
Entrada:
```cpp
std::list<float> a = {1.5, 2.5, 1};
std::deque<float> b = {3.0, 4.0};
auto result = outer<std::list>(a.begin(), a.end(), b.begin(), b.end());
```
`result` esperado:
```cpp
{
    {4.5, 6.0},
    {7.5, 10.0},
    {3.0, 4.0}
}
```
### Use Case #2: Rango vacío para filas.
Entrada:
```cpp
std::vector<int> a = {};
std::vector<int> b = {1, 2, 3};
auto result = outer(a.begin(), a.end(), b.begin(), b.end());
```
`result` esperado:
```cpp
{}
```

## Question #2 - `outer_parallel` (7 points)

Implementar el problema #1 pero en su versión concurrente, evitando los race conditions.

## Question #3 - `Complejidad Algoritmica` (6 points)

Calcular la función de coste de tiempo y Big O de `complex_function`:
```cpp
template <typename T>
long long complex_function(const std::vector<T>& input) {
    size_t n = input.size();
    long long sum = 0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::vector<T> subset;
            for (size_t p = 0; p < n; ++p) {
                for (size_t q = 0; q < n; ++q) {
                    subset.push_back(input[p] * input[q]);
                }
            }
            std::sort(subset.begin(), subset.end());
            sum += subset[0];
        }
    }
    return sum;
}
```