# include <iostream>

void my_swap(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}

void p_swap(int* var1, int* var2) {
	int tmp = *var1;
	*var1 = *var2;
	*var2 = tmp;
}

template<typename T>
void arr_sum(T arr[], const int length, T* var);

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// Указатели на переменные
	n = 7;
	std::cout << "n =  " << n << std::endl; // n = 7
	std::cout << "&n =  " << &n << std::endl; // Шестнадцатиричный код, т.к. & - операция обращения к адресу

	int* pn = &n; // Указатель на область памяти типа int, направленный на переменную n
	std::cout << "pn = " << pn << std::endl; // адрес

	std::cout << "pn = " << *pn << std::endl; // Разименование (7)
	*pn = 15;
	std::cout << "n =  " << n << std::endl; // 15

	std::cout << "-------------------------------";

	m = 42;
	std::cout << "m = " << m << std::endl; // 42
	std::cout << "&m = " << &m << std::endl; // адрес m

	pn = &m; // Перенаправление указателя на переменную m
	std::cout << "pn = " << pn << std::endl;

	*pn = 100;
	std::cout << "m = " << m << std::endl;

	int* pm = &m;
	std::cout << "pm = " << pm << std::endl;

	// Указатели и массивы
	const int size = 5;
	int arr[size]{ 30,40,50,60,70 };
	//				0  1  2  3  4
	int* parr = &arr[2];
	std::cout << *parr << std::endl; // 50
	std::cout << parr << std::endl; //
	std::cout << parr + 1 << std::endl; // увеличиваем адрес памяти на размер int
	std::cout << (parr + 1) << std::endl; // 60
	parr -=2;
	std::cout << *parr << std::endl; // 30

	std::cout << arr << std::endl; // адрес первого элемента массива

	std::cout << "Массив, выведенный через указатель:\n";
	for (short i = 0; i < size; i++)
		std::cout << *(parr + i) << ' ';
	std::cout << std::endl;

	// Указатели как параметры функции
	n = 7; m = 15;
	std::cout << "n = " << n << "; m = " << m << std::endl; // 7; 15
	// my_swap(n, m); // не работает, т.к. параметры функции - это лишь копии аргументов
	p_swap(&n, &m); //
	std::cout << "n = " << n << "; m = " << m << std::endl;

	// Задача 1. Сумма в указатель
	std::cout << "Задача 1.\nМассив: \n";
	const int size1 = 5;
	int arr1[size1]{ 15,5,6,13,1 };
	for (short i = 0; i < size1; i++)
		std::cout << *(arr1 + i) << ' ';
	std::cout << std::endl;
	int result;
	arr_sum(arr1, size1, &result);
	std::cout << "Сумма его элементов: " << result << std::endl;

	return 0;
}

template<typename T>
void arr_sum(T arr[], const int length, T* var) {
	*var = 0;
	for (int i = 0; i < length; i++)
		*var += *(arr + i);	
}