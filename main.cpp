#include <utility>


#include <iostream>
#include "defer.h"


int main() {
    try {
        struct test {
        public:
            char *ptr;

            test() {
                std::cout << "constructor called" << std::endl;
                ptr = new char[100];
            }

            ~test() {
                std::cout << "destructor called" << std::endl;
                delete[] ptr;
            }

        };

        auto inst = new test;
        auto ptr = new char[100];
        auto ptr_q = new float;
        ptr[0] = 1;
        /*
        volatile utils::defer defer_inst([inst]() -> void {
            delete inst;
        });*/
        DEFER(
                delete inst;
                std::cout << "deleting inst" << std::endl;
        )
        DEFER(
                delete[] ptr;
                std::cout << "deleting ptr" << std::endl
        )
        L_DEFER([ptr_q]()->void{
            delete ptr_q;
        })
        throw std::runtime_error("throwing runtime error");
    } catch (std::runtime_error &err) {
        std::cout << "exception have been caught" << std::endl;
    }
}