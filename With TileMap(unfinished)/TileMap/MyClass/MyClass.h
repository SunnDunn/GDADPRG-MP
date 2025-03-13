#pragma once

class MySingletonClass {
public:
	//Always need a static method to get the needed singular instances
	static MySingletonClass* getInstance();
	
	void test();
	void test2();
private:
	//Set constructor to private. Ensures only one instance
	//Prevents MysingletonClass copyClass = new MySingletonClass();
	MySingletonClass() {};
	
	//Set copy constructor to private. Ensures doesn't copy class in another var
	//Prevents MysingletonClass copyClass = *myClass
	MySingletonClass(MySingletonClass const&) {};

	//Assignment operator is private. Prevents asisgnment to other vars
	//If
	//MysingletonClass* myClass = MySingletonClass::getInstance();
	//MysingletonClass* myClass2 = MySingletonClass::getInstance();
	//Prevents *myClass2 = myClass
	MySingletonClass& operator=(MySingletonClass const&) {};

	//Variable where we store the instance
	static MySingletonClass* sharedInstance;
};