ProtoEngine: PE/output.o PE/sprite.o PE/entity.o PE/entityhandler.o PE/statemachine.o PE/grid.o PE/collision.o PE/level.o PE/vector2d.o
	g++ PE/output.o PE/sprite.o PE/entity.o PE/entityhandler.o PE/statemachine.o PE/grid.o PE/collision.o PE/level.o PE/vector2d.o game_main.cpp game_input.cpp game_entity.cpp game_statemachine.cpp -o game -lmingw32 -lSDL2main -lSDL2

subsystem:
	$(MAKE) -C PE

clean:
	del *.o
	cd PE && $(MAKE) clean