#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>
constexpr auto SIZE = 16;

const std::string points[SIZE] = { "msk_AP","msk_TS","msk_WH","mzh_TS",
"mzh_WH","zvn_WH","NN_AP","NN_TS", "NN_WH","dzr_TS","dzr_WH",
"vlg_AP","vlg_TS","vlg_WH","kam_TS","kam_WH" };

const std::map<std::string, int> towns = {
	{"Moscow", 2},
	{"Mozhaisk", 4},
	{"Zvenigorod", 5},
	{"Nizhniy Novgorod", 8},
	{"Dzerzhinsk", 10},
	{"Volgograd", 13},
	{"Kamishin", 15} };

const std::map<std::string, int> table = {
	{"msk", 0},
	{"mzh", 1},
	{"zvn", 2},
	{"NN", 3},
	{"dzr", 4},
	{"vlg", 5},
	{"kam", 6} };

const std::tuple<int, int, double> tableCost[21] = {
	{500, 300, 100},
	{200, 100, 500},
	{100, 60, 50},
	{0, 0, 0},
	{200, 100, 500},
	{100, 60, 50},
	{0, 0, 0},
	{0, 0, 0},
	{100, 60, 50},
	{500, 300, 100},
	{200, 100, 500},
	{100, 60, 50},
	{0, 0, 0},
	{200, 100, 500},
	{100, 60, 50},
	{500, 300, 100},
	{200, 100, 500},
	{100, 60, 50},
	{0, 0, 0},
	{200, 100, 500},
	{100, 60, 50} };

const int matrixDist[SIZE][SIZE] = {
{0, 20, 30, 108, 110, 65, 398, 0, 0, 0, 0, 926, 0, 0, 0, 0},
{20, 0, 10, 98, 100, 55, 0, 415, 0, 483, 0, 0, 937, 0, 1204, 0},
{30, 10, 0, 108, 110, 65, 0, 0, 430, 0, 390, 0, 0, 652, 0, 1234},
{108, 98, 108, 0, 5, 0, 0, 0, 0, 581, 0, 0, 1035, 0, 1302, 0},
{110, 100, 110, 5, 0, 78, 0, 0, 540, 0, 500, 0, 0 ,1062, 0, 1344},
{65, 55, 65, 0, 78, 0, 0, 0, 495, 0, 455, 0, 0, 1017, 0, 1299},
{398, 0, 0, 0, 0, 0, 0, 19, 23, 0, 26, 828, 0, 0, 0, 0},
{0, 415, 0, 0, 0, 0 ,19, 0, 4, 32, 0, 0, 840, 0, 919, 0},
{0, 0, 430, 0, 540, 495, 23, 4, 0, 0, 40, 0, 0, 849, 0, 1010},
{0, 483, 0, 581, 0, 0, 0, 32, 0, 0, 4, 0, 872, 0, 951, 0},
{0, 0, 390, 0, 500, 455, 26, 0, 40, 4, 0, 0, 0, 889, 0, 1050},
{926, 0, 0, 0, 0 ,0 ,828, 0, 0 ,0 ,0, 0, 15, 16, 0, 285},
{0, 937, 0, 1035, 0, 0, 0, 840, 0, 872, 0, 15, 0, 2, 257, 281},
{0, 0, 952, 0, 1062, 1017, 0, 0, 849, 0, 889, 16, 2, 0, 0 ,282},
{0, 1204, 0, 1302, 0, 0, 0, 919, 0, 951, 0, 0, 257, 0, 0, 2},
{0, 0, 1234, 0, 1344, 1299, 0, 0, 1010, 0, 1050, 285, 281, 282, 2, 0} };


enum Type { Turbo, Standart, Economy };

// ��������� �����
// ����������� � ����������� ��������
class Transport {
protected:
	int speed;
	int volume;
	double price;
	int distance;
public:
	Transport() {};
	~Transport() {};
	virtual double sumCost(int, int);
	virtual double sumTime(int);
	virtual int getDistance();
};

class Train : public Transport
{
public:
	Train();
	Train(std::tuple<int, int, double>, int);
	~Train();
};

class Plane : public Transport
{
public:
	Plane();
	Plane(std::tuple<int, int, double>, int);
	~Plane();
};

class Car : public Transport
{
public:
	Car();
	Car(std::tuple<int, int, double>, int);
	~Car();
};

//����������� � ���������� �������
class TransportFactory {
public:
	TransportFactory() {}
	~TransportFactory() {}
	virtual Transport create() = 0;
	virtual Transport create(std::tuple<int, int, double>, int) = 0;
};

class CarFactory : TransportFactory {
public:
	Transport create() {
		return Car();
	}
	Transport create(std::tuple<int, int, double> tuple, int dist) {
		return Car(tuple, dist);
	}
};

class PlaneFactory : TransportFactory {
public:
	Transport create() {
		return Plane();
	}
	Transport create(std::tuple<int, int, double> tuple, int dist) {
		return Plane(tuple, dist);
	}
};

class TrainFactory : TransportFactory {
public:
	Transport create() {
		return Train();
	}
	Transport create(std::tuple<int, int, double> tuple, int dist) {
		return Train(tuple, dist);
	}
};

class Track
{
	double cost;
	double time;
	int volume;
public:
	Track();
	Track(Transport, int);
	Track(Transport, Transport, Transport, int);
	Track(Transport, Transport, Transport, Transport, Transport, int);
	Track(Transport, Transport, Transport, Transport, Transport, Transport, Transport, int);
	double getCost();
	~Track();
};

class Order
{
	double cost;
	int volume;
	std::string startPoint;
	std::string finishPoint;
	enum::Type type;
	Track track;
public:
	Order();
	Order(Type, std::string, std::string, int);
	~Order();
	int decr(std::string);
	int** matrixUpd(Type);
	int* optim(int**, int, int);
	Track best(std::string, std::string, Type, int);
};

Train::Train()
{
	this->price = 200;
	this->speed = 100;
	this->volume = 500;
	this->distance = 0;
}

Train::Train(std::tuple<int, int, double> tuple, int dist)
{
	this->price = std::get<0>(tuple);
	this->speed = std::get<1>(tuple);
	this->volume = std::get<2>(tuple);
	this->distance = dist;
}

Train::~Train()
{

}

double Transport::sumCost(int mass, int dist)
{
	return (mass / volume) * sumTime(dist) * price;
}

double Transport::sumTime(int dist)
{
	return dist / speed;
}

int Transport::getDistance()
{
	return this->distance;
}

Car::Car()
{
	this->price = 100;
	this->speed = 60;
	this->volume = 50;
	this->distance = 0;
}

Car::Car(std::tuple<int, int, double> tuple, int dist)
{
	this->price = std::get<0>(tuple);
	this->speed = std::get<1>(tuple);
	this->volume = std::get<2>(tuple);
	this->distance = dist;
}

Car::~Car()
{

}

Plane::Plane()
{
	this->price = 500;
	this->speed = 300;
	this->volume = 100;
	this->distance = 0;
}

Plane::Plane(std::tuple<int, int, double> tuple, int dist)
{
	this->price = std::get<0>(tuple);
	this->speed = std::get<1>(tuple);
	this->volume = std::get<2>(tuple);
	this->distance = dist;
}

Plane::~Plane()
{

}

Track::Track()
{
	this->cost = 0;
	this->time = 0;
	this->volume = 0;
}

Track::~Track()
{

}

Track::Track(Transport car1, int volume)
{
	cost = car1.sumCost(volume, car1.getDistance());
	time = car1.sumTime(car1.getDistance());
}

Track::Track(Transport car1, Transport car2, Transport train1, int volume)
{
	cost = car1.sumCost(volume, car1.getDistance()) + car2.sumCost(volume, car2.getDistance());
	time = car1.sumTime(car1.getDistance()) + car2.sumTime(car2.getDistance());
	cost += train1.sumCost(volume, train1.getDistance());
	time += train1.sumTime(train1.getDistance());
}

Track::Track(Transport car1, Transport car2, Transport car3, Transport train1, Transport plane1, int volume)
{
	cost = car1.sumCost(volume, car1.getDistance()) + car2.sumCost(volume, car2.getDistance()) + car3.sumCost(volume, car3.getDistance());
	time = car1.sumTime(car1.getDistance()) + car2.sumTime(car2.getDistance()) + car3.sumTime(car3.getDistance());
	cost += train1.sumCost(volume, train1.getDistance());
	time += train1.sumTime(train1.getDistance());
	cost += plane1.sumCost(volume, plane1.getDistance());
	time += plane1.sumTime(plane1.getDistance());
}

Track::Track(Transport car1, Transport car2, Transport car3, Transport car4, Transport train1, Transport train2, Transport plane1, int volume)
{
	cost = car1.sumCost(volume, car1.getDistance()) + car2.sumCost(volume, car2.getDistance()) + car3.sumCost(volume, car3.getDistance()) + car4.sumCost(volume, car4.getDistance());
	time = car1.sumTime(car1.getDistance()) + car2.sumTime(car2.getDistance()) + car3.sumTime(car3.getDistance()) + car4.sumTime(car4.getDistance());
	cost += train1.sumCost(volume, train1.getDistance()) + train2.sumCost(volume, train2.getDistance());
	time += train1.sumTime(train1.getDistance()) + train2.sumTime(train2.getDistance());
	cost += plane1.sumCost(volume, plane1.getDistance());
	time += plane1.sumTime(plane1.getDistance());
}

double Track::getCost()
{
	return this->cost;
}

Order::Order()
{
	this->cost = 0;
	this->volume = 0;
	this->startPoint = "";
	this->finishPoint = "";
	this->track = Track();
	this->type = Type::Economy;
}

Order::Order(Type deliv, std::string startP, std::string finishP, int vol)
{
	this->startPoint = startP;
	this->finishPoint = finishP;
	type = deliv;
	this->track = best(startP, finishP, deliv, vol);
	this->cost = track.getCost();
	this->volume = vol;
}

Order::~Order()
{

}

// ���������
__interface Strategy
{
public:
	virtual Track createTrack(int* path, int volume);
};

class Context
{
	Strategy* strategy;
public:
	void setStrategy(Strategy* strategy)
	{
		this->strategy = strategy;
	}
	Track executeStrategy(int* path, int volume)
	{
		return this->strategy->createTrack(path, volume);
	}
};

class Strategy1 : public Strategy
{
	CarFactory carFactory;
public:
	Track createTrack(int* path, int volume) override
	{
		Transport car1 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[0]]))
			{
				car1 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
			}
		}

		Track track = Track(car1, volume);
		return track;
	}
};

class Strategy3 : public Strategy
{
	CarFactory carFactory;
	TrainFactory trainFactory;
	PlaneFactory planeFactory;
public:
	Track createTrack(int* path, int volume) override
	{
		Transport car1 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[0]]))
			{
				car1 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
			}
		}

		Transport car2 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[2]]))
			{
				car2 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[2]][path[3]]);
			}
		}

		Transport train1 = trainFactory.create();
		Transport plane1 = planeFactory.create();
		Track track = Track();

		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[1]]) && points[path[1]].find("TS"))
			{
				train1 = trainFactory.create(tableCost[(*it).second * 3 + 1], matrixDist[path[1]][path[2]]);
				track = Track(car1, car2, train1, volume);
			}

			if ((*it).first.find(points[path[1]]) && points[path[1]].find("AP"))
			{
				plane1 = planeFactory.create(tableCost[(*it).second * 3], matrixDist[path[1]][path[2]]);
				track = Track(car1, car2, plane1, volume);
			}
		}

		return track;
	}
};

class Strategy5 : public Strategy
{
	CarFactory carFactory;
	TrainFactory trainFactory;
	PlaneFactory planeFactory;
public:
	Track createTrack(int* path, int volume) override
	{
		Transport car1 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[0]]))
			{
				car1 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
			}
		}

		Transport train1 = trainFactory.create();
		Transport plane1 = planeFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[1]]) && points[path[1]].find("TS"))
			{
				train1 = trainFactory.create(tableCost[(*it).second * 3 + 1], matrixDist[path[1]][path[2]]);
			}
			if ((*it).first.find(points[path[1]]) && points[path[1]].find("AP"))
			{
				plane1 = planeFactory.create(tableCost[(*it).second * 3], matrixDist[path[1]][path[2]]);
			}
		}

		Transport car2 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[2]]))
			{
				car2 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[2]][path[3]]);
			}
		}

		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[3]]) && points[path[3]].find("AP"))
			{
				plane1 = planeFactory.create(tableCost[(*it).second * 3], matrixDist[path[3]][path[4]]);
			}
			if ((*it).first.find(points[path[3]]) && points[path[3]].find("TS"))
			{
				train1 = trainFactory.create(tableCost[(*it).second * 3 + 1], matrixDist[path[3]][path[4]]);
			}
		}

		Transport car3 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[4]]))
			{
				car3 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[4]][path[5]]);
			}
		}

		Track track = Track(car1, car2, car3, train1, plane1, volume);
		return track;
	}
};

class Strategy7 : public Strategy
{
	CarFactory carFactory;
	TrainFactory trainFactory;
	PlaneFactory planeFactory;
public:
	Track createTrack(int* path, int volume) override
	{
		Transport car1 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[0]]))
			{
				car1 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
			}
		}

		Transport train1 = trainFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[1]]))
			{
				train1 = trainFactory.create(tableCost[(*it).second * 3 + 1], matrixDist[path[1]][path[2]]);
			}
		}

		Transport car2 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[2]]))
			{
				car2 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[2]][path[3]]);
			}
		}

		Transport plane1 = planeFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[3]]))
			{
				plane1 = planeFactory.create(tableCost[(*it).second * 3], matrixDist[path[3]][path[4]]);
			}
		}

		Transport car3 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[4]]))
			{
				car3 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[4]][path[5]]);
			}
		}

		Transport train2 = trainFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[5]]))
			{
				train2 = trainFactory.create(tableCost[(*it).second * 3 + 1], matrixDist[path[5]][path[6]]);
			}
		}

		Transport car4 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[6]]))
			{
				car4 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[6]][path[7]]);
			}
		}

		Track track = Track(car1, car2, car3, car4, train1, train2, plane1, volume);

		return track;
	}
};

Track Order::best(std::string startP, std::string finishP, Type deliv, int volume)
{
	Context context = Context();
	int start = decr(startP);
	int finish = decr(finishP);
	int** mat = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
		mat[i] = new int[SIZE];
	mat = matrixUpd(deliv);
	int* path = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		path[i] = -1;
	}
	path = optim(mat, start, finish);
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (path[i] != -1)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	switch (count)
	{
	case 1:
	{
		context.setStrategy(new Strategy1());
		break;
	}
	case 3:
	{
		context.setStrategy(new Strategy3());
		break;
	}
	case 5:
	{
		context.setStrategy(new Strategy5());
		break;

	}
	case 7:
	{
		context.setStrategy(new Strategy7());
		break;
	}
	}
	return context.executeStrategy(path, volume);
}

int** Order::matrixUpd(Type type)
{
	int** matrix = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		matrix[i] = new int[SIZE];
		for (int j = 0; j < SIZE; j++)
		{
			matrix[i][j] = matrixDist[i][j];
		}
	}
	switch (type)
	{
	case Economy:
		for (int i = 0; i < SIZE; i++)
		{
			if (points[i].find("TS"))
				for (int j = 0; j < SIZE; j++)
					matrix[i][j] = 99999;
		}
	case Standart:
		for (int i = 0; i < SIZE; i++)
		{
			if (points[i].find("AP"))
				for (int j = 0; j < SIZE; j++)
					matrix[i][j] = 99999;
		}
	case Turbo:
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				if (matrix[i][j] == 0)
					matrix[i][j] = 99999;
		}
	}
	return matrix;
}

int* Order::optim(int** arr, int beginPoint, int endPoint)
{
	int* d = new int[SIZE];
	int* v = new int[SIZE];
	int temp, minindex, min;
	int begin_index = beginPoint;

	for (int i = 0; i < SIZE; i++)
	{
		d[i] = 99999;
		v[i] = 1;
	}
	d[begin_index] = 0;

	do {
		minindex = 99999;
		min = 99999;
		for (int i = 0; i < SIZE; i++)
		{
			if ((v[i] == 1) && (d[i] < min))
			{
				min = d[i];
				minindex = i;
			}
		}

		if (minindex != 99999)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (arr[minindex][i] > 0)
				{
					temp = min + arr[minindex][i];
					if (temp < d[i])
					{
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 99999);

	int* ver = new int[SIZE];
	int end = endPoint;
	ver[0] = end;
	int k = 1;
	int weight = d[end];

	while (end != begin_index)
	{
		for (int i = 0; i < SIZE; i++)
			if (arr[end][i] != 0)
			{
				int temp = weight - arr[end][i];
				if (temp == d[i])
				{
					weight = temp;
					end = i;
					ver[k] = i + 1;
					k++;
				}
			}
	}
	for (int i = 0; i < k / 2; i++)
		std::swap(ver[i], ver[k - 1 - i]);
	delete[] d, v;
	return ver;
}

int Order::decr(std::string str)
{
	for (auto it = towns.begin(); it != towns.end(); it++)
	{
		if (str._Equal((*it).first))
			return (*it).second;
	}
	return -1;
}