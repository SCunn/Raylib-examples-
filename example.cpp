#include "raylib.h"



int main(){

    const int windowWidth{500};
    const int windowHeight{500};
    
    InitWindow(windowWidth, windowHeight,"Game Window");
    int velocity{10};
    // set to 1000 for delta time, change gravity to pixels per second
    const int gravity{1000};
    // integer to move sprite
    int speed{250};
    // obstacle Velocity
    int obVel{-100};
    // change jumpHeight to pixels per second
    int jumpHeight{500};
    bool IsJumping = false;
 
    // data for animation goes here
    int frame{};
    // Update the animation speed, takes 1 second then divides it by 12
    const float updateTime{1.0/12};
    // float to contain the running time data
    float runningTime{};
    

    // Locate and load the texture file in the resources folder
    Texture2D scarfy =  LoadTexture("resources/scarfy.png");
    Texture2D obstacle = LoadTexture("resources/Raylib_logo.png");
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

    //  Variables for obstacle
    Rectangle obRec;
    obRec.width = obstacle.width;
    obRec.height = obstacle.height; 
    obRec.x = 0;
    obRec.y = 0;
    Vector2 obPos; 
    obPos.x = windowWidth- obRec.width;
    obPos.y = windowHeight - obRec.height;



    SetTargetFPS(60);
    while(!WindowShouldClose()){
        // Get time in seconds for the last frame drawn (delta time)
        const float deltaTime{GetFrameTime()};
        BeginDrawing();

            //     runningTime += deltaTime; 

            //  if(runningTime >= updateTime){
            //     runningTime = 0.0;
            //     // Create sprite animation, character rectangle on x axis is equal to frame integer multiplied rec width
            //     scarfyRec.x = frame* scarfyRec.width;
            //     // Increment frame by 1, cycle through .png frames
            //     frame++;
            //     // if the frame count gets greater than 6
            //  if (frame > 5){
            //     // set frame count back to zero in order to restart cycle through .png frames
            //     frame = 0;
            //  }
	        // }
        
        DrawTextureRec(scarfy,scarfyRec,scarfyPos,WHITE);

        DrawTextureRec(obstacle, obRec, obPos, WHITE);


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

        if(IsKeyDown(KEY_D) && !IsJumping){
            scarfyPos.x = scarfyPos.x += speed*deltaTime;
            scarfyRec.width = scarfy.width/6;
            
            
            runningTime += deltaTime; 

             if(runningTime >= updateTime){
                runningTime = 0.0;
                // Create sprite animation, character rectangle on x axis is equal to frame integer multiplied rec width
                scarfyRec.x = frame* scarfyRec.width;
                // Increment frame by 1, cycle through .png frames
                frame++;
                // if the frame count gets greater than 6
             if (frame > 5){
                // set frame count back to zero in order to restart cycle through .png frames
                frame = 0;
             }
	        }
        }
        // When D key is released and sprite is not jumping
        if(IsKeyReleased(KEY_D) && !IsJumping){
            // reset frame back to zero, revert sprite to first frame
            frame = 0;
            scarfyRec.x = frame * scarfyRec.width;
        }

        if(IsKeyDown(KEY_A) && !IsJumping){
            scarfyPos.x -= speed*deltaTime;
            scarfyRec.width = -scarfy.width/6;
            
            
            runningTime += deltaTime; 

             if(runningTime >= updateTime){
                runningTime = 0.0;
                // Create sprite animation, character rectangle on x axis is equal to frame integer multiplied rec width
                scarfyRec.x = frame* scarfyRec.width;
                // Increment frame by 1, cycle through .png frames
                frame++;
                // if the frame count gets greater than 6
             if (frame > 5){
                // set frame count back to zero in order to restart cycle through .png frames
                frame = 0;
             }
	        }
        }

                // When A key is released and sprite is not jumping
        if(IsKeyReleased(KEY_A) && !IsJumping){
            // reset frame back to zero, revert sprite to first frame
            frame = 0;
            scarfyRec.x = frame * scarfyRec.width;
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
    UnloadTexture(scarfy);
    UnloadTexture(obstacle);
    CloseWindow();


}



















