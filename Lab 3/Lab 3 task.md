На основе материалов лабораторной работы № 2 реализовать классы "транспортное средство" (ТС), "колесо", "двигатель" и "топливная система" и связать их в общую иерархию классов.

Минимальный набор данных и методов: 

1. Класс "транспортное средство"
	1. Поля данных:
		- название;
		- текущий пробег автомобиля;
		- текущая скорость ТС - функция от мощности, статуса колес и оставшегося топлива;
		- количество колес;
	1. Методы:
		- прохождение по трассе;
1. Класс "колесо". У каждого ТС - массив экземпляров класса
	1. Поля данных:
		- статус колеса. Множество статусов: {целое; повреждено}. Если колесо повреждено - текущая скорость ТС падает вдвое, если повреждены два колеса - вчетверо и т.д.;
		- текущий пробег колеса;
	1. Методы:
		- проверка статуса колеса. Вероятность повреждения увеличивается с увеличением пробега колеса;
2. Класс "двигатель"
	1. Поля данных:
		- мощность;
		- потребление;
	1. Методы:
		- расчет потребления двигателя;
3. Класс "топливная система"
	1. Поля данных:
		- объем бака;
		- текущий остаток топлива;
	1. Методы:
		- вычисление текущего остатка топлива.

Дополнительно каждому классу определить конструктор, которым инициализируются все необходимые значения и методы для вывода данных. Для реализации функции вывода использовать механизм перегрузки или виртуальные функции.

Требования к меню аналогичны изложенным в задании к лабораторной работе № 2. Расчет прохождения всех ТС по трассе реализовать с помощью дружественной функции.

Дата сдачи - дата выдачи + 3 недели.