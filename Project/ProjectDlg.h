
// ProjectDlg.h: 헤더 파일
//

#pragma once


// CProjectDlg 대화 상자
class CProjectDlg : public CDialogEx
{
// 생성입니다.
public:
	CProjectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void DrawMap(CDC* pDC);								//Drawing Map
	void DrawFood(CDC* pDC);								//Drawing Food
	void DrawSnake(CDC* pDC);								//Drawing Snake
	void DrawEatSnake(CDC* pDC);						//Drawing Snake that eats food
	void Deleteprev(CDC* pDC, int x1, int y1, int x2, int y2);									//Delete trail of snake
	void Deletefood(CDC* pDC);								//Delete food
	int size;																		//Size of map
	int SnakeSize;															//Size of Snake
	int Drawtimes;														//Count the OnPaint function executed
	int tail_x;																	//Coordinates of tail before move
	int tail_y;
	int body_x;																//Coordinates of body that front of tail before move
	int body_y;
	bool OneButton;														//Variable for get only one input
};
