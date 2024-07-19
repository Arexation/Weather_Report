CC = gcc
CFLAGS = -g -ansi -pedantic -Wall
OBJS = main.o temp.o wind.o gust.o

weather_report: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.c temp.h wind.h gust.h
	$(CC) $(CFLAGS) -c main.c

temp.o: temp.c temp.h
	$(CC) $(CFLAGS) -c temp.c

wind.o: wind.c wind.h
	$(CC) $(CFLAGS) -c wind.c

gust.o: gust.c gust.h
	$(CC) $(CFLAGS) -c gust.c

clean:
	rm -f *.o weather_report