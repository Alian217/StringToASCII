// StringToASCII.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CStringToASCIIApp:
// �йش����ʵ�֣������ StringToASCII.cpp
//

class CStringToASCIIApp : public CWinApp
{
public:
	CStringToASCIIApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CStringToASCIIApp theApp;