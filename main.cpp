#include "TXLib.h"

struct Mario
{
     int x;
     int y;
     HDC image;
     HDC image_run;
     HDC image_jump;

     void draw()
     {
        txTransparentBlt(txDC(), x, y, 160, 200, image, 0, 0, TX_WHITE);
     }
};

int main()
{
txCreateWindow (800, 600);
txTextCursor (false);

Mario mario = {100, 250, txLoadImage("mario_run.bmp"), txLoadImage("mario_run.bmp"), txLoadImage("mario_jump.bmp")};

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
         txClear();
         txBegin();

         mario.draw();
         mario.image = mario.image_run;

         if(GetAsyncKeyState(VK_RIGHT)) mario.x += 5;
         if(GetAsyncKeyState(VK_LEFT))  mario.x -= 5;

         if(GetAsyncKeyState(VK_SPACE))   //прыжок
         {
            /*
            while(GetAsyncKeyState(VK_SPACE))
            {
                txSleep(5);
            }
            */
            mario.image = mario.image_jump;
            mario.y -= 20;
         }

         mario.y += 5;  //гравитация

         if(mario.y > 350) mario.y = 350;


         txEnd();
         txSleep(10);
    }

txDisableAutoPause();
return 0;
}

