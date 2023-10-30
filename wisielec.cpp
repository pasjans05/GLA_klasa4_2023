﻿// wisielec.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    srand(time(0));
    int slw = rand();
    vector<string> slowa = { "topinambur", "analfabetyzm", "surykatka", "babuk", "luki oooo", "python", "ryszard kozak", "kapibara", "lipa", "drabina", "cake", "big troll" };
    string slowo = slowa[slw % slowa.size()];
    //string slowo = "luki oooo";
    string slowo1;
    for (int i = 0; i < slowo.length(); i++)
    {
        if (slowo[i] == ' ') slowo1 += ' ';
        else slowo1 += "_";
    }
    int proby = 11;
    cout << "Witaj w grze \"wisielec\". Masz " << proby << " prob blednych odpowiedzi. Zgadnij slowo: \n" << slowo1 << endl;
    string inproba;
    char proba;
    bool spr;
    bool sprr;
    bool sprrr;
    vector<char> prby;
    while (proby > 0)
    {
        spr = false;
        sprr = true;
        sprrr = false;
        cout << "Podaj znak: "; cin >> inproba;
        if (inproba.length() > 1) sprr = false;
        proba = inproba[0];
        if (int(proba) > 122 || int(proba) < 97)
        {
            if (int(proba) > 64 && int(proba) < 91)
            {
                proba = tolower(proba);
            }
            else sprr = false;
        }
        if (sprr == true)
        {
            for (int i = 0; i < slowo.length(); i++)
            {
                if (slowo[i] == proba)
                {
                    spr = true;
                    slowo1[i] = proba;
                }
            }
            if (spr == true) cout << "Ta litera znajduje sie w slowie. \n" << slowo1 << "\nPozostalo prob blednych odpowiedzi: " << proby << endl;
            else
            {
                for (int i = 0; i < prby.size(); i++) if (prby[i] == proba) spr = true;
                if (spr == true) cout << "Juz podano ten znak. Nic sie nie zmienilo. Caly czas nie ma go w slowie " << slowo << ".\n";
                else
                {
                    proby--;
                    prby.push_back(proba);
                    cout << "Tej litery nie ma w slowie " << slowo << endl << slowo1 << "\nPozostalo prob blednych odpowiedzi: " << proby << endl;
                }
            }
            if (slowo1 == slowo) break;
        }
        cout << endl << endl << "--------------------------------------------------------------------------" << endl << endl;
    }
    if (proby > 0) cout << "Gratulacje, slowo to " << slowo << endl;
    else cout << "GG, przegrales. Slowo to " << slowo << endl;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
