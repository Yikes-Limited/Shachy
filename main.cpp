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
Figura Szachownica[8][8];

// skazniki na kroli
Figura *krolB;
Figura *krolC;

// licznik do mata
int matLiczer;

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

/*
Nadpisuje koordynaty krola jezeli zostal on ruszony

Wykorzystuje:

xKoniec: pozycja na ktora gracz chce przeniesc pionka na osi x
yKoniec: pozycja na ktora gracz chce przeniesc pionka na osi y
Szachownica[][]: tabela z figurami(obiekty)

*/
void nadpiszKrol(int xKoniec, int yKoniec)
{
    if (Szachownica[xKoniec][yKoniec].kolor == 'b')
    {
        ::krolB->x = xKoniec + 1;
        ::krolB->y = yKoniec + 1;
    }
    else
    {
        ::krolC->x = xKoniec + 1;
        ::krolC->y = yKoniec + 1;
    }
}

/*
Sprawdza czy zachodzi szach

Wykorzystuje:

tempKrol: chwilowe przechowanie koordynatow krola bialego lub czarnego
xI: x figury przedstawiony w postaci indexowej
yI: y figury przedstawiony w postaci indexowej
Szachownica[][]: tabela z figurami(obiekty)

*/
bool szach(int matX, int matY)
{
    Figura *tempKrol;
    aktualnyRuch == 'b' ? tempKrol = ::krolC : tempKrol = ::krolB;

    if (matX != 100 && matY != 100)
    {
        tempKrol->x = matX;
        tempKrol->y = matY;
    }

    int xI = tempKrol->x - 1;
    int yI = tempKrol->y - 1;

    // sprawdzanie czy wieza bije krola
    // w dol
    for (int i = 1; i < 8; i++)
    {
        if (Szachownica[xI][yI + i].rodzaj != "puste" && yI + i < 8) // czy kolejne pole w dol jest puste i czy nie wychodzi poza szachownice
        {
            if (Szachownica[xI][yI + i].kolor != Szachownica[xI][yI].kolor) // czy kolor aktualnego krola jest rozny od koloru nastepnego pola
            {
                if (Szachownica[xI][yI + i].rodzaj == "wieza" || Szachownica[xI][yI + i].rodzaj == "dama") // czy ta figura to wieza lub dama
                    return true;
            }
            else
                break;
        }
        else if (yI + i > 7)
            break;
    }
    // w gore
    for (int i = 1; i < 8; i++)
    {
        if (Szachownica[xI][yI - i].rodzaj != "puste" && yI - i > -1) // czy kolejne pole w dol jest puste i czy nie wychodzi poza szachownice
        {
            if (Szachownica[xI][yI - i].kolor != Szachownica[xI][yI].kolor) // czy kolor aktualnego krola jest rozny od koloru nastepnego pola
            {
                if (Szachownica[xI][yI - i].rodzaj == "wieza" || Szachownica[xI][yI - i].rodzaj == "dama") // czy ta figura to wieza lub dama
                    return true;
            }
            else
                break;
        }
        else if (yI - i < 0)
            break;
    }
    // w prawo
    for (int i = 1; i < 8; i++)
    {
        if (Szachownica[xI + i][yI].rodzaj != "puste" && xI + i < 8) // czy kolejne pole w dol jest puste i czy nie wychodzi poza szachownice
        {
            if (Szachownica[xI + i][yI].kolor != Szachownica[xI][yI].kolor) // czy kolor aktualnego krola jest rozny od koloru nastepnego pola
            {
                if (Szachownica[xI + i][yI].rodzaj == "wieza" || Szachownica[xI + i][yI].rodzaj == "dama") // czy ta figura to wieza lub dama
                    return true;
            }
            else
                break;
        }
        else if (xI + i > 7)
            break;
    }
    // w lewo
    for (int i = 1; i < 8; i++)
    {
        if (Szachownica[xI - i][yI].rodzaj != "puste" && xI - i > -1) // czy kolejne pole w dol jest puste i czy nie wychodzi poza szachownice
        {
            if (Szachownica[xI - i][yI].kolor != Szachownica[xI][yI].kolor) // czy kolor aktualnego krola jest rozny od koloru nastepnego pola
            {
                if (Szachownica[xI - i][yI].rodzaj == "wieza" || Szachownica[xI - i][yI].rodzaj == "dama") // czy ta figura to wieza lub dama
                    return true;
            }
            else
                break;
        }
        else if (xI - i < 0)
            break;
    }

    // sprawdzanie czy goniec nie bije wiezy
    // prawy dolny
    for (int i = 1; i < 8; i++)
    {
        if (Szachownica[xI + i][yI + i].rodzaj != "puste" && (xI + i < 8 && yI + i < 8)) // czy kolejne pole w prawo w dol po skosie jest puste i czy nie wychodzi poza szachownice
        {
            if (Szachownica[xI + i][yI + i].kolor != Szachownica[xI][yI].kolor) // czy kolor aktualnego krola jest rozny od koloru nastepnego pola
            {
                if (Szachownica[xI + i][yI + i].rodzaj == "goniec" || Szachownica[xI + i][yI + i].rodzaj == "dama") // czy ta figura to goniec lub dama
                    return true;
            }
            else
                break;
        }
        else if (xI + i > 7 || yI + i > 7)
            break;
    }
    // lewy gorny
    for (int i = 1; i < 8; i++)
    {
        if (Szachownica[xI - i][yI - i].rodzaj != "puste" && (xI - i > -1 && yI - i > -1)) // czy kolejne pole w lewo w gore po skosie jest puste i czy nie wychodzi poza szachownice
        {
            if (Szachownica[xI - i][yI - i].kolor != Szachownica[xI][yI].kolor) // czy kolor aktualnego krola jest rozny od koloru nastepnego pola
            {
                if (Szachownica[xI - i][yI - i].rodzaj == "goniec" || Szachownica[xI - i][yI - i].rodzaj == "dama") // czy ta figura to goniec lub dama
                    return true;
            }
            else
                break;
        }
        else if (xI - i < 0 || yI - i < 0)
            break;
    }
    // prawy gorny
    for (int i = 1; i < 8; i++)
    {
        if (Szachownica[xI + i][yI - i].rodzaj != "puste" && (xI + i < 8 && yI - i > -1)) // czy kolejne pole w prawo w gore po skosie jest puste i czy nie wychodzi poza szachownice
        {
            if (Szachownica[xI + i][yI - i].kolor != Szachownica[xI][yI].kolor) // czy kolor aktualnego krola jest rozny od koloru nastepnego pola
            {
                if (Szachownica[xI + i][yI - i].rodzaj == "goniec" || Szachownica[xI + i][yI - i].rodzaj == "dama") // czy ta figura to goniec lub dama
                    return true;
            }
            else
                break;
        }
        else if (xI + i > 7 || yI - i < 0)
            break;
    }
    // lewy dolny
    for (int i = 1; i < 8; i++)
    {
        if (Szachownica[xI - i][yI + i].rodzaj != "puste" && (xI - i > -1 && yI + i < 8)) // czy kolejne pole w prawo w gore po skosie jest puste i czy nie wychodzi poza szachownice
        {
            if (Szachownica[xI - i][yI + i].kolor != Szachownica[xI][yI].kolor) // czy kolor aktualnego krola jest rozny od koloru nastepnego pola
            {
                if (Szachownica[xI - i][yI + i].rodzaj == "goniec" || Szachownica[xI - i][yI + i].rodzaj == "dama") // czy ta figura to goniec lub dama
                    return true;
            }
            else
                break;
        }
        else if (xI - i < 0 || yI + i > 7)
        {
            break;
        }
    }
    // skoczek
    // w gore
    if (yI - 2 > -1 && (xI + 1 < 8 && xI - 1 > -1)) // czy pole nie wychodzi poza szachownice
    {
        if (Szachownica[xI + 1][yI - 2].rodzaj != "puste") // czy na polu cos sie znajduje
        {
            if (Szachownica[xI + 1][yI - 2].kolor != Szachownica[xI][yI].kolor) // czy figura na tym polu ma inny kolor niz krol
                if (Szachownica[xI + 1][yI - 2].rodzaj == "skoczek")            // czy ta figura to skoczek
                    return true;
        }
        else if (Szachownica[xI - 1][yI - 2].rodzaj != "puste") // czy na polu cos sie znajduje
        {
            if (Szachownica[xI - 1][yI - 2].kolor != Szachownica[xI][yI].kolor) // czy figura na tym polu ma inny kolor niz krol
                if (Szachownica[xI - 1][yI - 2].rodzaj == "skoczek")            // czy ta figura to skoczek
                    return true;
        }
    }
    // w dol
    if (yI + 2 < 8 && (xI + 1 < 8 && xI - 1 > -1)) // czy pole nie wychodzi poza szachownice
    {
        if (Szachownica[xI + 1][yI + 2].rodzaj != "puste") // czy na polu cos sie znajduje
        {
            if (Szachownica[xI + 1][yI + 2].kolor != Szachownica[xI][yI].kolor) // czy figura na tym polu ma inny kolor niz krol
                if (Szachownica[xI + 1][yI + 2].rodzaj == "skoczek")            // czy ta figura to skoczek
                    return true;
        }
        else if (Szachownica[xI - 1][yI + 2].rodzaj != "puste") // czy na polu cos sie znajduje
        {
            if (Szachownica[xI - 1][yI + 2].kolor != Szachownica[xI][yI].kolor) // czy figura na tym polu ma inny kolor niz krol
                if (Szachownica[xI - 1][yI + 2].rodzaj == "skoczek")            // czy ta figura to skoczek
                    return true;
        }
    }
    // w lewo
    if (xI - 2 > -1 && (yI - 1 > -1 && yI + 1 < 8)) // czy pole nie wychodzi poza szachownice
    {
        if (Szachownica[xI - 2][yI - 1].rodzaj != "puste") // czy na polu cos sie znajduje
        {
            if (Szachownica[xI - 2][yI - 1].kolor != Szachownica[xI][yI].kolor) // czy figura na tym polu ma inny kolor niz krol
                if (Szachownica[xI - 2][yI - 1].rodzaj == "skoczek")            // czy ta figura to skoczek
                    return true;
        }
        else if (Szachownica[xI - 2][yI + 1].rodzaj != "puste") // czy na polu cos sie znajduje
        {
            if (Szachownica[xI - 2][yI + 1].kolor != Szachownica[xI][yI].kolor) // czy figura na tym polu ma inny kolor niz krol
                if (Szachownica[xI - 2][yI + 1].rodzaj == "skoczek")            // czy ta figura to skoczek
                    return true;
        }
    }
    // w prawo
    if (xI + 2 < 8 && (yI - 1 > -1 && yI + 1 < 8)) // czy pole nie wychodzi poza szachownice
    {
        if (Szachownica[xI + 2][yI - 1].rodzaj != "puste") // czy na polu cos sie znajduje
        {
            if (Szachownica[xI + 2][yI - 1].kolor != Szachownica[xI][yI].kolor) // czy figura na tym polu ma inny kolor niz krol
                if (Szachownica[xI + 2][yI - 1].rodzaj == "skoczek")            // czy ta figura to skoczek
                    return true;
        }
        else if (Szachownica[xI - 2][yI + 1].rodzaj != "puste") // czy na polu cos sie znajduje
        {
            if (Szachownica[xI - 2][yI + 1].kolor != Szachownica[xI][yI].kolor) // czy figura na tym polu ma inny kolor niz krol
                if (Szachownica[xI - 2][yI + 1].rodzaj == "skoczek")            // czy ta figura to skoczek
                    return true;
        }
    }

    // pionek

    int doPionka;
    aktualnyRuch == 'b' ? doPionka = -1 : doPionka = 1;

    if (yI - doPionka > -1) // sprawdza czy nastepne pole w gore lub w dol( w zaleznosci od koloru jaki sie ruszyl) nie wychodzi poza szachownice
    {
        if (xI - 1 > -1) // sprawdza czy nastepne pole w lewo nie wychodzi poza szachownice
        {
            if (Szachownica[xI - 1][yI - doPionka].rodzaj != "puste")
                if (Szachownica[xI - 1][yI - doPionka].kolor != Szachownica[xI][yI].kolor)
                    if (Szachownica[xI - 1][yI - doPionka].rodzaj == "pionek")
                        return true;
        }
        if (xI + 1 < 8) // sprawdza czy nastepne pole w prawo nie wychodzi poza szachownice
        {
            if (Szachownica[xI + 1][yI - doPionka].rodzaj != "puste")
                if (Szachownica[xI + 1][yI - doPionka].kolor != Szachownica[xI][yI].kolor)
                    if (Szachownica[xI + 1][yI - doPionka].rodzaj == "pionek")
                        return true;
        }
    }

    return false;
}

/*
Sprawdza czy zachodzi mat

Wykorzystuje:

tempKrol: chwilowe przechowanie koordynatow krola bialego lub czarnego
czySprawdzone

*/

bool mat()
{
    Figura *tempKrol;
    aktualnyRuch == 'b' ? tempKrol = ::krolC : tempKrol = ::krolB;

    // przeniesienie sprawdzacza o 1 pole w gore i 1 pole w lewo
    tempKrol->x -= 1;
    tempKrol->y -= 1;

    bool czySprawdzone = false;

    int i = 0;
    int matLiczer = 0;

    while (czySprawdzone == false)
    {
        int xDoWyslania = 100;
        int yDoWyslania = 100;

        switch (i)
        {
        case 0:
        case 1:
        case 2:
        {
            if ((tempKrol->x - 1 > -1 && tempKrol->x + 1 < 8) && tempKrol->y - 1 > 0)
            {
                xDoWyslania = tempKrol->x + i;
                yDoWyslania = tempKrol->y;
                if (szach(xDoWyslania, yDoWyslania) == true)
                    matLiczer++;
            }
            i++;
            break;
        }
        case 3:
        case 4:
        case 5:
        {
            if (matLiczer < 3)
                return false;
            else
            {
                if (tempKrol->x - 1 > -1 && tempKrol->x + 1 < 8)
                {
                    xDoWyslania = tempKrol->x + i;
                    yDoWyslania = tempKrol->y + 1;
                    if (szach(xDoWyslania, yDoWyslania) == true)
                    {
                        matLiczer++;
                    }
                }
                i++;
                break;
            }
        }
        case 6:
        case 7:
        case 8:
        {
            if (matLiczer < 6)
                return false;
            else
            {
                if ((tempKrol->x - 1 > -1 && tempKrol->x + 1 < 8) && tempKrol->y + 1 < 8)
                {
                    xDoWyslania = tempKrol->x + i;
                    yDoWyslania = tempKrol->y + 2;
                    if (szach(xDoWyslania, yDoWyslania) == true)
                    {
                        matLiczer++;
                    }
                }
                i++;
                break;
            }
        }

        case 9:
        {
            if (matLiczer == 9)
                return true;
            else
                return false;
        }
        }
    }
}

void rusz(Figura Fig, int xKoniec, int yKoniec)
{
    if (Szachownica[xKoniec][yKoniec].rodzaj == "puste")
        swap(Szachownica[Fig.x - 1][Fig.y - 1], Szachownica[xKoniec][yKoniec]);
    else
    {
        Figura *Puste = new Figura();
        Szachownica[xKoniec][yKoniec].przypisz(Puste);
        swap(Szachownica[Fig.x - 1][Fig.y - 1], Szachownica[xKoniec][yKoniec]);
    }
    Szachownica[xKoniec][yKoniec].x = xKoniec + 1;
    Szachownica[xKoniec][yKoniec].y = yKoniec + 1;

    bool bezblednie = false;
    short wybor;

    if (Fig.rodzaj == "pionek" && (Szachownica[xKoniec][yKoniec].y == 1 || Szachownica[xKoniec][yKoniec].y == 8)) // sprawdza czy ruch zostal wykonany pionkiem i czy przemiescil sie on na gorny lub dolny kraniec mapy
    {
        while (bezblednie == false)
        {
            cout << "PROMOCJA PIONKA" << endl;
            cout << "1. Dama" << endl;
            cout << "2. Wieza" << endl;
            cout << "3. Goniec" << endl;
            cout << "4. Skoczek" << endl;

            cin >> wybor;

            switch (wybor)
            {
            case 1:
            {
                Szachownica[xKoniec][yKoniec].rodzaj = "dama";
                Fig.kolor == 'b' ? Szachownica[xKoniec][yKoniec].symbol = 'D' : Szachownica[xKoniec][yKoniec].symbol = 'd';
                bezblednie = true;
                break;
            }
            case 2:
            {
                Szachownica[xKoniec][yKoniec].rodzaj = "wieza";
                Fig.kolor == 'b' ? Szachownica[xKoniec][yKoniec].symbol = 'W' : Szachownica[xKoniec][yKoniec].symbol = 'w';
                bezblednie = true;
                break;
            }
            case 3:
            {
                Szachownica[xKoniec][yKoniec].rodzaj = "goniec";
                Fig.kolor == 'b' ? Szachownica[xKoniec][yKoniec].symbol = 'G' : Szachownica[xKoniec][yKoniec].symbol = 'g';
                bezblednie = true;
                break;
            }
            case 4:
            {
                Szachownica[xKoniec][yKoniec].rodzaj = "skoczek";
                Fig.kolor == 'b' ? Szachownica[xKoniec][yKoniec].symbol = 'S' : Szachownica[xKoniec][yKoniec].symbol = 's';
                bezblednie = true;
                break;
            }
            default:
            {
                cout << "Wpisano liczbe z poza zakresu (1-4)" << endl;
                break;
            }
            }
        }
    }
    if (Szachownica[xKoniec][yKoniec].rodzaj == "krol") // sprawdza czy krol zmienil swoje polozenie
        nadpiszKrol(xKoniec, yKoniec);
    if (szach(100, 100) == true)
    {
        cout << "Zachodzi szach" << endl;
        mat();
        cout << " mat" << endl;
    }
}

/*
Sprawdza czy figura poprzedzajaca miejsce koncowe pionka jest biala czy czarna i zbija ja podstawiajac pod nia pusta figure

kolor: zmienna sluzaca do okreslenia czy figura jest biala czy czarna

Wykorzystuje:

Fig: aktualna figura ktora chce ruszyc gracz
xKoniec: pozycja na ktora gracz chce przeniesc pionka na osi x
yKoniec: pozycja na ktora gracz chce przeniesc pionka na osi y
Szachownica[][]: tabela z figurami(obiekty)

*/
void ruszFrancuz(Figura Fig, int xKoniec, int yKoniec)
{
    int kolor = 0;
    Fig.kolor == 'b' ? kolor += 1 : kolor -= 1;

    Figura *Puste = new Figura();
    Szachownica[xKoniec][yKoniec + kolor].przypisz(Puste);
    swap(Szachownica[Fig.x - 1][Fig.y - 1], Szachownica[xKoniec][yKoniec]);

    Szachownica[xKoniec][yKoniec].y = yKoniec + 1;
    (Fig.x - 1) - xKoniec == 1 ? Szachownica[xKoniec][yKoniec].x = xKoniec - 1 : Szachownica[xKoniec][yKoniec].x = xKoniec + 1;
}

/*
Zamienia miejsce krola i wiezy

xK: rzeczywista pozycja na planszy w osi x w postaci liczby
yK: rzeczywista pozycja na planszy w osi y w postaci liczby

Wykorzystuje:

Fig: aktualna figura ktora chce ruszyc gracz
xKoniec: pozycja na ktora gracz chce przeniesc krola na osi x
yKoniec: pozycja na ktora gracz chce przeniesc krola na osi y
idzieWPrawo: kierunek w ktorym gracz chce przeniesc krola
Szachownica[][]: tabela z figurami(obiekty)

*/

void ruchRoszada(Figura Fig, int xKoniec, int yKoniec, bool idzieWPrawo)
{
    int xK = xKoniec + 1;
    int yK = yKoniec + 1;

    swap(Szachownica[Fig.x - 1][Fig.y - 1], Szachownica[xK - 1][yK - 1]);
    Fig.x = xK;

    if (idzieWPrawo == true)
    {
        swap(Szachownica[xKoniec + 1][yKoniec], Szachownica[xKoniec - 1][yKoniec]);
        Szachownica[xKoniec - 1][yKoniec].x = xK - 1;
    }
    else
    {
        swap(Szachownica[xKoniec - 2][yKoniec], Szachownica[xKoniec + 1][yKoniec]);
        Szachownica[xKoniec + 1][yKoniec].x = xK + 1;
    }
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
                // francuz
                else if (FigStart.y == 4 && Szachownica[xKoniec][yKoniec + 1].rodzaj == "pionek" && FigKoniec.rodzaj == "puste") // czy pionek jest na miejscu poprzedzajacym koncowa pozycje pionka ("pod nim") i czy miejsce na ktore gracz chce sie przesunac jest wolne
                {
                    ruszFrancuz(FigStart, xKoniec, yKoniec);
                    return 0;
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
                // francuz
                else if (FigStart.y == 5 && Szachownica[xKoniec][yKoniec - 1].rodzaj == "pionek" && FigKoniec.rodzaj == "puste") // czy pionek jest na miejscu poprzedzajacym koncowa pozycje pionka ("pod nim") i czy miejsce na ktore gracz chce sie przesunac jest wolne
                {
                    ruszFrancuz(FigStart, xKoniec, yKoniec);
                    return 0;
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
                        if (Szachownica[xStart][i].rodzaj != "puste")
                        {
                            nieMozliwy = true;
                            break;
                        }
                }
                else
                {
                    for (int i = yStart + 1; i < yKoniec; i++)
                        if (Szachownica[xStart][i].rodzaj != "puste")
                        {
                            nieMozliwy = true;
                            break;
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
                            if (Szachownica[i][yStart].rodzaj != "puste")
                            {
                                nieMozliwy = true;
                                break;
                            }
                    }
                    else
                    {
                        for (int i = xStart + 1; i < xKoniec; i++)
                            if (Szachownica[i][yStart].rodzaj != "puste")
                            {
                                nieMozliwy = true;
                                break;
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
                        if (Szachownica[xStart][i].rodzaj != "puste")
                        {
                            nieMozliwy = true;
                            break;
                        }
                }
                else
                {
                    for (int i = yStart + 1; i < yKoniec; i++)
                        if (Szachownica[xStart][i].rodzaj != "puste")
                        {
                            nieMozliwy = true;
                            break;
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
                            if (Szachownica[i][yStart].rodzaj != "puste")
                            {
                                nieMozliwy = true;
                                break;
                            }
                    }
                    else
                    {
                        for (int i = xStart + 1; i < xKoniec; i++)
                            if (Szachownica[i][yStart].rodzaj != "puste")
                            {
                                nieMozliwy = true;
                                break;
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
            // roszada
            if (abs(xStart - xKoniec) == 2 && (yK == 8 || yK == 1)) // sprawdza czy krol rusza sie w prawo lub lewo o 2 pola co ma prowadzic do roszady oraz czy figury znajduja sie na samym dole szachownicy
            {
                bool idzieWPrawo = false; // zmienna do okreslenia kierunku ruchu gracza

                if (xKoniec > xStart) // idzie w prawo
                {
                    idzieWPrawo = true;
                    if (Szachownica[xStart + 1][yStart].rodzaj == "puste" && Szachownica[xStart + 2][yStart].rodzaj == "puste" && Szachownica[xStart + 3][yStart].rodzaj == "wieza") // sprawdza czy pola miedzy krolem a prawa wieza sa puste i czy wieza stoi w narozniku
                    {
                        ruchRoszada(FigStart, xKoniec, yKoniec, idzieWPrawo);
                        aktualnyRuch == 'b' ? aktualnyRuch = 'c' : aktualnyRuch = 'b';
                        return 0;
                    }
                    else
                    {
                        cout << "Ruch niemozliwy. Nie mozna zrobic roszady" << endl;
                        return 1;
                    }
                }
                else if (xKoniec < xStart) // idzie w lewo
                {
                    if (Szachownica[xStart - 1][yStart].rodzaj == "puste" && Szachownica[xStart - 2][yStart].rodzaj == "puste" && Szachownica[xStart - 3][yStart].rodzaj == "puste" && Szachownica[xStart - 4][yStart].rodzaj == "wieza") // sprawdza czy pola miedzy krolem a prawa wieza sa puste i czy wieza stoi w narozniku
                    {
                        ruchRoszada(FigStart, xKoniec, yKoniec, idzieWPrawo);
                        aktualnyRuch == 'b' ? aktualnyRuch = 'c' : aktualnyRuch = 'b';
                        return 0;
                    }
                    else
                    {
                        cout << "Ruch niemozliwy. Nie mozna zrobic roszady" << endl;
                        return 1;
                    }
                }
            }

            cout << "Ruch niemozliwy. Krol moze ruszyc sie tylko o 1 pole." << endl;
            return 1;
        }
    }
    rusz(FigStart, xKoniec, yKoniec);
    aktualnyRuch == 'b' ? aktualnyRuch = 'c' : aktualnyRuch = 'b';
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
    cout << "       CZARNE" << endl
         << endl;
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
         << "   A B C D E F G H " << endl
         << endl;
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
Figura *KrolC = new Figura(5, 1, "krol", 'k', 'c', true, false);
Figura *DamaC = new Figura(4, 1, "dama", 'd', 'c', true, false);
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
Figura *KrolB = new Figura(5, 8, "krol", 'K', 'b', true, false);
Figura *DamaB = new Figura(4, 8, "dama", 'D', 'b', true, false);
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
    // przypisanie kroli do zmiennych globalnych
    ::krolB = KrolB;
    ::krolC = KrolC;

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

// todo
//  szach mat