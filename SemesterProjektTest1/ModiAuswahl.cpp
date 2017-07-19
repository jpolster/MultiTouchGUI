// ModiAuswahl.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "SemesterProjektTest1.h"
#include "ModiAuswahl.h"
#include "afxdialogex.h"
#include <iostream>
#include "Windows.h"
#include "window2.h"


#include <fstream>
#include <sstream> 
#include <string>


// ModiAuswahl-Dialogfeld
//int rbModusV;
IMPLEMENT_DYNAMIC(ModiAuswahl, CDialog)




ModiAuswahl::ModiAuswahl(CWnd* pParent /*=NULL*/)
	: CDialog(modiWahl, pParent), rbModusV(0)
{
	std::cout << "KonstruktorTest" << std::endl;
}

ModiAuswahl::~ModiAuswahl()
{
}
BOOL ModiAuswahl::OnInitDialog() {
	CDialog::OnInitDialog();
	//SetDlgItemText(, "Desired Text String");
	CButton* pButton2;
	//
	//CEdit* ediit;
	//ediit = (CEdit*)this->GetDlgItem(brGesichterED);

	//std::stringstream s;// string Stream erzeugen 
	//s << CSemesterProjektTest1App::gesicherBerechtigt;//
	//std::string ss = s.str;

	////LPTSTR lpsz = new TCHAR[ss.length + 1];
	//
	//

	//SetDlgItemTextW(brGesichterED, 7);
	pButton2 = (CButton*)this->GetDlgItem(rbOeffentlich);
	pButton2->SetFocus();
	pButton2->SetCheck(true);
	return true;
}

void ModiAuswahl::DoDataExchange(CDataExchange* pDX)
{	
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, rbOeffentlich, rbModusV);  // <<--- Note
	//SetDlgItemText(brGesichterED, "HI");
	//ModiAuswahl dlg;
	//rbModusV = 1; // or 0,1, or 2
	//int nResp = this->DoModal();
	//if (nResp == rbOeffentlich) {
	//	MessageBeep(true);
	//}
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
	
	
	
	if (rbModusV == 0) {
		//OnCancel();
		ShowWindow(SW_MINIMIZE);
	}
	while (rbModusV == 1) {

		ShowWindow(SW_MINIMIZE);
		/*while (gesichter <= CSemesterProjektTest1App::gesicherBerechtigt) {
			if (OpenClipboard())
			{
				HANDLE hData = GetClipboardData(CF_TEXT);

				char * buffer = (char*)GlobalLock(hData);
				fromClipboard = buffer;
				GlobalUnlock(hData);
				CloseClipboard();
				gesichter = atoi(buffer);
			}

		}*/

		while (gesichter <= CSemesterProjektTest1App::gesicherBerechtigt) {

			//std::fstream myfile("C:\\Users\\mail\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\temp.txt", std::ios_base::in);
			std::fstream myfile("C:\\Users\\Jessi\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\faces.txt", std::ios_base::in);
			//std::fstream myfile("C:\\Users\\HFU_P\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\faces.txt", std::ios_base::in);
			int a;
			/*while (myfile >> a)
			{
				gesichter = a;
			}*/

			myfile >> gesichter;
			if (GetAsyncKeyState(VK_F7) & 0x8000) {
				
				rbModusV = 0;
				tastegedrueckt = true;
				break;
			}

		}
		if (!tastegedrueckt) {
			PlaySound(L"C:\\Users\\Jessi\\Source\\Repos\\MultiTouch_Reich\\SemesterProjektTest1\\res\\hund.wav", NULL, SND_ASYNC);
			

			//PlaySound(L"C:\\Users\\HFU_P\\Source\\Repos\\MultiTouchGUI\\SemesterProjektTest1\\res\\hund.wav", NULL,SND_ASYNC);
			CSemesterProjektTest1App::gesicherBerechtigt++;

		}
	}
	if (rbModusV == 2) {
		//window2 w;
		//CSemesterProjektTest1Dlg w;
		//w.DoModal();
		ShowWindow(SW_MINIMIZE);
		/*int i = 0;
		while (i < 4) {
			i++;
			Sleep(1000);
		}*/
		while (gesichter <= CSemesterProjektTest1App::gesicherBerechtigt) {

			//std::fstream myfile("C:\\Users\\mail\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\temp.txt", std::ios_base::in);
			
			
			//std::fstream myfile("C:\\Users\\HFU_P\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\faces.txt", std::ios_base::in);
			//std::fstream myfile("C:\\Users\\mail\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\temp.txt", std::ios_base::in);
			std::fstream myfile("C:\\Users\\Jessi\\AppData\\Local\\Packages\\Microsoft.SDKSamples.FaceTracking.CPP_8wekyb3d8bbwe\\LocalState\\faces.txt", std::ios_base::in);//jessi
			int a;
			/*while (myfile >> a)
			{
				gesichter = a;
			}*/
			myfile >> gesichter;
			if (GetAsyncKeyState(VK_F7) & 0x8000) {
				
				rbModusV = 0;
				tastegedrueckt = true;
				break;
			}
		}
		if (!tastegedrueckt) {
			window2 w;
			w.DoModal();
		}
	}
}
