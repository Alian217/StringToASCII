// StringToASCIIDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StringToASCII.h"
#include "StringToASCIIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStringToASCIIDlg �Ի���




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


// CStringToASCIIDlg ��Ϣ�������

BOOL CStringToASCIIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CStringToASCIIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CStringToASCIIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CStringToASCIIDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

}

void CStringToASCIIDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CStringToASCIIDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CStringToASCIIDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CStringToASCIIDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CStringToASCIIDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char cBuf[2048] = {0};
	char cRes[2048] = {0};
	int nFlag = 0;
	int nCount = 0;
	int nInputCharSum = 0;
	/*�Ȼ�ȡ�趨���ַ����޸�������Ϊ0\����100��ǿ��100*/
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
	/*״̬�ַ�����*/
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
