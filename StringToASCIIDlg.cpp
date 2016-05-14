// StringToASCIIDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StringToASCII.h"
#include "StringToASCIIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStringToASCIIDlg 对话框




CStringToASCIIDlg::CStringToASCIIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStringToASCIIDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nSumLimit = 0;
}

void CStringToASCIIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStringToASCIIDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT2, &CStringToASCIIDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON3, &CStringToASCIIDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &CStringToASCIIDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &CStringToASCIIDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &CStringToASCIIDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CStringToASCIIDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CStringToASCIIDlg 消息处理程序

BOOL CStringToASCIIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStringToASCIIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CStringToASCIIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CStringToASCIIDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}

void CStringToASCIIDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CStringToASCIIDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CStringToASCIIDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CStringToASCIIDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CStringToASCIIDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	char cBuf[2048] = {0};
	char cRes[2048] = {0};
	int nFlag = 0;
	int nCount = 0;
	int nInputCharSum = 0;
	/*先获取设定的字符上限个数，空为0\超过100个强制100*/
	char cLimit[20] = {0};
	int nSum = GetDlgItemText(IDC_EDIT1,cLimit,18);
	if( 0 == nSum )
	{
		nFlag = LIMITNULL;
	}
	else if( 2 < nSum )
	{
		nFlag = LIMITOVER;
	}
	else
	{
		nFlag = LIMITOK;
	}
	int nCharLimit = atoi( cLimit );

	memset( cRes, 0, sizeof(cRes) );
	/*状态分发处理*/
	switch (nFlag)
	{
	case LIMITNULL:
		nInputCharSum = GetDlgItemText(IDC_EDIT2,cBuf,LIMIT_INIT_SUM+2);
		if( LIMIT_INIT_SUM+1 == nInputCharSum )
		{
			sprintf( cRes, "More than %d char!",nInputCharSum-1 );
		}
		else if( 0 == nInputCharSum )
		{
			sprintf( cRes, "Input is NULL!");
		}
		else
		{
			for( nCount = 0; nCount < nInputCharSum; nCount++ )
			{
				sprintf( cRes+nCount*5, "0%03x ",cBuf[nCount] );
			}

		}
		break;

	case LIMITOVER:
		if( 0 >= nCharLimit )
		{
			sprintf( cRes, "Char Limit ERROR" );
		}
		else if( 100 < nCharLimit )
		{
			sprintf( cRes, "Char Limit(1-100)" );
		}
		else
		{
			nInputCharSum = GetDlgItemText(IDC_EDIT2,cBuf,nCharLimit+1);
			if( 0 == nInputCharSum )
			{
				sprintf( cRes, "Input is NULL!");
			}
			else
			{
				for( nCount = 0; nCount < nInputCharSum; nCount++ )
				{
					sprintf( cRes+nCount*5, "0%03x ",cBuf[nCount] );
				}
			}
		}
		break;

	case LIMITOK:
		if( 0 >= nCharLimit )
		{
			sprintf( cRes, "Char Limit ERROR" );
		}
		else
		{
			nInputCharSum = GetDlgItemText(IDC_EDIT2,cBuf,nCharLimit+1);
			if( 0 == nInputCharSum )
			{
				sprintf( cRes, "Input is NULL!");
			}
			else
			{
				for( nCount = 0; nCount < nInputCharSum; nCount++ )
				{
					sprintf( cRes+nCount*5, "0%03x ",cBuf[nCount] );
				}
			}
		}
		break;

	default:
		break;
	}
	
	SetDlgItemText(IDC_EDIT3,cRes);
}
