#include <iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<chrono>
#include<thread>
#include<Windows.h>
#include<vector>
using namespace std;
//s³upki
int t[2][10];
int taba[100], tabb[100], tabc[100];
//instrukcje
char tab[10000][100];
//czyszczenie ekranu
void gotoxy(int x, int y)
{
	COORD cord;
	cord.X = x;
	cord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}
class ConsoleOutputInfo
{
public:
	std::vector < int > zapisaneWiersze;
	void onOut()
	{
		static HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO CSBinfo;
		GetConsoleScreenBufferInfo(hOut, &CSBinfo);
		int y = CSBinfo.dwCursorPosition.Y;
		zapisaneWiersze.push_back(y);
	}
	void clear()
	{
		for (unsigned int i = 0; i < zapisaneWiersze.size(); i++)
		{
			gotoxy(0, zapisaneWiersze[i]); printf("\33[2K\r");
		}
	}
};




//kolorowanie klocków
void koloruj(int numofcol)

{
	HANDLE qwer;
	qwer = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(qwer, numofcol);

}

//wyœwietlanie
void wy()
{
	ConsoleOutputInfo info;
	info.onOut();
	cout << endl << endl << endl << endl << endl << endl << endl;

		for (int i = 1; i <= 10; i++)
		{

			if (t[0][i] == 0)cout << "                    |         ";
			if (t[0][i] == 1) { cout << "                    "; koloruj(12); cout << char(178) << "         "; koloruj(7); }
			if (t[0][i] == 2) { cout << "                   "; koloruj(11); cout << char(178) << char(178) << char(178) << "        "; koloruj(7); }
			if (t[0][i] == 3) { cout << "                  "; koloruj(10); cout << char(178) << char(178) << char(178) << char(178) << char(178) << "       "; koloruj(7); }
			if (t[0][i] == 4) { cout << "                 "; koloruj(9); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "      "; koloruj(7); }
			if (t[0][i] == 5) { cout << "                "; koloruj(8); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "     "; koloruj(7); }
			if (t[0][i] == 6) { cout << "               "; koloruj(13); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "    "; koloruj(7); }
			if (t[0][i] == 7) { cout << "              "; koloruj(14); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "   "; koloruj(7); }
			if (t[0][i] == 8) { cout << "             "; koloruj(15); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "  "; koloruj(7); }
			if (t[0][i] == 9) { cout << "            "; koloruj(17); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178); koloruj(7); cout << " "; koloruj(7); }
			if (t[0][i] == 10) { cout << "           "; koloruj(6); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178); koloruj(7); }
			/////////////////////////////////////////////////////////////////////////////
			if (t[1][i] == 0)cout << "         |         ";
			if (t[1][i] == 1) { cout << "         "; koloruj(12); cout << char(178) << "         "; koloruj(7); }
			if (t[1][i] == 2) { cout << "        "; koloruj(11); cout << char(178) << char(178) << char(178) << "        "; koloruj(7); }
			if (t[1][i] == 3) { cout << "       "; koloruj(10); cout << char(178) << char(178) << char(178) << char(178) << char(178) << "       "; koloruj(7); }
			if (t[1][i] == 4) { cout << "      "; koloruj(9); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "      "; koloruj(7); }
			if (t[1][i] == 5) { cout << "     "; koloruj(8); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "     "; koloruj(7); }
			if (t[1][i] == 6) { cout << "    "; koloruj(13); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "    "; koloruj(7); }
			if (t[1][i] == 7) { cout << "   "; koloruj(14); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "   "; koloruj(7); }
			if (t[1][i] == 8) { cout << "  "; koloruj(15); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "  "; koloruj(7); }
			if (t[1][i] == 9) { cout << " "; koloruj(17); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178); koloruj(7); cout << " "; koloruj(7); }
			if (t[1][i] == 10) { koloruj(6); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178); koloruj(7); }

			/////////////////////////////////////////////////////////////////////////////
			if (t[2][i] == 0)cout << "         |         ";
			if (t[2][i] == 1) { cout << "         "; koloruj(12); cout << char(178) << "         "; koloruj(7); }
			if (t[2][i] == 2) { cout << "        "; koloruj(11); cout << char(178) << char(178) << char(178) << "        "; koloruj(7); }
			if (t[2][i] == 3) { cout << "       "; koloruj(10); cout << char(178) << char(178) << char(178) << char(178) << char(178) << "       "; koloruj(7); }
			if (t[2][i] == 4) { cout << "      "; koloruj(9); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "      "; koloruj(7); }
			if (t[2][i] == 5) { cout << "     "; koloruj(8); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "     "; koloruj(7); }
			if (t[2][i] == 6) { cout << "    "; koloruj(13); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "    "; koloruj(7); }
			if (t[2][i] == 7) { cout << "   "; koloruj(14); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "   "; koloruj(7); }
			if (t[2][i] == 8) { cout << "  "; koloruj(15); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << "  "; koloruj(7); }
			if (t[2][i] == 9) { cout << " "; koloruj(17); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178); koloruj(7); cout << " "; koloruj(7); }
			if (t[2][i] == 10) { koloruj(6); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178); koloruj(7); }


			cout << endl;

	}
	cout << "--------------------" << char(193) << "------------------" << char(193) << "------------------" << char(193) << "---------------------\n";

	info.clear();
}
//algorytm
int l = 0;
void hanoi(int n, char A, char B, char C)
{
	// przek³ada n kr¹¿ków z A korzystaj¹c z B na C
	if (n > 0)
	{
		//zapisywanie instrukcji
		hanoi(n - 1, A, C, B);
		tab[l][1] = A;
		tab[l][2] = C;
		l++;
		hanoi(n - 1, B, A, C);
	}
}
int p;
int takeoff(char x)
{
	int p = 0,w;
	if (x == 'A')
		w = 0;
	if (x == 'B')
		w = 1;
	if (x == 'C')
		w = 2;

	for (int i = 1; i <= 10; i++)
	{
		if ((i == 1) && (t[w][i] != 0))
		{
			p = t[w][i];
			t[w][i] = 0;
			break;
		}
		else if (t[w][i] != 0)
		{
			swap(t[w][i], t[w][i - 1]);
			i--;
			i--;

			wy();
			Sleep(10);
		}
	}
	return p;
}

void puton(char x)
{
	int w;
	if (x == 'A')
		w = 0;
	if (x == 'B')
		w = 1;
	if (x == 'C')
		w = 2;

	t[w][1] = p;

	wy();
	Sleep(10);
	for (int i = 2; i <= 10; i++)
	{
		if (t[w][i] == 0)  swap(t[w][i], t[w][i - 1]);
		else break;

		wy();
		Sleep(10);
	}
}

int main()
{
	int m = 11;
	while ((m > 10) || (m<1))
	{
		cout << "Type the number of discs(1-10) ";
		cin >> m;
	}
	//nadawanie pocz¹tkowej pozycji kr¹¿ków
	int y = m;
	for (int i = 10; i > 10 - m; i--)
	{
		t[0][i] = y;
		y--;
	}
	wy();
	Sleep(2000);
	hanoi(m, 'A', 'B', 'C');
	wy();
	//czytanie instrukcji
	for (int u = 0; u < l; u++)
	{
		p = 0;
		//zdejmowanie kr¹¿ka z odpowiedniego s³upka
		p= takeoff(tab[u][1]);
		//zak³adanie kr¹¿ka na odpowiedni s³upek
		puton(tab[u][2]);
	}

	wy();
	Sleep(100);
	system("pause");
	return 0;
}