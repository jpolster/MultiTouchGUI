// ModiAuswahl.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "SemesterProjektTest1.h"
#include "ModiAuswahl.h"
#include "afxdialogex.h"
#include <iostream>
#include "Windows.h"
#include "window2.h"
#include "SemesterProjektTest1Dlg.h"
#include "HalbSicherDlg.h"


// ModiAuswahl-Dialogfeld
//int rbModusV;
IMPLEMENT_DYNAMIC(ModiAuswahl, CDialog)

int gesichterBerechtigt = 1;

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
	
	int gesichter=0;
	std::cout << "okbutClicked" << std::endl;
	//CWnd::ShowWindow(SW_MINIMIZE);
	UpdateData(TRUE);  //Daten müssen vorher aktualisiert werden, falls man neuen RadioButton wählt
	char * buffer = NULL;
	//open the clipboard
	CString fromClipboard(L"EMPTY");
	
	if (OpenClipboard())
	{
		HANDLE hData = GetClipboardData(CF_TEXT);
		
		char * buffer = (char*)GlobalLock(hData);
		fromClipboard = buffer;
		GlobalUnlock(hData);
		CloseClipboard();
		gesichter = atoi(buffer);
		
	}
	
	
	if (rbModusV == 0) {
		//OnCancel();
		ShowWindow(SW_MINIMIZE);
	}
	if (rbModusV == 1) {
		//HalbSicherDlg hs;
		//hs.DoModal();

		ShowWindow(SW_MINIMIZE);
		int i = 0;
		while (i < 4) {
			i++;
			Sleep(1000);
		}
		const int C = 261;
		const int Cis = 277;
		const int D = 293;
		const int Dis = 311;
		const int E = 329;
		const int F = 349;
		const int Fis = 369;
		const int G = 391;
		const int Gis = 415;
		const int A = 440;
		const int Ais = 466;
		const int H = 493;
		const int Takt = 1700;

		Beep(E * 2, Takt / 4);
		Beep(H * 1, Takt / 8);
		Beep(C * 2, Takt / 8);
		Beep(D * 2, Takt / 4);
		Beep(C * 2, Takt / 8);
		Beep(H * 1, Takt / 8);
		Beep(A * 1, Takt / 4);
		Beep(A * 1, Takt / 8);
		Beep(C * 2, Takt / 8);
		Beep(E * 2, Takt / 8);
		Beep(E * 2, Takt / 8);
		Beep(D * 2, Takt / 8);
		Beep(C * 2, Takt / 8);
		Beep(H * 1, Takt / 2.5);
		Beep(C * 2, Takt / 8);
		Beep(D * 2, Takt / 4);
		Beep(E * 2, Takt / 4);
		Beep(C * 2, Takt / 4);
		Beep(A * 1, Takt / 4);
		Beep(A * 1, Takt / 4);
		Sleep(Takt / (8 / 3));
		Beep(D * 2, Takt / 3.25);
		Beep(F * 2, Takt / 8);
		Beep(A * 2, Takt / 8);
		Beep(A * 2, Takt / 8);
		Beep(G * 2, Takt / 8);
		Beep(F * 2, Takt / 8);
		Beep(E * 2, Takt / 3);
		Beep(C * 2, Takt / 8);
		Beep(E * 2, Takt / 8);
		Beep(E * 2, Takt / 8);
		Beep(D * 2, Takt / 8);
		Beep(C * 2, Takt / 8);
		Beep(H * 1, Takt / 4);
		Beep(H * 1, Takt / 8);
		Beep(C * 2, Takt / 8);
		Beep(D * 2, Takt / 4);
		Beep(E * 2, Takt / 4);
		Beep(C * 2, Takt / 4);
		Beep(A * 1, Takt / 4);
		Beep(A * 1, Takt / 4);

		
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
		while (gesichter <= gesichterBerechtigt) {

		}
		window2 w;
		w.DoModal();
	}
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.


	//Test Kommentar Jessi
}
