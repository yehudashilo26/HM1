CC=gcc
AR=ar
CFLAGS= -Wall -g
PROG = mains maindloop maindrec loops recursives recursived
#-------------------------MAIN---------------------------------#
all: $(PROG)
#-------------------------MAIN-----------REC------------a------#
mains: main.o libclassrec.a
	$(CC) $(CFLAGS) -o mains main.o libclassrec.a -lm
#-------------------------MAIN-----------LOOP-----------so-----#
maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) -o maindloop main.o ./libclassloops.so -lm
#-------------------------MAIN-----------REC------------so-----#
maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) -o maindrec main.o ./libclassrec.so -lm
#-------------------------LIB------------LOOP-----------a------#
loops: libclassloops.a
libclassloops.a: advancedClassificationLoop.o basicClassification.o
	$(AR) -rcs libclassloops.a advancedClassificationLoop.o basicClassification.o
#-------------------------LIB------------REC------------a------#
recursives:libclassrec.a
libclassrec.a: advancedClassificationRecursion.o basicClassification.o
	$(AR) -rcs libclassrec.a advancedClassificationRecursion.o basicClassification.o
#-------------------------LIB------------REC------------so-----#
recursived: libclassrec.so
libclassrec.so: advancedClassificationRecursion.o basicClassification.o
	$(CC) -shared -o libclassrec.so advancedClassificationRecursion.o basicClassification.o
#-------------------------LIB------------LOOP-----------so-----#
loopd: libclassloops.so
libclassloops.so: advancedClassificationLoop.o basicClassification.o
	$(CC) -shared -o libclassloops.so advancedClassificationLoop.o basicClassification.o
#-------------------------func---------------------------------#
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -fpic -c advancedClassificationRecursion.c
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -fpic -c advancedClassificationLoop.c
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c basicClassification.c
main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -fpic -c main.c
#-------------------------------------------------------------#
.PHONY: clean all
clean:
	rm -f *.o *so *a $(PROG)
