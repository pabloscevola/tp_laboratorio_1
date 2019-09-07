/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "bibliotecaTP1.h"

int main(void) {
	float operandoUnoRecibido = 0;
	float operandoDosRecibido = 0;
	int menu;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	float resultadoFactorialA;
	float resultadoFactorialB;
	float resultadoDivisionOk;
	int flagOperandoUno = 0;
	int flagOperandoDos = 0;
	int flagOperandoResultado = 0;
	printf("Ingrese la opcion que desea\n ");
	printf("1. Ingresar primer operando: (A=%f)\n ", operandoUnoRecibido);
	printf("2. Ingresar segundo operando: (B=%f)\n ", operandoDosRecibido);
	printf("3. Calcular todas las operaciones:\n "
			"a. Calcular la suma\n "
			"b. Calcular la resta\n "
			"c. Calcular la division\n "
			"d. Calcular la multiplicacion\n "
			"e. Calcular el factorial de ambos operandos\n ");
	printf("4. Informar resultados\n "
			"5. Salir\n");
	scanf("%i", &menu);
//	system("clear");
	while (menu != 5) {
		switch (menu) {
		case 1: {
			getFloat(&operandoUnoRecibido, "Ingrese el primer operando\n",
					"El dato ingresado es incorrecto\n", 2);
			flagOperandoUno = 1;
			break;
		}
		case 2: {
			getFloat(&operandoDosRecibido, "Ingrese el segundo operando\n",
					"El dato ingresado es incorrecto\n", 2);
			flagOperandoDos = 1;
			break;
		}
		case 3: {
			if (flagOperandoUno == 1 && flagOperandoDos == 1) {

				resultadoSuma = Suma(operandoUnoRecibido, operandoDosRecibido);
				resultadoResta = Resta(operandoUnoRecibido,
						operandoDosRecibido);
				resultadoDivisionOk = Division(operandoUnoRecibido,
						operandoDosRecibido, &resultadoDivision);
				resultadoMultiplicacion = Multiplicacion(operandoUnoRecibido,
						operandoDosRecibido);
				resultadoFactorialA = Factorial(operandoUnoRecibido);
				resultadoFactorialB = Factorial(operandoDosRecibido);
				flagOperandoResultado = 1;
			} else {
				printf("Error de sintaxis\n");
			}

			break;
		}
		case 4: {
			if (flagOperandoResultado == 1) {
				printf("El resultado de %f + %f es: %f\n", operandoUnoRecibido,
						operandoDosRecibido, resultadoSuma);
				printf("El resultado de %f - %f es: %f\n", operandoUnoRecibido,
						operandoDosRecibido, resultadoResta);
				if (resultadoDivisionOk == EXIT_ERROR) {
					printf("No es posible dividir por 0");
				} else {
					printf("El resultado de %f/%f es: %f\n",
							operandoUnoRecibido, operandoDosRecibido,
							resultadoDivision);
				}
				printf("El resultado de %f * %f es: %f\n", operandoUnoRecibido,
						operandoDosRecibido, resultadoMultiplicacion);
				if (resultadoFactorialA != EXIT_ERROR
						&& resultadoFactorialB != EXIT_ERROR) {
					printf(
							"El factorial de %0.f es: %0.f y El factorial de %.0f es: %.0f\n",
							operandoUnoRecibido, resultadoFactorialA,
							operandoDosRecibido, resultadoFactorialB);
				} else {
					if (resultadoFactorialA == EXIT_ERROR
							&& resultadoFactorialB == EXIT_ERROR) {
						printf("No hay factorial disponible de %0.f\n",
								operandoUnoRecibido);
						printf("No hay factorial disponible de %0.f\n",
								operandoDosRecibido);
					} else {
						if (resultadoFactorialA == EXIT_ERROR) {
							printf("No hay factorial disponible de %0.f\n",
									operandoUnoRecibido);
							printf("El factorial de %0.f es: %0.f \n",
									operandoDosRecibido, resultadoFactorialB);
						} else {
							printf("El factorial de %0.f es: %0.f \n",
									operandoUnoRecibido, resultadoFactorialA);
							printf("No hay factorial disponible de %0.f\n",
									operandoDosRecibido);
						}
					}
				}
				printf("\n");
			} else {
				printf("No hay resultados disponibles\n");
			}
			break;
		}
		default: {
			printf("La opcion es incorrecta\n");
		}
		}
//		system("pause");
//		system("clear");
		printf("Ingrese la opcion que desea\n ");
		printf("1. Ingresar primer operando: (A=%f)\n ", operandoUnoRecibido);
		printf("2. Ingresar segundo operando: (B=%f)\n ", operandoDosRecibido);
		printf("3. Calcular todas las operaciones:\n "
				"a. Calcular la suma\n "
				"b. Calcular la resta\n "
				"c. Calcular la division\n "
				"d. Calcular la multiplicacion\n "
				"e. Calcular el factorial de ambos operandos\n ");
		printf("4. Informar resultados\n "
				"5. Salir\n");
		scanf("%i", &menu);
	}
}
