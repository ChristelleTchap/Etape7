.SILENT:
objets := ./objets/
classe:= ./Classes/
OBJ := $(objets)ImageB.o $(objets)ImageRGB.o $(objets)ImageNG.o $(objets)Dimension.o $(objets)Image.o $(objets)MyQT.o $(objets)Couleur.o $(objets)Exception.o $(objets)RGBException.o $(objets)XYException.o $(objets)ArrayList.o $(objets)Iterateur.o


all: Test7.cpp $(OBJ)
	echo --- Création de Test7 ---
	g++ Test7.cpp -o Test7 $(OBJ) -I $(classe) -I MyQT -lSDL -lpthread -Wl,-O1 -pipe -O2 -std=gnu++11  -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so

$(objets)ImageNG.o:  Classes/ImageNG.cpp Classes/ImageNG.h 
	echo --- Création de ImageNG.o ---
	g++ Classes/ImageNG.cpp -c -I  $(classe)
	mv ImageNG.o $(objets)

$(objets)ImageB.o:	 Classes/ImageB.cpp Classes/ImageB.h 
	echo --- Création de ImageB.o ---
	g++ Classes/ImageB.cpp -c -I  $(classe) 
	mv ImageB.o $(objets)

$(objets)ImageRGB.o: Classes/ImageRGB.cpp Classes/ImageRGB.h $(objets)Image.o
	echo --- Création de ImageRGB.o ---
	g++ Classes/ImageRGB.cpp -c -I  MyQT -I$(classe)
	mv ImageRGB.o $(objets)

$(objets)Dimension.o: Classes/Dimension.cpp Classes/Dimension.h
	g++ Classes/Dimension.cpp -c -I  $(classe) -o $(objets)/Dimension.o

$(objets)MyQT.o: Classes/MyQT.cpp Classes/MyQT.h
	echo --- Création de MyQT.o ---
	g++ -c Classes/MyQT.cpp -I  $(classe) -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -I$(objets)
	mv MyQT.o $(objets)

$(objets)Image.o: Classes/Image.cpp Classes/Image.h 
	echo --- Création de Image.o ---
	g++ Classes/Image.cpp -c -I  $(classe)
	mv Image.o $(objets)

$(objets)Couleur.o: Classes/Couleur.cpp Classes/Couleur.h 
	echo --- Création de Couleur.o ---
	g++ Classes/Couleur.cpp -c -I  $(classe)
	mv Couleur.o $(objets)

$(objets)Exception.o:	Classes/Exception.cpp Classes/Exception.h 
	echo --- Création de Exception.o ---
	g++ Classes/Exception.cpp -c -o $(objets)Exception.o  -I$(classe)
	

$(objets)RGBException.o:	Classes/RGBException.cpp Classes/RGBException.h 
	echo --- Création de RGBException.o ---
	g++ Classes/RGBException.cpp -c -I  $(classe)
	mv RGBException.o $(objets)


$(objets)XYException.o:	Classes/XYException.cpp Classes/XYException.h 
	echo --- Création de XYException.o ---
	g++ Classes/XYException.cpp -c -I  $(classe)
	mv XYException.o $(objets)

$(objets)ArrayList.o:Classes/ArrayList.cpp Classes/ArrayList.h 
	echo --- Création de ArrayList.o ---
	g++ Classes/ArrayList.cpp -c -I  $(classe)
	mv ArrayList.o $(objets)

$(objets)Iterateur.o:Classes/Iterateur.cpp Classes/Iterateur.h
	echo --- Création de Iterateur.o ---
	g++ Classes/Iterateur.cpp -c -I  $(classe)
	mv Iterateur.o $(objets)


clean:
	rm $(objets)*.o core -f

clobber: clean
	rm Test6 -f
