#include "MyClass.h"
#include <iostream>

MySingletonClass* MySingletonClass::sharedInstance = nullptr;

MySingletonClass* MySingletonClass::getInstance() {
	//Initialize only when needed
	if (sharedInstance == nullptr) {
		sharedInstance = new MySingletonClass();
	}

	return sharedInstance;
}

void MySingletonClass::test() {
	std::cout << "test" << std::endl;
}

void MySingletonClass::test2() {
	std::cout << "test2" << std::endl;
}