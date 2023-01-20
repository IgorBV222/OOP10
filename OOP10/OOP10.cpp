#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <tuple> //кортеж
#include <vector>
#include <unordered_map>


//Агрегация, композиция, наследование

//class A{
//public:
//    void public_metod() {}
//    //int public_field...
//protected:
//    void protected_metod() {}
//private:
//    void private_metod() {}
//};

// public, private, protected
//class B : public A{
//    // protected class A можно использовать только в теле наследника В
//    void func() {
//        void protected_metod();
//   }
//
//};

//Агрегация, композиция, наследование
//Ассоциация делится на :
//Агрегация и Композиция - один класс не существует без другого (автомобиль не существует без двигателя)
//class Engine {
//public:
//    Engine(int p) : _power(p){
//        std::cout << "Parametrized constructor was called (Engine)" << std::endl;
//    }
//    Engine(Engine& other) : _power(other._power) {
//        std::cout << "Copy constructor was called (Engine)" << std::endl;
//    }   
//      
//    int getPower() {
//        return _power;
//    }
//private:
//    int _power;
//};

//class Car  {
//    //Композиция
//public:
//    Car (int enginePower): _engine(enginePower){}
//    // Агрегация - классы могут суествовать друг без друга:
//    Car(Engine &e): _engine(e){}
//
//    int getPower() {
//        return _engine.getPower();
//    }
//private:
//    std::string _model = "Porshe";
//    Engine _engine; // Car ассоциирован с  Engine
//};

/*
int main(){
    
    A a;
    a.public_metod();
    B b; // B может использовать только public А в  main
    b.public_metod();


    //Композиция
   /* Car c(200);
    std::cout << c.getPower() << std::endl;*/
    
    // Агрегация
    /*Engine e(333);
    Car c2(e);
    std::cout << c2.getPower() << std::endl;
   
}*/


//Виртуальное наследование
//class Vehicle {
//public:
//
//    Vehicle(int speed) : _speed(speed) {
//        std::cout << "Vehicle()" << std::endl;
//    }
//    int getSpeed() {
//        return _speed;
//    }
//private:
//    int _speed;
//};
//
//enum Transmition { // enum - перечесляемый тип.int 
//    Auto, //АКП
//    Manual //МКП
//};
//class Car : public virtual Vehicle {
//public:
//    Car(int speed, Transmition transmition) : Vehicle(speed), _transmition(transmition) {}
//
//private:
//    Transmition _transmition;
//};
//
//enum OriginCountry {
//    Russia,
//    UAE
//
//};
//class Airplane : public virtual Vehicle {
//
//public:
//    Airplane(int speed, OriginCountry country) :
//        Vehicle(speed), _originCountry(country) {}
//private:
//    OriginCountry _originCountry;
//
//};
//
//class FlyingCar : public Car, Airplane {
//public:
//    FlyingCar(int speed, OriginCountry country,
//        Transmition transmition, FlyingCarMode initialMode) :
//        Car(speed, transmition), Airplane(speed, country),
//        _mode(initialMode), Vehicle(speed) {}
//private:
//    FlyingCarMode _mode;
//};
//
//int main() {
//    FlyingCar fc(800, OriginCountry::Russia, Transmition::Auto,
//        FlyingCarMode::Fly);
//    std::cout << fc.getSpeed() << std::endl;
//
//    Vehicle* fc2 = new FlyingCar(800, OriginCountry::Russia, Transmition::Auto,
//        FlyingCarMode::Fly);
//    
//    delete fc2;
//
//}



//ВИРТУАЛЬНЫЕ ФУНКЦИИ

class A {
public:
    //static dispatch / early binding (статический вызов, ранняя привязка метода)
    void foo() {
        std::cout << "A::foo()" << std::endl;
    }
};

class B { // vptr
public:
    //vtable
    virtual void bar() {
        std::cout << "B::bar()" << std::endl;
    }
    virtual void qux() {
        std::cout << "B::qux()" << std::endl;
    }
};

class C : public B { // vptr

public:
    // vptr
public:
     void bar() override {//override - перегрузка существующей функции
        std::cout << "C::bar()" << std::endl;
    }    
};

int main() {

    B* b = new C;
    b->bar();

}