#pragma once
#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <SDL_mixer.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"

#include "Util.h"
#include "Entity.h"
#include "Map.h"
#include "Effects.h"

struct GameState {
    Map *map;
    Map *floor_and_details;
    Entity *player;
    Entity *enemies;
    Entity *background;
    Entity *key;
    int nextScene;
};

class Scene {
public:
    GameState state;
    Mix_Chunk *win = Mix_LoadWAV("win.wav");
    Mix_Chunk *lose = Mix_LoadWAV("lose.wav");
    GLuint fontID = Util::LoadTexture("pixel_font.png");
    virtual void Initialize(int lives) = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render(ShaderProgram *program) = 0;
};
