	#include <windows.h>
	#include <stdlib.h>
	#include <stdio.h>
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
	#define OKCO 29
	#define COMBO3 30
	#define DEQUEUE 31
	#define DEQUEUE2 33
	#define BACK2 34
	#define COMBO4 35
	#define CB 36
	#define BM 37
	#define DC 38
	#define WH 39
	#define FF 40
	#define FC 41
	#define IT 42
	#define HC 43
	#define CC 44
	#define SP 45
	#define FA 46
	#define MW 47
		
	int Left, Right;
	int layoutsize;
	int sumy, y;
	int temp, price, sum;
	int cal, returns;
	int foodx, xcount, foody, ycount;
	int ht, wt, ifood, idrink;
	char out[2], sentence[2], menu[30], totalstr[30], totalstr2[30];
	char calsum[30], calwind[30], totalret[30], retfinal[30];
	char ordernums[2], finalord[30], qty[2], regist1[30], regist2[30], regd1[30];
	
	HWND hComboC, hFoodC, hDrinkC, hMenu, hOrderS, hOrderS2, hOrderS3, hClear;
	
	HWND hCombo1, hCombo2, hCombo3, hCombo4;
	
	HWND hCheeseBurger, hBigMac, hDoubleCheese, hWhopper, hFrFries, hFrChick;
	
	HWND hIceTea, hHotCoffee, hCoca, hSprite, hFanta, hMinWater;
	
	HWND hVSumScroll;
	
	HWND hPopUp;
	
	HWND hMinus, hPlus, hTotal, hOK, hTotal2, hTotalM;
	
	HWND h1, h2, h3, h4, h5, h6, h7, h8, h9, h0, hClearCal, h1000, hCalWin;
	
	HWND hBackMenu, hCheckOut, hReturns, hPopCO, hSuccess, hOK2;
	
	HWND hFoodBG, hList;
	
	HWND hOrderNum, hDequeue, hQty, hBack;
	
	HWND hDrinkBG, hList2;
	
	HWND hDequeue2, hQty2, hBack2;
	
	HINSTANCE hInst;

	static int yPos, yChar = 10;
	
	static int xPos, xChar = 10;

    SCROLLINFO si;
        
	void CreateScrollC();
	
	void CreateScrollH();

	void ComboLayOut (HWND hWnd);
	
	void display();
	
	void dequeue();
	
	void DestroyOWindow();
	
	void FoodWins (HWND);
	
	void insert(char*, int);
	
	void insertlist();
	
	void OrderSummary(HWND);
	
	void PopUpWindows();
	
	void SetTotalText();
	
	void SetTotal();
	
	void SetCal(int caltotal);
	
	void SetReturn();

	LRESULT CALLBACK MenuProc (HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
		switch (msg){
			case WM_COMMAND:{
				switch(wp){
					case COMBO1:{
						ifood = 1;
						idrink = 1;
						price = 30000;
						strcpy(menu, "");
						strcat(menu, "Combo 1");
						strcpy(regist1, "");
						strcat(regist1, "Cheeseburger");
						strcpy(regd1, "");
						strcat(regd1, "Soft Drink");
						PopUpWindows();
						break;
					}
					case COMBO2:{
						ifood = 1;
						idrink = 1;
						price = 40000;
						strcpy(menu, "");
						strcat(menu, "Combo 2");
						strcpy(regist1, "");
						strcat(regist1, "Big Mac");
						strcpy(regd1, "");
						strcat(regd1, "Soft Drink");
						PopUpWindows();
						break;
					}					
					case COMBO3:{
						ifood = 2;
						idrink = 1;
						price = 50000;
						strcpy(menu, "");
						strcat(menu, "Combo 3");
						strcpy(regist1, "");
						strcat(regist1, "Cheeseburger");
						strcpy(regist2, "");
						strcat(regist2, "French Fries");
						strcpy(regd1, "");
						strcat(regd1, "Soft Drink");
						PopUpWindows();
						break;
					}					
					case COMBO4:{
						ifood = 2;
						idrink = 1;
						price = 60000;
						strcpy(menu, "");
						strcat(menu, "Combo 4");
						strcpy(regist1, "");
						strcat(regist1, "Big Mac");
						strcpy(regist2, "");
						strcat(regist2, "French Fries");
						strcpy(regd1, "");
						strcat(regd1, "Soft Drink");
						PopUpWindows();
						break;
					}					
					case CB:{
						ifood = 1;
						idrink = 0;
						price = 20000;
						strcpy(menu, "");
						strcat(menu, "Cheeseburger");
						strcpy(regist1, "");
						strcat(regist1, "Cheeseburger");
						PopUpWindows();
						break;
					}
					case BM:{
						ifood = 1;
						idrink = 0;
						price = 30000;
						strcpy(menu, "");
						strcat(menu, "Big Mac");
						strcpy(regist1, "");
						strcat(regist1, "Big Mac");
						PopUpWindows();
						break;
					}
					case DC:{
						ifood = 1;
						idrink = 0;
						price = 35000;
						strcpy(menu, "");
						strcat(menu, "Double Cheeseburger");
						strcpy(regist1, "");
						strcat(regist1, "Double Cheeseburger");
						PopUpWindows();
						break;
					}
					case WH:{
						ifood = 1;
						idrink = 0;
						price = 45000;
						strcpy(menu, "");
						strcat(menu, "Whopper");
						strcpy(regist1, "");
						strcat(regist1, "Whopper");
						PopUpWindows();
						break;
					}
					case FF:{
						ifood = 1;
						idrink = 0;
						price = 20000;
						strcpy(menu, "");
						strcat(menu, "French Fries");
						strcpy(regist1, "");
						strcat(regist1, "French Fries");
						PopUpWindows();
						break;
					}
					case FC:{
						ifood = 1;
						idrink = 0;
						price = 20000;
						strcpy(menu, "");
						strcat(menu, "Fried Chicken");
						strcpy(regist1, "");
						strcat(regist1, "Fried Chicken");
						PopUpWindows();
						break;
					}
					case IT:{
						ifood = 0;
						idrink = 1;
						price = 5000;
						strcpy(menu, "");
						strcat(menu, "Ice Tea");
						strcpy(regd1, "");
						strcat(regd1, "Ice Tea");
						PopUpWindows();
						break;
					}
					case HC:{
						ifood = 0;
						idrink = 1;
						price = 5000;
						strcpy(menu, "");
						strcat(menu, "Hot Coffee");
						strcpy(regd1, "");
						strcat(regd1, "Hot Coffee");
						PopUpWindows();
						break;
					}
					case CC:{
						ifood = 0;
						idrink = 1;
						price = 8000;
						strcpy(menu, "");
						strcat(menu, "Coca-Cola");
						strcpy(regd1, "");
						strcat(regd1, "Coca-Cola");
						PopUpWindows();
						break;
					}
					case SP:{
						ifood = 0;
						idrink = 1;
						price = 8000;
						strcpy(menu, "");
						strcat(menu, "Sprite");
						strcpy(regd1, "");
						strcat(regd1, "Sprite");
						PopUpWindows();
						break;
					}
					case FA:{
						ifood = 0;
						idrink = 1;
						price = 8000;
						strcpy(menu, "");
						strcat(menu, "Fanta");
						strcpy(regd1, "");
						strcat(regd1, "Fanta");
						PopUpWindows();
						break;
					}
					case MW:{
						ifood = 0;
						idrink = 1;
						price = 8000;
						strcpy(menu, "");
						strcat(menu, "Mineral Water");
						strcpy(regd1, "");
						strcat(regd1, "Mineral Water");
						PopUpWindows();
						break;
					}
				}
			}
			case WM_VSCROLL:{
		    	si.cbSize = sizeof (si);
		        si.fMask  = SIF_ALL;
		        GetScrollInfo (hOrderS2, SB_VERT, &si);	
				yPos=si.nPos;	
		        switch (LOWORD (wp))
		        {
			        case SB_LINEUP:{
			            si.nPos -= 5;
						break;
					}
			        case SB_LINEDOWN:{
			            si.nPos += 5;
						break;
					}
			        case SB_THUMBTRACK:{
			            si.nPos = si.nTrackPos;
						break;
					}			              
			        default:{
						break;
					}
			    }
		
		        si.fMask = SIF_POS;
		        SetScrollInfo (hOrderS2, SB_VERT, &si, TRUE);
		        GetScrollInfo (hOrderS2, SB_VERT, &si);
		
		        if (si.nPos != yPos)
		        {                    
		            ScrollWindow(hOrderS2, 0, yChar * (yPos - si.nPos), NULL, NULL);
		            UpdateWindow (hOrderS2);
		        }				
				break;
			}		 
			case WM_HSCROLL:{
		    	si.cbSize = sizeof (si);
		        si.fMask  = SIF_ALL;
		        GetScrollInfo (hFoodBG, SB_HORZ, &si);	
				xPos=si.nPos;	
		        switch (LOWORD (wp))
		        {
			        case SB_LINEUP:{
			            si.nPos -= 5;
						break;
					}
			        case SB_LINEDOWN:{
			            si.nPos += 5;
						break;
					}
			        case SB_THUMBTRACK:{
			            si.nPos = si.nTrackPos;
						break;
					}			              
			        default:{
						break;
					}
			    }
		
		        si.fMask = SIF_POS;
		        SetScrollInfo (hFoodBG, SB_HORZ, &si, TRUE);
		        GetScrollInfo (hFoodBG, SB_HORZ, &si);
		
		        if (si.nPos != xPos)
		        {                    
		            ScrollWindow(hFoodBG, xChar * (xPos - si.nPos), 0, NULL, NULL);
		            UpdateWindow (hFoodBG);
		        }				
				break;
			}		 
			case WM_CREATE:{
				break;
			}
			case WM_DESTROY:{
				break;
			} 
			case WM_CLOSE:{
				break;
			}
		}
		return DefWindowProcW(hWnd, msg, wp, lp);	
	}	

	LRESULT CALLBACK PopCOProc (HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
		switch (msg){
			case WM_COMMAND:{
				switch(wp){
					case OKCO:{
						DestroyWindow(hPopCO);
						break;
					}					
				}
			}
			case WM_CREATE:{
				break;
			}
			case WM_DESTROY:{
				break;
			} 
		}
		return DefWindowProcW(hWnd, msg, wp, lp);	
	}
	
	LRESULT CALLBACK FoodProc (HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
		switch (msg){
			case WM_COMMAND:{
				switch(wp){
					case DEQUEUE:{
						dequeue();
						display();
						break;
					}					
				}
			}
			case WM_CREATE:{
				break;
			}
			case WM_DESTROY:{
				break;
			} 
		}
		return DefWindowProcW(hWnd, msg, wp, lp);	
	}

	LRESULT CALLBACK PopUpProc (HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
		switch (msg){
			case WM_COMMAND:{
				switch(wp){
					case PLUS:{
						temp += 1;
						SetTotalText();
						break;
					}					
					case MINUS:{
						if(temp>1){
							temp -= 1;
							SetTotalText();
						}
						break;
					}
					case OK:{
						DestroyWindow(hPopUp);
						sumy=10+(23*y);
						sum+=(price*temp);
						insertlist();
						printf("\n%d\n", sum);
						hOrderS3 = CreateWindowExW(NULL, L"static", 0, WS_CHILD|WS_VISIBLE|SS_LEFT, 10, sumy, 200, 20, hOrderS2, NULL, NULL, NULL);							
						hTotal2 = CreateWindowExW(NULL, L"static", 0, WS_CHILD|WS_VISIBLE|SS_LEFT, 270, sumy, 20, 20, hOrderS2, NULL, NULL, NULL);							
						SetWindowText(hOrderS3, menu);		
						SetWindowText(hTotal2, sentence);		
						SetTotal();
						y+=1;
						if(sumy>=130){
							CreateScrollC();
						}
						break;
					}					
				}
			}
			case WM_CREATE:{
				break;
			}
			case WM_DESTROY:{
				break;
			} 
		}
		return DefWindowProcW(hWnd, msg, wp, lp);	
	}	
		
	void MenuLayOut(HWND hWnd){
		Left = GetSystemMetrics(SM_CXSCREEN)*0.6;
		Right = GetSystemMetrics(SM_CXSCREEN)*0.4;		
		
		hComboC = CreateWindowExW(NULL, L"button", L"COMBO", WS_CHILD|WS_VISIBLE, (Left-200)/4, 20, 150, 100, hWnd, (HMENU) COMBO, NULL, NULL);
		hFoodC = CreateWindowExW(NULL, L"button", L"FOOD", WS_CHILD|WS_VISIBLE, (Left-200)/2, 20, 150, 100, hWnd, (HMENU) FOODC, NULL, NULL);
		hDrinkC = CreateWindowExW(NULL, L"button", L"DRINK", WS_CHILD|WS_VISIBLE, ((Left-200)/4)+((Left-200)/2), 20, 150, 100, hWnd, (HMENU) DRINKC, NULL, NULL);
	}

	void OrderSummary(HWND hWnd){
			
		hOrderS = CreateWindowExW(NULL, L"static", L"ORDER SUMMARY", WS_CHILD|WS_VISIBLE|SS_CENTERIMAGE|SS_CENTER|WS_BORDER, Left+((Right-300)/2), 20, 300, 50, hWnd, NULL, NULL, NULL);
		hOrderS2 = CreateWindowExW(NULL, L"MenuProc", NULL, WS_VISIBLE|WS_CHILD|WS_BORDER, Left+((Right-300)/2), 70, 300, 150, hWnd, NULL, hInst, NULL );
		hClear = CreateWindowExW(NULL, L"button", L"CLEAR ORDER", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2), 240, 300, 40, hWnd, (HMENU)CLEAR, NULL, NULL);

	}
	
	void CreateScrollC(){
	    RECT rc = { 0 };
    	GetClientRect(hOrderS2, &rc);
	    si.cbSize = sizeof(SCROLLINFO);
	    si.fMask = SIF_ALL;
    	si.nMin = 0;
	    si.nMax = (rc.bottom - rc.top)*2;
    	si.nPage = (rc.bottom - rc.top);
	    si.nPos = 0;
    	si.nTrackPos = 0;
	    SetScrollInfo(hOrderS2, SB_VERT, &si, true);
	}		

	void RegisterMenuLO(HWND hWnd){
		int bottom;
		bottom = GetSystemMetrics(SM_CYSCREEN);
		
		WNDCLASSW rwc = {0};
		rwc.hbrBackground = (HBRUSH) (COLOR_WINDOW) ;
		rwc.hCursor = LoadCursor(NULL, IDC_ARROW) ;
		rwc.lpszClassName = L"MenuProc";
		rwc.lpfnWndProc = MenuProc;	
		RegisterClassW(&rwc);
		hMenu = CreateWindowExW(0, L"MenuProc", NULL, WS_VISIBLE|WS_CHILD, 10, 130, Left-20, bottom-160, hWnd, NULL, NULL, NULL );
		ComboLayOut(hWnd);
		sum=0;
	}
	
	void RegisterFoodLO(HWND hWnd){
		ht = GetSystemMetrics(SM_CYSCREEN);
		wt = GetSystemMetrics(SM_CXSCREEN);		
		WNDCLASSW rwc = {0};
		rwc.hbrBackground = (HBRUSH) (COLOR_WINDOW+2) ;
		rwc.hCursor = LoadCursor(NULL, IDC_ARROW) ;
		rwc.lpszClassName = L"FoodProc";
		rwc.lpfnWndProc = MenuProc;	
		RegisterClassW(&rwc);
		xcount=0;
		ycount=0;
	}
	
	void RegisterPopCO(HWND hWnd){
		WNDCLASSW zwc = {0};
		zwc.hbrBackground = (HBRUSH) (COLOR_WINDOW) ;
		zwc.hCursor = LoadCursor(NULL, IDC_ARROW) ;
		zwc.lpszClassName = L"CheckOut";
		zwc.lpfnWndProc = PopCOProc;	
		RegisterClassW(&zwc);
	}

	void RegisterPopUp(HWND hWnd){
		WNDCLASSW zwc = {0};
		zwc.hbrBackground = (HBRUSH) (COLOR_WINDOW) ;
		zwc.hCursor = LoadCursor(NULL, IDC_ARROW) ;
		zwc.lpszClassName = L"Quantity";
		zwc.lpfnWndProc = PopUpProc;	
		RegisterClassW(&zwc);
	}
	
	void ComboLayOut (HWND hWnd){		
		hCombo1 = CreateWindowExW(NULL, L"button", L"COMBO 1\n-------------------------\nCheeseburger\nSoft Drink", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 75, 20, 300, 100, hMenu, (HMENU) COMBO1, NULL, NULL);
		hCombo2 = CreateWindowExW(NULL, L"button", L"COMBO 2\n-------------------------\nBig Mac\nSoft Drink", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 424, 20, 300, 100, hMenu, (HMENU) COMBO2, NULL, NULL);
		hCombo3 = CreateWindowExW(NULL, L"button", L"COMBO 3\n-------------------------\nCheeseburger\nFrench Fries\nSoft Drink", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 75, 140, 300, 100, hMenu, (HMENU) COMBO3, NULL, NULL);
		hCombo4 = CreateWindowExW(NULL, L"button", L"COMBO 4\n-------------------------\nBig Mac\nFrench Fries\nSoft Drink", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 424, 140, 300, 100, hMenu, (HMENU) COMBO4, NULL, NULL);
	}

	void FoodLayOut (HWND hWnd){		
		hCheeseBurger = CreateWindowExW(NULL, L"button", L"Cheeseburger", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 75, 20, 300, 100, hMenu, (HMENU) CB, NULL, NULL);
		hBigMac = CreateWindowExW(NULL, L"button", L"Big Mac", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 424, 20, 300, 100, hMenu, (HMENU) BM, NULL, NULL);
		hDoubleCheese = CreateWindowExW(NULL, L"button", L"Double Cheeseburger", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 75, 140, 300, 100, hMenu, (HMENU) DC, NULL, NULL);
		hWhopper = CreateWindowExW(NULL, L"button", L"Whopper", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 424, 140, 300, 100, hMenu, (HMENU) WH, NULL, NULL);
		hFrFries = CreateWindowExW(NULL, L"button", L"French Fries", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 75, 260, 300, 100, hMenu, (HMENU) FF, NULL, NULL);
		hFrChick = CreateWindowExW(NULL, L"button", L"Fried Chicken", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 424, 260, 300, 100, hMenu, (HMENU) FC, NULL, NULL);
	}
	
	void DrinkLayOut (HWND hWnd){
		hIceTea = CreateWindowExW(NULL, L"button", L"Ice Tea", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 75, 20, 300, 100, hMenu, (HMENU) IT, NULL, NULL);
		hHotCoffee = CreateWindowExW(NULL, L"button", L"Hot Coffee", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 424, 20, 300, 100, hMenu, (HMENU) HC, NULL, NULL);
		hCoca = CreateWindowExW(NULL, L"button", L"Coca-Cola", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 75, 140, 300, 100, hMenu, (HMENU) CC, NULL, NULL);
		hSprite = CreateWindowExW(NULL, L"button", L"Sprite", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 424, 140, 300, 100, hMenu, (HMENU) SP, NULL, NULL);
		hFanta = CreateWindowExW(NULL, L"button", L"Fanta", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 75, 260, 300, 100, hMenu, (HMENU) FA, NULL, NULL);
		hMinWater = CreateWindowExW(NULL, L"button", L"Mineral Water", WS_CHILD|WS_VISIBLE|BS_MULTILINE, 424, 260, 300, 100, hMenu, (HMENU) MW, NULL, NULL);
	}
	
	void DestroyChildMenu(){
		DestroyWindow(hCombo1);
		DestroyWindow(hCombo2);
		DestroyWindow(hCombo3);
		DestroyWindow(hCombo4);
		DestroyWindow(hCheeseBurger);
		DestroyWindow(hBigMac);
		DestroyWindow(hDoubleCheese);
		DestroyWindow(hWhopper);
		DestroyWindow(hFrFries);
		DestroyWindow(hFrChick);
		DestroyWindow(hIceTea);
		DestroyWindow(hHotCoffee);
		DestroyWindow(hCoca);
		DestroyWindow(hSprite);
		DestroyWindow(hFanta);
		DestroyWindow(hMinWater);
	}
	
	void DestroyOWindow(){
		sumy=0;
		y=0;
		sum=0;
		DestroyWindow(hOrderS);
		DestroyWindow(hOrderS2);
		DestroyWindow(hClear);
		SetTotal();
	}
	
	void PopUpWindows(){
		temp = 1;
		hPopUp = CreateWindowExW(0, L"Quantity", L"Quantity",  WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN)-300)/2, (GetSystemMetrics(SM_CYSCREEN)-300)/2, 300, 250, NULL, NULL, NULL, NULL );
		hPlus = CreateWindowExW(NULL, L"button", L"+", WS_VISIBLE|WS_CHILD, 200, 85, 30, 30, hPopUp, (HMENU)PLUS, NULL, NULL);
		hTotal = CreateWindowExW(NULL, L"static", 0, WS_VISIBLE|WS_CHILD|SS_CENTER|SS_CENTERIMAGE, 100, 75, 100, 50, hPopUp, NULL, NULL, NULL);
		hMinus = CreateWindowExW(NULL, L"button", L"-", WS_VISIBLE|WS_CHILD, 70, 85, 30, 30, hPopUp, (HMENU)MINUS, NULL, NULL);
		hOK = CreateWindowExW(NULL, L"button", L"OK", WS_VISIBLE|WS_CHILD, 125, 135, 50, 50, hPopUp, (HMENU)OK, NULL, NULL);		
		SetTotalText();
	}	
	
	void SetTotalText(){
		printf("%d", temp);
		_itoa(temp, out, 10);
		strcpy(sentence, "");
		strcat(sentence, out);
		SetWindowText(hTotal, sentence);		
	}
	
	void TotalLayout(HWND hWnd){
		 hTotalM = CreateWindowExW(NULL, L"static", 0, WS_VISIBLE|WS_CHILD|SS_CENTERIMAGE, (Left+(Right-300)/2), 290, 300, 30, hWnd, NULL, NULL, NULL);
	}	
	
	void SetTotal(){
		_itoa(sum, totalstr2, 10);
		strcpy(totalstr, "");
		strcat(totalstr, "Total : Rp ");
		strcat(totalstr, totalstr2);
		SetWindowText(hTotalM, totalstr);		
	}
	
	void Calculator(HWND hWnd){
		cal=0;
		hCalWin = CreateWindowExW(NULL, L"static", 0, WS_VISIBLE|WS_CHILD|SS_CENTERIMAGE, (Left+(Right-300)/2), 330, 300, 30, hWnd, NULL, NULL, NULL);
		h1 = CreateWindowExW(NULL, L"button", L"1", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+75, 370, 50, 50, hWnd, (HMENU) CAL1, NULL, NULL);		
		h2 = CreateWindowExW(NULL, L"button", L"2", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+125, 370, 50, 50, hWnd, (HMENU) CAL2, NULL, NULL);		
		h3 = CreateWindowExW(NULL, L"button", L"3", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+175, 370, 50, 50, hWnd, (HMENU) CAL3, NULL, NULL);		
		h4 = CreateWindowExW(NULL, L"button", L"4", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+75, 370+50, 50, 50, hWnd, (HMENU) CAL4, NULL, NULL);		
		h5 = CreateWindowExW(NULL, L"button", L"5", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+125, 370+50, 50, 50, hWnd, (HMENU) CAL5, NULL, NULL);		
		h6 = CreateWindowExW(NULL, L"button", L"6", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+175, 370+50, 50, 50, hWnd, (HMENU) CAL6, NULL, NULL);		
		h7 = CreateWindowExW(NULL, L"button", L"7", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+75, 370+100, 50, 50, hWnd, (HMENU) CAL7, NULL, NULL);		
		h8 = CreateWindowExW(NULL, L"button", L"8", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+125, 370+100, 50, 50, hWnd, (HMENU) CAL8, NULL, NULL);		
		h9 = CreateWindowExW(NULL, L"button", L"9", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+175, 370+100, 50, 50, hWnd, (HMENU) CAL9, NULL, NULL);		
		h1000 = CreateWindowExW(NULL, L"button", L".0", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+75, 370+150, 50, 50, hWnd, (HMENU) CAL1000, NULL, NULL);		
		h0 = CreateWindowExW(NULL, L"button", L"0", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+125, 370+150, 50, 50, hWnd, (HMENU) CAL0, NULL, NULL);		
		hClearCal = CreateWindowExW(NULL, L"button", L"CLR", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+175, 370+150, 50, 50, hWnd, (HMENU) CALCL, NULL, NULL);		
		SetCal(cal);
	}
	
	void SetCal(int caltotal){
		_itoa(caltotal, calsum, 10);
		strcpy(calwind, "");
		strcat(calwind, "Cash In : Rp ");
		strcat(calwind, calsum);
		SetWindowText(hCalWin, calwind);				
	}
	
	void MenuandCO(HWND hWnd){
		hBackMenu = CreateWindowExW(NULL, L"button", L"MENU", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2), 580, 150, 30, hWnd, (HMENU)BACK, NULL, NULL);		
		hCheckOut = CreateWindowExW(NULL, L"button", L"Check Out", WS_VISIBLE|WS_CHILD, (Left+(Right-300)/2)+150, 580, 150, 30, hWnd, (HMENU)CHECKOUT, NULL, NULL);		
	}
	
	void DestroyAllCashier(HWND hWnd){
		DestroyWindow(hComboC);
		DestroyWindow(hFoodC);
		DestroyWindow(hDrinkC);
		DestroyWindow(hMenu);
		DestroyWindow(hOrderS);
		DestroyWindow(hOrderS2);
		DestroyWindow(hClear);
		DestroyWindow(hTotalM);
		DestroyWindow(hCalWin);
		DestroyWindow(h1);
		DestroyWindow(h2);
		DestroyWindow(h3);
		DestroyWindow(h4);
		DestroyWindow(h5);
		DestroyWindow(h6);
		DestroyWindow(h7);
		DestroyWindow(h8);
		DestroyWindow(h9);
		DestroyWindow(h1000);
		DestroyWindow(h0);
		DestroyWindow(hClearCal);
		DestroyWindow(hBackMenu);
		DestroyWindow(hCheckOut);
	}

	int PopUpCO(HWND hWnd, int calnum){
		if(calnum>=sum&&sum!=0){
			returns = calnum - sum;
			sum=0;
			SetTotalText();
			hPopCO = CreateWindowExW(0, L"CheckOut", L"Check Out",  WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN)-300)/2, (GetSystemMetrics(SM_CYSCREEN)-300)/2, 300, 250, NULL, NULL, NULL, NULL );
			hSuccess = CreateWindowExW(NULL, L"static", L"Order Successful", WS_VISIBLE|WS_CHILD|SS_CENTER|SS_CENTERIMAGE, 50, 40, 200, 50, hPopCO, NULL, NULL, NULL);
			hReturns = CreateWindowExW(NULL, L"static", 0, WS_VISIBLE|WS_CHILD|SS_CENTER|SS_CENTERIMAGE, 50, 100, 200, 50, hPopCO, NULL, NULL, NULL);
			SetReturn();
			hOK2 = CreateWindowExW(NULL, L"button", L"OK", WS_VISIBLE|WS_CHILD, 135, 150, 30, 30, hPopCO, (HMENU)OKCO, NULL, NULL);
			calnum=0;
			return calnum;
		} else if (calnum<sum){
			hPopCO = CreateWindowExW(0, L"CheckOut", L"Check Out",  WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN)-300)/2, (GetSystemMetrics(SM_CYSCREEN)-300)/2, 300, 250, NULL, NULL, NULL, NULL );
			hSuccess = CreateWindowExW(NULL, L"static", L"Insufficient Cash", WS_VISIBLE|WS_CHILD|SS_CENTER|SS_CENTERIMAGE, 50, 40, 200, 50, hPopCO, NULL, NULL, NULL);			
			hOK2 = CreateWindowExW(NULL, L"button", L"OK", WS_VISIBLE|WS_CHILD, 135, 150, 30, 30, hPopCO, (HMENU)OKCO, NULL, NULL);
			return calnum;
		} else if (sum==0){
			hPopCO = CreateWindowExW(0, L"CheckOut", L"Check Out",  WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN)-300)/2, (GetSystemMetrics(SM_CYSCREEN)-300)/2, 300, 250, NULL, NULL, NULL, NULL );
			hSuccess = CreateWindowExW(NULL, L"static", L"No Order", WS_VISIBLE|WS_CHILD|SS_CENTER|SS_CENTERIMAGE, 50, 40, 200, 50, hPopCO, NULL, NULL, NULL);			
			hOK2 = CreateWindowExW(NULL, L"button", L"OK", WS_VISIBLE|WS_CHILD, 135, 150, 50, 30, hPopCO, (HMENU)OKCO, NULL, NULL);	
			return calnum;
		}
	}
	
	int calcheck(int calnum){
		if(calnum>=sum){
			return 1;
		} else if(calnum==0){
			return 0;
		}
	}
	
	void SetReturn(){
		_itoa(returns, totalret, 10);
		strcpy(retfinal, "");
		strcat(retfinal, "Return : Rp ");
		strcat(retfinal, totalret);
		SetWindowText(hReturns, retfinal);
	}
	
	struct in{
		int qty;
		char *menu;
		struct in *next2;
	};
	
	struct node{
		int qty;
		char* menu;
		struct node *next;
	};
	
	struct bignode{
		int ordernumber;
		struct node *orderlist;
		struct bignode *nexto;
	};
	
	struct in *front = NULL;
	struct in *back = NULL;
	struct in *temps = NULL;

	struct in *dfront = NULL;
	struct in *dback = NULL;
	struct in *dtemps = NULL;

	struct node *head = NULL;
	struct node *tail = NULL;
	struct node *temp2 = NULL;

	struct node *dhead = NULL;
	struct node *dtail = NULL;
	struct node *dtemp2 = NULL;

	struct bignode *head2 = NULL;
	struct bignode *tail2 = NULL;
	struct bignode *temp3 = NULL;
	
	struct bignode *dhead2 = NULL;
	struct bignode *dtail2 = NULL;
	struct bignode *dtemp3 = NULL;

	void insertdrink(char *append, int qty){
  		struct in *link = (struct in*) malloc (sizeof(struct in));
		link->menu = (char*) malloc (strlen(append)+1);
		strcpy(link->menu, append);
		link->qty = qty;
		link->next2=NULL;
		if(dfront == NULL){
			dfront = link;
			return;
		}
		dback = dfront;
		while(dback->next2!=NULL){
			dback = dback->next2; 
		}
		dback->next2=link;
	}

	void insert(char *append, int qty){
  		struct in *link = (struct in*) malloc (sizeof(struct in));
		link->menu = (char*) malloc (strlen(append)+1);
		strcpy(link->menu, append);
		link->qty = qty;
		link->next2=NULL;
		if(front == NULL){
			front = link;
			return;
		}
		back = front;
		while(back->next2!=NULL){
			back = back->next2; 
		}
		back->next2=link;
	}
	
	void display() {
		struct bignode *ptr2 = head2;
		printf("\n[head] =>");
		while(ptr2) {
			printf("Ordernumber : %d\n", ptr2->ordernumber);
			struct node *lists = ptr2->orderlist;
			while(lists){
	      		printf(" %s, qty :  %d =>", lists->menu, lists->qty);
    	  		lists = lists->next;
			}
			ptr2 = ptr2->nexto;
		}
		printf(" [null]\n");
	}
	
	void move(){
		struct in *ptr = front;
		while (ptr!=NULL){
			struct node *copy = (struct node*) malloc (sizeof(struct node));
			copy->menu = (char*) malloc (30);
			strcpy(copy->menu, ptr->menu);
			copy->qty = ptr->qty;
			printf("\n%s %d\n", copy->menu,copy->qty);
			copy->next = NULL;
			printf(" \noi : %d\n", tail2->ordernumber);
			if(tail2->orderlist==NULL){
				tail2->orderlist = copy;
			} else {
				tail = tail2->orderlist;
				while(tail->next!=NULL){
					tail = tail->next;
				}
				tail->next = copy;
			}
			ptr = ptr->next2;
		}
	}
	
	void move2(){
		struct in *ptr = dfront;
		while (ptr!=NULL){
			struct node *copy = (struct node*) malloc (sizeof(struct node));
			copy->menu = (char*) malloc (30);
			strcpy(copy->menu, ptr->menu);
			copy->qty = ptr->qty;
			printf("\n%s %d\n", copy->menu,copy->qty);
			copy->next = NULL;
			printf(" \noi : %d\n", dtail2->ordernumber);
			if(dtail2->orderlist==NULL){
				dtail2->orderlist = copy;
			} else {
				dtail = dtail2->orderlist;
				while(dtail->next!=NULL){
					dtail = dtail->next;
				}
				dtail->next = copy;
			}
			ptr = ptr->next2;
		}
	}
	
	void clearqueue(){
		struct in *temps = front;
		while(front!=NULL){
			front = temps->next2;
			free(temps);
			temps = temps->next2;
		}
	}

	void clearqueued(){
		struct in *temps = dfront;
		while(dfront!=NULL){
			dfront = temps->next2;
			free(temps);
			temps = temps->next2;
		}
	}
  	
	void FoodB(HWND hWnd){
  		hDequeue = CreateWindowExW(NULL, L"button", L"REMOVE", WS_VISIBLE|WS_CHILD, 30, ht-70, 70, 30, hWnd, (HMENU)DEQUEUE, NULL, NULL);
  		hBack =  CreateWindowExW(NULL, L"button", L"MENU", WS_VISIBLE|WS_CHILD, 110, ht-70, 70, 30, hWnd, (HMENU)BACK, NULL, NULL);
	}
	
	void DrinkB(HWND hWnd){
 		hDequeue2 = CreateWindowExW(NULL, L"button", L"REMOVE", WS_VISIBLE|WS_CHILD, 30, ht-70, 70, 30, hWnd, (HMENU)DEQUEUE2, NULL, NULL);
  		hBack2 =  CreateWindowExW(NULL, L"button", L"MENU", WS_VISIBLE|WS_CHILD, 110, ht-70, 70, 30, hWnd, (HMENU)BACK, NULL, NULL);		
	}

  	void FoodWins(HWND hWnd){
		hFoodBG = CreateWindowExW(0, L"FoodProc", NULL, WS_VISIBLE|WS_CHILD, 30, 10, wt-60, ht-100, hWnd, NULL, NULL, NULL );
		CreateScrollH();
		struct bignode *ptr2 = head2;
  		while(ptr2){
  			foodx=30+(300*xcount);
  			xcount+=1;
			if(foodx>(((wt-60)*1.05)+300)){
				return;
			}
  			hOrderNum = CreateWindowExW(NULL, L"static", 0, WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTERIMAGE|SS_CENTER, foodx, 10, 300, 30, hFoodBG, NULL, NULL, NULL);
			_itoa(ptr2->ordernumber, ordernums, 10);
			strcpy(finalord, "");
			strcat(finalord, "Order Number : ");
			strcat(finalord, ordernums);
			SetWindowText(hOrderNum, finalord);
  			struct node *lists = ptr2->orderlist;
  			while (lists){
	 	  		foody=50+(30*ycount);
	 			ycount+=1;
	  			hList = CreateWindowExW(NULL, L"static", 0, WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTERIMAGE, foodx, foody, 300, 30, hFoodBG, NULL, NULL, NULL);
	  			hQty = CreateWindowExW(NULL, L"static", 0, WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTERIMAGE|SS_CENTER, foodx+270, foody, 30, 30, hFoodBG, NULL, NULL, NULL);
	 			SetWindowText(hList, lists->menu);
	 			_itoa(lists->qty, qty, 10);
	 			SetWindowText(hQty, qty);
	 			lists = lists->next;
			}
			ycount=0;
			ptr2 = ptr2->nexto;
  		}
	}
	
  	void DrinkWins(HWND hWnd){
 		hDrinkBG = CreateWindowExW(0, L"FoodProc", NULL, WS_VISIBLE|WS_CHILD, 30, 10, wt-60, ht-100, hWnd, NULL, NULL, NULL );
		CreateScrollH();
		struct bignode *ptr2 = dhead2;
  		while(ptr2){
  			foodx=30+(300*xcount);
  			xcount+=1;
			if(foodx>(((wt-60)*1.05)+300)){
				return;
			}
  			hOrderNum = CreateWindowExW(NULL, L"static", 0, WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTERIMAGE|SS_CENTER, foodx, 10, 300, 30, hDrinkBG, NULL, NULL, NULL);
			_itoa(ptr2->ordernumber, ordernums, 10);
			strcpy(finalord, "");
			strcat(finalord, "Order Number : ");
			strcat(finalord, ordernums);
			SetWindowText(hOrderNum, finalord);
  			struct node *lists = ptr2->orderlist;
  			while (lists){
	 	  		foody=50+(30*ycount);
	 			ycount+=1;
	  			hList2 = CreateWindowExW(NULL, L"static", 0, WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTERIMAGE, foodx, foody, 300, 30, hDrinkBG, NULL, NULL, NULL);
	  			hQty2 = CreateWindowExW(NULL, L"static", 0, WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTERIMAGE|SS_CENTER, foodx+270, foody, 30, 30, hDrinkBG, NULL, NULL, NULL);
	 			SetWindowText(hList2, lists->menu);
	 			_itoa(lists->qty, qty, 10);
	 			SetWindowText(hQty2, qty);
	 			lists = lists->next;
			}
			ycount=0;
			ptr2 = ptr2->nexto;
  		}
	}
	
	void inorder(int ordernumber){
		struct bignode *order=(struct bignode *) malloc (sizeof(struct bignode));
		if(tail2==NULL) {
			tail2 = order;
			tail2->nexto = NULL;
			tail2->ordernumber = ordernumber;
		    head2=tail2;
			move();
		} else {
			temp3 = order;
			tail2->nexto = temp3;
			temp3->ordernumber = ordernumber;
			temp3->nexto = NULL;
			tail2 = temp3;
			move();
		}
	}

	void drinkorder(int ordernumber){
		struct bignode *order=(struct bignode *) malloc (sizeof(struct bignode));
		if(dtail2==NULL) {
			dtail2 = order;
			dtail2->nexto = NULL;
			dtail2->ordernumber = ordernumber;
		    dhead2=dtail2;
			move2();
		} else {
			dtemp3 = order;
			dtail2->nexto = dtemp3;
			dtemp3->ordernumber = ordernumber;
			dtemp3->nexto = NULL;
			dtail2 = dtemp3;
			move2();
		}
	}
	
	void display2(){
		struct bignode *ptr = head2;
		printf("\n[head] =>");
		while(ptr) {
      		printf("\nOrder number :  %d\n", ptr->ordernumber);
      		ptr = ptr->nexto;
			}
		printf(" [null]\n");
	}
	
	void dequeue(){
		if (head2==NULL){
			return;
		}
		struct bignode *temp = head2;
		head2 = temp->nexto;
		free(temp);	
	}

	void dequeue2(){
		if (dhead2==NULL){
			return;
		}
		struct bignode *temp = dhead2;
		dhead2 = temp->nexto;
		free(temp);	
	}
	
	void refreshwindow(HWND hWnd){
		DestroyWindow(hFoodBG);
		foodx = 0;
		foody = 0;
		xcount = 0;
		ycount = 0;
		FoodWins(hWnd);
	}

	void refreshdwindow(HWND hWnd){
		DestroyWindow(hDrinkBG);
		foodx = 0;
		foody = 0;
		xcount = 0;
		ycount = 0;
		DrinkWins(hWnd);
	}
	
	void DestroyAllFood(HWND hWnd){
		DestroyWindow(hFoodBG);
		DestroyWindow(hDequeue);
		DestroyWindow(hBack);
	}

	void DestroyAllDrink(HWND hWnd){
		DestroyWindow(hDrinkBG);
		DestroyWindow(hDequeue2);
		DestroyWindow(hBack2);
	}

	void insertlist(){
		if(ifood==1&&idrink==1){
			insert(regist1, temp);
			insertdrink(regd1, temp);
			display();
		}else if (ifood==2&&idrink==1){
			insert(regist1, temp);
			insert(regist2, temp);
			insertdrink(regd1, temp);
			display();
		}else if(idrink==0){
			insert(regist1, temp);
		} else if(ifood==0){
			insertdrink(regd1, temp);
		}
	}

	void regorder(int ordernum){
		if(ifood==1&&idrink==1){
			inorder(ordernum);
			drinkorder(ordernum);
		}else if (ifood==2&&idrink==1){
			inorder(ordernum);
			drinkorder(ordernum);
		}else if(idrink==0){
			inorder(ordernum);
		} else if(ifood==0){
			drinkorder(ordernum);
		}		
	}
	
	void CreateScrollH(){
	    RECT rc = { 0 };
    	GetClientRect(hFoodBG, &rc);
	    si.cbSize = sizeof(SCROLLINFO);
	    si.fMask = SIF_ALL;
    	si.nMin = 0;
	    si.nMax = (wt-60)*1.05;
    	si.nPage = (rc.right - rc.left);
	    si.nPos = 0;
    	si.nTrackPos = 0;
	    SetScrollInfo(hFoodBG, SB_HORZ, &si, true);
	}		
	
