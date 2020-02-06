#!/bin/bash
g++ Main.cpp Jogo.cpp TextureManager.cpp Map.cpp EntityComponentSystem/EntityComponentSystem.cpp Vector2D.cpp GameObject.cpp  -I/usr/include/SDL2 -lSDL2main -lSDL2 -lSDL2_image
