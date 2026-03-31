#include <iostream>

enum Opcode { LOAD = 1, STORE = 2, ADD = 3, HALT = 99 };

class TinyCPU {
private:
  int memory[4];
  int program[16];
  int regA;
  int pc;
  bool halted;

public:
  TinyCPU() {
    for (int i = 0; i < 4; i++) {
      memory[i] = 0;
    }

    for (int i = 0; i < 16; i++) {
      program[i] = 0;
    }

    regA = 0;
    pc = 0;
    halted = false;
  }

  void loadProgram() {
    program[0] = LOAD;
    program[1] = 7;
    program[2] = STORE;
    program[3] = 0;
    program[4] = LOAD;
    program[5] = 5;
    program[6] = ADD;
    program[7] = 0;
    program[8] = STORE;
    program[9] = 1;
    program[10] = HALT;
  }

  void run() {
    while (!halted) {
      int instruction = program[pc];
      pc++;

      if (instruction == LOAD) {
        regA = program[pc];
        pc++;
      } else if (instruction == STORE) {
        int index = program[pc];
        memory[index] = regA;
        pc++;
      } else if (instruction == ADD) {
        int index = program[pc];
        regA = regA + memory[index];
        pc++;
      } else if (instruction == HALT) {
        halted = true;
      } else {
        std::cout << "Unknown instruction\n";
        halted = true;
      }

      printState();
      std::cout << "----\n";
    }
  }

  void printState() {
    std::cout << "pc: " << pc << '\n';
    std::cout << "regA: " << regA << '\n';
    std::cout << "memory: ";
    for (int i = 0; i < 4; i++) {
      std::cout << memory[i] << " ";
    }
    std::cout << '\n';
    std::cout << "halted: " << halted << '\n';
  }
};

int main() {
  TinyCPU cpu;
  cpu.loadProgram();
  cpu.run();
  return 0;
}
