// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "UpTime.h"
#include "ElpTime.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static UINT WM_TASKBARCREATED = ::RegisterWindowMessage("TaskbarCreated");
static UINT WM_UPTIME_CALLBACK = ::RegisterWindowMessage("UpTimeNotify");

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
    ON_REGISTERED_MESSAGE( WM_TASKBARCREATED, OnTaskbarCreated )
    ON_REGISTERED_MESSAGE( WM_UPTIME_CALLBACK, OnTaskbarNotify )

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	
	
}

CMainFrame::~CMainFrame()
{
	KillTimer(IDR_UPTIME);
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	// forward focus to the view window
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_Tray.Create(this, WM_UPTIME_CALLBACK, "", NULL, IDR_UPTIME);

	SetTBIcon();
	SetTBTip();
	SetTimer(IDR_UPTIME,3600000L,NULL);		// send WM_TIMER once an hour
	
	return 0;
}

LONG CMainFrame::OnTaskbarCreated(WPARAM wParam, LPARAM lParam)
{
	// Explorer has terminate & restarted
	m_Tray.HideIcon();
	m_Tray.ShowIcon();	// redisplay on new start menu
	SetTBIcon();
	SetTBTip();
	return(1);
}


void CMainFrame::SetTBIcon()
{
	ElpTime	et;
	UINT	days = et.m_Days > 9 ? 10 : et.m_Days;

	m_Tray.SetSmallIcon(days + IDI_ICON_0);
}

void CMainFrame::SetTBTip()
{
	ElpTime	et;

	m_Tray.SetTooltipText("Uptime:" + et.AsString());
}

LONG CMainFrame::OnTaskbarNotify(WPARAM uID, LPARAM lEvent)
{
	ASSERT(uID == IDR_UPTIME);

	SetTBIcon();
	SetTBTip();

	m_Tray.OnTrayNotification(uID, lEvent);
	return(1);
}


void CMainFrame::OnTimer(UINT nIDEvent) 
{
	SetTBIcon();	
	CFrameWnd::OnTimer(nIDEvent);
}
