CC = gcc
MOVE = mv


DIR_INC = ./include
DIR_OBJ = ./obj


DIR_LIB_CUNIT = /usr/local/lib
DIR_INC_CUNIT = /usr/local/include/CUnit


CFLAGS = -g -Wall -I$(DIR_INC) -I$(DIR_INC_CUNIT)
LDFLAGS = -L$(DIR_LIB_CUNIT) 
LIBS = -lcunit


TARGET = main


DIRS_SRC   += src
#DIRS_SRC   += src/part1
#DIRS_SRC   += src/part2
DIRS_SRC   += src/part3
DIRS_SRC   += src/part3_ex
DIRS_SRC   += src/sort
DIRS_SRC   += src/time
DIRS_SRC   += src/cunit_test


DIR_FILES  = $(foreach dir, $(DIRS_SRC),$(wildcard $(dir)/*.c))
DIR_OBJS   = $(patsubst %.c,%.o,$(DIR_FILES))


$(ALL):$(TARGET)

$(TARGET):$(DIR_OBJS)
	$(CC) -o $(TARGET) $(DIR_OBJS) $(CFLAGS) $(LDFLAGS) $(LIBS)
	-$(MOVE) $(DIR_OBJS) ./$(DIR_OBJ)
	

.PHONY:clean
clean:
	find ${DIR_OBJ} -name *.o | xargs rm -rf {}
	rm -rf ${TARGET}
