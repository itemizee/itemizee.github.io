/*


This program saves any type of file with one key press.
It can save jpg, png, gif, mp4, gifv, html5.. etc. 
(basically anything that falls under "Save image as..." or "Save video as...")
It is a custom solution that works for my PC which is running windows 10.
It may or may not work on other PC's and I highly doubt it works on anything other than windows.

It currently works with a key press of a decimal point, or the middle mouse button
It works by running through the commands you would do manually.
It does this by inputing key presses to navigate.
It will save by navigating the menu as if you have "right-clicked".
It only works if you do not touch anything after you have pressed the initial button.
It will save to the last saved location automatically.
You can set up this location by saving the first file manually to the desired location.

Because of the limitations of this program, 
I have determined it to not be very useful or practical.

But, it was a fun learning experience to learn how to code key and mouse input to the input buffer.
And be able to see this input working in action, and accomplishing a task.

















*/
#include <iostream>
#include <Windows.h>

using namespace std;

// The program seems to encounter problems based on sleepTime
// The faster I input actions, the more errors occur
// I guess because the previous action was not completely done

int main()
{
	int count = 0;
	int sleepTime = 100;
	int sleepTimeSlow = 500;
	WORD keyInput = VK_MBUTTON;
	WORD keyInput2 = VK_DECIMAL;

	INPUT inputRightClick;
	INPUT inputReturn;
	INPUT inputDown;

	WORD keyRightClick = VK_RBUTTON;
	WORD keyReturn = VK_RETURN;
	WORD keyDown = VK_DOWN;

	while(true)
	{

		if( GetAsyncKeyState(keyInput) || GetAsyncKeyState(keyInput2) )
		{

			// SETUP FOR BUTTONS **********************************************************************

			inputRightClick.type = INPUT_MOUSE;
			inputRightClick.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
			inputRightClick.mi.dx = 0;
			inputRightClick.mi.dy = 0;
			inputRightClick.mi.mouseData = 0;
			inputRightClick.mi.time = 0;
			inputRightClick.mi.dwExtraInfo = 0;

			inputReturn.type = INPUT_KEYBOARD;
			inputReturn.ki.wScan = MapVirtualKey(keyReturn, MAPVK_VK_TO_VSC);
			inputReturn.ki.wVk = keyReturn;
			inputReturn.ki.time = 0;
			inputReturn.ki.dwExtraInfo = 0;
			inputReturn.ki.dwFlags = 0;

			inputDown.type = INPUT_KEYBOARD;
			inputDown.ki.wScan = MapVirtualKey(keyDown, MAPVK_VK_TO_VSC);
			inputDown.ki.wVk = keyDown;
			inputDown.ki.time = 0;
			inputDown.ki.dwExtraInfo = 0;
			inputDown.ki.dwFlags = 0;

			// MACRO SEQUENCE ***************************************************************

			Sleep(sleepTime);

			SendInput(1, &inputReturn, sizeof(inputReturn));
			inputReturn.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &inputReturn, sizeof(inputReturn));
			inputReturn.ki.dwFlags = 0;

			Sleep(sleepTime);

			SendInput(1, &inputRightClick, sizeof(inputRightClick));
			inputRightClick.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
			SendInput(1, &inputRightClick, sizeof(inputRightClick));
			inputRightClick.mi.dwFlags = 0;

			Sleep(sleepTime);

			SendInput(1, &inputDown, sizeof(inputDown));
			inputDown.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &inputDown, sizeof(inputDown));
			inputDown.ki.dwFlags = 0;

			Sleep(sleepTime);

			SendInput(1, &inputDown, sizeof(inputDown));
			inputDown.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &inputDown, sizeof(inputDown));
			inputDown.ki.dwFlags = 0;

			Sleep(sleepTime);

			SendInput(1, &inputDown, sizeof(inputDown));
			inputDown.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &inputDown, sizeof(inputDown));
			inputDown.ki.dwFlags = 0;

			Sleep(sleepTime);

			SendInput(1, &inputDown, sizeof(inputDown));
			inputDown.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &inputDown, sizeof(inputDown));
			inputDown.ki.dwFlags = 0;
			
			Sleep(sleepTime);
			
			SendInput(1, &inputReturn, sizeof(inputReturn));
			inputReturn.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &inputReturn, sizeof(inputReturn));
			inputReturn.ki.dwFlags = 0;

			Sleep(sleepTimeSlow);

			SendInput(1, &inputReturn, sizeof(inputReturn));
			inputReturn.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &inputReturn, sizeof(inputReturn));
			inputReturn.ki.dwFlags = 0;

			Sleep(sleepTimeSlow);

			SendInput(1, &inputReturn, sizeof(inputReturn));
			inputReturn.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &inputReturn, sizeof(inputReturn));
			inputReturn.ki.dwFlags = 0;

			Sleep(sleepTime);

			SendInput(1, &inputRightClick, sizeof(inputRightClick));
			inputRightClick.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
			SendInput(1, &inputRightClick, sizeof(inputRightClick));
			inputRightClick.mi.dwFlags = 0;

			Sleep(sleepTime);

			SendInput(1, &inputDown, sizeof(inputDown));
			inputDown.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &inputDown, sizeof(inputDown));
			inputDown.ki.dwFlags = 0;

			Sleep(sleepTime);

			SendInput(1, &inputDown, sizeof(inputDown));
			inputDown.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &inputDown, sizeof(inputDown));
			inputDown.ki.dwFlags = 0;

			Sleep(sleepTime);
			
			SendInput(1, &inputReturn, sizeof(inputReturn));
			inputReturn.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &inputReturn, sizeof(inputReturn));
			inputReturn.ki.dwFlags = 0;

			Sleep(sleepTimeSlow);

			SendInput(1, &inputReturn, sizeof(inputReturn));
			inputReturn.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &inputReturn, sizeof(inputReturn));
			inputReturn.ki.dwFlags = 0;

			Sleep(sleepTime);

			// COUNT **********************************************************************************

			cout << ++count;
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;

		}
	};

	return 0;
}