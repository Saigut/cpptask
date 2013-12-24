objects = main.o class.o

main : $(objects)
	g++ -o main $(objects)

$(objects) : head.h

.PHONY : clean
clean :
	-rm main StuDB.dat $(objects)

