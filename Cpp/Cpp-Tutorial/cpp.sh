#!/bin/bash
g++ -g ../Hello_World.cpp -o HelloWorld
gdb -tui --args executables/HelloWorld 