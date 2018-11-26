lechemin.out: balle.o lechemin.o affichage.o generer_board.o crea_balle.o crea_porte.o
	g++ -o lechemin.out balle.o lechemin.o affichage.o generer_board.o crea_balle.o crea_porte.o

balle.o: fonctions.h
	g++ -c balle.cpp

lechemin.o: lechemin.cpp fonctions.h 
	g++ -c lechemin.cpp

affichage.o: fonctions.h
	g++ -c affichage.cpp

crea_porte.o: fonctions.h
	g++ -c crea_porte.cpp

crea_balle.o: fonctions.h
	g++ -c crea_balle.cpp

generer_board.o: fonctions.h
	g++ -c generer_board.cpp

	
