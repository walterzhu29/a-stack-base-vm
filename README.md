# a-stack-base-vm
 A simple stack base virtual machine


## how program counter works
![ program counter](/media/program_counter.png "pic from LeongKJ") 

Cpu + Register + Program counter (PC) has 3 steps in it's circle:

- fetch instruction from memory to register
- pc++
- decode register current instruction pieces 
- check if decoded instruction pieces is a complete instruction
    - if complete, Cpu execute instruction
    - if not move to step1

## For example:

An add instruction looks like:
```
3 4 ADD
```

It has 3 pieces, data 3, data 4, primitive operation ADD, SUB, MUL, DIV

## Concepts

### lexing
The action of read string from source file, and break it up into tokens.
