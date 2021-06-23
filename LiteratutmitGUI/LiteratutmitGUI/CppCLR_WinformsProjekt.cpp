// CppCLR_WinformsProjekt.cpp: Hauptprojektdatei.

// #include "stdafx.h"
// using namespace System;

//int main(array<System::String ^> ^args)
//{
//    Console::WriteLine(L"Hello World");
//    return 0;
//}
#include "stdafx.h"
#include "Form1.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "Datentypen.h"
#include "Funktionen.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
// int main(array<String^>^ args) { // Kann Fehler nach 'using namespace std;' verursachen
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLR_WinformsProjekt::Form1()); // "CppCLR_WinformsProjekt" noch anpassen

	//Variablendeklarationen
	int auswahl, c = 0, a = 1;
	char buf[10];
	Daten Datensatz[1000];

	system("title Literaturverwaltung by Roman Rohlfs");		//Fensterüberschrift ändern
	nullen(Datensatz);											//Datensätze mit Nullen füllen
	einlesen(Datensatz);										//Gespeicherte Datensätze von HD einlesen

	//Programm läuft so lange, bis es im Menü beendet wird
	while (a == 1) {
		auswahl = -1;
		//Auswahl abfragen
		do {
			clear();
			menu();
			printf("\nAuswahl: ");
			fgets(buf, 10, stdin);			//Auswahl abfragen
			sscanf(buf, "%i", &auswahl);	//Auswahl als Zahl umwandeln
			//Fehlerhafte Eingabe abfangen
			if ((auswahl < 1) || (auswahl > 8)) {
				printf("\nFehlerhafte Eingabe!");
				getchar();
			}
		} while ((auswahl < 1) || (auswahl > 8));

		//Menüauswahl
		switch (auswahl) {
			//Datensätze eingeben
		case 1: {
			eingabe(Datensatz);
			break;
		}
				//Datensätze ausgeben
		case 2: {
			ausgabe(Datensatz);
			break;
		}
				//Datensätze durchsuchen
		case 3: {
			suchen(Datensatz);
			break;
		}
				//Datensätze speichern
		case 4: {
			speichern(Datensatz);
			break;
		}
				//Datensatz ändern
		case 5: {
			aendern(Datensatz);
			break;
		}
				//Datensatz löschen
		case 6: {
			loeschen(Datensatz);
			break;
		}
				//Datensätze als BibTex exportieren
		case 7: {
			exportbib(Datensatz);
			break;
		}
				//Programm beenden
		case 8: {
			do {
				clear();
				printf("Programm beenden.\n\n");
				printf("Aenderungen speichern?\n\nJa..... 1\nNein... 2\n\nAuswahl: ");
				fgets(buf, 10, stdin);			//Auswahl abfragen
				sscanf(buf, "%i", &c);			//Auswahl als Zahl umwandeln
				if ((c < 1) || (c > 2)) {
					printf("\nFehlerhafte Eingabe!");	//Fehlerhafte Eingabe abfangen
					getchar();
				}
			} while ((c < 1) || (c > 2));
			if (c == 1) {
				speichern(Datensatz);			//Datensätze speichern
			}
			a = 0;
			break;
		}
		}
	}
	return 0;
}