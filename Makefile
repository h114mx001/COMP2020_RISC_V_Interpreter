# Customized makefile for COMP2020 project. 

# Group members:
# + Nguyen Tuan Anh
# + Ta Viet Thang
# + Huynh Quynh Anh

CFLAGS = -std=c99 -D_BSD_SOURCE -Wall -g

all: riscv_interpreter

linkedlist: linkedlist.o linkedlist_main.o 
	$(CC) $(CFLAGS) -o ./build/linkedlist ./object/linkedlist.o ./object/linkedlist_main.o

hashtable: linkedlist.o hashtable.o hashtable_main.o
	$(CC) $(CFLAGS) -o ./build/hashtable ./object/linkedlist.o ./object/hashtable.o ./object/hashtable_main.o

riscv_interpreter: linkedlist.o hashtable.o riscv.o riscv_interpreter.o
	$(CC) $(CFLAGS) -Werror -o ./build/riscv_interpreter ./object/linkedlist.o ./object/hashtable.o ./object/riscv.o ./object/riscv_interpreter.o

%.o: ./source/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	mv *.o ./object/

clean:
	rm -f ./object/*.o ./build/riscv_interpreter ./build/linkedlist ./build/hashtable ./build/linkedlst_main ./build/hashtable_main