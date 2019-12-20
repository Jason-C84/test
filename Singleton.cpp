#include <iostream>
#include <pthread.h>

using namespace std;

class Singleton{
private:
	Singleton(){};
	Singleton *operator=(const Singleton &other);
	static Singleton *instance;
public:
	~Singleton(){};
	static Singleton *getInstance(){
		if(instance == NULL){
			instance = new Singleton;
		}
		return instance;
	}
};

Singleton *Singleton::instance = NULL;


class Singleton1{
private:
	Singleton1(){
		pthread_mutex_init(&mutex,NULL);
	};
	Singleton1 *operator=(const Singleton1 &other);
	static pthread_mutex_t mutex;
	static Singleton1 *instance;
public:
	~Singleton1(){};
	static Singleton1 *getInstance(){
			pthread_mutex_lock(&mutex);
			if(instance == NULL){
				instance = new Singleton1;
			}
			pthread_mutex_unlock(&mutex);
			return instance;
	}
};

Singleton1 *Singleton1::instance = NULL;
pthread_mutex_t Singleton1::mutex;


int main(int argc, char *argv[]){

	Singleton *instance1 = Singleton::getInstance();
	Singleton *instance2 = Singleton::getInstance();
	cout << "instance1 = " << instance1 << endl;
	cout << "instance2 = " << instance2 << endl;

	Singleton1 *instance3 = Singleton1::getInstance();
	Singleton1 *instance4 = Singleton1::getInstance();
	cout << "instance3 = " << instance3 << endl;
	cout << "instance4 = " << instance4 << endl;
	return 0;
}
