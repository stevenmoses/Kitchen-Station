#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "Food.h"

#define NEW 1
#define CLOSE 2
#define CASHIER 3
#define FOOD 4
#define REFRESH 5
#define COMBO 6
#define FOODC 7
#define DRINKC 8
#define CLEAR 9
#define COMBO1 10
#define COMBO2 11
#define PLUS 12
#define MINUS 13
#define OK 14
#define CAL1 15
#define CAL2 16
#define CAL3 17
#define CAL4 18
#define CAL5 19
#define CAL6 20
#define CAL7 21
#define CAL8 22
#define CAL9 23
#define CAL1000 24
#define CAL0 25
#define CALCL 26
#define BACK 27
#define CHECKOUT 28
#define DEQUEUE 31
#define DRINKS 32
#define DEQUEUE2 33
#define BACK2 34

LRESULT CALLBACK WinProc (HWND, UINT, WPARAM, LPARAM) ;

int calnum;

int Menu, WelcSize, width, height;

int verify, ordernum;

RECT rc;

void AddMenus(HWND), AddControls(HWND), LoadHeader(HWND);
void RegisterNewBG(HWND);
void CalFunct(int value);
void GetWinSize(HWND);

HBITMAP hHeader;

HWND hWelcome, hCashier, hFoodM, hDrinkM;

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst, LPSTR args, int ncmdshow){
	
	WNDCLASSW wc = {0};
	wc.hbrBackground = (HBRUSH) (COLOR_WINDOW+3) ;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW) ;
	wc.hInstance = hInst;
	wc.lpszClassName = L"Kitchen Station";
	wc.lpfnWndProc = WinProc;
	
	if(!RegisterClassW(&wc)){
		return -1;
	}
	
	CreateWindowExW(0, L"Kitchen Station", L"Kitchen Station", WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX|WS_VISIBLE|WS_MAXIMIZE, CW_USEDEFAULT, CW_USEDEFAULT, 180, 
				300, NULL, NULL, NULL, NULL );
	
	MSG msg = {0};
	
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WinProc (HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
	int value;
	switch (msg){
		case WM_COMMAND:{
			switch(wp){
				case NEW:{
					MessageBeep(MB_ICONINFORMATION);
					break;
				}
				case CLOSE:{
					MessageBeep(MB_OK);
					DestroyWindow(hWnd);
					break;
				}
				case CASHIER:{
					DestroyWindow(hWelcome);
					DestroyWindow(hCashier);
					DestroyWindow(hFoodM);
					DestroyWindow(hDrinkM);
					MenuLayOut(hWnd);
					RegisterMenuLO(hWnd);
					RegisterPopUp(hWnd);
					OrderSummary(hWnd);
					TotalLayout(hWnd);
					SetTotal();
					Calculator(hWnd);
					MenuandCO(hWnd);
					break;
				}
				case FOOD:{
					DestroyWindow(hWelcome);
					DestroyWindow(hCashier);
					DestroyWindow(hFoodM);
					DestroyWindow(hDrinkM);
					RegisterFoodLO(hWnd);
					FoodB(hWnd);
					FoodWins(hWnd);
					break;
				}
				case DRINKS:{
					DestroyWindow(hWelcome);
					DestroyWindow(hCashier);
					DestroyWindow(hFoodM);
					DestroyWindow(hDrinkM);
					RegisterFoodLO(hWnd);
					DrinkB(hWnd);
					DrinkWins(hWnd);
					break;
				}
				case COMBO:{
					DestroyChildMenu();
					ComboLayOut(hWnd);
					break;
				}
				case FOODC:{
					DestroyChildMenu();
					FoodLayOut(hWnd);
					break;
				}
				case DRINKC:{
					DestroyChildMenu();
					DrinkLayOut(hWnd);
					break;
				}
				case CLEAR:{
					DestroyOWindow();
					OrderSummary(hWnd);
					clearqueue();
					display();
					break;
				}
				case CAL1:{
					value = 1;
					CalFunct(value);
					break;
				}
				case CAL2:{
					value = 2;
					CalFunct(value);
					break;
				}
				case CAL3:{
					value = 3;
					CalFunct(value);
					break;
				}
				case CAL4:{
					value = 4;
					CalFunct(value);
					break;
				}
				case CAL5:{
					value = 5;
					CalFunct(value);
					break;
				}
				case CAL6:{
					value = 6;
					CalFunct(value);
					break;
				}
				case CAL7:{
					value = 7;
					CalFunct(value);
					break;
				}
				case CAL8:{
					value = 8;
					CalFunct(value);
					break;
				}
				case CAL9:{
					value = 9;
					CalFunct(value);
					break;
				}
				case CAL1000:{
					calnum=calnum*100;
					value = 0;
					CalFunct(value);
					break;
				}
				case CAL0:{
					value = 0;
					CalFunct(value);
					break;
				}
				case CALCL:{
					calnum = 0;
					value = 0;
					CalFunct(value);
					break;
				}
				case BACK:{
					DestroyAllCashier(hWnd);
					DestroyAllFood(hWnd);
					DestroyAllDrink(hWnd);
					LoadHeader(hWnd);
					AddControls(hWnd);
					clearqueue();
					clearqueued();
					calnum=0;
					break;
				}
				case CHECKOUT:{
					RegisterPopCO(hWnd);
					verify=calcheck(calnum);
					calnum = PopUpCO(hWnd, calnum);
					SetCal(calnum);
					if(calnum==0&&verify==1){
						ordernum+=1;
						DestroyOWindow();
						OrderSummary(hWnd);
						regorder(ordernum);
						display2();
						display();
						clearqueue();
						clearqueued();
					}
					break;
				}
				case DEQUEUE:{
					dequeue();
					display();
					refreshwindow(hWnd);
					break;
				}
				case DEQUEUE2:{
					dequeue2();
					refreshdwindow(hWnd);
					break;
				}
				break;
			}
			break;
		}
		case WM_CREATE:{
			GetWinSize(hWnd);
			LoadHeader(hWnd);
			AddControls(hWnd);
			ordernum=0;
			break;
		}
		case WM_DESTROY:{
			PostQuitMessage(0);
			break;
		} 
		default :{
			return DefWindowProcW(hWnd, msg, wp, lp);
		}	
	}
}

void AddControls(HWND hWnd){
	hWelcome = CreateWindowExW(0, L"static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, ((Menu-WelcSize)/2), 40, WelcSize, 100, hWnd, NULL, NULL, NULL);
	SendMessageW(hWelcome, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hHeader);
	
	hCashier = CreateWindowExW(0, L"Button", L"CASHIER", WS_VISIBLE | WS_CHILD | SS_CENTER, ((Menu-width)/4), 260, 200, 100, hWnd, (HMENU) CASHIER, NULL, NULL);
	hFoodM = CreateWindowExW(0, L"Button", L"FOOD", WS_VISIBLE | WS_CHILD | SS_CENTER, ((Menu-width)/2), 260, 200, 100, hWnd, (HMENU) FOOD, NULL, NULL);
	hDrinkM = CreateWindowExW(0, L"Button", L"DRINKS", WS_VISIBLE | WS_CHILD | SS_CENTER, (((Menu-width)/2)+((Menu-width)/4)), 260, 200, 100, hWnd, (HMENU) DRINKS, NULL, NULL);
}

void LoadHeader(HWND hWnd){
	int Menu, WelcSize;
	Menu = GetSystemMetrics(SM_CXSCREEN);
	hHeader = (HBITMAP)LoadImageW(NULL, L"Header.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	
}

void CalFunct(int value){
	calnum=(calnum*10)+value;
	SetCal(calnum);
}

void GetWinSize(HWND hWnd){
	if(GetWindowRect(hWnd, &rc))
	{
	  width = rc.right - rc.left;
	  height = rc.bottom - rc.top;
	}
	Menu = GetSystemMetrics(SM_CXSCREEN);
	WelcSize = Menu-50;
}
