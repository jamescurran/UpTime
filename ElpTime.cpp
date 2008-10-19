// ElpTime.cpp: implementation of the ElpTime class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UpTime.h"
#include "ElpTime.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ElpTime::ElpTime()
{
	GetTime();
}

ElpTime::~ElpTime()
{

}

void ElpTime::GetTime()
{
	DWORD	ticks = GetTickCount();
	DWORD	secs  = ticks/1000;

	m_Days  =  secs/86400;
	secs   -= (m_Days*86400);
	m_Hours =  secs/3600;
	secs   -= (m_Hours*3600);
	m_Mins  =  secs/60;
	secs   -= (m_Mins*60);
	m_Secs  = secs;
}

CString ElpTime::AsString()
{
	CString	str1;
	if (m_Days > 0)
		if (m_Days == 1)
			str1 = "1 Day, ";
		else
			str1.Format("%d Days, ", m_Days);

	CString	str2;
	if (m_Hours > 0)
		if (m_Hours == 1)
			str2 = "1 hour, ";
		else
			str2.Format("%d hours, ", m_Hours);

	CString str3;
	str3.Format("%d minutes, %d seconds", m_Mins, m_Secs);
	
	return (str1+str2+str3);

}

