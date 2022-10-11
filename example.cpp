#include "raylib.h"
// #include <cstdio>
// #define LIGHTGRAY (Color){ 200, 200, 200, 255 }

// init main printf
// int main(){
//     printf("hello world");
// }


// Draw Window
int main(){
    int WindowSize{250};
    char WindowName[] = "Game Window";
    InitWindow(WindowSize,WindowSize,WindowName);
    while(WindowShouldClose() == 0){
        BeginDrawing();
        ClearBackground(BLUE);
        EndDrawing();
    }
}

// Char example
// int main(){
//     int WindowSize{250};
//     char WindowName1 = 'G';
//     InitWindow(WindowSize,WindowSize,WindowName1);
//     while(WindowShouldClose() == 0){
//         BeginDrawing();
//         ClearBackground(BLUE);
//         EndDrawing();
//     }
// }


// int main(){
//     // int width;
//     // width = 350;
//     // int height;
//     // height = 500;
//     int circle_posX = 250;
//     int circle_posY = 250;
//     // int WindowSizeArray[3]{250,150,50};
//     // char WindowName[1]{WindowSizeArray, "Shane's Window"};
//     InitWindow(500, 500, "Shane's Window");
//     SetTargetFPS(60);
//     while(WindowShouldClose() == false)
//     {
//         BeginDrawing();
//         // DrawRectangle(75,75,20,20, RED);
//         DrawCircle(400,400,20,PURPLE);
//         // DrawText("Shanes Text", 40,250,55, LIGHTGRAY);      
//         ClearBackground(LIGHTGRAY);
//     if(IsKeyDown(KEY_D)){
//         circle_posX = circle_posX+10;
//     }
//         EndDrawing();
//     }
// }

// Draw Red Circle in bottom left of Game Window
// int main(){
//     int circleX = 10;
//     int circleY = 290;
//     int circleRadi = 10;
//     int WindowSizeArr[] = {250,300,375};
//     char WindowName[] = "Game Window";
//     InitWindow(WindowSizeArr[0],WindowSizeArr[1],WindowName);
//     while(WindowShouldClose() == 0){
//         BeginDrawing();
//         ClearBackground(LIGHTGRAY);
//         DrawCircle(circleX,circleY,circleRadi,RED);
//         EndDrawing();
//     }
// }

// Draw a green rectangle on top right corner
// int main(){ 
//     // window variables
//     int WindowSizeArr[] = {250,300,375};
//     char WindowName[] = "Game Window";
//     // circle variables
//     int circleX = 10;
//     int circleY = 290;
//     int circleRadi = 10;
//     // rectangle variables
//     int rect_X = 235;
//     int rect_Y = 0;
//     int rect_H = 15;
//     int rect_W = 15;
//     InitWindow(WindowSizeArr[0],WindowSizeArr[1],WindowName);
//     while(WindowShouldClose() == 0){
//         BeginDrawing();
//         ClearBackground(LIGHTGRAY);
//         DrawCircle(circleX,circleY,circleRadi,RED);
//         DrawRectangle(rect_X,rect_Y,rect_W,rect_H,GREEN);
//         EndDrawing();
//     }
// }

// Create text in the center of Game Window
// int main(){
//     int WindowSize[] = {250,300};
//     char WindowName[] = "Game Window";
//     int circle_posX = 10;
//     int circle_posY = 290;
//     int circle_radius = 10;
//     int rect_posX = 235;
//     int rect_posY = 0;
//     int rect_Width = 15;
//     int rect_Height = 15;
//     int txt_posX = 70;
//     int txt_posY = 120;
//     char winTxt[] = "I've made a circle\n and a rectangle";
//     int font_Size[] = {9,10,11,12,13,14,15};
//     InitWindow(WindowSize[0],WindowSize[1],WindowName);
//     while(WindowShouldClose() == 0){
//         BeginDrawing();
//         ClearBackground(BLUE);
//         DrawCircle(circle_posX, circle_posY, circle_radius, RED);
//         DrawRectangle(rect_posX, rect_posY, rect_Width, rect_Height, GREEN);
//         DrawText(winTxt,txt_posX,txt_posY,font_Size[3],LIGHTGRAY);
//         EndDrawing();
//     }
// }

// If Statement,move circle, bounce rectangle
// int main(){
//     int WindowSize[] = {500,500};
//     char WindowName[] = "Game Window";
//     int circle_posX = 250;
//     int circle_posY = 250;
//     int circle_radius = 10;
//     int rect_posX = 400;
//     int rect_posY = 400;
//     int rect_Width = 15;
//     int rect_Height = 15;
//     int direction = 10;
//     InitWindow(WindowSize[1],WindowSize[0],WindowName);
//     SetTargetFPS(60);
//     while(!WindowShouldClose()){
//         BeginDrawing();
//         ClearBackground(WHITE);
//         DrawCircle(circle_posX, circle_posY, circle_radius, RED);
//         DrawRectangle(rect_posX, rect_posY, rect_Width, rect_Height, GREEN);
//         // DrawText(winTxt,txt_posX,txt_posY,font_Size[3],LIGHTGRAY);
//         if(IsKeyDown(KEY_D)){
//             circle_posX = circle_posX+10;
//         }
//         if(IsKeyDown(KEY_A)){
//             circle_posX = circle_posX-10;
//         }
//         if(IsKeyDown(KEY_S)){
//             circle_posY = circle_posY+10;
//         }
//         if(IsKeyDown(KEY_W)){
//             circle_posY = circle_posY-10;
//         }
//         // rect_posY += direction;
//         rect_posY = rect_posY + direction;
//         if (rect_posY < 0 || rect_posY > 400){
//             direction *= -1;
//         }
//         EndDrawing();
//     }
// }
















