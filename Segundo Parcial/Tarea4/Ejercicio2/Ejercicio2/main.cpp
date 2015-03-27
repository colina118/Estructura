#include "C:\Users\Miguel\Documents\tec\Cuarto Semestre\Estructura de Datos\Estructura\Segundo Parcial\Tema_6_Estructuras no lineales\CircularLinkedLis\CircularLinkedLis\CircularLinkedList.h"
#include "DispositivoToken.h"
#include <windows.h>

int main()
{
	CircularLinkedList<DispositivoToken> * dispositivos = new CircularLinkedList<DispositivoToken>();
	DispositivoToken first("112.255.255.109", "cisco", 1);
	DispositivoToken second("113.145.234.0", "cisco", 2);
	DispositivoToken third("113.145.123.234", "cisco", 3);
	DispositivoToken fourth("113.145.123.234", "HP", 4);
	DispositivoToken fifth("113.145.123.234", "Apple", 5);
	DispositivoToken sixth("113.145.123.234", "cisco", 6);
	int envia;
	int recibe;
	int a, b, c, d, e;

	//DoubleNode<DispositivoToken> *newnode = new DoubleNode<DispositivoToken>("112.255.255.109", "cisco", 1234);

	dispositivos->insert(new DoubleNode<DispositivoToken>(first), 0);
	dispositivos->insert(new DoubleNode<DispositivoToken>(second), 1);
	dispositivos->insert(new DoubleNode<DispositivoToken>(third), 2);
	dispositivos->insert(new DoubleNode<DispositivoToken>(fourth), 3);
	dispositivos->insert(new DoubleNode<DispositivoToken>(fifth), 4);
	dispositivos->insert(new DoubleNode<DispositivoToken>(sixth), 5);

	//std::cout << *dispositivos << std::endl;

	std::cout << "Escoga que dispositivo va a enviar (Ejemplo 1 = el primero envia)" << std::endl;
	std::cin >> envia;
	std::cout << "Escoge que dispositivo recibe " << std::endl;
	std::cin >> recibe;

		a = envia - 1;
		b = recibe - 1;
		c = 0;
		d = 0;

		if (a < b && b < dispositivos->size())
		{
			while (a < b - 1)
			{
					//Sleep(5000);
					std::cout << *dispositivos->at(a)->getNext();
					std::cout << "Este mensaje no es para mi" << std::endl;
					std::cout << std::endl;
					a++;
			}

			//Sleep(5000);
			std::cout << *dispositivos->at(a)->getNext();
			std::cout << "Este mensaje es para mi \nLe contestare al que me lo envio que lo recibi" << std::endl;
			std::cout << std::endl;

			a = envia - 1;
			c = 0;
			int k = b;

			while (b != dispositivos->size() -1 || c != a - 1 || k != dispositivos->size())
			{
				//Sleep(5000);
				if (b != dispositivos->size() -1)
				{
					std::cout << *dispositivos->at(b)->getNext();
					std::cout << "Yo no envie el mensaje" << std::endl;
					std::cout << std::endl;
					b++;
					k++;
				}
				else if (k != dispositivos->size())
				{
					if (envia == 1)
					{
						k++;
					}
					else{
						std::cout << *dispositivos->at(b)->getNext();
						std::cout << "Yo no envie el mensaje" << std::endl;
						std::cout << std::endl;
						k++;
					}
				}
				else if (c != a)
				{
					std::cout << *dispositivos->at(c)->getNext();
					std::cout << "Yo no envie el mensaje" << std::endl;
					std::cout << std::endl;
					c++;
				}
				else
				{
					c = -1;
				}
			}

			if (c == -1)
			{
				//Sleep(5000);
				std::cout << *dispositivos->at(b)->getNext();
				std::cout << "Yo envie el mensaje" << std::endl;
				std::cout << std::endl;
			}
			else
			{
				//Sleep(5000);
				std::cout << *dispositivos->at(c)->getNext();
				std::cout << "Yo envie el mensaje" << std::endl;
				std::cout << std::endl;
			}
		}
		else if (a > b)
		{
			int k= -1;
			while (a != dispositivos->size() - 1 || c != k)
			{
				if (a != dispositivos->size() - 1)
				{
					//Sleep(5000);
					std::cout << *dispositivos->at(a)->getNext();
					std::cout << "Este mensaje no es para mi" << std::endl;
					std::cout << std::endl;
					a++;
				}
				else if (c != b)
				{
					//Sleep(5000);
					std::cout << *dispositivos->at(c + 1)->getNext();
					std::cout << "Este mensaje no es mio" << std::endl;
					std::cout << std::endl;
					c++;
				}
				else
				{
					c = -1;
				}
			}

			if (c == -1)
			{
				//Sleep(5000);
				std::cout << *dispositivos->at(a)->getNext();
				std::cout << "Este mensaje es para mi \nLe contestare al que me lo envio que lo recibi" << std::endl;
				std::cout << std::endl;
			}
			else
			{
				//Sleep(5000);
				std::cout << *dispositivos->at(c)->getNext();
				std::cout << "Este mensaje es para mi \nLe contestare al que me lo envio que lo recibi" << std::endl;
				std::cout << std::endl;
			}

			a = envia - 1;
			c = 0;

			while (b < a - 1)
			{
				//Sleep(5000);
				std::cout << *dispositivos->at(b)->getNext();
				std::cout << "Yo no envie el mensaje" << std::endl;
				std::cout << std::endl;
				b++;
			}

			//Sleep(5000);
			std::cout << *dispositivos->at(b)->getNext();
			std::cout << "Yo envie el mensaje" << std::endl;
			std::cout << std::endl;

		}
		else if (b + 1> dispositivos->size())
		{
			e = a;
			while (d != 3)
			{
				if (a != dispositivos->size())
				{
					std::cout << *dispositivos->at(a)->getNext();
					std::cout << "Este mensaje no es para mi" << std::endl;
					std::cout << std::endl;
					a++;
				}
				else if (c + 1 != e)
				{
					std::cout << *dispositivos->at(c)->getNext();
					std::cout << "Este mensaje no es para mi" << std::endl;
					std::cout << std::endl;
					c++;
				}
				else if (c + 1 == e && d != 2)
				{
					std::cout << *dispositivos->at(c)->getNext();
					std::cout << "El dispositivo no contesto si le llego" << std::endl;
					std::cout << std::endl;
					c = 0;
					a = envia - 1;
					d++;
				}
				else
				{
					d++;
				}
			}

			std::cout << *dispositivos->at(c)->getNext();
			std::cout << "El dispositivo no existe" << std::endl;
			std::cout << std::endl;
		}

		delete dispositivos;
}