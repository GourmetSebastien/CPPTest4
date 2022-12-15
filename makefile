.SILENT:
	
CLASSES=Classes/
OBJS=$(CLASSES)Personne.o $(CLASSES)Intervenant.o $(CLASSES)Client.o $(CLASSES)Employe.o
CO=g++ -I $(CLASSES) -D DEBUG
PROGRAMS=Test4


Test4:	Test4.cpp Personne.o Intervenant.o Client.o Employe.o
	$(CO) Test4.cpp $(OBJS) -o Test4
	echo "Creation de Test4"

Personne.o:	$(CLASSES)Personne.h $(CLASSES)Personne.cpp
	$(CO) $(CLASSES)Personne.cpp -c -o $(CLASSES)Personne.o
	echo "Creation de Personne.o"

Intervenant.o:	$(CLASSES)Intervenant.h $(CLASSES)Intervenant.cpp
	$(CO) $(CLASSES)Intervenant.cpp -c -o $(CLASSES)Intervenant.o
	echo "Creation de Intervenant.o"

Client.o:	$(CLASSES)Client.h $(CLASSES)Client.cpp
	$(CO) $(CLASSES)Client.cpp -c -o $(CLASSES)Client.o
	echo "Creation de Client.o"

Employe.o:	$(CLASSES)Employe.h $(CLASSES)Employe.cpp
	$(CO) $(CLASSES)Employe.cpp -c -o $(CLASSES)Employe.o
	echo "Creation de Employe.o"

clean:	
	rm $(CLASSES)*.o

clobber:
	clean
	rm -f $(PROGRAMS)
