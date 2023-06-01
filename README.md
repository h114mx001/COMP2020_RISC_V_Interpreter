# COMP2020_RISC_V_Interpreter

RISC-V 32I Base Integer Instruction Set (Partial) Interpreter. 

Group project COMP2020 - Computer Organization. 

The interpreter supports: 
| Instruction type | Instructions |
|------------------|--------------|
| R-type      |	ADD, SUB, AND, OR, XOR, NOR, SLT, SLL, SRA |
| I-type      |	ADDI, ANDI, ORI, XORI, SLTI |
| Memory-type | LW, LB, SW, SB              |
| U-type      | LUI                         | 
 
## How to use this file 

**Prerequisite:** Any *NIX distributions. 

When you clone this repo, please run 

```bash
git clone https://github.com/h114mx001/COMP2020_RISC_V_Interpreter
cd COMP2020_RISC_V_Interpreter
./test.sh 
```

to compile the code and run our test cases. 

To run new file, please prepare a RISC-V code file and run

```bash
./build/risc_v_interpreter < /path/to/your_file
```

For debug mode, run the binary with `-d` flag. 

## Compile the code only 

```bash
make riscv_interpreter
./build/riscv_interpreter < /path/to/your_file
# for cleaning the repository only
make clean
```
