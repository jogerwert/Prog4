
#Variablen
ZU_LOESCHENDE_DATEIEN = *.o *.exe *~ *stackdump
COMPILER_NAME = g++
COMPILER_FLAGS = -O -Wall -pedantic -g -std=c++17
LINKER_NAME = g++
LINKER_FLAGS =
OBJECT_DATEINAMEN = ueb02.o utilities.o

#Ziele und Quellen fuer das Hauptprogramm
all: ueb02

ueb02: $(OBJECT_DATEINAMEN)

ueb02.o: ueb02.cpp

utilities.o: utilities.cpp utilities.h

#Regel, um aus .cpp Dateien eine .o Datei zu machen
%.o: %.cpp
	$(COMPILER_NAME) $(COMPILER_FLAGS) -c $<

#Regel, um aus .o Dateien eine ausfuehrbare Datei zu machen
%: %.o
	$(LINKER_NAME) $(LINKER_FLAGS) -o $@ $^

#Ziel clean, ohne Quellen. Dient dem entfernen von Dateien, um danach einen Rebuild machen zu koennen.
clean:
	@echo "Diese Dateien werden alle von make clean geloescht:"
	@echo $(ZU_LOESCHENDE_DATEIEN) 
	rm -f $(ZU_LOESCHENDE_DATEIEN)
