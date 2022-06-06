#include <iostream>

using namespace std;

class Car {
    friend class Driver;

private:
    enum {
        off, on
    };
    enum {
        Minvel, Maxvel = 200
    };
    int mode;
    int velocity;
public:
    Car(int m = on, int v = 50) : mode(m), velocity(v) {};

    bool velup(int v);

    bool veldown(int v);

    bool ison() const;

    int getvel() const;

    void showinfo() const;
};

class Driver {
public:
    bool velup(Car &car, int v);

    bool veldown(Car &car, int v);

    void setmode(Car &car);

    bool ison(Car &car) const;
};

bool Driver::velup(Car &car, int v) {
    return car.velup(v);
}

bool Driver::veldown(Car &car, int v) {
    return car.veldown(v);
}

void Driver::setmode(Car &car) {
    car.mode = (car.mode == car.on ? car.off : car.on);
}

bool Driver::ison(Car &car) const {
    return car.ison();
}

bool Car::velup(int v) {
    if (this->velocity + v <= Maxvel && this->velocity + v >= Minvel) {
        this->velocity += v;
        return true;
    } else return false;
}

bool Car::veldown(int v) {
    if (this->velocity - v <= Maxvel && this->velocity - v >= Minvel) {
        this->velocity -= v;
        return true;
    } else return false;
}

bool Car::ison() const {
    return this->mode == on;
}

int Car::getvel() const {
    return this->velocity;
}

void Car::showinfo() const {
    if (mode == on)
        cout << "The information of the car: " << "mode is On" << ", velocity is " << velocity << endl;
    else
        cout << "The information of the car: " << "mode is Off" << ", velocity is " << velocity << endl;
}

int main() {
    Car c;
    c.showinfo();
    c.velup(120);
    c.showinfo();
    Driver d;
    d.setmode(c);
    c.showinfo();
    d.veldown(c, 50);
    c.showinfo();
    d.velup(c, 150);
    c.showinfo();
}