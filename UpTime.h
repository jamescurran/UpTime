// UpTime.h : main header file for the UPTIME application
//

#if !defined(AFX_UPTIME_H__4154F633_685D_11D2_9968_00AA0020E483__INCLUDED_)
#define AFX_UPTIME_H__4154F633_685D_11D2_9968_00AA0020E483__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


/////////////////////////////////////////////////////////////////////////////
// CUpTimeApp:
// See UpTime.cpp for the implementation of this class
//

class CUpTimeApp : public CWinApp
{
public:
	CUpTimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpTimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CUpTimeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#define UPTIME_ID		1492

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPTIME_H__4154F633_685D_11D2_9968_00AA0020E483__INCLUDED_)
