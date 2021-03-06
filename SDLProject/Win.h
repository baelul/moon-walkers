#include "Scene.h"

class Win : public Scene {
    
public:
    void Initialize(int lives) override;
    void Update(float deltaTime) override;
    void Render(ShaderProgram *program) override;
};
