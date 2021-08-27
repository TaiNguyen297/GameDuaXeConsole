#include<iostream>
#include<string>
#include<Windows.h>
#include<ctime>
using namespace std;


char map[50][50]; // mang 2 chieu cac ki tu
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Ham to mau
void textColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void gotoxy(int x ,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);	
}

void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void VeXeChuongNgaiVat(int x , int y)
{
	map[x][y] = '!'; // Than xe dua
	map[x][y - 1] = '!';// ben trai than xe
	map[x][y + 1] = '!';// ben phai than xe
    map[x - 1][y - 1] = '!';//banh xe tren ben trai
    map[x + 1][y - 1] = '!';//banh xe duoi ben trai
    map[x - 1][y + 1] = '!';//banh xe tren ben phai
    map[x + 1][y + 1] = '!';//banh xe duoi ben phai
    
}
void XoaXeChuongNgaiVat(int x, int y)
{
	map[x][y] = ' '; // Than xe dua
	map[x][y - 1] = ' ';// ben trai than xe
	map[x][y + 1] = ' ';// ben phai than xe
    map[x - 1][y - 1] = ' ';//banh xe tren ben trai
    map[x + 1][y - 1] = ' ';//banh xe duoi ben trai
    map[x - 1][y + 1] = ' ';//banh xe tren ben phai
    map[x + 1][y + 1] = ' ';//banh xe duoi ben phai
}
void VeXeDua(int x , int y)
{
	map[x][y] = 'X'; // Than xe dua
	map[x][y - 1] = '|';// ben trai than xe
	map[x][y + 1] = '|';// ben phai than xe
    map[x - 1][y - 1] = '0';//banh xe tren ben trai
    map[x + 1][y - 1] = '0';//banh xe duoi ben trai
    map[x - 1][y + 1] = '0';//banh xe tren ben phai
    map[x + 1][y + 1] = '0';//banh xe duoi ben phai
    
}

void DiChuyenXe(int &x, int &y)
{
	if(GetAsyncKeyState(VK_LEFT))
		{
			if(y > 2 )
			{
				if(map[x][y] == '!' ||	map[x][y - 1] == '!' ||	map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!' )
				{
		 			exit(0);
				}
				// Xoa xe di
				map[x][y] = ' '; 
				map[x][y - 1] = ' ';
				map[x][y + 1] = ' ';
	  		    map[x - 1][y - 1] = ' ';
	    		map[x + 1][y - 1] = ' ';
	    		map[x - 1][y + 1] = ' ';
	    		map[x + 1][y + 1] = ' ';
	    		y--; //Giam cot xuong
	    		VeXeDua(x ,y);
	    		
	    	}
		}
		
	else if(GetAsyncKeyState(VK_RIGHT))
		{
			if(y < 27)
			{
				if(map[x][y] == '!' ||	map[x][y - 1] == '!' ||	map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!' )
				{
		 			exit(0);
				}
				// Xoa xe di
				map[x][y] = ' '; 
				map[x][y - 1] = ' ';
				map[x][y + 1] = ' ';
  		    	map[x - 1][y - 1] = ' ';
    			map[x + 1][y - 1] = ' ';
    			map[x - 1][y + 1] = ' ';
    			map[x + 1][y + 1] = ' ';
    			y++; //Tang cot len
    			VeXeDua(x ,y);
    			
    		}
		}
	else if(GetAsyncKeyState(VK_UP))
		{
			if(x>1)
			{
				if(map[x][y] == '!' ||	map[x][y - 1] == '!' ||	map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!' )
				{
		 			exit(0);
				}
				// Xoa xe di
				map[x][y] = ' '; 
				map[x][y - 1] = ' ';
				map[x][y + 1] = ' ';
	  		    map[x - 1][y - 1] = ' ';
	    		map[x + 1][y - 1] = ' ';
	    		map[x - 1][y + 1] = ' ';
	    		map[x + 1][y + 1] = ' ';
	    		x--; //Giam so dong
	    		VeXeDua(x ,y); // ve lai xe
	    	}
		}
	else if(GetAsyncKeyState(VK_DOWN))
		{
			if(x < 28)
			{
				if(map[x][y] == '!' ||	map[x][y - 1] == '!' ||	map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!' )
				{
		 			exit(0);
				}
				// Xoa xe di
				map[x][y] = ' '; 
				map[x][y - 1] = ' ';
				map[x][y + 1] = ' ';
	  		    map[x - 1][y - 1] = ' ';
	    		map[x + 1][y - 1] = ' ';
	    		map[x - 1][y + 1] = ' ';
	    		map[x + 1][y + 1] = ' ';
	    		x++; //tang do dong
	    		VeXeDua(x ,y); // ve lai xe
	    	}
		}
}

void VeDuongDua_1()
{
	for(int i = 0;i<30;i++)
	{
		map[i][0] = '|';
		map[i][29]= '|';
		if(i % 2 == 0)
		{
			map[i][15]= '|';
		}
		for(int j = 1;j<29 && j!= 14;j++)
		{
			map[i][j] = '  ';
		}
	}
}
void VeDuongDua_2()
{
	for(int i = 0;i<30;i++)
	{
		map[i][0] = '|';
		map[i][29]= '|';
		if(i % 2 != 0)
		{
			map[i][15]= '|';
		}
		for(int j = 1;j<29 && j!= 14;j++)
		{
			map[i][j] = '  ';
		}
	}
}
void DongXu(int x, int y)
{
	map[x][y] = '$';
}
void XoaDongXu(int x , int y)
{
	map[x][y] = ' ';
}
void InDuongDua()
{
	
	for(int i = 0;i<30;i++)
	{
		cout << "";
		for(int j = 0;j<30;j++)
		{
			if(j == 0 || j == 29)
			{
				textColor(191);
				map[i][j]= ' ';
				cout <<	map[i][j];
				textColor(7);	
			}
			else if(j == 15)
			{
				textColor(15);
				cout<< map[i][j];
				textColor(7);
				map[i][j] = ' ';
			}
			
			else if(map[i][j] == 'X' || map[i][j] == '|' || map[i][j] == '0')
			{
				textColor(14);
				cout << map[i][j];
				textColor(7);
			}
			
			else if(map[i][j] == '!')
			{
				map[i][j] = '!';
				textColor(200);
				cout<<map[i][j];
				textColor(7);			
			}
			
			else
			{
				cout << map[i][j];
			}
		}
		cout << endl;
	}
 
}
int main()
{	
	resizeConsole(800,600);
	int a = 0;
	int x = 20,y = 25;// toa do xe dua
	int x1 = 5,y1 = 10;// toa do xe chuong ngai vat dong
	int x2 = 5, y2 = 10;// toa do xe chuong ngai vat tinh
	int x3 = 2, y3 = 10;
	int x4 = 2, y4 = 10;
	while(true)
	{
		a++;
		if(a % 2 != 0)
		{
			VeDuongDua_1();
		}
		else
		{
			VeDuongDua_2();
		}
		//Random tung do cho xe chuong ngai vat 
		/*
		
		Random 1 so nguyen trong doan [a,b]:
		srand(time(0));// reset time
		int x = a + rand() % (b-a+1) // Cong thuc
		
		*/
		srand(time(0)); // Reset thoi gian
		y1 = 1 + rand() % 26; //random trong doan [2,27]
		y4 = 2 + rand() % 26;
		VeXeDua(x,y);
		
		VeXeChuongNgaiVat(x1,y1);// Xe dong
		
		VeXeChuongNgaiVat(x2,y2);// xe tinh
		
		XoaManHinh();
		
		DongXu(x3,y3);
		DongXu(x4,y4);
		
		InDuongDua();
		
		DiChuyenXe(x, y);
		
		Sleep(50);
		
		if(a >= 30)
		{
			a = 0;
		}
		// Kiem tra su dung do cua xe vs chuong ngai vat
		if(map[x][y] == '!' ||	map[x][y - 1] == '!' ||	map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!' )
		{
		 	return 0;
		}
		
		XoaDongXu(x3,y3);
		x3++;
		if(x3 == 31)
		{
			x3 = 4;
			y3 = 2 + rand() %26;
		}
		XoaDongXu(x4,y4);
		x4++;
		if(x4 == 31)
		{
			x4 = 2;
		}
		
		XoaXeChuongNgaiVat(x1,y1);
		x1++;//Tao hieu ung di chuyen cho chuong ngai vat dong
		if(x1 == 31)
		{
			x1 = 2;
		}
		
		XoaXeChuongNgaiVat(x2,y2);
		x2++;//Tao hieu ung di chuyen cho ngai vat tinh
		if(x2 == 31)
		{
			x2 = 5;
			y2 =  2 + rand() % 26;
		}
	}
	
	system("pause");
	return 0;
}
