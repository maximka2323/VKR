//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "math.h"
#include "UDraw.h"
#include "UHead.h"
#include "ULib.h"
//#include "UHead.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfmDraw *fmDraw;
//---------------------------------------------------------------------------

extern element EL[100];
extern usel US[100];
extern int NE, NU;
double FW, FH, maxX=0, maxY=0, minX, minY, kScale, elH=0;
double XUS[100],YUS[100];
int notFirst = 0;

__fastcall TfmDraw::TfmDraw(TComponent* Owner)
	: TForm(Owner)
{
	fmDraw->Width = 640;
	fmDraw->Height = 480;
	FW = Form1->Width;
	FH = Form1->Height;
//	Form1->pb2->BringToFront();
//	Form1->pb1->BringToFront();

}
//---------------------------------------------------------------------------
void __fastcall TfmDraw::FormShow(TObject *Sender)
{
   //	cDraw();
}
//---------------------------------------------------------------------------
void __fastcall TfmDraw::FormClose(TObject *Sender, TCloseAction &Action)
{
		fmDraw->DestroyComponents();
}
//---------------------------------------------------------------------------
void findMax()
{
	extern int NU;
	maxX = US[0].x;
	maxY = US[0].y;
	minX = US[0].x;
	minY = US[0].y;
	for (int i = 0; i < NU; i++)
	{
	   if(maxX<US[i].x)
	   maxX = US[i].x;
	   if(maxY<US[i].y)
	   maxY = US[i].y;
	   if(minX>US[i].x)
	   minX = US[i].x;
	   if(minY>US[i].y)
	   minY = US[i].y;
	}
	maxX = maxX - minX;
	maxY = maxY - minY;
	if(FW*0.7/maxX<FH*0.7/maxY)
	kScale = FW*0.7/maxX;
	else
	kScale = FH*0.7/maxY;

}

void drawLine()
{

	double x,y,xi,yi,is,ic, L;
	elH = 0;
	for (int i = 0; i < NE; i++) {
		 xi = US[EL[i].U1-1].x;
		 yi = US[EL[i].U1-1].y;
		 L = EL[i].L;
		 is = -EL[i].Esin;
		 ic = EL[i].Ecos;

		 TLine *elBody = new TLine(Form1->pb);
		 elBody->Parent = Form1->pb;
		 elBody->Height = 30;
		 elBody->Width = L*kScale ;
		 elBody->LineType = TLineType::Top;
		 elBody->Stroke->Color = claGrey;//RGB (125, 125, 125);
		 elBody->Stroke->Thickness = sqrt(EL[i].S)*kScale;
		 elBody->RotationCenter->X = 0;
		 elBody->RotationCenter->Y = 0;
		 if(ic==0)
		 elBody->RotationAngle = 90*is ;
		 else
		 elBody->RotationAngle = 90 - ic*(90 - 180 * (asin(is)/3.14))/abs(ic);
		 elBody->Position->X = xi*kScale + 0.1 * FW ;
		 elBody->Position->Y = -yi*kScale + 0.75 * FH ;
		 if(elH<sqrt(EL[i].S)*kScale)
		 elH = sqrt(EL[i].S)*kScale;
	}
}

void drawRect()
{
	double x,y,xi,yi,is,ic, L;
		for (int i = 0; i < NE; i++) {
		 xi = US[EL[i].U1-1].x;
		 yi = US[EL[i].U1-1].y;
		 L = EL[i].L;
		 is = -EL[i].Esin;
		 ic = EL[i].Ecos;

		 TRectangle *conta = new TRectangle(Form1->pb);
		 conta->Parent = Form1->pb;
		 conta->Height = 20;
		 conta->Width = L*kScale ;
		 conta->RotationCenter->X = 0;
		 conta->RotationCenter->Y = 0;
		 conta->RotationAngle = 90-180 * (asin(is)/3.14);
		 conta->Position->X = xi*kScale + 0.1 * FW + notFirst*20*is;//+ is*L*sc/2;
		 conta->Position->Y = -yi*kScale + 0.5 * FH ;//+ notFirst*5*ic;//+ is*L*sc/2;
		 notFirst = 1;
	}
}

void usDraw()
{
		double x,y,xi,yi,is,ic, L;

		for (int i = 0; i < NU; i++) {
		x = StrToInt(fmIn->StringGrid5->Cells[1][i]);
		y = StrToInt(fmIn->StringGrid5->Cells[2][i]);
		TEllipse *conta1 = new TEllipse(Form1->pb);
		conta1->Parent = Form1->pb;
		conta1->Width = elH*1.5;
		conta1->Height = elH*1.5;
		conta1->Fill->Color = claBlack;
		conta1->RotationCenter->X = 0;
		conta1->RotationCenter->Y = 0;
		//conta1->RotationAngle = 180 * (asin(is)/3.14);
		conta1->Position->X = x*kScale + 0.1 * FW - (conta1->Width)/2 ;
		conta1->Position->Y = -y*kScale + 0.75 * FH - (conta1->Width)/2;
		XUS[i] = conta1->Position->X;
		YUS[i] = conta1->Position->Y;
}
}

void sup1YDraw(int i)
{
	double x,y,xi,yi,is,ic, L;
	xi = US[EL[i].U1-1].x;
	yi = US[EL[i].U1-1].y;
	L = EL[i].L;
	is = -EL[i].Esin;
	ic = EL[i].Ecos;
	double wh = elH*1.5;
	double whc = wh;
	TLine *supLine1 = new TLine(Form1->pb);
	supLine1->Parent = Form1->pb;
	supLine1->Position->X = XUS[i] + wh/2 ;//+ is*L*sc/2;
	supLine1->Position->Y = YUS[i] + wh/2 ;
	if(wh<10)
	whc = 10;
	supLine1->Height = 3*whc;
	supLine1->Width = 3*whc;
	supLine1->LineType = TLineType::Left;
	supLine1->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine1->Stroke->Thickness = 3;


	TLine *supLine2 = new TLine(Form1->pb);
	supLine2->Parent = Form1->pb;
	supLine2->Height = 3*whc;
	supLine2->Width = 6*whc;
	supLine2->LineType = TLineType::Top;
	supLine2->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i] + wh/2 - 3*whc;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + 3*whc;

	for(int j=0;j<6;j++)
	{
	TLine *supLinen = new TLine(Form1->pb);
	supLinen->Parent = Form1->pb;
	supLinen->Height = whc;
	supLinen->Width = whc;
	supLinen->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = 90;
	supLinen->Position->X = XUS[i] + wh/2 - 3*whc + j*whc;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + 3*whc;
	}

	for(int j=0;j<2;j++)
	{
	TEllipse *supP = new TEllipse(Form1->pb);
	supP->Parent = Form1->pb;
	supP->Width = whc;
	supP->Height = whc;
	supP->Fill->Color = claWhite;
	supP->BringToFront();
	supP->Position->X = XUS[i] - (whc-wh)/2;
	supP->Position->Y = YUS[i] - (whc-wh)/2 + 2.5*whc*j;
	}
}

void sup1XDraw(int i)
{
	double x,y,xi,yi,is,ic, L;
	int kSide ;
	if(i==0)
	kSide = 0;
	else if(XUS[i-1]>XUS[i])
	kSide = 0;
	else kSide = 1;
	xi = US[EL[i].U1-1].x;
	yi = US[EL[i].U1-1].y;
	L = EL[i].L;
	is = -EL[i].Esin;
	ic = EL[i].Ecos;
	double whc, wh = elH*1.5;
	whc = wh;
	if(wh<10)
	whc = 10;
	TLine *supLine1 = new TLine(Form1->pb);
	supLine1->Parent = Form1->pb;
	supLine1->Height = 3*whc;
	supLine1->Width = 3*whc;
	supLine1->LineType = TLineType::Top;
	supLine1->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine1->Stroke->Thickness = 3;
	supLine1->Position->X = XUS[i] + wh/2 - whc*3 + kSide*3*whc;//+ is*L*sc/2;
	supLine1->Position->Y = YUS[i] + wh/2 ;

	TLine *supLine2 = new TLine(Form1->pb);
	supLine2->Parent = Form1->pb;
	supLine2->Height = 6*whc;
	supLine2->Width = whc;
	supLine2->LineType = TLineType::Left;
	supLine2->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i] + wh/2 - 3*whc + kSide*6*whc;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + wh/2 - 3*whc;

	for(int j=0;j<6;j++)
	{
	TLine *supLinen = new TLine(Form1->pb);
	supLinen->Parent = Form1->pb;
	supLinen->Height = whc;
	supLinen->Width = whc;
	supLinen->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = 90;
	supLinen->Position->X = XUS[i] + wh/2 - 4*whc + kSide*7*whc;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + wh/2 - 3*whc + j*whc;
	}

	for(int j=0;j<2;j++)
	{
	TEllipse *supP = new TEllipse(Form1->pb);
	supP->Parent = Form1->pb;
	supP->Width = whc;
	supP->Height = whc;
	supP->Fill->Color = claWhite;
	supP->Position->X = XUS[i] - (whc-wh)/2 - 3*whc*j + kSide*6*j*whc;
	supP->Position->Y = YUS[i] - (whc-wh)/2;
	}
}

void sup2Draw(int i)
{
	double whc,wh = elH*1.5;
	whc = wh;
	if(wh<10)
	whc = 10;
	for(int j=0;j<2;j++)
	{
	TLine *supLine1 = new TLine(Form1->pb);
	supLine1->Parent = Form1->pb;
	supLine1->Height = 3*whc;
	supLine1->Width = 3*whc;
	supLine1->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine1->Stroke->Thickness = 3;
	supLine1->RotationAngle = j*90;
	supLine1->Position->X = XUS[i] + wh/2 - 3*whc*j ;//+ is*L*sc/2;
	supLine1->Position->Y = YUS[i] + wh/2 ;
	}

	TLine *supLine2 = new TLine(Form1->pb);
	supLine2->Parent = Form1->pb;
	supLine2->Height = 3*whc;
	supLine2->Width = 6*whc;
	supLine2->LineType = TLineType::Top;
	supLine2->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i] + wh/2 - 3*whc;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + 3*whc;

	for(int j=0;j<6;j++)
	{
	TLine *supLinen = new TLine(Form1->pb);
	supLinen->Parent = Form1->pb;
	supLinen->Height = whc;
	supLinen->Width = whc;
	supLinen->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = 90;
	supLinen->Position->X = XUS[i] + wh/2 - 3*whc + j*whc;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + 3*whc;
	}
	for(int j=0;j<3;j++)
	{
	TEllipse *supP = new TEllipse(Form1->pb);
	supP->Parent = Form1->pb;
	supP->Width = whc;
	supP->Height = whc;
	supP->Fill->Color = claWhite;
	supP->Position->X = XUS[i] - (whc-wh)/2 - 3*whc + 3*whc*j;
	supP->Position->Y = YUS[i] - (whc-wh)/2 + 1.25*whc + 1.25*whc*pow(-1,j);
	}
}

void sup3Draw(int i)
{
	double whc, wh = elH*1.5;
	whc = wh;
	if(wh<10)
	whc = 10;
	TLine *supLine1 = new TLine(Form1->pb);
	supLine1->Parent = Form1->pb;
	supLine1->Height = 3*whc;
	supLine1->Width = 3*whc;
	supLine1->LineType = TLineType::Left;
	supLine1->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine1->Stroke->Thickness = 3;
	supLine1->Position->X = XUS[i] + wh/2 ;//+ is*L*sc/2;
	supLine1->Position->Y = YUS[i] + wh/2 ;


	TLine *supLine2 = new TLine(Form1->pb);
	supLine2->Parent = Form1->pb;
	supLine2->Height = whc;
	supLine2->Width = 6*whc;
	supLine2->LineType = TLineType::Top;
	supLine2->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i]  + wh/2 - 3*whc;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + wh/2 + whc*3;

	for(int j=0;j<6;j++)
	{
	TLine *supLinen = new TLine(Form1->pb);
	supLinen->Parent = Form1->pb;
	supLinen->Height = whc;
	supLinen->Width = whc;
	supLinen->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = 90;
	supLinen->Position->X = XUS[i] + wh/2 - 3*whc + j*whc;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + wh/2 + whc*3;
	}

}

void strengthXDraw(int i)
{
	double kTurn = US[i].R.v(0)/abs(US[i].R.v(0));
	double whc, wh = elH*1.5;
	whc = wh;
	if(wh<10)
	whc = 10;
	TLine *supLine2 = new TLine(Form1->pb1);
	supLine2->Parent = Form1->pb1;
	supLine2->Height = whc;
	supLine2->Width = 3*whc;
	supLine2->LineType = TLineType::Top;
	supLine2->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i] + (wh - kTurn*wh)/2 - 1.5*whc - 1.5*whc*kTurn;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + wh/2;

	for(int j=0;j<2;j++)
	{
	TLine *supLinen = new TLine(Form1->pb1);
	supLinen->Parent = Form1->pb1;
	supLinen->Height = whc/2;
	supLinen->Width = whc/2;
	supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = (45 - 45*kTurn) - j*90;
	supLinen->Position->X = XUS[i] + (wh - wh*kTurn)/2 - (whc + whc*kTurn)/4;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + j*wh/2;
	}
}

void strengthYDraw(int i)
{
	double kTurn = US[i].R.v(1)/abs(US[i].R.v(1));
	double whc, wh = elH*1.5;
	whc = wh;
	if(wh<10)
	whc = 10;
	TLine *supLine2 = new TLine(Form1->pb1);
	supLine2->Parent = Form1->pb1;
	supLine2->Height = 3*whc;
	supLine2->Width = whc;
	supLine2->LineType = TLineType::Left;
	supLine2->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i] + wh/2;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + (wh + wh*kTurn)/2 - (1.5*whc - kTurn*1.5*whc);

	for(int j=0;j<2;j++)
	{
	TLine *supLinen = new TLine(Form1->pb1);
	supLinen->Parent = Form1->pb1;
	supLinen->Height = whc/2;
	supLinen->Width = whc/2;
	supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = (45 + 45*kTurn) - j*90;
	supLinen->Position->X = XUS[i] - (whc-wh)/2 + whc*j/2 ;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + (3*wh + wh*kTurn - 2*(whc-kTurn*whc))/4;
	}
}

void momentDraw(int i)
{
	double kTurn = US[i].R.v(2)/abs(US[i].R.v(2));
	double whc, wh = elH*1.5;
	whc =wh;
	if(wh<10)
	whc = 10;
	double ang = asin(1/3)*180/3.14;
	TArc *supLine2 = new TArc(Form1->pb1);
	supLine2->Parent = Form1->pb1;
	supLine2->Height = 3*whc;
	supLine2->Width = 3*whc;
	supLine2->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->StartAngle = -110;
	supLine2->EndAngle = 220 ;
	supLine2->Position->X = XUS[i] - (3*whc - wh)/2;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] - (3*whc - wh)/2;

	for(int j=0;j<2;j++)
	{
	TLine *supLinen = new TLine(Form1->pb1);
	supLinen->Parent = Form1->pb1;
	supLinen->Height = whc/2;
	supLinen->Width = whc/2;
	supLinen->LineType = TLineType::Top;
	supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationCenter->X = 0;
	supLinen->RotationCenter->Y = 0;
	supLinen->RotationAngle = -30*j*kTurn;
	supLinen->Position->X = XUS[i] - (3*whc - wh)/2 + whc;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] - (3*whc - wh)/2 + whc*1.5 - 1.5*whc*kTurn + kTurn*whc*sqrt(2)/9;
	}
}

void strengthX2Draw(int i)
{
	double kTurn = US[i].R.v(0)/abs(US[i].R.v(0));
	double whc, wh = elH*1.5;
	whc = wh;
	if(wh<10)
	whc = 10;
	TLine *supLine2 = new TLine(Form1->pb2);
	supLine2->Parent = Form1->pb2;
	supLine2->Height = whc;
	supLine2->Width = 3*whc;
	supLine2->LineType = TLineType::Top;
	supLine2->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i] + (wh - kTurn*wh)/2 - 1.5*whc - 1.5*whc*kTurn;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + wh/2;

	for(int j=0;j<2;j++)
	{
	TLine *supLinen = new TLine(Form1->pb2);
	supLinen->Parent = Form1->pb2;
	supLinen->Height = whc/2;
	supLinen->Width = whc/2;
	supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = (45 - 45*kTurn) - j*90;
	supLinen->Position->X = XUS[i] + (wh - wh*kTurn)/2 - (whc + whc*kTurn)/4;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + j*wh/2;
	}
}

void strengthY2Draw(int i)
{
	double kTurn = US[i].R.v(1)/abs(US[i].R.v(1));
	double whc, wh = elH*1.5;
	whc = wh;
	if(wh<10)
	whc = 10;
	TLine *supLine2 = new TLine(Form1->pb2);
	supLine2->Parent = Form1->pb2;
	supLine2->Height = 3*whc;
	supLine2->Width = whc;
	supLine2->LineType = TLineType::Left;
	supLine2->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i] + wh/2;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + (wh + wh*kTurn)/2 - (1.5*whc - kTurn*1.5*whc);

	for(int j=0;j<2;j++)
	{
	TLine *supLinen = new TLine(Form1->pb2);
	supLinen->Parent = Form1->pb2;
	supLinen->Height = whc/2;
	supLinen->Width = whc/2;
	supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = (45 + 45*kTurn) - j*90;
	supLinen->Position->X = XUS[i] - (whc-wh)/2 + whc*j/2 ;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + (3*wh + wh*kTurn - 2*(whc-kTurn*whc))/4;
	}
}

void moment2Draw(int i)
{
	double kTurn = US[i].R.v(2)/abs(US[i].R.v(2));
	double whc, wh = elH*1.5;
	whc =wh;
	if(wh<10)
	whc = 10;
	double ang = asin(1/3)*180/3.14;
	TArc *supLine2 = new TArc(Form1->pb2);
	supLine2->Parent = Form1->pb2;
	supLine2->Height = 3*whc;
	supLine2->Width = 3*whc;
	supLine2->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->StartAngle = -110;
	supLine2->EndAngle = 220 ;
	supLine2->Position->X = XUS[i] - (3*whc - wh)/2;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] - (3*whc - wh)/2;

	for(int j=0;j<2;j++)
	{
	TLine *supLinen = new TLine(Form1->pb2);
	supLinen->Parent = Form1->pb2;
	supLinen->Height = whc/2;
	supLinen->Width = whc/2;
	supLinen->LineType = TLineType::Top;
	supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationCenter->X = 0;
	supLinen->RotationCenter->Y = 0;
	supLinen->RotationAngle = -30*j*kTurn;
	supLinen->Position->X = XUS[i] - (3*whc - wh)/2 + whc;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] - (3*whc - wh)/2 + whc*1.5 - 1.5*whc*kTurn + kTurn*whc*sqrt(2)/9;
	}
}

void pDraw(int i)
{

		 double x,y,xi,yi,is,ic, L;
		 double kTurn = EL[i].p/abs(EL[i].p);
		 xi = US[EL[i].U1-1].x;
		 yi = US[EL[i].U1-1].y;
		 L = EL[i].L;
		 is = -EL[i].Esin;
		 ic = EL[i].Ecos;

		 TLine *elBody = new TLine(Form1->pb1);
		 elBody->Parent = Form1->pb1;
		 elBody->Height = 10;
		 elBody->Width = L*kScale/3 ;
		 elBody->LineType = TLineType::Top;
		 elBody->Stroke->Color = claRed;//RGB (125, 125, 125);
		 elBody->RotationCenter->X = 0;
		 elBody->RotationCenter->Y = 0;
		 if(ic ==0)
		 elBody->RotationAngle = 90;
		 else
		 elBody->RotationAngle = 90 - ic*(90 - 180 * (asin(is)/3.14))/abs(ic);
		 double ugol = elBody->RotationAngle;
		 elBody->Position->X = (xi + (ic*L/3))*kScale + 0.1 * FW ;
		 elBody->Position->Y = -(yi - (is*L/3))*kScale + 0.75 * FH  ;
		 for(int j=0;j<2;j++)
{
	TLine *supLinen = new TLine(Form1->pb1);
	supLinen->Parent = Form1->pb1;
	supLinen->Height = 7;
	supLinen->Width = 7;
	supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLinen->RotationCenter->X = 0;
	supLinen->RotationCenter->Y = 0;
	if(ic==0)
	supLinen->RotationAngle = 90*j + ugol + 45 - 45*kTurn + 90;
	else
	supLinen->RotationAngle = 90*j + ugol + 45 - 45*kTurn;
	supLinen->Position->X = (xi + ((1.5 + kTurn*0.5)*ic*L/3))*kScale + 0.1 * FW ;
	supLinen->Position->Y = -(yi - ((1.5 + kTurn*0.5)*is*L/3))*kScale + 0.75 * FH  ;
		 }
}

void qDraw(int i)
{
	double x,y,xi,yi,is,ic, L;
		 double kTurn = EL[i].q/abs(EL[i].q);
		 xi = US[EL[i].U1-1].x;
		 yi = US[EL[i].U1-1].y;
		 L = EL[i].L;
		 is = -EL[i].Esin;
		 ic = EL[i].Ecos;

		 TLine *elBody = new TLine(Form1->pb1);
		 elBody->Parent = Form1->pb1;
		 elBody->Height = 10;
		 elBody->Width = L*kScale/3 ;
		 elBody->LineType = TLineType::Top;
		 elBody->Stroke->Color = claRed;//RGB (125, 125, 125);
		 elBody->RotationCenter->X = 0;
		 elBody->RotationCenter->Y = 0;
		 elBody->Position->X = (xi + (ic*L/3))*kScale + 0.1 * FW ;
		 if(ic ==0) {
		 elBody->RotationAngle = kTurn*90;
		 elBody->Position->X = (xi + (ic*L/3))*kScale + 0.1 * FW - 30*kTurn;
		 }
		 else
		 elBody->RotationAngle = 90 - ic*(90 - 180 * (asin(is)/3.14))/abs(ic);
		 double ugol = elBody->RotationAngle;

		 elBody->Position->Y = -(yi - (is*L/3))*kScale + 30*kTurn + 0.75 * FH  ;

	 for(int c=0;c<7;c++)
	 {
		TLine *supLine2 = new TLine(Form1->pb1);
		supLine2->Parent = Form1->pb1;
		supLine2->Height = 30;
		supLine2->Width = 10;
		supLine2->LineType = TLineType::Left;
		supLine2->Stroke->Color = claRed;//RGB (125, 125, 125);
		supLine2->Stroke->Thickness = 1;
		supLine2->RotationCenter->X = 0;
		supLine2->RotationCenter->Y = 0;
		if(ic == 0)
		supLine2->RotationAngle = 90*kTurn;
		else
		supLine2->RotationAngle = 90 - 90*kTurn;
		supLine2->Position->X = (xi + (ic*L/3 + c*ic*L/18))*kScale + 0.1 * FW;
		supLine2->Position->Y = -(yi - (is*L/3 + c*is*L/18))*kScale + 0.75 * FH ;
		for(int j=0;j<2;j++)
		{
		TLine *supLinen = new TLine(Form1->pb1);
		supLinen->Parent = Form1->pb1;
		supLinen->Height = 7;
		supLinen->Width = 7;
		supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
		supLinen->LineType = TLineType::Left;
		supLinen->RotationCenter->X = 0;
		supLinen->RotationCenter->Y = 0;
		if(ic==0)
		supLinen->RotationAngle =  45*pow(-1,j) + 90*kTurn ;
		else
		supLinen->RotationAngle =  45*pow(-1,j) + 90 - 90*kTurn;
		supLinen->Position->X = (xi + (ic*L/3 + c*ic*L/18))*kScale + 0.1 * FW;
		supLinen->Position->Y = -(yi - (is*L/3 + c*is*L/18))*kScale + 0.75 * FH ;

		}
	 }

}

void clearAll()
{
	Form1->pb->DeleteChildren();
	Form1->pb1->DeleteChildren();
	Form1->pb2->DeleteChildren();
}

void cDraw()
{
    	notFirst = 0;
	double x,y,xi,yi, sc,is,ic, L;
	sc = 0.3;
	findMax();
	drawLine();
	usDraw();
	for(int i=0;i<NU;i++)
	{
		if(US[i].C[0]==1&&US[i].C[1]==1&&US[i].C[2]==1)
		 sup3Draw(i);
		 else
		 if(US[i].C[0]==1&&US[i].C[1]==1)
		 sup2Draw(i);
		 else
		 if(US[i].C[1]==1)
		 sup1YDraw(i);
		 else
		 if(US[i].C[0]==1)
		 sup1XDraw(i);
	}

	for(int i=0;i<NE;i++)
	{
		if(EL[i].p!=0)
		pDraw(i);
		if(EL[i].q!=0)
        qDraw(i);
	}

}


void __fastcall TfmDraw::mItem1Click(TObject *Sender)
{
	fmDraw->pb2->Visible = false;
	fmDraw->pb1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfmDraw::mItem2Click(TObject *Sender)
{
	fmDraw->pb2->Visible = true;
	fmDraw->pb1->Visible = false;
	for(int i=0;i<NU;i++)
	{
		if(US[i].R.v(0)!=0) strengthX2Draw(i);
		if(US[i].R.v(1)!=0) strengthY2Draw(i);
		if(US[i].R.v(2)!=0) moment2Draw(i);
	}
}
//---------------------------------------------------------------------------

