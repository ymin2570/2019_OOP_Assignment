
// ProjectDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Project.h"
#include "ProjectDlg.h"
#include "afxdialogex.h"
#include "Snake.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static Snake *SnakeHead;							//Declare static class variables
static Food *food;
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CProjectDlg 대화 상자



CProjectDlg::CProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()											//WM_PAINT message
	ON_WM_QUERYDRAGICON()
	ON_WM_KEYDOWN()									//WM_KEYDOWN message
	ON_WM_KEYUP()											//WM_KEYUP message
	ON_WM_TIMER()											//WM_TIMER message
END_MESSAGE_MAP()


// CProjectDlg 메시지 처리기

BOOL CProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	//Print out warning message
	if (MessageBox(L"이 게임은 뱀에 대한 잔혹한 묘사가 포함되어 있습니다.\n무서운 것에 서투른 분은 플레이를 삼가해 주십시오.\n게임 진행을 원하십니까?", L"경고문", MB_YESNO) == IDYES)
		MoveWindow(0, 0, 560, 600);				//If yes clicked
	else
		this->DestroyWindow();						//If no clicked

	SetTimer(0, 55, nullptr);								//Set timer
	size = 20;															//Size for one cell of the map
	SetSnake(&SnakeHead);								//Make Snake
	SnakeSize = 3;												//Size of Snake
	SetFood(SnakeHead, &food);						//Make food
	Drawtimes = 0;												//Initialize
	tail_x = 1;
	tail_y = 1;
	body_x = 1;
	body_y = 1;
	OneButton = false;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CProjectDlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	if (Drawtimes == 0) {														//At first
		DrawMap(&dc);																//Draw Map only once
		DrawFood(&dc);															//Draw Food
	}
	if (Eat(SnakeHead, food) == true) {							//If Snake eats food
		Deletefood(&dc);															//Delete food
		SetFood(SnakeHead, &food);										//Make new food
		DrawFood(&dc);															//Draw new food
		Deleteprev(&dc, tail_x, tail_y, body_x, body_y);	//Delete trail
		if (tail_x == food->xpos && tail_y == food->ypos) {	//If food was deleted because of Deleteprev
			DrawFood(&dc);
		}
		DrawEatSnake(&dc);													//Draw Snake that eats food
	}
	else {
	Deleteprev(&dc, tail_x, tail_y, body_x, body_y);		//Delete trail
	DrawSnake(&dc);																//Draw Snake
	}
	
	Drawtimes++;																	//Store Onpaint function executed
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CProjectDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (OneButton == false) {																	//Get only one input
		switch (nChar)																					//Consider input
		{
		case'w':
		case'W':
			if (SnakeHead->direct != 's' && SnakeHead->direct != 'S')		//Cannot move opposite direction
				SnakeHead->direct = 'W';														//Change direction
			break;

		case's':
		case'S':
			if (SnakeHead->direct != 'w' && SnakeHead->direct != 'W')		//Cannot move opposite direction
				SnakeHead->direct = 'S';														//Change direction
			break;

		case'a':
		case'A':
			if (SnakeHead->direct != 'd' && SnakeHead->direct != 'D')		//Cannot move opposite direction
				SnakeHead->direct = 'A';														//Change direction
			break;

		case'd':
		case'D':
			if (SnakeHead->direct != 'a' && SnakeHead->direct != 'A')		//Cannot move opposite direction
				SnakeHead->direct = 'D';														//Change direction
			break;
		}
		OneButton = true;																			//Change variable for get only one input
	}
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CProjectDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	switch (nIDEvent)														//Executed every 55ms
	{
	case 0:
		if (Eat(SnakeHead, food) == true) {				//If Snake eats food
			EatMove(SnakeHead);										//Move Snake that eats food
			SnakeSize++;														//Store Snake size
		}
		else
			Move(SnakeHead);											//Move Snake

		if (SnakeSize >= 25 * 25) {								//If snake's body fill entire map
			KillTimer(0);																												//Stop cycle
			MessageBox(L"게임을 클리어하셨습니다!!", L"성공", MB_OK);				//Print out clear message
			this->DestroyWindow();																						//End program
			return;
		}
		if (WallCoong(SnakeHead) == true) {
			KillTimer(0);																												//Stop cycle
			MessageBox(L"벽에 쿵!", L"실패", MB_ICONSTOP);										//Print out failure message
			this->DestroyWindow();																						//End program
			return;
		}
		if (BodyCoong(SnakeHead) == true) {
			KillTimer(0);																												//Stop cycle
			MessageBox(L"몸에 쿵!", L"실패", MB_ICONSTOP);										//Print out failure message
			this->DestroyWindow();																						//End program
			return;
		}
		OneButton = false;											//Reset variable
		Invalidate(FALSE);											//Restart cycle
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CProjectDlg::DrawMap(CDC* pDC)
{
	// TODO: 여기에 구현 코드 추가.
	SetBackgroundColor(RGB(0, 0, 0));						//Back ground color is black
	int x, y;
	x = size;
	y = size;
	CBrush Map_Color(RGB(128, 128, 128));				//Map color is gray

	for (int i = 0; i < 25; i++) {										//Map size is 25x25
		for (int j = 0; j < 25; j++) {
			pDC->SelectObject(Map_Color);
			pDC->Rectangle(x, y, x + size, y + size);		//Draw map
			x += size;
		}
		x = size;
		y += size;
	}
}


void CProjectDlg::DrawFood(CDC* pDC)
{
	// TODO: 여기에 구현 코드 추가.
	CBrush Food_Color(RGB(255, 0, 0));						//Food color is red
	pDC->SelectObject(Food_Color);
	pDC->Rectangle(food->xpos * size, food->ypos * size, food->xpos * size + size, food->ypos * size + size);		//Draw food
}


void CProjectDlg::DrawSnake(CDC* pDC)
{
	// TODO: 여기에 구현 코드 추가.
	CBrush snake_head(RGB(0, 255, 0));					//Head color is green
	CBrush snake_body(RGB(255, 255, 0));			//Body color is yellow
	CBrush snake_tail(RGB(0, 255, 255));				//Tail color is skyblue
	Snake *temp;
	temp = SnakeHead;

	while (temp != NULL) {
		if (temp->prev == NULL) {								//If head node
			pDC->SelectObject(snake_head);
			pDC->Ellipse(temp->xpos * size, temp->ypos*size, temp->xpos * size + size, temp->ypos*size + size);			//Draw head
		}
		else if (temp->prev != NULL && temp->next != NULL) {				//If body node
			pDC->SelectObject(snake_body);
			pDC->Rectangle(temp->xpos * size, temp->ypos*size, temp->xpos * size + size, temp->ypos*size + size);		//Draw body
		}
		else {
			pDC->SelectObject(snake_tail);
			pDC->Ellipse(temp->xpos * size, temp->ypos*size, temp->xpos * size + size, temp->ypos*size + size);			//Draw tail
		}
		temp = temp->next;
	}
	temp = SnakeHead;
	while (temp->next != NULL) {					//Get tail node
		temp = temp->next;
	}
	tail_x = temp->xpos;									//Store tail coordinates
	tail_y = temp->ypos;
	temp = temp->prev;
	body_x = temp->xpos;								//Store body coordinates that front of tail
	body_y = temp->ypos;
}


void CProjectDlg::DrawEatSnake(CDC *pDC)
{
	// TODO: 여기에 구현 코드 추가.
	CBrush snake_head(RGB(0, 255, 0));						//Head color is green
	CBrush snake_body(RGB(255, 255, 0));				//Body color is yellow
	CBrush snake_tail(RGB(0, 255, 255));					//Tail color is skyblue
	Snake *temp;
	temp = SnakeHead;

	while (temp->next != NULL) {
		if (temp->prev == NULL) {
			pDC->SelectObject(snake_head);
			pDC->Ellipse(temp->xpos * size, temp->ypos*size, temp->xpos * size + size, temp->ypos*size + size);			//Draw head
		}
		else if (temp->next->next == NULL) {			//Except for new node, find tail node
			pDC->SelectObject(snake_tail);
			pDC->Ellipse(temp->xpos * size, temp->ypos*size, temp->xpos * size + size, temp->ypos*size + size);			//Draw tail
		}
		else {
			pDC->SelectObject(snake_body);
			pDC->Rectangle(temp->xpos * size, temp->ypos*size, temp->xpos * size + size, temp->ypos*size + size);		//Draw body
		}
		temp = temp->next;
	}
	temp = SnakeHead;
	while (temp->next != NULL) {					//Get tail node
		temp = temp->next;
	}
	tail_x = temp->xpos;									//Store tail coordinates
	tail_y = temp->ypos;
	temp = temp->prev;
	body_x = temp->xpos;								//Store body coordinates that front of tail
	body_y = temp->ypos;
}


void CProjectDlg::Deleteprev(CDC* pDC, int x1, int y1, int x2, int y2)
{
	// TODO: 여기에 구현 코드 추가.
	CBrush Map_Color(RGB(128, 128, 128));
	CBrush snake_tail(RGB(0, 255, 255));
	Snake *temp;
	temp = SnakeHead;
	while (temp->next != NULL) {													//Get tail node
		temp = temp->next;
	}
	pDC->SelectObject(Map_Color);
	pDC->Rectangle(x1 * size, y1 * size, x1 * size + size, y1 * size + size);	//Delete trail
	pDC->Rectangle(x2 * size, y2 * size, x2 * size + size, y2 * size + size);	//Delete trail
}


void CProjectDlg::Deletefood(CDC* pDC)
{
	// TODO: 여기에 구현 코드 추가.
	CBrush Map_Color(RGB(128, 128, 128));
	CBrush snake_head(RGB(0, 255, 0));
	pDC->SelectObject(Map_Color);
	pDC->Rectangle(SnakeHead->xpos * size, SnakeHead->ypos * size, SnakeHead->xpos * size + size, SnakeHead->ypos * size + size);	//Food coordinates is same with head coordinates
	pDC->SelectObject(snake_head);
	pDC->Ellipse(SnakeHead->xpos * size, SnakeHead->ypos * size, SnakeHead->xpos * size + size, SnakeHead->ypos * size + size);			//Food coordinates is same with head coordinates
}

