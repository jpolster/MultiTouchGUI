
// SemesterProjektTest1.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CSemesterProjektTest1App:
// Siehe SemesterProjektTest1.cpp für die Implementierung dieser Klasse
//

class CSemesterProjektTest1App : public CWinApp
{
public:
	CSemesterProjektTest1App();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CSemesterProjektTest1App theApp;
