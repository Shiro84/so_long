📚 Libft - Biblioteca Personalizada

🌟 Propósito del Proyecto
La Libft es una colección de funciones básicas en C, implementadas manualmente, con el fin de dominar operaciones fundamentales de memoria, manipulación de cadenas, listas enlazadas y conversión de tipos. Este proyecto no solo sirve como una biblioteca práctica, sino que también proporciona una sólida base para desarrollos en C de más alto nivel.

🧩 Funciones Clave de la Libft
Manipulación de Cadenas
Estas funciones imitan las de la biblioteca estándar string.h, y son fundamentales para trabajar con texto en C.

ft_strlen: Devuelve la longitud de una cadena (const char *str), sin contar el carácter nulo.
Útil en casi todos los contextos donde se manipulen strings.
ft_strcpy y ft_strncpy: Copian una cadena a otra. ft_strncpy permite limitar el número de caracteres copiados.
Crucial para el manejo seguro de memoria, evita problemas al copiar cadenas de tamaño desconocido.
ft_strcmp y ft_strncmp: Comparan cadenas de texto completas o hasta n caracteres, respectivamente.
Esencial para verificar si dos cadenas son iguales, con control sobre la cantidad de caracteres a comparar.
ft_strdup: Duplica una cadena de texto, reservando memoria para la copia.
Ideal para casos donde necesitamos una copia independiente de una cadena para evitar conflictos de memoria.
Gestión de Memoria

Estas funciones son fundamentales en C, donde la memoria se maneja de forma manual:

ft_memset: Rellena una región de memoria con un byte específico.
Útil para inicializar memoria antes de usarla, como rellenar una estructura o array vacío.
ft_memcpy y ft_memmove: Copian bloques de memoria. ft_memmove es seguro para copiar en regiones de memoria que se solapan.
Son la base para mover datos entre arrays o estructuras de manera controlada.
ft_memalloc: Reserva un bloque de memoria y lo inicializa a cero.
Es una alternativa a malloc, pero garantiza que los datos sean cero al inicio, evitando errores al no inicializar.
ft_memdel: Libera un puntero y lo establece en NULL para evitar "dangling pointers".
Recomendado para gestionar la liberación segura de memoria, reduciendo el riesgo de fugas y errores de acceso.

Conversión de Tipos

Convierte datos en strings o enteros, comúnmente usados en muchas aplicaciones.
ft_atoi: Convierte una cadena de caracteres numéricos (char *str) a un entero (int).
Ideal para interpretar entradas numéricas del usuario o archivos.
ft_itoa: Convierte un número entero a una cadena de caracteres (char *).
Útil en aplicaciones donde necesitas manipular números en forma de texto (ej. mostrar números en pantalla).

Operaciones con Caracteres

Estas funciones ayudan a trabajar con caracteres individuales, como mayúsculas, minúsculas y dígitos.
ft_isalpha, ft_isdigit, ft_isalnum: Comprueban si un carácter es una letra, un dígito o una combinación alfanumérica.
Ideales para validar entradas del usuario y formatear texto de entrada.
ft_tolower y ft_toupper: Convierte un carácter a minúscula o mayúscula.
Muy útil en aplicaciones que requieren normalización de texto, como procesadores de texto o parsers.
Entrada/Salida Básica

Para manipulación básica de la entrada y salida de datos en C.

ft_putchar_fd y ft_putstr_fd: Imprimen un carácter o una cadena en un file descriptor (ej. consola o archivo).
Permiten mayor control sobre dónde se envía la salida, útil para depuración o generación de logs.
ft_putendl_fd: Similar a ft_putstr_fd, pero añade un salto de línea al final.
Perfecto para mejorar la legibilidad de la salida.
ft_putnbr_fd: Imprime un número entero en un file descriptor.
Especialmente útil para debug, ya que permite ver valores de enteros en consola o archivos sin conversiones adicionales.

Funciones de Listas Enlazadas
Para manipular listas dinámicas, un elemento clave en estructuras de datos avanzadas.

ft_lstnew: Crea un nuevo nodo en la lista.
Es la base para crear listas enlazadas, almacenando datos de forma dinámica.
ft_lstdelone y ft_lstdel: Eliminan uno o todos los nodos de una lista.
Permiten gestionar la memoria de listas enlazadas evitando fugas y eliminando nodos específicos o toda la lista.
ft_lstadd: Añade un nuevo nodo al inicio de la lista.
Muy útil para crear listas de forma dinámica y rápida.
ft_lstiter y ft_lstmap: Iteran sobre los elementos de la lista y aplican una función a cada nodo o crean una nueva lista con los resultados.
Ideales para manipular cada elemento de una lista enlazada, aplicando transformaciones o recolectando información.
