CC = sdcc
LINK_FLAGS = --no-std-crt0 -mz80 --opt-code-size --code-loc 0xC100 --data-loc 0x1000
COMPILE_FLAGS = --no-std-crt0 -mz80 --opt-code-size --code-loc 0xC100 --data-loc 0x1000 --Werror
# TODO: add obj/lisp.rel
REL_FILES = obj/crt0.rel obj/amsgraph.rel obj/amstext.rel obj/main.rel
TEST_REL_FILES = $(REL_FILES) obj/lisp_tests.rel

all: clean assemble_libs_release compile_release link rom checksize
tests: clean assemble_libs_tests compile_tests link_tests rom

clean:
	rm -rf bin
	rm -rf obj
	mkdir -p bin
	mkdir -p obj

assemble_libs_release:
	sdasz80 -o ./obj/crt0.rel src/crt0.s
	sdasz80 -o ./obj/amsgraph.rel src/amsgraph.s
	sdasz80 -o ./obj/amstext.rel src/amstext.s

assemble_libs_tests:
	sdasz80 -o ./obj/crt0.rel src/crt0_test.s
	sdasz80 -o ./obj/amsgraph.rel src/amsgraph.s
	sdasz80 -o ./obj/amstext.rel src/amstext.s

compile_release:
	$(CC) $(COMPILE_FLAGS) -c src/main.c -o obj/main.rel
	# $(CC) $(COMPILE_FLAGS) -c src/lisp.c -o obj/lisp.rel

compile_tests:
	$(CC) $(COMPILE_FLAGS) -c tests/main.c -o obj/main.rel
	# $(CC) $(COMPILE_FLAGS) -c src/lisp.c -o obj/lisp.rel
	$(CC) $(COMPILE_FLAGS) -c tests/lisp_tests.c -o obj/lisp_tests.rel

link:
	$(CC) -o bin/zlisp.ihx $(LINK_FLAGS) $(REL_FILES)

link_tests:
	$(CC) -o bin/zlisp.ihx $(LINK_FLAGS) $(TEST_REL_FILES)

rom:
	utils/hex2bin -e rom bin/zlisp.ihx

checksize:
	utils/check64k.sh
