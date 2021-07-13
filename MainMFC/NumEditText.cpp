#include <string>
#include <limits>
#include "pch.h"
#include "NumEditText.h"

using namespace std;

constexpr double MAX = DBL_MAX;
constexpr double MIN = -MAX;

BEGIN_MESSAGE_MAP(NumEditText, CEdit)
	ON_WM_CHAR()
	ON_WM_CREATE()
END_MESSAGE_MAP()

NumEditText::NumEditText()
{
	maxValue = MAX;
	minValue = MIN;
}

NumEditText::~NumEditText()
{
}

void NumEditText::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString str;
	GetWindowText(str);

	int nSource, nDestination;
	GetSel(nSource, nDestination);

	// ��֤С�������ֻ�ܳ���һ��
	if (nChar == '.')
	{
		//��ԭ�����ַ������Ѿ���һ��С����,�򲻽�С��������,��֤�����ֻ������һ��С����
		if (str.Find('.') != -1)
		{
		}
		// ������������С����
		else
		{
			CEdit::OnChar(nChar, nRepCnt, nFlags);
		}
	}
	// ��֤����ֻ�ܳ���һ��,����ֻ�ܳ����ڵ�һ���ַ�
	else if (nChar == '-')
	{
		// ��û�������κ��ַ���
		if (str.IsEmpty())
		{
			CEdit::OnChar(nChar, nRepCnt, nFlags);
		}
		else
		{
			// ��ʱѡ����ȫ��������
			if (nSource == 0 && nDestination == str.GetLength() || nSource == 0 && nDestination == 0 && str.Left(1).Compare(L"-"))
			{
				CEdit::OnChar(nChar, nRepCnt, nFlags);
			}
		}
	}
	// ����С����͸���,��������������,Backspace,Delete
	else if ((nChar >= '0' && nChar <= '9') || (nChar == 0x08) || (nChar == 0x10))
	{
		//����ǵ�һ���ַ������룬������'-'������
		if (nSource == 0 && nDestination == 0 && !str.IsEmpty() && str.Find('-') != -1)
		{
		}
		else
		{
			CEdit::OnChar(nChar, nRepCnt, nFlags);
		}

	}
	// �����ļ�,������Ӧ
	else
	{
	}

	GetWindowText(str);
	if (_ttof(str) > maxValue)
	{
		CString msg;
		msg.Format(L"�������ֵ���ܴ��� %0.1f", maxValue);
		AfxMessageBox(msg);
		SetWindowText(L"");
	}
	else if (_ttof(str) < minValue)
	{
		CString msg;
		msg.Format(L"�������ֵ����С�� %0.1f", minValue);
		AfxMessageBox(msg);
		SetWindowText(L"");
	}

}

void NumEditText::setRange(double min, double max)
{
	maxValue = max;
	minValue = min;
}

double NumEditText::GetDoubleData()
{
	CString str;
	GetWindowText(str);
	if (str.GetLength() <= 0)
	{
		return 0.0;
	}
	return  _ttof(str);
}
