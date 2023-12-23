all: compileL

compileL:
	g++ -c main.cpp Menu.cpp Game.cpp Player.cpp Enemy.cpp Bullet.cpp EnemyEntity.hpp Enemy2.cpp -I"/opt/homebrew/Cellar/sfml/2.5.1_2/include"
	g++ main.o Menu.o Game.o Player.o Enemy.o Bullet.o Enemy2.o -o main -L"/opt/homebrew/Cellar/sfml/2.5.1_2/lib" -lsfml-graphics -lsfml-window -lsfml-system
	./main
clean:
	rm -f main *.o *.gch

compileM:
	g++ -c main.cpp Menu.cpp Game.cpp Player.cpp Enemy.cpp Bullet.cpp EnemyEntity.hpp Enemy2.cpp -I"\Users\Matthew\Desktop\University\First Year\Semester 2\Object Oriented Programming/include" 
	g++ main.o Menu.o Game.o Player.o Enemy.o Bullet.o Enemy2.o -o main -L"\Users\Matthew\Desktop\University\First Year\Semester 2\Object Oriented Programming/lib" -lsfml-graphics -lsfml-window -lsfml-system
	./main

