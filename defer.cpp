//
// Created by Kirill on 2019-02-28.
//

#include <iostream>
#include "defer.h"

utils::defer::defer(std::function<void(void)> instruction)
        : responsibility(std::move(instruction)) {}

utils::defer::~defer() {
    std::cout<<"calling defer destructor"<<std::endl;
    this->responsibility();
}

utils::defer::defer() {
    responsibility = []() -> void {};
}

utils::defer::defer(utils::defer &&other) noexcept {
    responsibility = std::move(other.responsibility);
    other.responsibility = []() -> void {};
}
