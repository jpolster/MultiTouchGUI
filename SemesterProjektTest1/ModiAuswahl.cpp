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


// ModiAuswahl-Dialogfeld
//int rbModusV;
IMPLEMENT_DYNAMIC(ModiAuswahl, CDialog)



ModiAuswahl::ModiAuswahl(CWnd* pParent /*=NULL*/)
	: CDialog(modiWahl, pParent), rbModusV(0)
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
	std::cout << "okbutClicked" << std::endl;
	//CWnd::ShowWindow(SW_MINIMIZE);
	UpdateData(TRUE);  //Daten müssen vorher aktualisiert werden, falls man neuen RadioButton wählt
	if (rbModusV==0)
		MessageBeep(true);
	if (rbModusV == 1)
		MessageBeep(true);
	if (rbModusV == 2) {
		//window2 w;
		CSemesterProjektTest1Dlg w;
		w.DoModal();
	}
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
