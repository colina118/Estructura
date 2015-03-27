#include "C:\Users\Miguel\Documents\tec\Cuarto Semestre\Estructura de Datos\Estructura\Segundo Parcial\Tema_6_Estructuras no lineales\Stack\Stack\Stack.h"

#include <iostream>
#include <string>


int main()
{
	using namespace mike;
	Stack<char> * stack = new Stack<char>();
	bool valida = true;


	std::string ecuacion;
	std::string inicio = "{([";
	std::string fin = "})]";


	std::cout << "escriba la ecuacion que desea verificar" << std::endl;
	std::getline(std::cin, ecuacion);

	for (auto i : ecuacion)
	{
		if (inicio.find(i) != std::string::npos)
		{
			stack->push(i);
		}
		else if (fin.find(i) != std::string::npos)
		{
			if (stack->empty() == true)
			{
				valida = false;
				break;
			}
			else if (i == '}' && stack->pop()->getInfo() != '{')
			{
				valida = false;
			}
			else if (i == ']' && stack->pop()->getInfo() != '[')
			{
				valida = false;
			}
			else if (i == ')' && stack->pop()->getInfo() != '(')
			{
				valida = false;
			}
		}
	}
	if (stack->empty() != true)
	{
		valida = false;
	}
	if (valida)
	{
		std::cout << "Si es una ecuacion valida" << std::endl;
	}
	else
	{
		std::cout << "No es una ecuacion valida" << std::endl;
	}
	delete stack;
	return 0;
}