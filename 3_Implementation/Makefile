
PROJ_NAME = contact_management

SRC = src/list_all_contact.c\
src/add_new_cont.c\
src/search_cont.c\
src/edit_cont.c\
src/del_cont.c

TEST = test.c\
unity/unity.c

BUILD_DIR = Build

INC = -Iinc\
-Iunity

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY : all test coverage run clean doc

all:
	gcc main.c $(SRC) $(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC))

run: all
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

test: $(SRC) $(TEST)
	gcc $^ $(INC) -o $(call FixPath,test.$(EXEC))
	./test.$(EXEC)

coverage:
	gcc -fprofile-arcs -ftest-coverage $(SRC) $(TEST) $(INC) -o $(call FixPath,test.$(EXEC))
	./test.$(EXEC)
	gcov -a test.c

cppcheck:
	cppcheck --enable=all $(SRC) main.c

valgrind:
	valgrind ./test.out


clean:
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
