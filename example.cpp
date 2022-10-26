#include "raylib.h"

int main(){

    const int windowWidth{500};
    const int windowHeight{500};
    
    InitWindow(windowWidth, windowHeight,"Game Window");
    int velocity{10};
    const int gravity{1};

    bool IsJumping = false;

    

    // Locate and load the texture file in the resources folder
    Texture2D scarfy =  LoadTexture("resources/scarfy.png");
    // Rectangle that will contain the texture sprite
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0; 
    // Vector2 is the position of the line on X and Y axis
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height;



    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        
        DrawTextureRec(scarfy,scarfyRec,scarfyPos,WHITE);

        // if posY is greater or equal to 420
        if (scarfyPos.y >= windowHeight - scarfyRec.height){
            // slow velocity
            velocity = 0;
            IsJumping = false;

        } else {
            velocity += gravity;
            IsJumping = 1;
        }

        // velocity = 0; if space is pressed, velocity = -10, making object jump.  and if IsJumping is not true, allow velocity(object) jump by -10
        if(IsKeyPressed(KEY_SPACE) && !IsJumping){
            // Move object up by 10
            velocity -= 20;
             
        }
        
        scarfyPos.y += velocity;

        // Colour background of window
        ClearBackground(WHITE);
        EndDrawing();
    }
    CloseWindow();


}
















