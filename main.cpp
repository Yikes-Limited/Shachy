#include <iostream>
#include <algorithm>
#include <windows.h>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;
class Figura
{
public:
    int x; // A - H
    int y; // 1 - 8
    string rodzaj;
    char symbol;
    char kolor; // B/C
    bool tyl;
    bool zbita;

    Figura(int x = 10, int y = 8, string rodzaj = "puste", char symbol = '-', char kolor = 'x', bool tyl = true, bool zbita = false)
    {
        this->x = x;
        this->y = y;
        this->rodzaj = rodzaj;
        this->symbol = symbol;
        this->kolor = kolor;
        this->tyl = tyl;
        this->zbita = zbita;
    }

    void przypisz(Figura *Figura)
    {
        this->x = Figura->x;
        this->y = Figura->y;
        this->rodzaj = Figura->rodzaj;
        this->symbol = Figura->symbol;
        this->kolor = Figura->kolor;
        this->tyl = Figura->tyl;
        this->zbita = Figura->zbita;
    }
};
Figura Szachownica[9][8];
// kto ma ruch
char aktualnyRuch = 'b';
void autodestrukcja()
{
    system("cls");

    cout << "Naruszono integralnosc plikow" << endl;
    cout << "Autodestrukcja za 5..." << endl;
    Sleep(1000);
    cout << "4.." << endl;
    Sleep(1000);
    cout << "3.." << endl;
    Sleep(1000);
    cout << "2.." << endl;
    Sleep(1000);
    cout << "1.." << endl;
    Sleep(1000);
    // system("C:\\WINDOWS\\System32\\shutdown -s -t 0");
}

void rusz(Figura Fig, int xKoniec, int yKoniec)
{
    if (Szachownica[xKoniec][yKoniec].rodzaj == "puste")
    {
        swap(Szachownica[Fig.x - 1][Fig.y - 1], Szachownica[xKoniec][yKoniec]);
    }
    else
    {
        Figura *Puste = new Figura();
        Szachownica[xKoniec][yKoniec].przypisz(Puste);
        swap(Szachownica[Fig.x - 1][Fig.y - 1], Szachownica[xKoniec][yKoniec]);
    }
    Szachownica[xKoniec][yKoniec].x = xKoniec + 1;
    Szachownica[xKoniec][yKoniec].y = yKoniec + 1;
}

int walidacja(int xStart, int yStart, int xKoniec, int yKoniec)
{
    Figura FigStart = Szachownica[xStart][yStart];
    Figura FigKoniec = Szachownica[xKoniec][yKoniec];
    // do obliczen
    int xK = xKoniec + 1;
    int yK = yKoniec + 1;
    if (FigStart.kolor != aktualnyRuch)
    {
        cout << "Mozesz przemiescic tylko swoje figury" << endl;
        return 1;
    }
    if (FigStart.kolor == FigKoniec.kolor)
    {
        cout << "Nie mozesz zbic wlasnej figury" << endl;
        return 1;
    }

    if (FigStart.rodzaj == "pionek")
    {
        if (FigStart.kolor == 'b')
        {
            // czy ruch jest mozliwy
            if (FigStart.y - yK == 1 || (FigStart.y == 7 && FigStart.y - yK == 2 && FigStart.x == xK))
            {
                if (FigStart.x == xK)
                {
                    // ruch o 1 do przodu
                    if (Szachownica[xStart][yStart - 1].rodzaj != "puste")
                    {
                        cout << "Ruch niemozliwy. Miejsce nie jest puste" << endl;
                        return 1;
                    }
                    // ruch o 2 do przodu ze startowej pozycji
                    if (FigStart.y == 7 && FigStart.y - yK == 2 && Szachownica[xStart][yStart - 2].rodzaj != "puste")
                    {
                        cout << "Ruch niemozliwy. Miejsce nie jest puste" << endl;
                        return 1;
                    }
                }
                // bicie
                else if (FigStart.x - xK == 1 || xK - FigStart.x == 1)
                {
                    if (FigKoniec.kolor != 'c')
                    {
                        cout << "Nie mozesz ruszyc sie na bok nie bijac figury przeciwnika" << endl;
                        return 1;
                    }
                }
                // ruch nie jest mozliwy
                else
                {
                    cout << "Ruch niemozliwy. Nie mozesz sie ruszyc o tyle pol w bok" << endl;
                    return 1;
                }
            }
            else
            {
                cout << "Ruch niemozliwy. Nie mozesz sie ruszyc o tyle pol." << endl;
                return 1;
            }
        }
        else
        {
            // czy ruch jest mozliwy
            if (yK - FigStart.y == 1 || (FigStart.y == 2 && yK - FigStart.y == 2 && FigStart.x == xK))
            {
                if (FigStart.x == xK)
                {
                    // ruch o 1 do przodu
                    if (Szachownica[xStart][yStart + 1].rodzaj != "puste")
                    {
                        cout << "Ruch niemozliwy. Miejsce nie jest puste" << endl;
                        return 1;
                    }
                    // ruch o 2 do przodu ze startowej pozycji
                    if (FigStart.y == 7 && yK - FigStart.y == 2 && Szachownica[xStart][yStart + 2].rodzaj != "puste")
                    {
                        cout << "Ruch niemozliwy. Miejsce nie jest puste" << endl;
                        return 1;
                    }
                }
                // bicie
                else if (FigStart.x - xK == 1 || xK - FigStart.x == 1)
                {
                    if (FigKoniec.kolor != 'b')
                    {
                        cout << "Nie mozesz ruszyc sie na bok nie bijac figury przeciwnika" << endl;
                        return 1;
                    }
                }
                // ruch nie jest mozliwy
                else
                {
                    cout << "Ruch niemozliwy. Nie mozesz sie ruszyc o tyle pol w bok" << endl;
                    return 1;
                }
            }
            else
            {
                cout << "Ruch niemozliwy. Nie mozesz sie ruszyc o tyle pol." << endl;
                return 1;
            }
        }
    }
    else if (FigStart.rodzaj == "wieza")
    {
        if (FigStart.y != yK && FigStart.x != xK)
        {
            cout << "Ruch niemozliwy." << endl;
            return 1;
        }
        else
        {
            bool nieMozliwy = false;
            if (FigStart.y != yK)
            {
                if (FigStart.y - yK > 0)
                {
                    for (int i = yStart - 1; i > yKoniec; i--)
                    {
                        if (Szachownica[xStart][i].rodzaj != "puste")
                        {
                            nieMozliwy = true;
                            break;
                        }
                    }
                }
                else
                {
                    for (int i = yStart + 1; i < yKoniec; i++)
                    {
                        if (Szachownica[xStart][i].rodzaj != "puste")
                        {
                            nieMozliwy = true;
                            break;
                        }
                    }
                }
            }
            else
            {
                if (FigStart.x != xK)
                {
                    if (FigStart.x - xK > 0)
                    {
                        for (int i = xStart - 1; i > xKoniec; i--)
                        {
                            if (Szachownica[i][yStart].rodzaj != "puste")
                            {
                                nieMozliwy = true;
                                break;
                            }
                        }
                    }
                    else
                    {
                        for (int i = xStart + 1; i < xKoniec; i++)
                        {
                            if (Szachownica[i][yStart].rodzaj != "puste")
                            {
                                nieMozliwy = true;
                                break;
                            }
                        }
                    }
                }
            }
            if (nieMozliwy)
            {
                cout << "Ruch niemozliwy." << endl;
                return 1;
            }
        }
    }
    else if (FigStart.rodzaj == "goniec")
    {
        bool nieMozliwy = true;
        if (FigStart.x - xK > 0)
        {
            if (FigStart.y - yK > 0)
            {
                // czy ruch jest w ogole mozliwy
                for (int x = xStart - 1, y = yStart - 1; x >= xKoniec && y >= yKoniec; x--, y--)
                    if (x == xKoniec && y == yKoniec)
                        nieMozliwy = false;

                // czy po drodze nie ma innych figur
                for (int x = xStart - 1, y = yStart - 1; x > xKoniec && y > yKoniec; x--, y--)
                    if (Szachownica[x][y].rodzaj != "puste")
                    {
                        nieMozliwy = true;
                        break;
                    }
            }
            else
            {
                for (int x = xStart - 1, y = yStart + 1; x >= xKoniec && y <= yKoniec; x--, y++)
                    if (x == xKoniec && y == yKoniec)
                        nieMozliwy = false;

                for (int x = xStart - 1, y = yStart + 1; x > xKoniec && y < yKoniec; x--, y++)
                    if (Szachownica[x][y].rodzaj != "puste")
                    {
                        nieMozliwy = true;
                        break;
                    }
            }
        }
        else
        {
            if (FigStart.y - yK > 0)
            {
                for (int x = xStart + 1, y = yStart - 1; x <= xKoniec && y >= yKoniec; x++, y--)
                    if (x == xKoniec && y == yKoniec)
                        nieMozliwy = false;

                for (int x = xStart + 1, y = yStart - 1; x < xKoniec && y > yKoniec; x++, y--)
                    if (Szachownica[x][y].rodzaj != "puste")
                    {
                        nieMozliwy = true;
                        break;
                    }
            }
            else
            {
                for (int x = xStart + 1, y = yStart + 1; x <= xKoniec && y <= yKoniec; x++, y++)
                    if (x == xKoniec && y == yKoniec)
                        nieMozliwy = false;

                for (int x = xStart + 1, y = yStart + 1; x < xKoniec && y < yKoniec; x++, y++)
                    if (Szachownica[x][y].rodzaj != "puste")
                    {
                        nieMozliwy = true;
                        break;
                    }
            }
        }
        if (nieMozliwy)
        {
            cout << "Ruch niemozliwy." << endl;
            return 1;
        }
    }
    else if (FigStart.rodzaj == "dama")
    {
        if (FigStart.y != yK && FigStart.x != xK)
        {
            bool nieMozliwy = true;
            if (FigStart.x - xK > 0)
            {
                if (FigStart.y - yK > 0)
                {
                    // czy ruch jest w ogole mozliwy
                    for (int x = xStart - 1, y = yStart - 1; x >= xKoniec && y >= yKoniec; x--, y--)
                        if (x == xKoniec && y == yKoniec)
                            nieMozliwy = false;

                    // czy po drodze nie ma innych figur
                    for (int x = xStart - 1, y = yStart - 1; x > xKoniec && y > yKoniec; x--, y--)
                        if (Szachownica[x][y].rodzaj != "puste")
                        {
                            nieMozliwy = true;
                            break;
                        }
                }
                else
                {
                    for (int x = xStart - 1, y = yStart + 1; x >= xKoniec && y <= yKoniec; x--, y++)
                        if (x == xKoniec && y == yKoniec)
                            nieMozliwy = false;

                    for (int x = xStart - 1, y = yStart + 1; x > xKoniec && y < yKoniec; x--, y++)
                        if (Szachownica[x][y].rodzaj != "puste")
                        {
                            nieMozliwy = true;
                            break;
                        }
                }
            }
            else
            {
                if (FigStart.y - yK > 0)
                {
                    for (int x = xStart + 1, y = yStart - 1; x <= xKoniec && y >= yKoniec; x++, y--)
                        if (x == xKoniec && y == yKoniec)
                            nieMozliwy = false;

                    for (int x = xStart + 1, y = yStart - 1; x < xKoniec && y > yKoniec; x++, y--)
                        if (Szachownica[x][y].rodzaj != "puste")
                        {
                            nieMozliwy = true;
                            break;
                        }
                }
                else
                {
                    for (int x = xStart + 1, y = yStart + 1; x <= xKoniec && y <= yKoniec; x++, y++)
                        if (x == xKoniec && y == yKoniec)
                            nieMozliwy = false;

                    for (int x = xStart + 1, y = yStart + 1; x < xKoniec && y < yKoniec; x++, y++)
                        if (Szachownica[x][y].rodzaj != "puste")
                        {
                            nieMozliwy = true;
                            break;
                        }
                }
            }
            if (nieMozliwy)
            {
                cout << "Ruch niemozliwy." << endl;
                return 1;
            }
        }
        else
        {
            bool nieMozliwy = false;
            if (FigStart.y != yK)
            {
                if (FigStart.y - yK > 0)
                {
                    for (int i = yStart - 1; i > yKoniec; i--)
                    {
                        if (Szachownica[xStart][i].rodzaj != "puste")
                        {
                            nieMozliwy = true;
                            break;
                        }
                    }
                }
                else
                {
                    for (int i = yStart + 1; i < yKoniec; i++)
                    {
                        if (Szachownica[xStart][i].rodzaj != "puste")
                        {
                            nieMozliwy = true;
                            break;
                        }
                    }
                }
            }
            else
            {
                if (FigStart.x != xK)
                {
                    if (FigStart.x - xK > 0)
                    {
                        for (int i = xStart - 1; i > xKoniec; i--)
                        {
                            if (Szachownica[i][yStart].rodzaj != "puste")
                            {
                                nieMozliwy = true;
                                break;
                            }
                        }
                    }
                    else
                    {
                        for (int i = xStart + 1; i < xKoniec; i++)
                        {
                            if (Szachownica[i][yStart].rodzaj != "puste")
                            {
                                nieMozliwy = true;
                                break;
                            }
                        }
                    }
                }
            }
            if (nieMozliwy)
            {
                cout << "Ruch niemozliwy." << endl;
                return 1;
            }
        }
    }
    else if (FigStart.rodzaj == "skoczek")
    {
        if ((FigStart.x + xK == 2 && FigStart.y + yK == 1) || (FigStart.x + xK == 1 && FigStart.y + yK == 2) || (abs(FigStart.x - xK) == 1 && FigStart.y + yK == 2) || (abs(FigStart.x - xK) == 2 && FigStart.y + yK == 1) || (abs(FigStart.x - xK) == 1 && abs(FigStart.y - yK) == 2) || (abs(FigStart.x - xK) == 2 && abs(FigStart.y - yK) == 1) || (FigStart.x + xK == 1 && abs(FigStart.y - yK) == 2) || (FigStart.x + xK == 2 && abs(FigStart.y - yK) == 1))
        {
        }
        else
        {
            cout << "Ruch niemozliwy. Nie mozesz ruszyc sie w ten sposob skoczkiem" << endl;
            return 1;
        }
    }
    else if (FigStart.rodzaj == "krol")
    {
        if (abs(FigStart.x - xK) > 1 || abs(FigStart.y - yK) > 1)
        {
            cout << "Ruch niemozliwy. Krol moze ruszyc sie tylko o 1 pole." << endl;
            return 1;
        }
    }
    rusz(FigStart, xKoniec, yKoniec);
    if (aktualnyRuch == 'b')
        aktualnyRuch = 'c';
    else
        aktualnyRuch = 'b';
    return 0;
}

int input()
{
    string wejscie;
    // litery
    char startL, koniecL;
    // cyfry
    int startC, koniecC;
    cout << "Wybierz ruch (Format F1F4)" << endl;
    cin >> wejscie;
    if (wejscie.length() != 4)
    {
        cout << "Nie jest to poprawny format. Przykladowy ruch C2E4" << endl;
        return 1;
    }
    try
    {
        startL = tolower(wejscie[0]);
        startC = stoi(wejscie.substr(1, 2));
        koniecL = tolower(wejscie[2]);
        koniecC = stoi(wejscie.substr(3, 4));
    }
    catch (...)
    {
        cout << "Nie jest to poprawny format. Przykladowy ruch C2E4" << endl;
        return 1;
    }
    if (startC > 8 || startC < 1 || koniecC > 8 || koniecC < 1)
    {
        cout << "Liczba nie moze byc wieksza niz 8 ani mniejsza niz 1" << endl;
        return 1;
    }
    if (startL > 104 || startL < 97 || koniecL > 104 || koniecL < 97)
    {
        cout << "Nie jest to poprawna litera. Mozna wybrac od A-H" << endl;
        return 1;
    }
    int x = (int)startL - 97;
    int y = (int)koniecL - 97;
    if (walidacja(x, startC - 1, y, koniecC - 1))
    {
        return 1;
    }
    return 0;
}

void rysuj()
{
    cout << endl;
    cout << "       CZARNE" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 8; j++)
        {
            cout << "|" << Szachownica[j][i].symbol;
        }
        cout << "|" << endl;
    }
    cout << endl
         << "   A B C D E F G H " << endl;
    cout << "        BIALE" << endl;
    if (aktualnyRuch == 'b')
        cout << "Aktualny ruch biale" << endl;
    else
        cout << "Aktualny ruch czarne" << endl;
}

// czarne
Figura *WiezaLC = new Figura(1, 1, "wieza", 'w', 'c', true, false);
Figura *SkoczekLC = new Figura(2, 1, "skoczek", 's', 'c', true, false);
Figura *GoniecLC = new Figura(3, 1, "goniec", 'g', 'c', true, false);
Figura *KrolC = new Figura(4, 1, "krol", 'k', 'c', true, false);
Figura *DamaC = new Figura(5, 1, "dama", 'd', 'c', true, false);
Figura *GoniecPC = new Figura(6, 1, "goniec", 'g', 'c', true, false);
Figura *SkoczekPC = new Figura(7, 1, "skoczek", 's', 'c', true, false);
Figura *WiezaPC = new Figura(8, 1, "wieza", 'w', 'c', true, false);

// czarne piony

Figura *Pionek1C = new Figura(1, 2, "pionek", 'p', 'c', true, false);
Figura *Pionek2C = new Figura(2, 2, "pionek", 'p', 'c', true, false);
Figura *Pionek3C = new Figura(3, 2, "pionek", 'p', 'c', true, false);
Figura *Pionek4C = new Figura(4, 2, "pionek", 'p', 'c', true, false);
Figura *Pionek5C = new Figura(5, 2, "pionek", 'p', 'c', true, false);
Figura *Pionek6C = new Figura(6, 2, "pionek", 'p', 'c', true, false);
Figura *Pionek7C = new Figura(7, 2, "pionek", 'p', 'c', true, false);
Figura *Pionek8C = new Figura(8, 2, "pionek", 'p', 'c', true, false);

// biale
Figura *WiezaLB = new Figura(1, 8, "wieza", 'W', 'b', true, false);
Figura *SkoczekLB = new Figura(2, 8, "skoczek", 'S', 'b', true, false);
Figura *GoniecLB = new Figura(3, 8, "goniec", 'G', 'b', true, false);
Figura *KrolB = new Figura(4, 8, "krol", 'K', 'b', true, false);
Figura *DamaB = new Figura(5, 8, "dama", 'D', 'b', true, false);
Figura *GoniecPB = new Figura(6, 8, "goniec", 'G', 'b', true, false);
Figura *SkoczekPB = new Figura(7, 8, "skoczek", 'S', 'b', true, false);
Figura *WiezaPB = new Figura(8, 8, "wieza", 'W', 'b', true, false);

// biale piony

Figura *Pionek1B = new Figura(1, 7, "pionek", 'P', 'b', true, false);
Figura *Pionek2B = new Figura(2, 7, "pionek", 'P', 'b', true, false);
Figura *Pionek3B = new Figura(3, 7, "pionek", 'P', 'b', true, false);
Figura *Pionek4B = new Figura(4, 7, "pionek", 'P', 'b', true, false);
Figura *Pionek5B = new Figura(5, 7, "pionek", 'P', 'b', true, false);
Figura *Pionek6B = new Figura(6, 7, "pionek", 'P', 'b', true, false);
Figura *Pionek7B = new Figura(7, 7, "pionek", 'P', 'b', true, false);
Figura *Pionek8B = new Figura(8, 7, "pionek", 'P', 'b', true, false);

Figura *Figury[32]{WiezaLC, SkoczekLC, GoniecLC, KrolC, DamaC, GoniecPC, SkoczekPC, WiezaPC, WiezaLB, SkoczekLB, SkoczekPB, GoniecLB, KrolB, DamaB, GoniecPB, WiezaPB, Pionek1B, Pionek2B, Pionek3B, Pionek4B, Pionek5B, Pionek6B, Pionek7B, Pionek8B, Pionek1C, Pionek2C, Pionek3C, Pionek4C, Pionek5C, Pionek6C, Pionek7C, Pionek8C};

int main()
{
    for (int i = 0; i < 32; i++)
    {
        Figura *Temp = Figury[i];
        Szachownica[Temp->x - 1][Temp->y - 1].przypisz(Temp);
    }
    while (true)
    {
        rysuj();
        while (true)
        {

            int kontrolna = input();
            if (kontrolna == 0)
                break;
        }
    }
}

// Y      CZARNE
// 1 |w|s|g|k|d|g|s|w|
// 2 |p|p|p|p|p|p|p|p|
// 3 |-|-|-|-|-|-|-|-|
// 4 |-|-|-|-|-|-|-|-|
// 5 |-|-|-|-|-|-|-|-|
// 6 |-|-|-|-|-|-|-|-|
// 7 |P|P|P|P|P|P|P|P|
// 8 |W|S|G|K|D|G|S|W|
//    A B C D E F G H
//    1 2 3 4 5 6 7 8 X
//         BIAŁE