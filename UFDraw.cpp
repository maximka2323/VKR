//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UFDraw.h"
#include "math.h"
#include "Unit2.h"
#include "UHead.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfmFDraw *fmFDraw;
//---------------------------------------------------------------------------
extern element EL[100];
extern usel US[100];
extern int NE, NU;
double FW, FH, maxX=0, maxY=0, minX, minY, kScale, elH=0;
double XUS[100],YUS[100];
int notFirst = 0;

__fastcall TfmFDraw::TfmFDraw(TComponent* Owner)
	: TForm(Owner)
{
	fmFDraw->Width = 640;
	fmFDraw->Height = 480;
	FW = fmFDraw->Width;
	FH = fmFDraw->Height;
}
//---------------------------------------------------------------------------
void __fastcall TfmFDraw::FormShow(TObject *Sender)
{
	notFirst = 0;
	double x,y,xi,yi, sc,is,ic, L;
	sc = 0.3;
//	NU = StrToInt(Form1->StringGrid4->Cells[0][0]);
//	NE = StrToInt(Form1->StringGrid4->Cells[1][0]);
	FfindMax();
	FdrawLine();
	usFDraw();
	for(int i=0;i<NU;i++)
	{
		if(US[i].C[0]==1&&US[i].C[1]==1&&US[i].C[2]==1)
		 sup3FDraw(i);
		 else
		 if(US[i].C[0]==1&&US[i].C[1]==1)
		 sup2FDraw(i);
		 else
		 if(US[i].C[1]==1)
		 sup1YFDraw(i);
		 else
		 if(US[i].C[0]==1)
		 sup1XFDraw(i);
	}
	for(int i=0;i<NU;i++)
	{
		if(US[i].R.v(0)!=0) strengthXFDraw(i);
		if(US[i].R.v(1)!=0) strengthYFDraw(i);
		if(US[i].R.v(2)!=0) momentFDraw(i);
	}
	for(int i=0;i<NE;i++)
	{
		if(EL[i].p!=0)
		pFDraw(i);
		if(EL[i].q!=0)
        qFDraw(i);
	}
}
//---------------------------------------------------------------------------
void FfindMax()
{
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
	if(FW*0.75/maxX<FH*0.75/maxY)
	kScale = FW*0.75/maxX;
	else
	kScale = FH*0.75/maxY;

}

void FdrawLine()
{

	double x,y,xi,yi,is,ic, L;
	elH = 0;
	for (int i = 0; i < NE; i++) {
		 xi = US[EL[i].U1-1].x;
		 yi = US[EL[i].U1-1].y;
		 L = EL[i].L;
		 is = -EL[i].Esin;
		 ic = EL[i].Ecos;

		 TLine *elBody = new TLine(fmFDraw);
		 elBody->Parent = fmFDraw;
		 elBody->Height = 30;
		 elBody->Width = L*kScale ;
		 elBody->LineType = TLineType::Top;
		 elBody->Stroke->Color = claGrey;//RGB (125, 125, 125);
		 elBody->Stroke->Thickness = sqrt(EL[i].S)*kScale;
		 elBody->RotationCenter->X = 0;
		 elBody->RotationCenter->Y = 0;
		 elBody->RotationAngle = 90 - ic*(90 - 180 * (asin(is)/3.14))/abs(ic);
		 elBody->Position->X = xi*kScale + 0.1 * FW ;
		 elBody->Position->Y = -yi*kScale + 0.75 * FH ;
		 if(elH<sqrt(EL[i].S)*kScale)
		 elH = sqrt(EL[i].S)*kScale;
	}
}

void FdrawRect()
{
	double x,y,xi,yi,is,ic, L;
		for (int i = 0; i < NE; i++) {
		 xi = US[EL[i].U1-1].x;
		 yi = US[EL[i].U1-1].y;
		 L = EL[i].L;
		 is = -EL[i].Esin;
		 ic = EL[i].Ecos;

		 TRectangle *conta = new TRectangle(fmFDraw);
		 conta->Parent = fmFDraw;
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

void usFDraw()
{
		double x,y,xi,yi,is,ic, L;

		for (int i = 0; i < NU; i++) {
		x = StrToInt(Form1->StringGrid5->Cells[1][i]);
		y = StrToInt(Form1->StringGrid5->Cells[2][i]);
		TEllipse *conta1 = new TEllipse(fmFDraw);
		conta1->Parent = fmFDraw;
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

void sup1YFDraw(int i)
{
	double x,y,xi,yi,is,ic, L;
	xi = US[EL[i].U1-1].x;
	yi = US[EL[i].U1-1].y;
	L = EL[i].L;
	is = -EL[i].Esin;
	ic = EL[i].Ecos;
	double wh = elH*1.5;
	TLine *supLine1 = new TLine(fmFDraw);
	supLine1->Parent = fmFDraw;
	supLine1->Height = 3*wh;
	supLine1->Width = 3*wh;
	supLine1->LineType = TLineType::Left;
	supLine1->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine1->Stroke->Thickness = 3;
	supLine1->Position->X = XUS[i] + wh/2 ;//+ is*L*sc/2;
	supLine1->Position->Y = YUS[i] + wh/2 ;

	TLine *supLine2 = new TLine(fmFDraw);
	supLine2->Parent = fmFDraw;
	supLine2->Height = 3*wh;
	supLine2->Width = 6*wh;
	supLine2->LineType = TLineType::Top;
	supLine2->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i] + wh/2 - 3*wh;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + 3*wh;

	for(int j=0;j<6;j++)
	{
	TLine *supLinen = new TLine(fmFDraw);
	supLinen->Parent = fmFDraw;
	supLinen->Height = wh;
	supLinen->Width = wh;
	supLinen->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = 90;
	supLinen->Position->X = XUS[i] + wh/2 - 3*wh + j*wh;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + 3*wh;
	}

	for(int j=0;j<2;j++)
	{
	TEllipse *supP = new TEllipse(fmFDraw);
	supP->Parent = fmFDraw;
	supP->Width = elH*1.5;
	supP->Height = elH*1.5;
	supP->Position->X = XUS[i];
	supP->Position->Y = YUS[i] + 2.5*wh*j;
	}
}

void sup1XFDraw(int i)
{
	double x,y,xi,yi,is,ic, L;
	xi = US[EL[i].U1-1].x;
	yi = US[EL[i].U1-1].y;
	L = EL[i].L;
	is = -EL[i].Esin;
	ic = EL[i].Ecos;
	double wh = elH*1.5;
	TLine *supLine1 = new TLine(fmFDraw);
	supLine1->Parent = fmFDraw;
	supLine1->Height = 3*wh;
	supLine1->Width = 3*wh;
	supLine1->LineType = TLineType::Top;
	supLine1->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine1->Stroke->Thickness = 3;
	supLine1->Position->X = XUS[i] - wh*2.5 ;//+ is*L*sc/2;
	supLine1->Position->Y = YUS[i] + wh/2 ;

	TLine *supLine2 = new TLine(fmFDraw);
	supLine2->Parent = fmFDraw;
	supLine2->Height = 6*wh;
	supLine2->Width = wh;
	supLine2->LineType = TLineType::Left;
	supLine2->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i] - wh/2 - 2*wh;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] - 2.5*wh;

	for(int j=0;j<6;j++)
	{
	TLine *supLinen = new TLine(fmFDraw);
	supLinen->Parent = fmFDraw;
	supLinen->Height = wh;
	supLinen->Width = wh;
	supLinen->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = 90;
	supLinen->Position->X = XUS[i] + wh/2 - 4*wh ;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] - 2.5*wh + j*wh;
	}

	for(int j=0;j<2;j++)
	{
	TEllipse *supP = new TEllipse(fmFDraw);
	supP->Parent = fmFDraw;
	supP->Width = elH*1.5;
	supP->Height = elH*1.5;
	supP->Position->X = XUS[i] - 3*wh*j;
	supP->Position->Y = YUS[i];
	}
}

void sup2FDraw(int i)
{
	double wh = elH*1.5;
	for(int j=0;j<2;j++)
	{
	TLine *supLine1 = new TLine(fmFDraw);
	supLine1->Parent = fmFDraw;
	supLine1->Height = 3*wh;
	supLine1->Width = 3*wh;
	supLine1->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine1->Stroke->Thickness = 3;
	supLine1->RotationAngle = j*90;
	supLine1->Position->X = XUS[i] + wh/2 - 3*wh*j ;//+ is*L*sc/2;
	supLine1->Position->Y = YUS[i] + wh/2 ;
	}

	TLine *supLine2 = new TLine(fmFDraw);
	supLine2->Parent = fmFDraw;
	supLine2->Height = 3*wh;
	supLine2->Width = 6*wh;
	supLine2->LineType = TLineType::Top;
	supLine2->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i] + wh/2 - 3*wh;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + 3*wh;

	for(int j=0;j<6;j++)
	{
	TLine *supLinen = new TLine(fmFDraw);
	supLinen->Parent = fmFDraw;
	supLinen->Height = wh;
	supLinen->Width = wh;
	supLinen->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = 90;
	supLinen->Position->X = XUS[i] + wh/2 - 3*wh + j*wh;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + 3*wh;
	}
	for(int j=0;j<3;j++)
	{
	TEllipse *supP = new TEllipse(fmFDraw);
	supP->Parent = fmFDraw;
	supP->Width = elH*1.5;
	supP->Height = elH*1.5;
	supP->Position->X = XUS[i] - 3*wh + 3*wh*j;
	supP->Position->Y = YUS[i] + 1.25*wh + 1.25*wh*pow(-1,j);
	}
}

void sup3FDraw(int i)
{
	double wh = elH*1.5;
	TLine *supLine1 = new TLine(fmFDraw);
	supLine1->Parent = fmFDraw;
	supLine1->Height = 3*wh;
	supLine1->Width = 3*wh;
	supLine1->LineType = TLineType::Left;
	supLine1->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine1->Stroke->Thickness = 3;
	supLine1->Position->X = XUS[i] + wh/2 ;//+ is*L*sc/2;
	supLine1->Position->Y = YUS[i] + wh/2 ;


	TLine *supLine2 = new TLine(fmFDraw);
	supLine2->Parent = fmFDraw;
	supLine2->Height = wh;
	supLine2->Width = 6*wh;
	supLine2->LineType = TLineType::Top;
	supLine2->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i]  + wh/2 - 3*wh;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + wh*3.5;

	for(int j=0;j<6;j++)
	{
	TLine *supLinen = new TLine(fmFDraw);
	supLinen->Parent = fmFDraw;
	supLinen->Height = wh;
	supLinen->Width = wh;
	supLinen->Stroke->Color = claBlack;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = 90;
	supLinen->Position->X = XUS[i] + wh/2 - 3*wh + j*wh;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + wh*3.5;
	}

}

void strengthXFDraw(int i)
{
	double kTurn = US[i].R.v(0)/abs(US[i].R.v(0));
	double wh = elH*1.5;
	TLine *supLine2 = new TLine(fmFDraw);
	supLine2->Parent = fmFDraw;
	supLine2->Height = wh;
	supLine2->Width = 3*wh;
	supLine2->LineType = TLineType::Top;
	supLine2->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i] - wh - 2*wh*kTurn;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + wh/2;

	for(int j=0;j<2;j++)
	{
	TLine *supLinen = new TLine(fmFDraw);
	supLinen->Parent = fmFDraw;
	supLinen->Height = wh/2;
	supLinen->Width = wh/2;
	supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = (45 - 45*kTurn) - j*90;
	supLinen->Position->X = XUS[i] + wh/4 - wh*kTurn*3/4;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + j*wh/2;
	}
}

void strengthYFDraw(int i)
{
	double kTurn = US[i].R.v(1)/abs(US[i].R.v(1));
	double wh = elH*1.5;
	TLine *supLine2 = new TLine(fmFDraw);
	supLine2->Parent = fmFDraw;
	supLine2->Height = 3*wh;
	supLine2->Width = wh;
	supLine2->LineType = TLineType::Left;
	supLine2->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->Position->X = XUS[i] + wh/2;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] + wh/2 + wh*kTurn/2 - 1.5*wh + kTurn*1.5*wh;

	for(int j=0;j<2;j++)
	{
	TLine *supLinen = new TLine(fmFDraw);
	supLinen->Parent = fmFDraw;
	supLinen->Height = wh/2;
	supLinen->Width = wh/2;
	supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationAngle = (45 + 45*kTurn) - j*90;
	supLinen->Position->X = XUS[i] + wh*j/2 ;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] + wh/4 + kTurn*wh*3/4;
	}
}

void momentFDraw(int i)
{
	double kTurn = US[i].R.v(2)/abs(US[i].R.v(2));
	double wh = elH*1.5;
	double ang = asin(1/3)*180/3.14;
	TArc *supLine2 = new TArc(fmFDraw);
	supLine2->Parent = fmFDraw;
	supLine2->Height = 2*wh;
	supLine2->Width = 2*wh;
	supLine2->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLine2->Stroke->Thickness = 3;
	supLine2->StartAngle = -110;
	supLine2->EndAngle = 220 ;
	supLine2->Position->X = XUS[i] - wh/2;//+ is*L*sc/2;
	supLine2->Position->Y = YUS[i] - wh/2;

	for(int j=0;j<2;j++)
	{
	TLine *supLinen = new TLine(fmFDraw);
	supLinen->Parent = fmFDraw;
	supLinen->Height = wh/2;
	supLinen->Width = wh/2;
	supLinen->LineType = TLineType::Top;
	supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLinen->Stroke->Thickness = 3;
	supLinen->RotationCenter->X = 0;
	supLinen->RotationCenter->Y = 0;
	supLinen->RotationAngle = -30*j*kTurn;
	supLinen->Position->X = XUS[i] - wh/2 + wh*2/3 ;//+ is*L*sc/2;
	supLinen->Position->Y = YUS[i] - wh/2 + wh - wh*kTurn + kTurn*wh*sqrt(2)*2/27;
	}
}

void pFDraw(int i)
{

		 double x,y,xi,yi,is,ic, L;
		 double kTurn = EL[i].p/abs(EL[i].p);
		 xi = US[EL[i].U1-1].x;
		 yi = US[EL[i].U1-1].y;
		 L = EL[i].L;
		 is = -EL[i].Esin;
		 ic = EL[i].Ecos;

		 TLine *elBody = new TLine(fmFDraw);
		 elBody->Parent = fmFDraw;
		 elBody->Height = 10;
		 elBody->Width = L*kScale/3 ;
		 elBody->LineType = TLineType::Top;
		 elBody->Stroke->Color = claRed;//RGB (125, 125, 125);
		 elBody->RotationCenter->X = 0;
		 elBody->RotationCenter->Y = 0;
		 elBody->RotationAngle = 90 - ic*(90 - 180 * (asin(is)/3.14))/abs(ic);
		 double ugol = 90 - ic*(90 - 180 * (asin(is)/3.14))/abs(ic);
		 elBody->Position->X = (xi + (ic*L/3))*kScale + 0.1 * FW ;
		 elBody->Position->Y = -(yi - (is*L/3))*kScale + 0.75 * FH  ;
		 for(int j=0;j<2;j++)
{
	TLine *supLinen = new TLine(fmFDraw);
	supLinen->Parent = fmFDraw;
	supLinen->Height = 7;
	supLinen->Width = 7;
	supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
	supLinen->RotationCenter->X = 0;
	supLinen->RotationCenter->Y = 0;
	supLinen->RotationAngle = 90*j + ugol + 45 - 45*kTurn;
	supLinen->Position->X = (xi + ((1.5 + kTurn*0.5)*ic*L/3))*kScale + 0.1 * FW ;
	supLinen->Position->Y = -(yi - ((1.5 + kTurn*0.5)*is*L/3))*kScale + 0.75 * FH  ;
		 }
}

void qFDraw(int i)
{
	double x,y,xi,yi,is,ic, L;
		 double kTurn = EL[i].q/abs(EL[i].q);
		 xi = US[EL[i].U1-1].x;
		 yi = US[EL[i].U1-1].y;
		 L = EL[i].L;
		 is = -EL[i].Esin;
		 ic = EL[i].Ecos;

		 TLine *elBody = new TLine(fmFDraw);
		 elBody->Parent = fmFDraw;
		 elBody->Height = 10;
		 elBody->Width = L*kScale/3 ;
		 elBody->LineType = TLineType::Top;
		 elBody->Stroke->Color = claRed;//RGB (125, 125, 125);
		 elBody->RotationCenter->X = 0;
		 elBody->RotationCenter->Y = 0;
		 elBody->RotationAngle = 90 - ic*(90 - 180 * (asin(is)/3.14))/abs(ic);
		 double ugol = 90 - ic*(90 - 180 * (asin(is)/3.14))/abs(ic);
		 elBody->Position->X = (xi + (ic*L/3))*kScale + 0.1 * FW ;
		 elBody->Position->Y = -(yi - (is*L/3))*kScale + 30*kTurn + 0.75 * FH  ;

	 for(int c=0;c<7;c++)
	 {
		TLine *supLine2 = new TLine(fmFDraw);
		supLine2->Parent = fmFDraw;
		supLine2->Height = 30;
		supLine2->Width = 10;
		supLine2->LineType = TLineType::Left;
		supLine2->Stroke->Color = claRed;//RGB (125, 125, 125);
		supLine2->Stroke->Thickness = 1;
		supLine2->RotationCenter->X = 0;
		supLine2->RotationCenter->Y = 0;
		supLine2->RotationAngle = 90 - 90*kTurn;
		supLine2->Position->X = (xi + (ic*L/3 + c*ic*L/18))*kScale + 0.1 * FW;
		supLine2->Position->Y = -(yi - (is*L/3 + c*is*L/18))*kScale + 0.75 * FH ;
		for(int j=0;j<2;j++)
		{
		TLine *supLinen = new TLine(fmFDraw);
		supLinen->Parent = fmFDraw;
		supLinen->Height = 7;
		supLinen->Width = 7;
		supLinen->Stroke->Color = claRed;//RGB (125, 125, 125);
		supLinen->LineType = TLineType::Left;
		supLinen->RotationCenter->X = 0;
		supLinen->RotationCenter->Y = 0;
		supLinen->RotationAngle =  45*pow(-1,j) + 90 - 90*kTurn;
		supLinen->Position->X = (xi + (ic*L/3 + c*ic*L/18))*kScale + 0.1 * FW;
		supLinen->Position->Y = -(yi - (is*L/3 + c*is*L/18))*kScale + 0.75 * FH ;

		}
	 }

}
