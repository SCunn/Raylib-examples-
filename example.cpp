#include "raylib.h"

int main(){

    const int windowWidth{500};
    const int windowHeight{500};
    
    InitWindow(windowWidth, windowHeight,"Game Window");
    int velocity{10};
    // set to 1000 for delta time, change gravity to pixels per second
    const int gravity{1000};
    // change jumpHeight to pixels per second
    int jumpHeight{500};
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
        // Get time in seconds for the last frame drawn (delta time)
        const float deltaTime{GetFrameTime()};
        BeginDrawing();
        
        DrawTextureRec(scarfy,scarfyRec,scarfyPos,WHITE);

        // if scarfyPosY is greater or equal to 420
        if (scarfyPos.y >= windowHeight - scarfyRec.height){
            // slow velocity
            velocity = 0;
            IsJumping = false;

        } else {
            // multiply gravity & velocity by delta time
            velocity += gravity * deltaTime;
            IsJumping = 1;
        }

        // velocity = 0; if space is pressed, velocity = -10, making object jump.  and if IsJumping is not true, allow velocity(object) jump by -10
        if(IsKeyPressed(KEY_SPACE) && !IsJumping){
            // Move object up by 10
            velocity -= jumpHeight;
             
        }
        // multiply velocity by delta time
        scarfyPos.y += velocity * deltaTime;

        // Colour background of window
        ClearBackground(WHITE);
        EndDrawing();
    }
    CloseWindow();


}
















