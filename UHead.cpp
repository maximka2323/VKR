//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include <Eigen/Dense>


#include <iostream>
#include <string>
#include <conio.h>
#include <comobj.hpp>
#include "utilcls.h"
#include "UHead.h"
#include "UMaster.h"
#include "URef.h"
#include "UDraw.h"
#include "Unit2.h"

using namespace std;
using namespace Eigen;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Form1->TabControl1->ActiveTab = TabItem11;
	Form1->StringGrid9->RowCount = 6;
	Form1->StringGrid10->RowCount = 6;
//	Form1->StringGrid11->RowCount = 6;
	Form1->StringGrid8->RowCount = 6;

}
//---------------------------------------------------------------------------

double  Strength[100][4];
int NE, NU;
double Nx[101], Mx[101], Qx[101], Ux[101], Wx[101], FIx[101], S1x[101], S2x[101];
Pmtx globmtx[100][100];
Pvec globv[100];

element EL[100];
double Support[100][3];
int	NSupport;
bool med = true;
MatrixXd gpmtx(300,300);
MatrixXd MGmod(300,300);
VectorXd gpv(300);
VectorXd FGmod(300);
VectorXd Dlt(300);
int nEl = 1;
usel US[100];



//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	for(int i=0;i<6;i++)
	for(int j=0;j<6;j++)
	Form1->StringGrid3->Cells[i][j] = " ";
}
//---------------------------------------------------------------------------

void SetGeom(int n)
{
		EL[n].L = sqrt(((US[EL[n].U2-1].x-US[EL[n].U1-1].x)*(US[EL[n].U2-1].x-US[EL[n].U1-1].x))+((US[EL[n].U2-1].y-US[EL[n].U1-1].y)*(US[EL[n].U2-1].y-US[EL[n].U1-1].y)));
		EL[n].Esin =  (US[EL[n].U2-1].y-US[EL[n].U1-1].y)/EL[n].L;
		EL[n].Ecos =  (US[EL[n].U2-1].x-US[EL[n].U1-1].x)/EL[n].L;
}

void Getelem()
{
	for(int i=0;i<NE;i++)
	{
	EL[i].getEL(i);
	SetGeom(i) ;
	EL[i].SetLmtx()  ;
	EL[i].SetLvec();
	EL[i].SetTmtx() ;
	EL[i].SetTrmtx() ;
	EL[i].SetGmtx();
	EL[i].SetGvec() ;
	}
	}

void Getusel()
{
	for(int i=0;i<NU;i++)
	{
	US[i].getUS(i);
	}
	}

void Getglobmtx()
{
		for(int i=0;i<NU;i++)
			for(int j=0;j<NU;j++){
			globmtx[i][j].mtx(0,0)=0;
			globmtx[i][j].mtx(1,0)=0;
			globmtx[i][j].mtx(0,1)=0;
			globmtx[i][j].mtx(1,1)=0;
			globmtx[i][j].mtx(2,0)=0;
			globmtx[i][j].mtx(0,2)=0;
			globmtx[i][j].mtx(2,2)=0;
			globmtx[i][j].mtx(1,2)=0;
			globmtx[i][j].mtx(2,1)=0;
			}
	for(int i=0;i<NE;i++)
	{
		globmtx[EL[i].U1-1][EL[i].U1-1] = globmtx[EL[i].U1-1][EL[i].U1-1] + EL[i].Gmtx[0][0];
		globmtx[EL[i].U2-1][EL[i].U1-1] = globmtx[EL[i].U2-1][EL[i].U1-1] + EL[i].Gmtx[1][0];
		globmtx[EL[i].U1-1][EL[i].U2-1] = globmtx[EL[i].U1-1][EL[i].U2-1] + EL[i].Gmtx[0][1];
		globmtx[EL[i].U2-1][EL[i].U2-1] = globmtx[EL[i].U2-1][EL[i].U2-1] + EL[i].Gmtx[1][1];
	}
}

void Getglobvec()
{

	  for(int k=0;k<NU;k++){
  globv[k].v(0)=0;
  globv[k].v(1)=0;
  globv[k].v(2)=0;
	  }
//  {Учитываем распределенные нагрузки p,q и температуру T}

	  for (int i=0;i<NE;i++)
		{
		  globv[EL[i].U1-1] = globv[EL[i].U1-1] + EL[i].Gvec[0];
		  globv[EL[i].U2-1] = globv[EL[i].U2-1] + EL[i].Gvec[1];
		}
	VectorXd usr(6);
	for(int j=0;j<NU;j++) {
	Form1->StringGrid27->Cells[0][3*j] = FloatToStrF(globv[j].v(0),ffFixed,8,2);
	Form1->StringGrid27->Cells[0][3*j+1] = FloatToStrF(globv[j].v(1),ffFixed,8,2);
	Form1->StringGrid27->Cells[0][3*j+2] = FloatToStrF(globv[j].v(2),ffFixed,8,2);
	}


	for(int i=0;i<NU;i++)
	{

		globv[i] = globv[i] + US[i].R;
//		globv[EL[i].U2-1] = globv[EL[i].U2-1] + US[EL[i].U2-1].R;
	}

		for(int j=0;j<NU;j++) {
	Form1->StringGrid27->Cells[2][3*j] = FloatToStrF(globv[j].v(0),ffFixed,8,2);
	Form1->StringGrid27->Cells[2][3*j+1] = FloatToStrF(globv[j].v(1),ffFixed,8,2);
	Form1->StringGrid27->Cells[2][3*j+2] = FloatToStrF(globv[j].v(2),ffFixed,8,2);
	}

	for(int i=0;i<NE;i++)
	{
		US[EL[i].U1-1].R = globv[EL[i].U1-1] ;
		US[EL[i].U2-1].R = globv[EL[i].U2-1]  ;
	}

}



void __fastcall TForm1::Button3Click(TObject *Sender)
{
//if(!(Form1->TabControl2->Visible))
//		Form1->TabControl2->Visible = true;
	Form1->TabControl2->ActiveTab = TabItem15;
}


void Boundary_Data(){/*{Учет ограничений, наложенных на перемещения узлов конструкции/
 Корректировка глобальной матрицы жесткости и глобального вектора нагрузки}  */


   for (int i=0;i<NU;i++){
   FGmod(3*i) = (globv[i].v(0));
   FGmod(3*i+1) = (globv[i].v(1));
   FGmod(3*i+2) = (globv[i].v(2));
	for (int j=0;j<NU;j++){
   MGmod(3*i,3*j) = globmtx[i][j].mtx(0,0);
   MGmod(3*i+1,3*j) = globmtx[i][j].mtx(1,0);
   MGmod(3*i,3*j+1) = globmtx[i][j].mtx(0,1);
   MGmod(3*i+1,3*j+1) = globmtx[i][j].mtx(1,1);
   MGmod(3*i+2,3*j) = globmtx[i][j].mtx(2,0);
   MGmod(3*i,3*j+2) = globmtx[i][j].mtx(0,2);
   MGmod(3*i+2,3*j+2) = globmtx[i][j].mtx(2,2);
   MGmod(3*i+2,3*j+1) = globmtx[i][j].mtx(2,1);
   MGmod(3*i+1,3*j+2) = globmtx[i][j].mtx(1,2);
   }
  }

	for(int i=0;i<9;i++)
	  for(int j=0;j<9;j++)
	  {
		Form1->StringGrid16->Cells[i][j] = FloatToStrF(MGmod(i,j),ffFixed,8,2);
		Form1->StringGrid11->Cells[0][j] = FloatToStrF(FGmod(j),ffFixed,8,2);
	  }


  for (int i=0;i<NU;i++){
	for (int j=0;j<3;j++){
		if (US[i].C[j]==1)    //строка глобальной матрицы MG:  (i-1)*NS+j
		{
		  int k = (i) * 3 + j;
		  for (int n=0;n<NU*3;n++){MGmod(k,n) = 0;}
		  MGmod(k,k) = 1;    //Корректировка глобальной матрицы жесткости
		  FGmod(k) = 0;    //Корректировка глобального вектора нагрузки
		}
	}
  }


}// {Boundary_Data} */







void  usl()
{//  {Определяем реакции опор (реакции связей)}

	VectorXd VDL(6) ;
	VectorXd VDG(6) ;
	VectorXd FmD(6) ;
	VectorXd FmL(6);
	MatrixXd lmtx(6,6);
	bool   B;
	NSupport = 0;




//  for (int i=0;i<NU;i++)
//  {
//	B = true;
//	for (int j=0;j<3;j++)
//	{
//	  if (USG[i][j]==1)
//		{
//		  k3 = (i) * 3 + j;
//		  for (int n=0;n<3*NU;n++)
//		   {
//		  V[n] = G[k3][n];
//		 // Form1->StringGrid8->Cells[2][n] = FloatToStrF(V[n],ffFixed,8,4);
//
//			}
//		  U_VV(NU*3,V,Dlt, VV);
//		  USR[i][j] = VV - F[k3];
//		 // Form1->StringGrid9->Cells[i][j] = FloatToStrF(USR[i][j],ffFixed,8,4); //US[i].R[j] +VV-Fpqt[k1];//=R[k1];
//		  if (B)  NSupport++;
//		  Support[NSupport][0] = i+1;
//		  Support[NSupport][j] = VV-F[k3];  //US[i].R[j];
//
//		  B = false;
//		}
//	 }
//	}

 //{Формируем векторы перемещений узлов балочных элементов в локальных координатах}
	for (int n=0;n<NU;n++) {
  for (int i=0;i<3;i++)   {
		US[n].D[i] =  Dlt(n*3+i);
   Form1->StringGrid30->Cells[i+1][n] = FloatToStrF(US[n].D[i],ffFixed,8,4);
   Form1->StringGrid30->Cells[0][n] = n+1 ;
  }
  }

 for (int n=0;n<NE;n++)
	{

//int n=1;
	  for (int i=0;i<3;i++)
			VDG(i) =  US[(EL[n].U1)-1].D[i];
	   for (int i=0;i<3;i++)
			VDG(i+3) = US[(EL[n].U2)-1].D[i];

//       {Формируем вектор перемещений узлов балочного элемента m в локальных координатах}
		VDL = EL[n].Trmtx * VDG;
	   for (int i=0;i<6;i++){
	   EL[n].DL(i) = VDL(i);
	   }
	}

	for (int n=0;n<NE;n++)
	{
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
			lmtx(3*i,3*j) = EL[n].Lmtx[i][j].mtx(0,0);
			lmtx(3*i+1,3*j) = EL[n].Lmtx[i][j].mtx(1,0);
			lmtx(3*i,3*j+1) = EL[n].Lmtx[i][j].mtx(0,1);
			lmtx(3*i+1,3*j+1) = EL[n].Lmtx[i][j].mtx(1,1);
			lmtx(3*i+2,3*j) = EL[n].Lmtx[i][j].mtx(2,0);
			lmtx(3*i,3*j+2) = EL[n].Lmtx[i][j].mtx(0,2);
			lmtx(3*i+2,3*j+2) = EL[n].Lmtx[i][j].mtx(2,2);
			lmtx(3*i+2,3*j+1) = EL[n].Lmtx[i][j].mtx(2,1);
			lmtx(3*i+1,3*j+2) = EL[n].Lmtx[i][j].mtx(1,2);
			}
		}


	   VDL = EL[n].DL;
	   FmD = lmtx * VDL;

//       	for(int i=0;i<6;i++)

//	for(int i=0;i<2;i++)
//		{
			FmL(0) = EL[n].Lvec[0].v(0) ;
			FmL(1) = EL[n].Lvec[0].v(1) ;
			FmL(2) = EL[n].Lvec[0].v(2)  ;
			FmL(3) = EL[n].Lvec[1].v(0) ;
			FmL(4) = EL[n].Lvec[1].v(1) ;
			FmL(5) = EL[n].Lvec[1].v(2)  ;

	   EL[n].FL = FmD - FmL;
			for(int i=0;i<6;i++){
	for(int j=0;j<6;j++)
	{
		lmtx(i,j)=0;
	}
		VDL(i)=0 ;
		VDG(i)=0 ;
		FmD(i)=0 ;
		FmL(i)=0 ;
	}
	}
}



//
void Calc_ParametersNDS(int n){/*{Вычисление компонентов НДС в поперечных сечениях балочного элемента.
 m - номер элемента}      */
double x, Smax, SigmaMax = 0;
		//x - безразмерная координата поперечного сечения (x=x/L)
Strength[n][0] = n+1;

   //  {Вычисляем внутренние усилия в поперечных сечениях балочного элемента m}
  for (int k=0;k<101;k++)
	{
	  x = static_cast<double>(k)/100;
	  Nx[k] = -EL[n].FL(0) - (EL[n].p * EL[n].L * x);
	  Mx[k] = -EL[n].FL(2) + EL[n].FL(1) * EL[n].L * x + EL[n].q * EL[n].L * EL[n].L * x * x/2;
	  Qx[k] = EL[n].FL(1) + EL[n].q * EL[n].L * x;
	  Ux[k] = EL[n].DL(0) + EL[n].L * (-EL[n].FL(0) * x + EL[n].p * EL[n].L * x * x/2)/(EL[n].E * EL[n].S);
	  Wx[k] = EL[n].DL(1) + EL[n].DL(2) * EL[n].L * x + EL[n].L * EL[n].L *(-EL[n].FL(2) * x * x/2 + EL[n].FL(1) * EL[n].L * x * x * x/6 + EL[n].q * EL[n].L * EL[n].L * x * x * x * x/24)/(EL[n].E * EL[n].I);
	  FIx[k] = EL[n].DL(2) + EL[n].L *(-EL[n].FL(2) * x + EL[n].FL(1) * EL[n].L * x * x/2 + EL[n].q * EL[n].L * EL[n].L * x * x * x/6)/(EL[n].E * EL[n].I);
	  S1x[k] = Nx[k]/EL[n].S - Mx[k]/EL[n].W;
	  S2x[k] = Nx[k]/EL[n].S + Mx[k]/EL[n].W;
	  // {Заполнение массива Strength - оценка прочности}
	   Smax = Max(abs(S1x[k]),abs(S2x[k]));
   if(Smax>SigmaMax)
   {
	SigmaMax = Smax;
	Strength[n][1] = x;
	Strength[n][2] = SigmaMax;
	Strength[n][3] = EL[n].ST/SigmaMax;
   }
	}
}// {Calc_ParametersNDS}

void prmtx()
{
	MatrixXd gqmtx(6, 6);
	for(int i=0;i<2;i++)
   for(int j=0;j<2;j++){
			gqmtx(3*i,3*j) = EL[0].Lmtx[i][j].mtx(0,0);
			gqmtx(3*i+1,3*j) = EL[0].Lmtx[i][j].mtx(1,0);
			gqmtx(3*i,3*j+1) = EL[0].Lmtx[i][j].mtx(0,1);
			gqmtx(3*i+1,3*j+1) = EL[0].Lmtx[i][j].mtx(1,1);
			gqmtx(3*i+2,3*j) = EL[0].Lmtx[i][j].mtx(2,0);
			gqmtx(3*i,3*j+2) = EL[0].Lmtx[i][j].mtx(0,2);
			gqmtx(3*i+2,3*j+2) = EL[0].Lmtx[i][j].mtx(2,2);
			gqmtx(3*i+2,3*j+1) = EL[0].Lmtx[i][j].mtx(2,1);
			gqmtx(3*i+1,3*j+2) = EL[0].Lmtx[i][j].mtx(1,2);

   }
   for(int i=0;i<6;i++)
   for(int j=0;j<6;j++)
   {
		Form1->StringGrid21->Cells[i][j] = FloatToStrF(gqmtx(i,j),ffFixed,8,2);
	}

	for(int i=0;i<2;i++)
   for(int j=0;j<2;j++){
			gqmtx(3*i,3*j) = EL[1].Lmtx[i][j].mtx(0,0);
			gqmtx(3*i+1,3*j) = EL[1].Lmtx[i][j].mtx(1,0);
			gqmtx(3*i,3*j+1) = EL[1].Lmtx[i][j].mtx(0,1);
			gqmtx(3*i+1,3*j+1) = EL[1].Lmtx[i][j].mtx(1,1);
			gqmtx(3*i+2,3*j) = EL[1].Lmtx[i][j].mtx(2,0);
			gqmtx(3*i,3*j+2) = EL[1].Lmtx[i][j].mtx(0,2);
			gqmtx(3*i+2,3*j+2) = EL[1].Lmtx[i][j].mtx(2,2);
			gqmtx(3*i+2,3*j+1) = EL[1].Lmtx[i][j].mtx(2,1);
			gqmtx(3*i+1,3*j+2) = EL[1].Lmtx[i][j].mtx(1,2);

   }

   for(int i=0;i<6;i++)
   for(int j=0;j<6;j++)
   {
		Form1->StringGrid22->Cells[i][j] = FloatToStrF(gqmtx(i,j),ffFixed,8,2);
	}
	for(int i=0;i<2;i++)
   for(int j=0;j<2;j++){
			gqmtx(3*i,3*j) = EL[0].Gmtx[i][j].mtx(0,0);
			gqmtx(3*i+1,3*j) = EL[0].Gmtx[i][j].mtx(1,0);
			gqmtx(3*i,3*j+1) = EL[0].Gmtx[i][j].mtx(0,1);
			gqmtx(3*i+1,3*j+1) = EL[0].Gmtx[i][j].mtx(1,1);
			gqmtx(3*i+2,3*j) = EL[0].Gmtx[i][j].mtx(2,0);
			gqmtx(3*i,3*j+2) = EL[0].Gmtx[i][j].mtx(0,2);
			gqmtx(3*i+2,3*j+2) = EL[0].Gmtx[i][j].mtx(2,2);
			gqmtx(3*i+2,3*j+1) = EL[0].Gmtx[i][j].mtx(2,1);
			gqmtx(3*i+1,3*j+2) = EL[0].Gmtx[i][j].mtx(1,2);

   }
   for(int i=0;i<6;i++)
   for(int j=0;j<6;j++)
   {
		Form1->StringGrid23->Cells[i][j] = FloatToStrF(gqmtx(i,j),ffFixed,8,2);
	}

	for(int i=0;i<2;i++)
   for(int j=0;j<2;j++){
			gqmtx(3*i,3*j) = EL[1].Gmtx[i][j].mtx(0,0);
			gqmtx(3*i+1,3*j) = EL[1].Gmtx[i][j].mtx(1,0);
			gqmtx(3*i,3*j+1) = EL[1].Gmtx[i][j].mtx(0,1);
			gqmtx(3*i+1,3*j+1) = EL[1].Gmtx[i][j].mtx(1,1);
			gqmtx(3*i+2,3*j) = EL[1].Gmtx[i][j].mtx(2,0);
			gqmtx(3*i,3*j+2) = EL[1].Gmtx[i][j].mtx(0,2);
			gqmtx(3*i+2,3*j+2) = EL[1].Gmtx[i][j].mtx(2,2);
			gqmtx(3*i+2,3*j+1) = EL[1].Gmtx[i][j].mtx(2,1);
			gqmtx(3*i+1,3*j+2) = EL[1].Gmtx[i][j].mtx(1,2);

   }

   for(int i=0;i<6;i++)
   for(int j=0;j<6;j++)
   {
		Form1->StringGrid24->Cells[i][j] = FloatToStrF(gqmtx(i,j),ffFixed,8,2);
	}

		VectorXd gqvec(6);
   for(int j=0;j<2;j++){
			gqvec(3*j) = EL[0].Lvec[j].v(0);
			gqvec(3*j+1) = EL[0].Lvec[j].v(1);
			gqvec(3*j+2) = EL[0].Lvec[j].v(2);
}
for(int j=0;j<6;j++)
   {
		Form1->StringGrid25->Cells[0][j] = FloatToStrF(gqvec(j),ffFixed,8,2);
	}
	  for(int j=0;j<2;j++){
			gqvec(3*j) = EL[0].Gvec[j].v(0);
			gqvec(3*j+1) = EL[0].Gvec[j].v(1);
			gqvec(3*j+2) = EL[0].Gvec[j].v(2);
}
for(int j=0;j<6;j++)
   {
		Form1->StringGrid25->Cells[2][j] = FloatToStrF(gqvec(j),ffFixed,8,2);
	}  for(int j=0;j<2;j++){
			gqvec(3*j) = EL[1].Lvec[j].v(0);
			gqvec(3*j+1) = EL[1].Lvec[j].v(1);
			gqvec(3*j+2) = EL[1].Lvec[j].v(2);
}
for(int j=0;j<6;j++)
   {
		Form1->StringGrid26->Cells[0][j] = FloatToStrF(gqvec(j),ffFixed,8,2);
	}
	for(int j=0;j<2;j++){
			gqvec(3*j) = EL[1].Gvec[j].v(0);
			gqvec(3*j+1) = EL[1].Gvec[j].v(1);
			gqvec(3*j+2) = EL[1].Gvec[j].v(2);
}
for(int j=0;j<6;j++)
   {
		Form1->StringGrid26->Cells[2][j] = FloatToStrF(gqvec(j),ffFixed,8,2);
	}

    for(int j=0;j<2;j++){
			gqvec(3*j) = EL[2].Lvec[j].v(0);
			gqvec(3*j+1) = EL[2].Lvec[j].v(1);
			gqvec(3*j+2) = EL[2].Lvec[j].v(2);
}
for(int j=0;j<6;j++)
   {
		Form1->StringGrid26->Cells[4][j] = FloatToStrF(gqvec(j),ffFixed,8,2);
	}
	for(int j=0;j<2;j++){
			gqvec(3*j) = EL[2].Gvec[j].v(0);
			gqvec(3*j+1) = EL[2].Gvec[j].v(1);
			gqvec(3*j+2) = EL[2].Gvec[j].v(2);
}
for(int j=0;j<6;j++)
   {
		Form1->StringGrid26->Cells[5][j] = FloatToStrF(gqvec(j),ffFixed,8,2);
	}
}


void pNDS(){
	for (int IRow=0;IRow<101;IRow++)
		{
//		  if(IRow == 3||IRow == 4) ShowMessage("!!!x = "+FloatToStr(0.6)+" ");
		  Form1->StringGrid29->Cells[0][IRow] = static_cast<double>(IRow)/100;
		  Form1->StringGrid29->Cells[1][IRow] = FloatToStrF(Nx[IRow],ffFixed,8,2);
		  Form1->StringGrid29->Cells[2][IRow] = FloatToStrF(Mx[IRow],ffFixed,8,2);
		  Form1->StringGrid29->Cells[3][IRow] = FloatToStrF(Qx[IRow],ffFixed,8,2);
		  Form1->StringGrid29->Cells[4][IRow] = FloatToStrF(Ux[IRow],ffFixed,8,4);
		  Form1->StringGrid29->Cells[5][IRow] = FloatToStrF(Wx[IRow],ffFixed,8,4);
		  Form1->StringGrid29->Cells[6][IRow] = FloatToStrF(FIx[IRow],ffFixed,8,6);
		  Form1->StringGrid29->Cells[7][IRow] = FloatToStrF(S1x[IRow],ffFixed,8,2);
		  Form1->StringGrid29->Cells[8][IRow] = FloatToStrF(S2x[IRow],ffFixed,8,2);
		}
}

void pS(){
	for (int IRow=0;IRow<NE;IRow++)
		{
		  Form1->StringGrid32->Cells[0][IRow] = FloatToStrF(Strength[IRow][0],ffFixed,8,0);
		  Form1->StringGrid32->Cells[1][IRow] = FloatToStrF(Strength[IRow][1],ffFixed,8,2);
		  Form1->StringGrid32->Cells[2][IRow] = FloatToStrF(Strength[IRow][2],ffFixed,8,2);
		  Form1->StringGrid32->Cells[3][IRow] = FloatToStrF(Strength[IRow][3],ffFixed,8,2);
}		 }

void pR(){
	 for (int IRow=0;IRow<NSupport;IRow++)
		{
		  Form1->StringGrid31->Cells[0][IRow] = FloatToStrF(Support[IRow+1][0],ffFixed,8,0);
		  Form1->StringGrid31->Cells[1][IRow] = FloatToStrF(Support[IRow+1][1],ffFixed,8,2);
		  Form1->StringGrid31->Cells[2][IRow] = FloatToStrF(Support[IRow+1][2],ffFixed,8,2);
		  Form1->StringGrid31->Cells[3][IRow] = FloatToStrF(Support[IRow+1][3],ffFixed,8,2);
}
}

void __fastcall TForm1::Button5Click(TObject *Sender)
{
//	if(!(Form1->TabControl2->Visible))
//		Form1->TabControl2->Visible = true;
	Form1->TabControl2->ActiveTab = TabItem16;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
//	if(!(Form1->TabControl2->Visible))
//		Form1->TabControl2->Visible = true;
Form1->TabControl2->ActiveTab = TabItem17;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	 LineSeries1->Clear();
	if(Form1->Chart1->Visible)
	Form1->Chart1->Visible = false;
	 else if(Form1->Chart2->Visible)
	 Form1->Chart2->Visible = false;
	 else if(Form1->Chart3->Visible)
	 Form1->Chart3->Visible = false;
	 else if(Form1->Chart5->Visible)
	 Form1->Chart5->Visible = false;
	 else if(Form1->Chart6->Visible)
	 Form1->Chart6->Visible = false;
	 else if(Form1->Chart7->Visible)
	 Form1->Chart7->Visible = false;
	 Form1->Chart4->Visible = true;
	double Ax[101], Ay[101];

	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(Form1->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(Form1->StringGrid29->Cells[4][i]);
		LineSeries1->AddXY(Ax[i],Ay[i]);
	}
	Form1->Chart4->BottomAxis->Title->Text = "L, мм" ;
	Form1->Chart4->LeftAxis->Title->Text = "U, мм" ;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 LineSeries2->Clear();
	if(Form1->Chart1->Visible)
	Form1->Chart1->Visible = false;
	 else if(Form1->Chart2->Visible)
	 Form1->Chart2->Visible = false;
	 else if(Form1->Chart3->Visible)
	 Form1->Chart3->Visible = false;
	 else if(Form1->Chart4->Visible)
	 Form1->Chart4->Visible = false;
	 else if(Form1->Chart6->Visible)
	 Form1->Chart6->Visible = false;
	 else if(Form1->Chart7->Visible)
	 Form1->Chart7->Visible = false;
	 Form1->Chart5->Visible = true;
	double Ax[101], Ay[101];

	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(Form1->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(Form1->StringGrid29->Cells[3][i]);
		LineSeries2->AddXY(Ax[i],Ay[i]);
	}
	Form1->Chart5->BottomAxis->Title->Text = "L, мм" ;
	Form1->Chart5->LeftAxis->Title->Text = "Q, Н" ;

}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	Form1->TabControl1->ActiveTab = TabItem2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	Form1->TabControl1->ActiveTab = TabItem12;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
//     Form1->TabControl1->ActiveTab = TabItem10;

//	   StringGrid5->ClearContent();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
	double Ax[101], Ay[101];
	Series1->Clear();
	if(Form1->Chart2->Visible)
		Form1->Chart2->Visible = false;
	 else if(Form1->Chart3->Visible)
	 Form1->Chart3->Visible = false;
	  else if(Form1->Chart4->Visible)
	 Form1->Chart4->Visible = false;
	  else if(Form1->Chart5->Visible)
	 Form1->Chart5->Visible = false;
	  else if(Form1->Chart6->Visible)
	 Form1->Chart6->Visible = false;
	  else if(Form1->Chart7->Visible)
	 Form1->Chart7->Visible = false;
	 Form1->Chart1->Visible = true;
	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(Form1->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(Form1->StringGrid29->Cells[1][i]);
		Series1->AddXY(Ax[i],Ay[i]);
	}

	Form1->Chart1->BottomAxis->Title->Text = "L, мм" ;
	Form1->Chart1->LeftAxis->Title->Text = "N, Н" ;
//	Series1->Title = "График зависимости нормального усилия в поперечном сечении от длины балочного элемента";
	//Series1->Title = "N(x/L)";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
	 Series2->Clear();
if(Form1->Chart3->Visible)
	Form1->Chart3->Visible = false;
	 else if(Form1->Chart1->Visible)
	 Form1->Chart1->Visible = false;
	 else if(Form1->Chart4->Visible)
	 Form1->Chart4->Visible = false;
	  else if(Form1->Chart5->Visible)
	 Form1->Chart5->Visible = false;
	  else if(Form1->Chart6->Visible)
	 Form1->Chart6->Visible = false;
	  else if(Form1->Chart7->Visible)
	 Form1->Chart7->Visible = false;
	Form1->Chart2->Visible = true;
	double Ax[101], Ay[101];

	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(Form1->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(Form1->StringGrid29->Cells[2][i]);
		Series2->AddXY(Ax[i],Ay[i]);
//
	}
	Form1->Chart2->BottomAxis->Title->Text = "L, мм" ;
	Form1->Chart2->LeftAxis->Title->Text = "M, Н*мм" ;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{

	 Series3->Clear();
	if(Form1->Chart1->Visible)
	Form1->Chart1->Visible = false;
	 else if(Form1->Chart2->Visible)
	 Form1->Chart2->Visible = false;
	 else if(Form1->Chart4->Visible)
	 Form1->Chart4->Visible = false;
	 else if(Form1->Chart5->Visible)
	 Form1->Chart5->Visible = false;
	 else if(Form1->Chart6->Visible)
	 Form1->Chart6->Visible = false;
	 else if(Form1->Chart7->Visible)
	 Form1->Chart7->Visible = false;
	 Form1->Chart3->Visible = true;
	double Ax[101], Ay[101];

	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(Form1->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(Form1->StringGrid29->Cells[5][i]);
		Series3->AddXY(Ax[i],Ay[i]);
	}
	Form1->Chart3->BottomAxis->Title->Text = "L, мм" ;
	Form1->Chart3->LeftAxis->Title->Text = "W, мм" ;

}
//---------------------------------------------------------------------------




void __fastcall TForm1::ExcelInClick(TObject *Sender)
{
	int IRow,k;
	for (IRow=0;IRow<101;IRow++){
	for (k=0;k<9;k++){ Form1->StringGrid29->Cells[k][IRow] = ' '; }}
	for (IRow=0;IRow<101;IRow++){
	for (k=0;k<9;k++){ Form1->StringGrid5->Cells[k][IRow] = ' '; }}
	for (IRow=0;IRow<101;IRow++){
	for (k=0;k<12;k++){ Form1->StringGrid6->Cells[k][IRow] = ' '; }}
		for (IRow=0;IRow<101;IRow++){
	for (k=0;k<4;k++){ Form1->StringGrid30->Cells[k][IRow] = ' '; }}
		for (IRow=0;IRow<101;IRow++){
	for (k=0;k<4;k++){ Form1->StringGrid31->Cells[k][IRow] = ' '; }}
	for (IRow=0;IRow<101;IRow++){
	for (k=0;k<4;k++){ Form1->StringGrid32->Cells[k][IRow] = ' '; }}
	med=false;
	Form1->Edit2->Text = 1;
	med=true;




	if (OpenDialog1->Execute())
	{

	Variant ExcelApplicationl,ExcelWorkBookl,ExcelWorksheetl;

	ExcelApplicationl = CreateOleObject("Excel.Application");
	ExcelApplicationl.OlePropertyGet("Application").OlePropertyGet("Workbooks").OlePropertyGet("Open", WideString(Form1->OpenDialog1->FileName.c_str()));
																				  //ExcelApplicationl.Visible:=True;
	ExcelWorksheetl = ExcelApplicationl.OlePropertyGet("ActiveSheet");

	NU = StrToInt(ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item", 2 ,1));
	NE = StrToInt(ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item", 2,2 ));
	Form1->StringGrid4->Cells[0][0] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item", 2 ,1);
	Form1->StringGrid4->Cells[1][0] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item", 2,2 );
	Form1->StringGrid4->RowCount = 1;
	  for (IRow=0;IRow<NU;IRow++)
		{
		  k = IRow + 5;
		  Form1->StringGrid5->Cells[0][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item", k ,1 );
		  Form1->StringGrid5->Cells[1][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k,2 );
		  Form1->StringGrid5->Cells[2][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k,3 );
		  Form1->StringGrid5->Cells[3][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k,4 );
		  Form1->StringGrid5->Cells[4][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 5);
		  Form1->StringGrid5->Cells[5][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 6);
		  Form1->StringGrid5->Cells[6][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 7);
		  Form1->StringGrid5->Cells[7][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 8);
		  Form1->StringGrid5->Cells[8][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 9);
		}
//	   Form1->StringGrid5->RowCount = NU;
//	  RowCount:=NE+1;
	  for (IRow=0;IRow<NE;IRow++)
		{
		  k = IRow + 5 + NU + 2;
		  Form1->StringGrid6->Cells[0][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item", k ,1 );
		  Form1->StringGrid6->Cells[1][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k,2 );
		  Form1->StringGrid6->Cells[2][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k,3 );
		  Form1->StringGrid6->Cells[3][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k,4 );
		  Form1->StringGrid6->Cells[4][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 5);
		  Form1->StringGrid6->Cells[5][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 6);
		  Form1->StringGrid6->Cells[6][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 7);
		  Form1->StringGrid6->Cells[7][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 8);
		  Form1->StringGrid6->Cells[8][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 9);
		  Form1->StringGrid6->Cells[9][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 10);
		  Form1->StringGrid6->Cells[10][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 11);
		  Form1->StringGrid6->Cells[11][IRow] = ExcelWorksheetl.OlePropertyGet("Cells").OlePropertyGet("Item",  k, 12);
		}
//		Form1->StringGrid6->RowCount = NE;
//  ExcelApplicationl.Workbooks.Close;
  ExcelApplicationl.OlePropertyGet("Application").OleProcedure("Quit");
  ExcelWorksheetl = Unassigned;
  ExcelApplicationl = Unassigned;
  Form1->TabControl1->ActiveTab = TabItem2;
  Form1->CalcItem->Enabled = True;
							 }

  }
//---------------------------------------------------------------------------

void __fastcall TForm1::TablOutClick(TObject *Sender)
{
  Form1->TabControl1->ActiveTab = TabItem10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CalcItemClick(TObject *Sender)
{
	Getusel();
	Getelem();

	Getglobmtx();
	Getglobvec();

	for(int i=0;i<3;i++)
	  for(int j=0;j<3;j++)
	  {
		Form1->StringGrid8->Cells[i][j] = FloatToStrF(EL[0].Lmtx[0][0].mtx(i,j),ffFixed,8,2);
		}

		for(int i=0;i<6;i++)
	  for(int j=0;j<6;j++)
	  {
		Form1->StringGrid9->Cells[i][j] = FloatToStrF(EL[0].Tmtx(i,j),ffFixed,8,2);
		}
		for(int i=0;i<6;i++)
	  for(int j=0;j<6;j++)
	  {
		Form1->StringGrid10->Cells[i][j] = FloatToStrF(EL[0].Trmtx(i,j),ffFixed,8,2);
		}



			Form1->StringGrid18->Cells[0][0] = FloatToStrF(EL[0].Lvec[0].v(0),ffFixed,8,2);
			Form1->StringGrid18->Cells[0][1] = FloatToStrF(EL[0].Lvec[0].v(1),ffFixed,8,2);
			Form1->StringGrid18->Cells[0][2] = FloatToStrF(EL[0].Lvec[0].v(2),ffFixed,8,2);
			Form1->StringGrid18->Cells[0][3] = FloatToStrF(EL[0].Lvec[1].v(0),ffFixed,8,2);
			Form1->StringGrid18->Cells[0][4] = FloatToStrF(EL[0].Lvec[1].v(1),ffFixed,8,2);
			Form1->StringGrid18->Cells[0][5] = FloatToStrF(EL[0].Lvec[1].v(2),ffFixed,8,2);

			Form1->StringGrid18->Cells[2][0] = FloatToStrF(EL[0].Gvec[0].v(0),ffFixed,8,2);
			Form1->StringGrid18->Cells[2][1] = FloatToStrF(EL[0].Gvec[0].v(1),ffFixed,8,2);
			Form1->StringGrid18->Cells[2][2] = FloatToStrF(EL[0].Gvec[0].v(2),ffFixed,8,2);
			Form1->StringGrid18->Cells[2][3] = FloatToStrF(EL[0].Gvec[1].v(0),ffFixed,8,2);
			Form1->StringGrid18->Cells[2][4] = FloatToStrF(EL[0].Gvec[1].v(1),ffFixed,8,2);
			Form1->StringGrid18->Cells[2][5] = FloatToStrF(EL[0].Gvec[1].v(2),ffFixed,8,2);



	prmtx();

	Boundary_Data();

	Dlt = MGmod.colPivHouseholderQr().solve(FGmod);

	  for(int j=0;j<6;j++)
	  {
		Form1->StringGrid17->Cells[0][j] = FloatToStrF(Dlt(j),ffFixed,8,2);
	  }
	usl();

 // {Очищаем таблицу}
  for (int IRow=0;IRow<101;IRow++){
	 for (int k=0;k<9;k++){ Form1->StringGrid29->Cells[k][IRow] = ' '; }}

	 for(int i=0;i<NE;i++)
	 Calc_ParametersNDS(i);
	 Calc_ParametersNDS(0);
	 pNDS();
	 pS();
	 pR();
	 Form1->Output->Enabled = true;

	 ShowMessage("Расчёт выполнен");
	// Form1->CalcItem->Enabled = false;
	for(int i=0;i<3*NU;i++)
	{
		FGmod(i)=0;
		for(int j=0;j<3*NU;j++)
		{
			MGmod(i,j)=0;
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::GraphOutClick(TObject *Sender)
{
	Form1->Chart1->Visible = false;
	Form1->Chart2->Visible = false;
	Form1->Chart3->Visible = false;
	Form1->Chart4->Visible = false;
	Form1->Chart5->Visible = false;
	Form1->Chart7->Visible = false;
	Form1->Chart6->Visible = false;
	Form1->TabControl1->ActiveTab = TabItem12;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ManualInClick(TObject *Sender)
{
	int IRow,k;
	for (IRow=0;IRow<101;IRow++){
	for (k=0;k<9;k++){ Form1->StringGrid29->Cells[k][IRow] = ' '; }}
	for (IRow=0;IRow<101;IRow++){
	for (k=0;k<9;k++){ Form1->StringGrid5->Cells[k][IRow] = ' '; }}
	for (IRow=0;IRow<101;IRow++){
	for (k=0;k<12;k++){ Form1->StringGrid6->Cells[k][IRow] = ' '; }}
        	for (IRow=0;IRow<101;IRow++){
	for (k=0;k<4;k++){ Form1->StringGrid30->Cells[k][IRow] = ' '; }}
		for (IRow=0;IRow<101;IRow++){
	for (k=0;k<4;k++){ Form1->StringGrid31->Cells[k][IRow] = ' '; }}
	for (IRow=0;IRow<101;IRow++){
	for (k=0;k<4;k++){ Form1->StringGrid32->Cells[k][IRow] = ' '; }}
	med=false;
	Form1->Edit2->Text = 1;
	med=true;
	MasterIn->Show();
	Form1->TabControl1->ActiveTab = TabItem2;
	Form1->CalcItem->Enabled = True;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::RefClick(TObject *Sender)
{
//	URef->tcRef->ActiveTab = tb;
//	URef->Show;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button15Click(TObject *Sender)
{
//	if(!(Form1->TabControl2->Visible))
//		Form1->TabControl2->Visible = true;
	 Form1->TabControl2->ActiveTab = TabItem14;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
	LineSeries3->Clear();
	if(Form1->Chart1->Visible)
	Form1->Chart1->Visible = false;
	 else if(Form1->Chart2->Visible)
	 Form1->Chart2->Visible = false;
	 else if(Form1->Chart3->Visible)
	 Form1->Chart3->Visible = false;
	 else if(Form1->Chart4->Visible)
	 Form1->Chart4->Visible = false;
	 else if(Form1->Chart5->Visible)
	 Form1->Chart5->Visible = false;
	 else if(Form1->Chart7->Visible)
	 Form1->Chart7->Visible = false;
	 Form1->Chart6->Visible = true;
	double Ax[101], Ay[101];

	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(Form1->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(Form1->StringGrid29->Cells[6][i]);
		LineSeries3->AddXY(Ax[i],Ay[i]);
	}
	Form1->Chart6->BottomAxis->Title->Text = "L, мм" ;
	Form1->Chart6->LeftAxis->Title->Text = "fi, рад" ;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
	LineSeries4->Clear();
	Series4->Clear();
	if(Form1->Chart1->Visible)
	Form1->Chart1->Visible = false;
	 else if(Form1->Chart2->Visible)
	 Form1->Chart2->Visible = false;
	 else if(Form1->Chart3->Visible)
	 Form1->Chart3->Visible = false;
	 else if(Form1->Chart4->Visible)
	 Form1->Chart4->Visible = false;
	 else if(Form1->Chart6->Visible)
	 Form1->Chart6->Visible = false;
	 else if(Form1->Chart5->Visible)
	 Form1->Chart5->Visible = false;
	 Form1->Chart7->Visible = true;
	double Ax[101], Ay[101], By[101];

	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(Form1->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(Form1->StringGrid29->Cells[7][i]);
		By[i] = StrToFloat(Form1->StringGrid29->Cells[8][i]);
		LineSeries4->AddXY(Ax[i],Ay[i]);
		Series4->AddXY(Ax[i],By[i]);
	}
	Form1->Chart5->BottomAxis->Title->Text = "L, мм" ;
	Form1->Chart5->LeftAxis->Title->Text = "Sigma, МПа" ;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
	med = true;
	if (Form1->Edit2->Text == ' ')  {
		med = false;
	}
		else
	if (med) {

//	double x;
	nEl = StrToInt(Form1->Edit2->Text);
	if (nEl>0&&nEl<=NE) {
	Calc_ParametersNDS(nEl-1);
	pNDS();}
	else{
	med = false;
	  Form1->Edit2->Text = 1;}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawClick(TObject *Sender)
{
	fmDraw->Show();
}
//---------------------------------------------------------------------------

