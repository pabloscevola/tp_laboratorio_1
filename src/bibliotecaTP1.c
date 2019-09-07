#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "bibliotecaTP1.h"

/**
 * \brief Recibe el numero, lo verifica para que sea un numero valido (float) y lo devuelve.
 * \param *presultado Es el numero recibido.
 * \param *pmensaje Es el mensaje a ser mostrado.
 * \param *pmensajeError Es el mensaje de error a ser mostrado.
 * \param reintentos Son los reintentos para ingresar un numero valido.
 * \return Devuelve si pudo recibir el numero y guarda el valor en la direccion del *presultado.
 *
 */
float getFloat(float *presultado, char *pmensaje, char *pmensajeError,
		int reintentos) {
	int retorno = EXIT_ERROR;
	float bufferFloat;
	if (presultado != NULL && pmensaje != NULL && pmensajeError != NULL
			&& reintentos >= 0) {
		do {
			printf("%s", pmensaje);
			__fpurge(stdin);
			if (scanf("%f", &bufferFloat) == 1) {
				retorno = EXIT_SUCCESS;
				*presultado = bufferFloat;
				break;
			}
			printf("%s", pmensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}
/**
 * \brief Recibe los dos numeros ingresados y calcula la suma.
 * \param operandoUno Corresponde al primer numero ingresado.
 * \param operandoDos Corresponde al segundo numero ingresado.
 * \return La suma de los números.
 *
 */
float Suma(float operandoUno, float operandoDos) {
	float suma;
	suma = operandoUno + operandoDos;
	return suma;
}
/**
 * \brief Recibe los dos numeros ingresados y calcula la resta.
 * \param operandoUno Corresponde al primer numero ingresado.
 * \param operandoDos Corresponde al segundo numero ingresado.
 * \return La resta de los números.
 *
 */
float Resta(float operandoUno, float operandoDos) {
	float resta;
	resta = operandoUno - operandoDos;
	return resta;
}
/**
 * \brief Recibe los dos numeros ingresados y calcula la division.
 * \param operandoUno Corresponde al primer numero ingresado.
 * \param operandoDos Corresponde al segundo numero ingresado.
 * \param *pdivision Corresponde al puntero del resultado de la división.
 * \return Devuelve si pudo realizar la division.
 *
 */
float Division(float operandoUno, float operandoDos, float *pdivision) {
	if (operandoDos == 0) {
		return EXIT_ERROR;
	} else {
		*pdivision = operandoUno / operandoDos;
		return EXIT_SUCCESS;
	}
}
/**
 * \brief Recibe los dos numeros ingresados y calcula la multiplicacion.
 * \param operandoUno Corresponde al primer numero ingresado.
 * \param operandoDos Corresponde al segundo numero ingresado.
 * \return La multiplicacion de los numeros.
 *
 */
float Multiplicacion(float operandoUno, float operandoDos) {
	float multiplicacion;
	multiplicacion = operandoUno * operandoDos;
	return multiplicacion;
}
/**
 * \brief Recibe los dos numeros ingresados y calcula el factorial.
 * \param operandoFactorial Corresponde al numero ingresado.
 * \return El factorial del numero.
 *
 */
int Factorial(float operandoFactorial) {
	int factorial = 1;
	int operandoFactorialInt;
	operandoFactorialInt = (int) operandoFactorial;
	if (operandoFactorialInt == 0 || operandoFactorialInt == 1) {
		return 1;
	} else {
		if (operandoFactorialInt < 0) {
			return EXIT_ERROR;
		} else {
			while (operandoFactorialInt > 1) {
				factorial = factorial * operandoFactorialInt;
				operandoFactorialInt--;
			}
			return factorial;
		}
	}
}
