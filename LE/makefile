leveleditor: ../PE/output.o ../PE/sprite.o ../PE/entity.o ../PE/entityhandler.o ../PE/statemachine.o ../PE/collision.o ../PE/level.o ../PE/vector2d.o
	g++ ../PE/output.o ../PE/sprite.o ../PE/entity.o ../PE/entityhandler.o ../PE/statemachine.o ../PE/collision.o ../PE/level.o ../PE/vector2d.o main.cpp input.cpp output.cpp entityselector.cpp grid.cpp -o leveleditor -lmingw32 -lSDL2main -lSDL2

subsystem:
	$(MAKE) -C ../PE

clean:
	del *.o
	cd ../PE && $(MAKE) clean