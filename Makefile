CC = sdcc
LINK_FLAGS = --no-std-crt0 -mz80 --opt-code-size --code-loc 0xC100 --data-loc 0x1000
COMPILE_FLAGS = --std-c99 --no-std-crt0 -mz80 --opt-code-size --code-loc 0xC100 --data-loc 0x1000 --Werror
COMMON_REL_FILES = obj/crt0.rel obj/amsgraph.rel obj/amstext.rel obj/heap.rel obj/readline.rel obj/repl.rel obj/atom.rel obj/main.rel
REL_FILES = $(COMMON_REL_FILES)
TEST_REL_FILES = $(COMMON_REL_FILES) obj/test_helpers.rel obj/lisp_tests.rel obj/atom_tests.rel

all: clean assemble_libs_common assemble_libs_release compile_release link rom checksize
tests: clean assemble_libs_common assemble_libs_tests compile_tests link_tests rom emulate

clean:
	rm -rf bin
	rm -rf obj
	mkdir -p bin
	mkdir -p obj

assemble_libs_release:
	sdasz80 -o ./obj/crt0.rel src/crt0.s

assemble_libs_tests:
	sdasz80 -o ./obj/crt0.rel src/crt0_test.s

assemble_libs_common:
	sdasz80 -o ./obj/amsgraph.rel src/amsgraph.s
	sdasz80 -o ./obj/amstext.rel src/amstext.s
	sdasz80 -o ./obj/heap.rel src/heap.s

compile_release:
	$(CC) $(COMPILE_FLAGS) -c src/main.c -o obj/main.rel
	$(CC) $(COMPILE_FLAGS) -c src/readline.c -o obj/readline.rel
	$(CC) $(COMPILE_FLAGS) -c src/repl.c -o obj/repl.rel
	$(CC) $(COMPILE_FLAGS) -c src/atom.c -o obj/atom.rel

compile_tests:
	$(CC) $(COMPILE_FLAGS) -c tests/main.c -o obj/main.rel
	$(CC) $(COMPILE_FLAGS) -c src/readline.c -o obj/readline.rel
	$(CC) $(COMPILE_FLAGS) -c src/repl.c -o obj/repl.rel
	$(CC) $(COMPILE_FLAGS) -c src/atom.c -o obj/atom.rel
	$(CC) $(COMPILE_FLAGS) -c tests/test_helpers.c -o obj/test_helpers.rel
	$(CC) $(COMPILE_FLAGS) -c tests/lisp_tests.c -o obj/lisp_tests.rel
	$(CC) $(COMPILE_FLAGS) -c tests/atom_tests.c -o obj/atom_tests.rel

link:
	$(CC) -o bin/zlisp.ihx $(LINK_FLAGS) $(REL_FILES)

link_tests:
	$(CC) -o bin/zlisp.ihx $(LINK_FLAGS) $(TEST_REL_FILES)

rom:
	utils/hex2bin -e rom bin/zlisp.ihx

checksize:
	./utils/check16k.sh

emulate:
	wine ./wincpc/WinCPC.exe
