/*main.c Brett Wagner 4/10/19
 * This program creates a binary clock on the sense hat.*/

#include "framebuffer.h"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void theSec(int sec, pi_framebuffer_t* fb)
{
	if (sec>=32)
	{
		fb->bitmap->pixel[5][2] = getColor(255,0,0);
		sec-=32;
	}
	if (sec>=16)
	{
		fb->bitmap->pixel[5][3] = getColor(255,0,0);
		sec-=16;
	}
	if (sec>=8)
	{
		fb->bitmap->pixel[5][4] = getColor(255,0,0);
		sec-=8;
	}
	if (sec>=4)
	{
		fb->bitmap->pixel[5][5] = getColor(255,0,0);
		sec-=4;
	}
	if (sec>=2)
	{
		fb->bitmap->pixel[5][6] = getColor(255,0,0);
		sec-=2;
	}
	if (sec==1)
	{
		fb->bitmap->pixel[5][7] = getColor(255,0,0);
	}
}

int running = 1;

void end(int sig)
{
	running = 0;
}


int main()
{
	pi_framebuffer_t* fb = getFBDevice();
	clearBitmap(fb->bitmap, getColor(0,0,0));
	signal(SIGINT, end);
	while(running)
	{
		clearBitmap(fb->bitmap, getColor(0,0,0));
		time_t seconds;
		time(&seconds);
		struct tm* local = localtime(&seconds);
		int sec = local->tm_sec;
		int min = local->tm_min;
		int hour = local->tm_hour;
		if (hour>=16)
		{
			fb->bitmap->pixel[1][3] = getColor(0,0,255);
			hour-=16;
		}
		if (hour>=8)
		{
			fb->bitmap->pixel[1][4] = getColor(0,0,255);
			hour-=8;
		}
		if (hour>=4)
		{
			fb->bitmap->pixel[1][5] = getColor(0,0,255);
			hour-=4;
		}
		if (hour>=2)
		{
			fb->bitmap->pixel[1][6] = getColor(0,0,255);
			hour-=2;
		}
		if (hour==1)
		{
			fb->bitmap->pixel[1][7] = getColor(0,0,255);
			hour-=1;
		}
		if (min>=32)
		{
			fb->bitmap->pixel[3][2] = getColor(0,255,0);
			min-=32;
		}
		if (min>=16)
		{
			fb->bitmap->pixel[3][3] = getColor(0,255,0);
			min-=16;
		}
		if(min>=8)
		{
			fb->bitmap->pixel[3][4] = getColor(0,255,0);
			min-=8;
		}
		if (min>=4)
		{
			fb->bitmap->pixel[3][5] = getColor(0,255,0);
			min-=4;
		}
		if (min>=2)
		{
			fb->bitmap->pixel[3][6] = getColor(0,255,0);
			min-=2;
		}
		if(min==1)			
		{
			fb->bitmap->pixel[3][7] = getColor(0,255,0);
			min-=1;
		}
		theSec(sec, fb);
		sleep(1);
	}
	clearBitmap(fb->bitmap, getColor(0,0,0));
	freeFrameBuffer(fb);
	return 0;
}
