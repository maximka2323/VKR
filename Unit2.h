//---------------------------------------------------------------------------


#ifndef Unit2H
#define Unit2H

#include "UHead.h"
#include <Eigen/Dense>
//---------------------------------------------------------------------------
#endif
using namespace Eigen;
class Pmtx
{
public:
	MatrixXd mtx = MatrixXd(3,3);
	friend Pmtx operator+(const Pmtx& x, const Pmtx& y)
	{
		Pmtx z;
		for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			z.mtx(i,j) = x.mtx(i,j) + y.mtx(i,j);
		}
		}
		return z;
	}
};

class Pvec
{
public:
	VectorXd v = VectorXd(3);
	friend Pvec operator+(const Pvec& x, const Pvec& y)
	{
		Pvec z;
		for(int i=0;i<3;i++){

			z.v(i) = x.v(i) + y.v(i);
		}
		return z;
	}
} ;

class usel{
public:
	double x;
	double y;
	Pvec R;
	double C[3];
	double D[3];
	int k;
	void getUS(int n)
	{
	x = StrToFloat(Form1->StringGrid5->Cells[1][n]);
	y = StrToFloat(Form1->StringGrid5->Cells[2][n]);
	R.v(0) = StrToFloat(Form1->StringGrid5->Cells[3][n]);
	R.v(1) = StrToFloat(Form1->StringGrid5->Cells[4][n]);
	R.v(2) = StrToFloat(Form1->StringGrid5->Cells[5][n]);
	C[0] = StrToInt(Form1->StringGrid5->Cells[6][n]);
	C[1] = StrToInt(Form1->StringGrid5->Cells[7][n]);
	C[2] = StrToInt(Form1->StringGrid5->Cells[8][n]);
	}

};

class element{
public:
   int U1;
   int U2;
   double E;
   double S;
   double I;
   double W;
   double ST;
   double p;
   double q;
   double Alfa;
   double T;
   double L;
   double Esin;
   double Ecos;
   int n;
   Pmtx Lmtx[2][2];
   Pmtx Gmtx[2][2];
   MatrixXd Tmtx = MatrixXd(6,6);
   MatrixXd Trmtx = MatrixXd(6,6);
   VectorXd DL = VectorXd(6);
   VectorXd FL = VectorXd(6);
   Pvec Lvec[2];
   Pvec Gvec[2];

	void SetLmtx()
   {
		for(int i=0;i<2;i++)
		{
		for(int j=0;j<2;j++)
			{
			Lmtx[i][j].mtx(0,0) =  pow(-1,(i+j))*E*S/L;
			Lmtx[i][j].mtx(1,0) =  0;
			Lmtx[i][j].mtx(0,1) =  0;
			Lmtx[i][j].mtx(1,1) =  pow(-1,(i+j))*12*E*I/pow(L,3);
			Lmtx[i][j].mtx(2,0) =  0;
			Lmtx[i][j].mtx(0,2) =  0;
			Lmtx[i][j].mtx(2,2) =  (3*E*I/L) + (E*I/L) * pow(-1,(i+j));
			Lmtx[i][j].mtx(2,1) =  pow(-1,j)*6*E*I/pow(L,2);
			Lmtx[i][j].mtx(1,2) =  pow(-1,i)*6*E*I/pow(L,2);
			}
		}
   }
	void SetLvec()
   {
		for(int i=0;i<2;i++)
		{
			Lvec[i].v(0) = (p*L/2) - (pow(-1,i)*E*Alfa*T*S);
			Lvec[i].v(1) = q*L/2;
			Lvec[i].v(2) = (pow(-1,i)*pow(L,2)*q/12);
		}
   }
  void SetTmtx()
   {
		for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
		Tmtx(i,j) = 0;
		Tmtx(0,0) = Ecos;
		Tmtx(1,0) = Esin;
		Tmtx(0,1) = -Esin;
		Tmtx(1,1) = Ecos;
		Tmtx(2,2) = 1;
		Tmtx(3,3) = Ecos;
		Tmtx(4,3) = Esin;
		Tmtx(3,4) = -Esin;
		Tmtx(4,4) = Ecos;
		Tmtx(5,5) = 1;

   }
   void SetTrmtx()
   {
		Trmtx = Tmtx.transpose() ;
   }
   void SetGmtx()
   {
		MatrixXd gmtx(6,6);
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
			gmtx(3*i,3*j) = Lmtx[i][j].mtx(0,0);
			gmtx(3*i+1,3*j) = Lmtx[i][j].mtx(1,0);
			gmtx(3*i,3*j+1) = Lmtx[i][j].mtx(0,1);
			gmtx(3*i+1,3*j+1) = Lmtx[i][j].mtx(1,1);
			gmtx(3*i+2,3*j) = Lmtx[i][j].mtx(2,0);
			gmtx(3*i,3*j+2) = Lmtx[i][j].mtx(0,2);
			gmtx(3*i+2,3*j+2) = Lmtx[i][j].mtx(2,2);
			gmtx(3*i+2,3*j+1) = Lmtx[i][j].mtx(2,1);
			gmtx(3*i+1,3*j+2) = Lmtx[i][j].mtx(1,2);
			}
		}
        gmtx = Tmtx * gmtx;
		gmtx = gmtx * Trmtx;

		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
			Gmtx[i][j].mtx(0,0) = gmtx(3*i,3*j) ;
			Gmtx[i][j].mtx(1,0) = gmtx(3*i+1,3*j);
			Gmtx[i][j].mtx(0,1) = gmtx(3*i,3*j+1) ;
			Gmtx[i][j].mtx(1,1) = gmtx(3*i+1,3*j+1) ;
			Gmtx[i][j].mtx(2,0) = gmtx(3*i+2,3*j);
			Gmtx[i][j].mtx(0,2) = gmtx(3*i,3*j+2);
			Gmtx[i][j].mtx(2,2) = gmtx(3*i+2,3*j+2);
			Gmtx[i][j].mtx(2,1) = gmtx(3*i+2,3*j+1);
			Gmtx[i][j].mtx(1,2) = gmtx(3*i+1,3*j+2);
			}
		}
   }
   void SetGvec()
   {
		VectorXd vc(6);
		for(int i=0;i<2;i++)
		{
			vc(3*i) = Lvec[i].v(0) ;
			vc(3*i+1) = Lvec[i].v(1) ;
			vc(3*i+2) = Lvec[i].v(2)  ;
		}
		vc = Trmtx * vc;
		for(int i=0;i<2;i++)
		{
			Gvec[i].v(0) = vc(3*i) ;
			Gvec[i].v(1) = vc(3*i+1)  ;
			Gvec[i].v(2) = vc(3*i+2)  ;
		}
   }
   void getEL(int n)
	{
	U1 = StrToInt(Form1->StringGrid6->Cells[1][n]);
	U2 = StrToInt(Form1->StringGrid6->Cells[2][n]);
	E = StrToFloat(Form1->StringGrid6->Cells[3][n]);
	S = StrToFloat(Form1->StringGrid6->Cells[4][n]);
	I = StrToFloat(Form1->StringGrid6->Cells[5][n]);
	W = StrToFloat(Form1->StringGrid6->Cells[6][n]);
	ST = StrToFloat(Form1->StringGrid6->Cells[7][n]);
	p = StrToFloat(Form1->StringGrid6->Cells[8][n]);
	q = StrToFloat(Form1->StringGrid6->Cells[9][n]);
	Alfa = StrToFloat(Form1->StringGrid6->Cells[10][n]);
	T = StrToFloat(Form1->StringGrid6->Cells[11][n]);
	}

} ;

