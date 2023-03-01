#include "Car.hpp"
#include <json/json.h>

Car::Car(const Json::Value &carJson) {
    model = carJson["model"].asString();
    year = carJson["year"].asInt();
    price = carJson["price"].asFloat();
    count = carJson["count"].asInt();
}

std::string Car::getModel() const {
    return model;
}

int Car::getYear() const {
    return year;
}

float Car::getPrice() const {
    return price;
}

int Car::getCount() const {
    return count;
}

void Car::setModel(const std::string &model) {
    this->model = model;
}

void Car::setYear(int year) {
    this->year = year;
}

void Car::setPrice(float price) {
    this->price = price;
}

void Car::setCount(int count) {
    this->count = count;
}

void Car::setAvailability(bool available) {
    this->available = available;
}

int Car::getNumAvailable() {
    return count;
}
