MOVE = mv
DIR_INC = ./include
DIR_OBJ = ./obj
DIR_BIN = ./bin
CC = gcc
CFLAGS = -g -Wall -I${DIR_INC}

TARGET = main
BIN_TARGET = ${DIR_BIN}/${TARGET}



DIRS_Spk   += src
#DIRS_Spk   += src/part1
DIRS_Spk   += src/part2
DIRS_Spk   += src/sort
DIRS_Spk   += src/time


DIR_FILES  = $(foreach dir, $(DIRS_Spk),$(wildcard $(dir)/*.c))
DIR_OBJS   = $(patsubst %.c,%.o,$(DIR_FILES))


$(ALL):$(TARGET)

$(TARGET):$(DIR_OBJS)
	$(CC) -o $(TARGET) $(DIR_OBJS) $(CFLAGES) #-pthread
	-$(MOVE) $(DIR_OBJS) ./$(DIR_OBJ)
	
.PHONY:clean
clean:
#	find ${DIR_OBJ} -name *.o | xargs rm -rf {}
	find ./ -name *.o | xargs rm -rf {}
#rm -rf ${DIR_BIN}/${TARGET}
	rm -rf ${TARGET}
