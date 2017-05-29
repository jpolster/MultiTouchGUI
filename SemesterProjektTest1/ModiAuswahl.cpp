// ModiAuswahl.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "SemesterProjektTest1.h"
#include "ModiAuswahl.h"
#include "afxdialogex.h"
#include <iostream>


// ModiAuswahl-Dialogfeld
//int rbModusV;
IMPLEMENT_DYNAMIC(ModiAuswahl, CDialog)



ModiAuswahl::ModiAuswahl(CWnd* pParent /*=NULL*/)
	: CDialog(modiWahl, pParent)
{

}

ModiAuswahl::~ModiAuswahl()
{
}
BOOL ModiAuswahl::OnInitDialog() {
	/*CDialog::OnInitDialog();
	CButton* pButton2;
	pButton2 = (CButton*)this->GetDlgItem(rbOeffentlich);
	pButton2->SetFocus();
	pButton2->SetCheck(true);*/
	//(CButton*)this->GetDlgItem(rbOeffentlich)->SetCheck(true);

	return true;
}

void ModiAuswahl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, rgModus, rbModusV);  // <<--- Note
	//ModiAuswahl dlg;
	rbModusV = 1; // or 0,1, or 2
	int nResp = this->DoModal();
	if (nResp == rbOeffentlich) {
		MessageBeep(true);
	}
}


BEGIN_MESSAGE_MAP(ModiAuswahl, CDialog)
	ON_BN_CLICKED(buOk, &ModiAuswahl::OnBnClickedbuok)
END_MESSAGE_MAP()


// ModiAuswahl-Meldungshandler


void ModiAuswahl::OnBnClickedbuok()
{
	std::cout << "okbutClicked" << std::endl;
	CWnd::ShowWindow(SW_MINIMIZE);
	MessageBeep(true);
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
