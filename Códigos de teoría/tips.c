/*
			Algunos tips random acerca de C, IDEs, y cosas por el estilo.
*/


/*
		Sobre entradas y salidas en C: 
	
    Para C, la entrada y salida de datos son archivos. C abre estos archivos automáticamente.
	
	Cuando hacemos un fflush(stdin), estamos limpiando el buffer del archivo de entrada.
	
    stdin es un puntero a archivo, que apunta hacia el teclado
    stdout es un puntero a archivo, que apunta a la pantalla
    stderr es un puntero a archivo, que apunta a la salida normal de errores    
*/


/*
		Sobre declaraciones de compilación: 
		
    Declaracion de compilación: https://en.wikipedia.org/wiki/Include_guard
	
	TL;DR: si pongo dos includes de la misma biblioteca en dos headers diferentes, poner un include guard me asegura
	que las cosas no se definan dos veces y cause error de compilación.
	
    #ifndef MAIN_H_
    #define MAIN_H_

    #endif // MAIN_H_
*/


/*
		Sobre el fin de ejecución de un programa:

	Siempre terminar un programa ejecutado por el entorno de desarrollo utilizando CTRL+C (o CTRL + Pausa, el que sea),
	o si el programa terminó su ejecución correctamente, apretando alguna tecla cualquiera (PRESS ANY KEY).	
*/

/*
		Sobre static:
	
	La declaración static inicializa una región de memoria con los valores de esa variable, lo hace en un lugar "a parte", y ya queda inicializado 
	desde el comienzo de ejecución del programa. O sea, sin necesidad de ir a la función que declara esa variable para asignar la memoria con esos valores.
*/

/*
		Sobre operaciones y letras específicas: 
	
	La operación: 234 + 123L, devuelve un LONG. Esto es debido a que la letra L que agregamos en 123 convierte la operación en una operación con long ints.
	
	Algo parecido sucede al usar la letra U, que hace referencia a UNSIGNED.
*/

/**		
*		Sobre comentarios de documentación: 
*
*	Este es el formato utilizado para comentarios de documentación. Notar cómo es diferente.
*	Si yo pongo uno de estos comentarios antes de una función, va a aparecer en la descripción que del IDE al momento de escribir la función.
*
**/