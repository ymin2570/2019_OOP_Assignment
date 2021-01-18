
// Assignment3-4View.cpp: CAssignment34View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Assignment3-4.h"
#endif

#include "Assignment3-4Doc.h"
#include "Assignment3-4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAssignment34View

IMPLEMENT_DYNCREATE(CAssignment34View, CView)

BEGIN_MESSAGE_MAP(CAssignment34View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_RESET, &CAssignment34View::OnReset)							//If Reset button pressed
	ON_COMMAND(ID_1STEP, &CAssignment34View::On1step)								//If 1 Step button pressed
	ON_COMMAND(ID_FINAL, &CAssignment34View::OnFinal)								//If Final button pressed
END_MESSAGE_MAP()

// CAssignment34View 생성/소멸

CAssignment34View::CAssignment34View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CAssignment34View::~CAssignment34View()
{
}

BOOL CAssignment34View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CAssignment34View 그리기

void CAssignment34View::OnDraw(CDC* /*pDC*/)
{
	CAssignment34Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CAssignment34View 인쇄

BOOL CAssignment34View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CAssignment34View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CAssignment34View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CAssignment34View 진단

#ifdef _DEBUG
void CAssignment34View::AssertValid() const
{
	CView::AssertValid();
}

void CAssignment34View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAssignment34Doc* CAssignment34View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAssignment34Doc)));
	return (CAssignment34Doc*)m_pDocument;
}
#endif //_DEBUG


// CAssignment34View 메시지 처리기


void CAssignment34View::OnReset()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	x = 0;							//x coordinate
	y = 0;							//y coordinate
	count = 0;
	for (int i = 0; i < 52; i++) {
		if (count < 10) {		//Cards in row are not 10
			OnPaint(i);			//Print out card in same row
			x += 49;				//Change x coordinate
			count++;
		}
		else {							//If cards in row are 10
			x = 0;						//Move forward
			y += 72;				//Move to next row y coordinate
			count = 0;
			OnPaint(i);			//Print out and adjust coordinate
			x += 49;
			count++;
		}
		front[i] = true;		//All cards are front
	}
	multiple = 2;				//Reverses from multiples of 2
}


void CAssignment34View::On1step()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int temp = 0;							//Variable to use when multiple > 10
	count = multiple;
	y = 0;
	while (count > 10) {				//Make count <= 10
		y += 72;								//Adjust y coordinate
		count -= 10;
	}
	temp = count;
	x = 49 * (count - 1);				//Adjust the x coordinate at first
	for (int i = multiple - 1; i < 52; i += multiple) {
		if (count <= 10) {
			if (front[i] == true) {	//If the card is front
				OnPaint(52);				//Change card to backside
				front[i] = false;
				x += 49 * temp;			//Adjust x coordinate
				count += multiple;	//For find the next multiple card
			}
			else {									//If the card is back
				OnPaint(i);					//Turn the card over to the front
				front[i] = true;
				x += 49 * temp;
				count += multiple;
			}
		}
		else {
			while (count > 10) {		//If count > 10
				y += 72;						//Adjust y coordinate
				count -= 10;
			}
			x = 49 * (count - 1);		//Set x coordinate
			if (front[i] == true) {	//Same with above
				OnPaint(52);
				front[i] = false;
				x += 49 * temp;
				count += multiple;
			}
			else {
				OnPaint(i);
				front[i] = true;
				x += 49 * temp;
				count += multiple;
			}
		}
	}
	multiple++;							//Next step
}


void CAssignment34View::OnFinal()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	for (int i = 0; i < 51; i++) {
		On1step();								//Repeat 1Step function 51times to get the result
	}
}


void CAssignment34View::OnPaint(int i)
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC windc(this);										//Get window size information
	CDC MemDC;															//Declare memory DC

	MemDC.CreateCompatibleDC(&windc);		//Create a memory DC that is compatible with the screen DC
	CBitmap bmp;															//Load bitmap resource
	CBitmap* pOldBmp = NULL;	
	bmp.LoadBitmapW(310 + i);							//Load bitmap in resource
	pOldBmp = MemDC.SelectObject(&bmp);	//Bitmap connections created in MemDC
	windc.BitBlt(x, y, 49, 72, &MemDC, 0, 0, SRCCOPY);		//Copy the bitmap in memory DC to screen DC and print out
	MemDC.SelectObject(pOldBmp);						//Deallocating used objects and memory
}
