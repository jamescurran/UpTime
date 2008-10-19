// ElpTime.h: interface for the ElpTime class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELPTIME_H__4154F63F_685D_11D2_9968_00AA0020E483__INCLUDED_)
#define AFX_ELPTIME_H__4154F63F_685D_11D2_9968_00AA0020E483__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ElpTime  
{
public:
	void GetTime();
	CString AsString();
	ElpTime();
	virtual ~ElpTime();

	int m_Days;
	int m_Hours;
	int m_Mins;
	int m_Secs;

};

#endif // !defined(AFX_ELPTIME_H__4154F63F_685D_11D2_9968_00AA0020E483__INCLUDED_)
