#include "raylib.h"

// structs are used to group related variables to one place, struct Anim hold variables related to the animation logic
struct Anim {
    Rectangle rec;
    // Vector2 is the position of the line on X and Y axis
    Vector2 pos;
    int frame;
    float updateTime;
    float runningTime;
};

int main(){

    const int windowWidth{700};
    const int windowHeight{450};
    
    InitWindow(windowWidth, windowHeight,"Game Window");
    
        // Locate and load the texture file in the resources folder
    Texture2D scarfy =  LoadTexture("resources/scarfy.png");
    Texture2D obstacle = LoadTexture("resources/Raylib_logo.png");

    Anim scarfyAnim;
    scarfyAnim.rec.width = scarfy.width/6; 
    scarfyAnim.rec.height = scarfy.height;
    scarfyAnim.rec.x = 0;
    scarfyAnim.rec.y = 0;
    scarfyAnim.pos.x = windowWidth/2 -scarfyAnim.rec.width/2;
    scarfyAnim.pos.y = windowHeight - scarfyAnim.rec.height;
    scarfyAnim.frame = 0;
    scarfyAnim.updateTime = 1.0/12.0;
    scarfyAnim.runningTime = 0.0;
    
    //  Variables for obstacle
    Rectangle obRec;
    obRec.width = obstacle.width;
    obRec.height = obstacle.height; 
    obRec.x = 0;
    obRec.y = 0;
    Vector2 obPos; 
    obPos.x = windowWidth- obRec.width;
    obPos.y = windowHeight - obRec.height;


    // obstacle Velocity
    int obVel{-300};

    int velocity{10};
    
    const int gravity{1000};
    // integer to move sprite
    int speed{250};
    // change jumpHeight to pixels per second
    int jumpHeight{500};
    bool IsJumping = false;
    bool collision{};

    const char* winnerText = nullptr;
 
    // data for animation goes here // frame is in struct Anim
    // int frame{};

    // Update the animation speed, takes 1 second then divides it by 12
    const float updateTime{1.0/12};
    // float to contain the running time data
    float runningTime{};
    




    SetTargetFPS(60);
    while(!WindowShouldClose()){
        // Get time in seconds for the last frame drawn (delta time)
        const float deltaTime{GetFrameTime()};

        Rectangle obstacleRec{
		    obPos.x,
		    obPos.y,
		    obRec.height,
		    obRec.width,
	    };
	    Rectangle scarfyRec{
	        scarfyAnim.pos.x,
	        scarfyAnim.pos.y,
	        scarfyAnim.rec.height,
	        scarfyAnim.rec.width	
	    };

	    if(CheckCollisionRecs(scarfyRec,obstacleRec)){
	    	collision = true;
	    }

        BeginDrawing();

            //     runningTime += deltaTime; 

            //  if(runningTime >= updateTime){
            //     runningTime = 0.0;
            //     // Create sprite animation, character rectangle on x axis is equal to frame integer multiplied rec width
            //     scarfyAnim.x = frame* scarfyAnim.width;
            //     // Increment frame by 1, cycle through .png frames
            //     frame++;
            //     // if the frame count gets greater than 6
            //  if (frame > 5){
            //     // set frame count back to zero in order to restart cycle through .png frames
            //     frame = 0;
            //  }
	        // }
        



        // if scarfyPosY is greater or equal to 420
        if (scarfyAnim.pos.y >= windowHeight - scarfy.height){
            // slow velocity
            velocity = 0;
            IsJumping = false;

        } else {
            // multiply gravity & velocity by delta time
            velocity += gravity * deltaTime;
            IsJumping = 1;
        }

        if(IsKeyDown(KEY_D) && !IsJumping){
            scarfyAnim.pos.x += speed*deltaTime;
            scarfyAnim.rec.width = scarfy.width/6;
            
            
            scarfyAnim.runningTime += deltaTime; 

             if(scarfyAnim.runningTime >= scarfyAnim.updateTime){
                scarfyAnim.runningTime = 0.0;
                // Create sprite animation, character rectangle on x axis is equal to frame integer multiplied rec width
                scarfyAnim.rec.x = scarfyAnim.frame* scarfyAnim.rec.width;
                // Increment frame by 1, cycle through .png frames
                scarfyAnim.frame++;
                // if the frame count gets greater than 6
             if (scarfyAnim.frame > 5){
                // set frame count back to zero in order to restart cycle through .png frames
                scarfyAnim.frame = 0;
             }
	        }
        }
        // When D key is released and sprite is not jumping
        if(IsKeyReleased(KEY_D) && !IsJumping){
            // reset frame back to zero, revert sprite to first frame
            scarfyAnim.frame = 0;
            scarfyAnim.rec.x = scarfyAnim.frame * scarfyAnim.rec.width;
        }

        if(IsKeyDown(KEY_A) && !IsJumping){
	        scarfyAnim.pos.x -= speed*deltaTime;
	        scarfyAnim.rec.width = -scarfy.width/6;
            
            
            scarfyAnim.runningTime += deltaTime;

             if(scarfyAnim.runningTime >= scarfyAnim.updateTime){
                scarfyAnim.runningTime = 0.0;
                // Create sprite animation, character rectangle on x axis is equal to frame integer multiplied rec width
                scarfyAnim.rec.x = scarfyAnim.frame* scarfyAnim.rec.width;
                // Increment frame by 1, cycle through .png frames
                scarfyAnim.frame++;
                // if the frame count gets greater than 6
             if (scarfyAnim.frame > 5){
                // set frame count back to zero in order to restart cycle through .png frames
                scarfyAnim.frame = 0;
             }
	        }
        }

                // When A key is released and sprite is not jumping
        if(IsKeyReleased(KEY_A) && !IsJumping){
            // reset frame back to zero, revert sprite to first frame
            scarfyAnim.frame = 0;
            scarfyAnim.rec.x = scarfyAnim.frame * scarfyAnim.rec.width;
        }

        // velocity = 0; if space is pressed, velocity = -10, making object jump.  and if IsJumping is not true, allow velocity(object) jump by -10
        if(IsKeyPressed(KEY_SPACE) && !IsJumping){
            // Move object up by 10
            velocity -= jumpHeight;
             
        }
        // multiply velocity by delta time
        scarfyAnim.pos.y += velocity * deltaTime;
        // add velocity to obstacle
        obPos.x += obVel * deltaTime;

        // Colour background of window
        ClearBackground(WHITE);

        if(collision){
            ClearBackground(RED);
        } else {

            DrawTextureRec(scarfy,scarfyAnim.rec,scarfyAnim.pos,WHITE);
            DrawTextureRec(obstacle, obRec, obPos, WHITE);
        }


        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(obstacle);
    CloseWindow();


}



















