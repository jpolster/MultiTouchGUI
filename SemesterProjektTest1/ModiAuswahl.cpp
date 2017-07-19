// ModiAuswahl.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "SemesterProjektTest1.h"
#include "ModiAuswahl.h"
#include "afxdialogex.h"
#include <iostream>
#include "Windows.h"
#include "Overlay.h"


#include <fstream>
#include <sstream> 
#include <string>


// ModiAuswahl-Dialogfeld
IMPLEMENT_DYNAMIC(ModiAuswahl, CDialog)




ModiAuswahl::ModiAuswahl(CWnd* pParent /*=NULL*/)
	: CDialog(modiWahl, pParent), rbModusV(0)  //Modus zunächst auf "Öffentlich"
{
	
}

ModiAuswahl::~ModiAuswahl()
{
}
BOOL ModiAuswahl::OnInitDialog() {
	CDialog::OnInitDialog();

	CButton* pButton2;
	pButton2 = (CButton*)this->GetDlgItem(rbOeffentlich);  
	pButton2->SetFocus();
	pButton2->SetCheck(true);
	return true;
}

void ModiAuswahl::DoDataExchange(CDataExchange* pDX)
{	
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, rbOeffentlich, rbModusV);  // <<--- Note
	
}


BEGIN_MESSAGE_MAP(ModiAuswahl, CDialog)
	ON_BN_CLICKED(buOk, &ModiAuswahl::OnBnClickedbuok)
END_MESSAGE_MAP()


// ModiAuswahl-Meldungshandler


void ModiAuswahl::OnBnClickedbuok()
{
	bool tastegedrueckt = false;
	int gesichter = 0;

	char * buffer = NULL;
	//open the clipboard
	CString fromClipboard(L"EMPTY");
	
	
	std::cout << "okbutClicked" << std::endl;
	//CWnd::ShowWindow(SW_MINIMIZE);
	
	UpdateData(TRUE);  //Daten müssen vorher aktualisiert werden, falls man neuen RadioButton wählt
	
	
	
	if (rbModusV == 0) {  //Öffentlicher Modus
		//OnCancel();
		ShowWindow(SW_MINIMIZE);
	}
	while (rbModusV == 1) { //Halbsicherer Modus

		ShowWindow(SW_MINIMIZE);
		

		// Anzahl der Gesichter wird ständig aus einer Datei ausgelesen
		// solange sie unter der Anzahl der berechtigten Gesichter ist, passiert nichts
		// ansonsten wird eine wav-Datei abgespielt (hier Hundebellen), um den User zu warnen

		while (gesichter <= CSemesterProjektTest1App::gesicherBerechtigt) {
			// jenachdem, auf welchem Rechner das läuft, muss man den Dateipfad der Datei, in der die Anzahl der Gesichter
			// ausgelesen werden, anpassen


			//std::fstream myfile("C:\\Users\\mail\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\temp.txt", std::ios_base::in);
			std::fstream myfile("C:\\Users\\Jessi\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\faces.txt", std::ios_base::in);
			//std::fstream myfile("C:\\Users\\HFU_P\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\faces.txt", std::ios_base::in);
			int a;
			

			myfile >> gesichter;  //auslesen aus Datei
			if (GetAsyncKeyState(VK_F7) & 0x8000) {  // mit "F7" kommt man wieder  zur Modusauswahl
				
				rbModusV = 0;
				tastegedrueckt = true;
				break;
			}

		}
		if (!tastegedrueckt) {
			// jenachdem, auf welchem Rechner das läuft, muss man den Dateipfad der wav-Datei anpassen

			PlaySound(L"C:\\Users\\Jessi\\Source\\Repos\\MultiTouch_Reich\\SemesterProjektTest1\\res\\hund.wav", NULL, SND_ASYNC);
			//PlaySound(L"C:\\Users\\HFU_P\\Source\\Repos\\MultiTouchGUI\\SemesterProjektTest1\\res\\hund.wav", NULL,SND_ASYNC);
			
			CSemesterProjektTest1App::gesicherBerechtigt++; // nach dem "Warnsignal" wird die Anzahl der berechtigten Gesichter automatisch hochgezählt

		}
	}
	if (rbModusV == 2) { //Privater Modus
		ShowWindow(SW_MINIMIZE);

		// Anzahl der Gesichter wird ständig aus einer Datei ausgelesen
		// solange sie unter der Anzahl der berechtigten Gesichter ist, passiert nichts
		// ansonsten sperrt ein Overlay den Bildschirm

		while (gesichter <= CSemesterProjektTest1App::gesicherBerechtigt) {

			// jenachdem, auf welchem Rechner das läuft, muss man den Dateipfad der Datei, in der die Anzahl der Gesichter
			// ausgelesen werden, anpassen

			//std::fstream myfile("C:\\Users\\HFU_P\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\faces.txt", std::ios_base::in);
			//std::fstream myfile("C:\\Users\\mail\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\temp.txt", std::ios_base::in);
			std::fstream myfile("C:\\Users\\Jessi\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\faces.txt", std::ios_base::in);//jessi
			int a;
			
			myfile >> gesichter;  //auslesen der Datei
			if (GetAsyncKeyState(VK_F7) & 0x8000) {  // mit "F7" kommt man wieder  zur Modusauswahl
				
				rbModusV = 0;
				tastegedrueckt = true;
				break;
			}
		}
		if (!tastegedrueckt) {
			// das Overlay wird geöffnet
			Overlay w;
			w.DoModal();
		}
	}
}
