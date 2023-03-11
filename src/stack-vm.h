#ifndef STACK_VM_H
#define STACK_VM_H

#include <iostream>
#include <vector>

//type definitions
typedef int32_t i32;

class StackVM {
    i32 pc = 100; //program counter, for instructions we use memories start at 100
    i32 sp = -1; //stack pointer, for stack we use memeories start at 0 to 99
    std::vector<i32> memory;
    i32 typ = 0;
    i32 dat = 0;
    i32 running = 1;

    i32 getType(i32 instruction);
    i32 getData(i32 instruction);

    void fetch();
    void decode();
    void execute();
    void doPrimitive();

    public:
    StackVM();
    void run();
    void loadProgram(std::vector<i32> prog);
};

#endif