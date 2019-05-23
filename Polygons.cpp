#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
using namespace std;
int getxy(string z, float x[], float y[]);
string getpoly(string z, string p, int order);
int polyno(string z);
float Max_x(string z, float maxx);
float Min_x(string z, float maxx);
float Max_y(string z, float maxx);
float Min_y(string z, float maxx);
int totalred(string z);
void printpointa(float x[], float y[], int s);
void printpola(int x[], int s);
void printpoints(float x, float y);
int polpts(string p, float x[], float y[]);
int ptspol(string z, int ptpol[], float x1, float y1);
int polyptmore(string z, int ptpol[], int v);
int polyptless(string z, int ptpol[], int v);
int polyptequal(string z, int ptpol[], int v);
float polyprem(string p);
void rectangles(string z);
void trapezoid(string z);
void insiderect(string z, string v);
void insidecir(string z, string v);
float printarea(string z, string v);
float printarea(string z, int a);
void printrange(string z, string v);
int checkclock(float x[], float y[], int j);
void inversepts(float x[], float y[], int j);
int checkinside(float x1, float y1, float x[], float y[],int j);
void printenclose(string z, string v);
int intersect(string z, string v);
int intersect(string z, int p1, int p2);
int intergrp(string z, string v);
void largestpair(string z);
void listptsmore(string z, string v);
void listptsless(string z, string v);
void listptseq(string z, string v);
int listptsless(string z, int n, float xo[], float yo[], int f);
int listptsmore(string z, int n, float xo[], float yo[], int f);






int main()
{
	int n, i, j = 0, j1 = 0, l = 0, k = 0, w = 0, s, f, q, h, v;
	float x[100], y[100], x1, y1;
	int ptpol[100], totalpoints, totalredundant;
	string z, o[50], p;
	cout << "enter input" << endl;
	//operations counter
	z = "Polygons=[(1,1),(2,2),(1,3),(0,2);(0,1),(3,3),(1,6),(-2,4);(2,3),(5,3),(4,8);(5,5),(7,7),(7,7),(6,8),(4,11),(3,10),(2,5),(3,3),(3,3),(5,5);(4,5),(7,8),(6,11),(3,8);(2,6),(5,8),(5,13),(1,11);(0,6),(2,10),(2,12),(-1,13),(-2,11),(-2,7);(-5,5),(-1,5),(-1,10),(-1,10),(-5,12);(-4,4),(-1,8),(-2,10),(-4,4);(-5,3),(-3,3),(-1,3),(-3,7),(-5,6);(-2,-1),(-4,-4),(-4,-7),(-2,-9),(-2,-4),(-2,-1);(-2,-7),(-4,-10),(-1,-12);(-1,-6),(-3,-6),(-2,-9),(1,-11),(3,-6),(0,-6),(-1,-6);(1,-9),(4,-2),(7,-5),(4,-11);(5,-5),(1,-3),(4,1),(7,2),(7,-6);(-1,1),(-2,2),(3,5),(4,4)]";
	totalpoints = getxy(z, x, y);
	float maxx = x[0], minx = x[0], maxy = y[0], miny = y[0];
	minx = Min_x(z, minx);
	maxy = Max_y(z, maxy);
	maxx = Max_x(z, maxx);
	miny = Min_y(z, miny);
	totalredundant = totalred(z);
	






	for (s = 0; s <= 50; s++)
	{
		getline(cin, o[s]);
		if (o[s] == "Number_Polygons")cout << polyno(z);
		if (o[s] == "Total_Number_Points")cout << getxy(z, x, y);
		if (o[s] == "Minimum_X")cout << minx;
		if (o[s] == "Maximum_Y")cout << maxy;
		if (o[s] == "Maximum_X")cout << maxx;
		if (o[s] == "Minimum_Y")cout << miny;
		if (o[s] == "Enclosing_Rectangle")cout << "(" << minx << "," << miny << ")" << "," << "(" << minx << "," << maxy << ")" << "," << "(" << maxx << "," << maxy << ")" << "," << "(" << maxx << "," << miny << ")";
		if (o[s] == "Total_Redundant_Points")cout << totalredundant;
		if (o[s] == "Quit")break;
		if (o[s].substr(0, 14) == "Polygon_Points")
		{
			v = atoi(o[s].substr(15).c_str());
			p = getpoly(z, p, v);
			f = polpts(p, x, y);
			if (f == 0)cout << "none";
			else
			printpointa(x, y, f);
		}
		if (o[s].substr(0, 14) == "Point_Polygons")
		{
			x1 = atof(o[s].substr(16, (o[s].find(",", 16) - 16)).c_str());
			y1 = atof(o[s].substr((o[s].find(",", 15) + 1), (o[s].find(")") - (o[s].find(",") - 1))).c_str());
			j1 = ptspol(z, ptpol, x1, y1);
			if (j1 == 0)cout << "none";
			printpola(ptpol, j1);
		}
		if (o[s].substr(0, 25) == "List_Polygons_Points More")
		{
			v = atoi(o[s].substr(26).c_str());
			n = polyptmore(z, ptpol, v);
			if (n == 0)cout << "none";
			printpola(ptpol, n);

		}
		if (o[s].substr(0, 26) == "List_Polygons_Points Equal")
		{
			v = atoi(o[s].substr(27).c_str());
			n = polyptequal(z, ptpol, v);
			if (n == 0)cout << "none";
			printpola(ptpol, n);

		}
		if (o[s].substr(0, 25) == "List_Polygons_Points Less")
		{
			v = atoi(o[s].substr(26).c_str());
			n = polyptless(z, ptpol, v);
			if (n == 0)cout << "none";
			printpola(ptpol, n);

		}
		if (o[s].substr(0,17) == "Polygon_Perimeter")
		{
			v= atoi(o[s].substr(18).c_str());
			cout << polyprem(getpoly(z, p, v));

		}
		if (o[s] == "List_Triangles")
		{
			n = polyptequal(z, ptpol, 3);
			printpola(ptpol, n);
		}
		if (o[s] == "List_Rectangles")rectangles(z);
		if (o[s] == "List_Trapezoid")trapezoid(z);
		if (o[s].substr(0, 16) == "Inside_Rectangle")insiderect(z, o[s]);
		if (o[s].substr(0, 13) == "Inside_Circle")insidecir(z, o[s]);
		if (o[s].substr(0, 12) == "Polygon_Area")cout<<printarea(z, o[s]);
		if (o[s].substr(0, 19) == "Polygons_Area_Range")printrange( z, o[s]);
		if (o[s].substr(0, 24) == "Polygons_Enclosing_Point")printenclose(z, o[s]);
		if (o[s].substr(0, 15) == "Is_Intersecting")
		{
			if (intersect(z, o[s]) > 0)cout << "TRUE";
			else cout << "FALSE";

		}
		if (o[s].substr(0, 18) == "Intersecting_Group")
		
		{
			if (intergrp(z, o[s]) > 0)cout << "TRUE";
			else cout << "FALSE";

		}
		if (o[s].substr(0, 25) == "Largest_Intersecting_Pair")largestpair( z);
		if (o[s].substr(0, 25) == "List_Points_Polygons More")listptsmore(z, o[s]);
		if (o[s].substr(0, 25) == "List_Points_Polygons Less")listptsless(z, o[s]);
		if (o[s].substr(0, 26) == "List_Points_Polygons Equal")listptseq(z, o[s]);



		}
		return 0;
	
}
int getxy(string z, float x[], float y[])
{
	int n = z.length();
	int i, k, j = 0, l;
	for (i = 0; i <= n; i++)
	{

		if (z.substr(i, 1) == "(")
		{

			for (k = i; k <= n; k++)
			{
				if (z.substr(k, 1) == ",") { x[j] = atof(z.substr(i + 1, k - i - 1).c_str()); break; }
			}
			for (l = k + 2; l <= n; l++)
			{
				if (z.substr(l, 1) == ")") { y[j] = atof(z.substr(k + 1, l - k - 1).c_str()); break; }
			}
			j++;
			i = l;
		}
		if (j == 99)i = 0;
	}
	return j;
}
string getpoly(string z, string p,int order)
{
	int i, j, k,a,b,c=0,d=order-1,e,f,n=z.length(),s=polyno(z);
	int w = polyno(z);
	
	

	if (order == 1)
	{
		for (j = 0; j <= n; j++)
		{
			if (z.substr(j, 1) == "[") {
				a = j;
				if (s == 1) 
				{ p = z.substr(a +	1, n - a - 2); break; }
			}
			
			if (z.substr(j, 1) == ";")
			{ b = j;
			p = z.substr(a+1, b - a-1);
			break;
			}
		}
	}

	else if (order == w)
	{
		for (j = 0; j <= n; j++)
		{
			if (z.substr(j, 1) == ";")c++;
			if (c == w - 1)
			{

				p = z.substr(j + 1, n - j - 1);
				break;
			}
		}
	}
	else
	{
		for (i = 0; i <= n; i++)
		{
			if (z.substr(i, 1) == ";")
			{
				c++;
				if (c == d)e = i;
			}
			
			if (c == order) 
			{ 
				f = i;
				p = z.substr(e+1, f - e -1);
				break;
			}
		}
	}
	return p;
}
int polyno(string z)
{
	int i, j=1,n;
	n = z.length();
	for (i = 0; i <n; i++)
	{
		if (z.substr(i, 1) == ";")j++;
	}
	return j;
}
float Max_x(string z,float maxx)
{
	string p;
	float x[100], y[100];
	int i, j,f, k, n;
	k = polyno(z);
	for (i = 1; i <= k; i++)
	{
		p = getpoly(z, p, i);
		n = p.length();
		f = getxy(p, x, y);
		for (j = 0; j <= f; j++)
		{
			if (x[j] > maxx)maxx = x[j];
		}
	}return maxx;
}
float Min_x(string z, float maxx)
{
	string p;
	float x[100], y[100];
	int i, j, f, k, n;
	k = polyno(z);
	for (i = 1; i <= k; i++)
	{
		p = getpoly(z, p, i);
		n = p.length();
		f = getxy(p, x, y);
		for (j = 0; j < f; j++)
		{
			if (x[j] < maxx)maxx = x[j];
		}
	}return maxx;
}
float Max_y(string z, float maxx)
{
	string p;
	float x[100], y[100];
	int i, j, f, k, n;
	k = polyno(z);
	for (i = 1; i <= k; i++)
	{
		p = getpoly(z, p, i);
		n = p.length();
		f = getxy(p, x, y);
		for (j = 0; j <= f; j++)
		{
			if (y[j] > maxx)maxx = y[j];
		}
	}return maxx;
}
float Min_y(string z, float maxx)
{
	string p;
	float x[100], y[100];
	int i, j, f, k, n;
	k = polyno(z);
	for (i = 1; i <= k; i++)
	{
		p = getpoly(z, p, i);
		n = p.length();
		f = getxy(p, x, y);
		for (j = 0; j < f; j++)
		{
			if (y[j] < maxx)maxx = y[j];
		}
	}return maxx;
}
int totalred(string z)
{
	string p;
	int i, j, k,r=0,f,n,t,s,as;
	float x[100], y[100],slope,intercept;
	f = polyno(z);
	for (i = 1; i <= f; i++)
	{
		p = getpoly(z, p, i  );
		j = getxy(p, x, y);
		t = 0;
		for (k = 0; k < j-t; k++)
		{
			if (k == j - 2 - t)
			{
				slope = (y[k] - y[0]) / (x[k] - x[0]);
				intercept = (y[k] - (slope*x[k]));
				
				if ((y[k + 1]) == ((slope*x[k + 1]) + intercept))
				{
					r++; t++; k = k - 1; 

				}
				slope = (y[k + 1] - y[1]) / (x[k + 1] - x[1]);
				intercept = (y[1] - (slope*x[1]));
				if (y[0] == slope*x[0] + intercept) { r++; t++; x[0] = x[k + 1]; y[0] = y[k + 1]; }
				break;


			}
			slope = (y[k + 2] - y[k]) / (x[k + 2] - x[k]);
			intercept = (y[k] - (slope*x[k]));
			if (x[k] == x[k + 1] && x[k +1] == x[k + 2])
			{
				r++; t++; 
				for (n = k+1 ; n < j - t; n++)
				{
					x[n] = x[n+ 1];
					y[n] = y[n + 1];
					

				}
				k--;
			}
			
			else if (y[k + 1] == slope*x[k + 1] + intercept)
			{
				r++; t++;
				for (n = k + 1; n < j-t; n++)
				{
					x[n] = x[n + 1];
					y[n] = y[n + 1];
					

				}
				k--;

			}
			
		}
		
	}
	return r;
}
void printpointa(float x[], float y[],int s)
{
	int i, j, k;
	string z;
		for (i = 0; i < s; i++) 
		{
			cout << "(" << x[i] << "," << y[i] << ")";
			if (i != s-1)cout << ",";
		}
}
void printpola(int x[], int s)
{
	int i, j, k;
	string z;
	for (i = 0; i < s; i++)
	{
		cout  << x[i];
		if (i != s-1 )cout << ",";
	}
}
void printpoints(float x, float y)
{
	cout << "(" << x << "," << y << ")";
}
int polpts(string p,float x[],float y[])
{
	int i, j, k, f, n, t, s;
	float slope, intercept;
		j = getxy(p, x, y);
		t = 0;
		for (k = 0; k < j - t; k++)
		{
			if (k == j - 2 - t)
			{
				slope = (y[k] - y[0]) / (x[k] - x[0]);
				intercept = (y[k] - (slope*x[k]));
				if ((y[k + 1]) == ((slope*x[k + 1]) + intercept))
				{
					 t++; break;
				}
				slope = (y[k + 1] - y[1]) / (x[k + 1] - x[1]);
				intercept = (y[1] - (slope*x[1]));
				if (y[0] == slope*x[0] + intercept) { t++; x[0] = x[k+1]; y[0] =y[k+1] ; }
				break;
			}
			slope = (y[k + 2] - y[k]) / (x[k + 2] - x[k]);
			intercept = (y[k] - (slope*x[k]));
			if (x[k] == x[k + 1] && x[k + 1] == x[k + 2])
			{
				 t++;
				for (n = k + 1; n < j - t; n++)
				{
					x[n] = x[n + 1];
					y[n] = y[n + 1];


				}
				k--;
			}

			else if (y[k + 1] == slope*x[k + 1] + intercept)
			{
			 t++;
				for (n = k + 1; n < j - t; n++)
				{
					x[n] = x[n + 1];
					y[n] = y[n + 1];


				}
				k--;

			}

		

	}
	return (j-t);
}
int ptspol(string z, int ptpol[],float x1,float y1)
{
	int i, j, k=0,f, n;
	float x[100], y[100];
	string p;
	f = polyno(z);
	for (i = 1; i <= f; i++)
	{
		p = getpoly(z, p, i);
		n = polpts(p, x, y);
		for (j = 0; j < n; j++)
		{
			if(x[j]==x1&&y[j]==y1)
			{
				ptpol[k] = i;
				k++;
			}
		}
	}
	return k;
}
int polyptmore(string z, int ptpol[], int v)
{
	int j, n,h, i;
	string p;
	float x[100], y[100];
	j = polyno(z);
	n = 0;
	for (i = 1; i <= j; i++)
	{
		p = getpoly(z, p, i);
		h = polpts(p, x, y);
		if (h > v)
		{
			ptpol[n] = i;
			n++;
		}
	}

	return n;
}
int polyptequal(string z, int ptpol[], int v)
{
	int j, n, h, i;
	string p;
	float x[100], y[100];
	j = polyno(z);
	n = 0;
	for (i = 1; i <= j; i++)
	{
		p = getpoly(z, p, i);
		h = polpts(p, x, y);
		if (h == v)
		{
			ptpol[n] = i;
			n++;
		}
	}

	return n;
}
int polyptless(string z, int ptpol[], int v)
{
	int j, n, h, i;
	string p;
	float x[100], y[100];
	j = polyno(z);
	n = 0;
	for (i = 1; i <= j; i++)
	{
		p = getpoly(z, p, i);
		h = polpts(p, x, y);
		if (h < v)
		{
			ptpol[n] = i;
			n++;
		}
	}

	return n;
}
float polyprem(string p)
{
	float x[100], y[100],prem=0,dist;
	int i,j;
	j = getxy(p, x, y);
	for (i = 0; i < j; i++)
	{
		if (i == j - 1)
		{
			dist = sqrt(pow((x[0] - x[i]), 2) + pow((y[0] - y[i]), 2));
			prem += dist;
			break;
		}
		dist = sqrt(pow((x[i + 1] - x[i]), 2) + pow((y[i + 1] - y[i]), 2));
		prem += dist;
	}
	return prem;
}
void rectangles(string z)
{
	int i, j=0, k, l, ptpol[100], rects[100];
	string p;
	float x[100], y[100],slope1,slope2,slope3,slope4;
	l = polyptequal(z,  ptpol, 4);
	for (i = 0; i < l; i++)
	{
		p = getpoly(z, p, ptpol[i]);
		k = polpts(p, x, y);
		if ((x[0] != x[1] && x[2] != x[3]))
		{
			if ((x[2] != x[1] && x[0] != x[3]))
			{
				slope1 = (y[0] - y[1]) / (x[0] - x[1]);
				slope2 = (y[2] - y[1]) / (x[2] - x[1]);
				slope3 = (y[0] - y[3]) / (x[0] - x[3]);
				slope4 = (y[3] - y[2]) / (x[3] - x[2]);
			}
		}
		if (x[0] == x[1] && x[2] == x[3] && y[2] == y[1] && y[0] == y[3])
		{
			rects[j] = ptpol[i];
			j++;
		}
		else if (x[2] == x[1] && x[0] == x[3] && y[0] == y[1] && y[2] == y[3])
		{
			rects[j] = ptpol[i];
			j++;
		}
		else if (slope1 == slope4 && slope2 == slope3 && slope1*slope2 == -1)
		{
			rects[j] = ptpol[i];
			j++;
		}

	}
	printpola(rects, j);

	

}
void trapezoid(string z)
{

	int i, j = 0, k, l, ptpol[100], rects[100];
	string p;
	float x[100], y[100], slope1, slope2, slope3, slope4;
	l = polyptequal(z, ptpol, 4);
	for (i = 0; i < l; i++)
	{
		p = getpoly(z, p, ptpol[i]);
		k = polpts(p, x, y);
		if ((x[0] != x[1] && x[2] != x[3]))
		{
			if ((x[2] != x[1] && x[0] != x[3]))
			{
				slope1 = (y[0] - y[1]) / (x[0] - x[1]);
				slope2 = (y[2] - y[1]) / (x[2] - x[1]);
				slope3 = (y[0] - y[3]) / (x[0] - x[3]);
				slope4 = (y[3] - y[2]) / (x[3] - x[2]);
			}
		}
		if (x[0] == x[1] && x[2] == x[3])
		{
			if (sqrt(pow((x[0] - x[1]), 2) + pow((y[0] - y[1]), 2)) != sqrt(pow((x[3] - x[2]), 2) + pow((y[3] - y[2]), 2)))
			{

				rects[j] = ptpol[i];
				j++;

			}
		}
		else if (x[0] == x[3] && x[2] == x[1])
		{
			if (sqrt(pow((x[0] - x[3]), 2) + pow((y[0] - y[3]), 2)) != sqrt(pow((x[1] - x[2]), 2) + pow((y[1] - y[2]), 2)))
			{

				rects[j] = ptpol[i];
				j++;

			}
		}
		else if (slope1 == slope4)
		{
			if (sqrt(pow((x[0] - x[1]), 2) + pow((y[0] - y[1]), 2)) != sqrt(pow((x[3] - x[2]), 2) + pow((y[3] - y[2]), 2)))
			{
				
					rects[j] = ptpol[i];
					j++;
				
			}
		}
		else if (slope2 == slope3)
		{
			
				if (sqrt(pow((x[3] - x[0]), 2) + pow((y[3] - y[0]), 2)) != sqrt(pow((x[2] - x[1]), 2) + pow((y[2] - y[1]), 2)))
				{
					rects[j] = ptpol[i];
					j++;
				
			}
		}

	}
	printpola(rects, j);

}
void insiderect(string z, string v)
{
	int i, k, n,j=0,f,s,o=0,h=0, l;
	n = v.length();
	float x1[4], y1[4],x[100],y[100],maxx,maxy,minx,miny;
	string p;
	int insiderec[100];
	
	
	for (i = 17; i <= n; i++)
	{

		if (v.substr(i, 1) == "(")
		{

			for (k = i; k <= n; k++)
			{
				if (v.substr(k, 1) == ",") { x1[j] = atof(v.substr(i + 1, k - i - 1).c_str()); break; }
			}
			for (l = k + 2; l <= n; l++)
			{
				if (v.substr(l, 1) == ")") { y1[j] = atof(v.substr(k + 1, l - k - 1).c_str()); break; }
			}
			j++;
			i = l;
		}
	}maxx = x1[0], miny = y1[0], minx = x1[0], maxy = y1[0] ;
	for (i = 0; i < 4; i++)
	{
		if (x1[i] > maxx)maxx = x1[i];
		if (x1[i] < minx)minx = x1[i];
		if (y1[i] > maxy)maxy = y1[i];
		if (x1[i] < miny)miny = y1[i];
	}
	k = polyno(z);
	for (i = 1; i <= k; i++)
	{
		p = getpoly(z, p, i);
		f = getxy(p, x, y);
		h = 0;
		for (s = 0; s < f; s++)
		{
			if (x[s] > maxx || x[s]<miny || y[s]>maxy || y[s] < miny)
				continue;
			else
				h++;
		}
		if (h == f )
		{ insiderec[o] = i; o++; }
	}
	if (o == 0)cout << "none";
	printpola(insiderec, o);
}
void insidecir(string z, string v)
{
	float x1, y1, r,x[100],y[100],dist;
	int i, j, k, l, s, o=0,h=0,insidecir[100];
	string p;
	x1= atof(v.substr(15,(v.find(",",15)-15)).c_str());
	y1= atof(v.substr((v.find(",", 15)+1), (v.find(")") -(v.find(",")- 1))).c_str());
	r = atof(v.substr((v.find(")") + 2)).c_str());
	j = polyno(z);
	for (i = 1; i <= j; i++)
	{
		p = getpoly(z, p, i);
		k = getxy(p, x, y);
		h = 0;
		for (l = 0; l < k; l++)
		{
			dist = sqrt(pow((x[l] - x1), 2) + pow((y[l] - y1), 2));
			if (dist > r)
				continue;
			else
				h++;
		}
		if (h==k)
		{
			insidecir[o] = i; o++;
		}
	}
	if (o == 0)cout << "none";
	printpola(insidecir, o);
}
float printarea(string z, string v)
{
	int i, j, k, l, m,a;
	float x[100], y[100], area = 0,areaa,sum=0;
	string p;
	a= atof(v.substr(13).c_str());
	p = getpoly(z, p, a);
	j = polpts(p, x, y);

	for (i = 0; i < j; i++)
	{
		if (i == j - 1)
		{
			sum = (x[i] * y[0]) - (x[0] * y[i]);
			area += sum;
			break;
		}
		sum = (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
		area += sum;
	}
	areaa = area*0.5;
	if (areaa < 0)areaa = 0 - areaa;
	return areaa;
}
float printarea(string z,int a)
{
	int i, j, k, l, m;
	float x[100], y[100], area = 0, areaa, sum = 0;
	string p;
	p = getpoly(z, p, a);
	j = polpts(p, x, y);

	for (i = 0; i < j; i++)
	{
		if (i == j - 1)
		{
			sum = (x[i] * y[0]) - (x[0] * y[i]);
			area += sum;
			break;
		}
		sum = (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
		area += sum;
	}
	areaa = area*0.5;
	if (areaa < 0)areaa = 0 - areaa;
	return areaa;
}
void printrange(string z, string v)
{
	int i, j, k, l=0,range[100], m;
	float x[100], y[100], minarea, maxarea;
	string p;
	minarea = atof(v.substr(20,(v.find(",")-20)).c_str());
	maxarea = atof(v.substr(v.find(",")+1).c_str());
	j = polyno(z);
	for (i = 1; i <= j; i++)
	{
		if (printarea(z, i) > maxarea || printarea(z, i) < minarea)
			continue;
		else
		{
			range[l] = i;
			l++;
		}
	}
	if (l== 0)cout << "none";
	printpola(range, l);
}
int checkclock(float x[], float y[],int j)
{
	int i, k;
	float sum = 0;
	for (i = 0; i < j; i++)
	{
		if (i == j - 1)
		{
			sum += ((x[0] - x[i])*(y[0] + y[i]));
			return sum;

		}
		sum += ((x[i + 1] - x[i])*(y[i + 1] + y[i]));
	}
}
void inversepts(float x[], float y[], int j)
{
	int i;
	float x1, y1;
	x1 = x[0];
	y1 = y[0];
	for (i = 0; i < j; i++)
	{
		if (i == (j / 2))break;
		x[i] = x[j - i - 1];
		y[i] = y[j - i - 1];
		x[j - i - 1] = x1;
		y[j - i - 1] = y1;
		x1 = x[i + 1];
		y1 = y[i + 1];
	}
}
int checkinside(float x1, float y1, float x[], float y[],int j)
{
	int i, k,h=0;
	float check;
	if (checkclock(x, y, j) > 0)inversepts(x, y, j);
	for (i = 0; i < j; i++)
	{
		if (i == j - 1)
		{
			check = (x[0] - x[i])*(y1 - y[i]) - (y[0] - y[i])*(x1 - x[i]);
			if (check == 0)  return 0;
			if (check >0)h++;
			if (h == j)return 1;
			else return -1;
		}
		check = (x[i + 1] - x[i])*(y1 - y[i]) - (y[i + 1] - y[i])*(x1 - x[i]);
		if (check == 0)  return 0;
		if (check < 0)  return -1;
		if (check > 0)
		{
			h++;
		}
	}
}
void printenclose(string z, string v)
{
	float x[100], y[100], x1, y1;
	int j, i, k, l = 0, enclose[100], m;
	string p;
	x1 = atof(v.substr(26, (v.find(",", 26) - 26)).c_str());
	y1 = atof(v.substr((v.find(",", 26) + 1), (v.find(")") - (v.find(",") - 1))).c_str());
	j = polyno(z);
	for (i = 1; i <= j; i++)
	{
		p = getpoly(z, p, i);
		k = polpts(p, x, y);
		if (checkinside(x1, y1, x, y, k) >= 0)
		{
			enclose[l] = i; l++;
		}

	}
	if (l == 0)cout << "none";
	printpola(enclose, l);
}
int intersect(string z, string v)
{
	int i, j, k, l, p1, p2;
	float x[100], y[100], x1[100], y1[100];
	string p;
	p1 = atoi(v.substr(16, (v.find(",", 16) - 16)).c_str());
	p2 = atoi(v.substr((v.find(",", 16) + 1)).c_str());
	p = getpoly(z, p, p1);
	j = polpts(p, x1, y1);
	p = getpoly(z, p, p2);
	k = polpts(p, x, y);
	for (i = 0; i < k; i++)
	{
		if (checkinside(x[i], y[i], x1, y1, j) >= 0)return 1;
	}
	for (i = 0; i < j; i++)
	{
		if (checkinside(x1[i], y1[i], x, y, k) >= 0)return 1;
	}
	return -1;
}
int intersect(string z, int p1, int p2)
{
	int i, j, k, l;
	float x[100], y[100], x1[100], y1[100];
	string p;
	p = getpoly(z, p, p1);
	j = polpts(p, x1, y1);
	p = getpoly(z, p, p2);
	k = polpts(p, x, y);
	for (i = 0; i < k; i++)
	{
		if (checkinside(x[i], y[i], x1, y1, j) >= 0)return 1;
	}
	for (i = 0; i < j; i++)
	{
		if (checkinside(x1[i], y1[i], x, y, k) >= 0)return 1;
	}
	return -1;
}
int intergrp(string z, string v)
{
	int i, j, f, k = 0, l, o = 1, grp[100];
	float x[100], y[100];
	string p;
	for (i = 0; i < v.length(); i++)
	{
		if (v[i] == ',')k++;
	}
	grp[0] = atoi(v.substr(19, (v.find(",", 19) - 19)).c_str());
	for (i = 19; i <= v.length(); i++)
	{
		if (o == k)
		{
			grp[o] = atoi(v.substr(f + 1).c_str());
			break;
		}
		if (v[i] == ',')
		{
			l = i;
			f = v.find(",", i + 1);
			grp[o] = atoi(v.substr(l + 1, f - l - 1).c_str());
			o++;
		}
	}
	o++;
	for (i = 0; i < o; i++)
	{
		if (i == o - 1)
		{
			if (intersect(z, grp[i], grp[0]) < 0)return -1;
			else return 1;
		}
		if (intersect(z, grp[i], grp[i + 1]) < 0)return -1;
	}
	return 1;
}
void largestpair(string z)
{
	int i, j, k, l, m, grp[2],n , h, o;
	string p;
	float total=0, area1=0,area2=0,maxarea=0;
	j = polyno(z);
	for (i = 1; i <= j; i++)
	{
		for (k = i+1; k <= j; k++)
		{
			if (intersect(z, i, k) > 0)
			{
				area1 = printarea(z, i);
				area2 = printarea(z, k);
				total = area1 + area2;
				if (total > maxarea)
				{
					maxarea = total;
					grp[0] = i;
					grp[1] = k;
				}

			}
		}
	}
	printpola(grp, 2);
}
void listptsmore(string z, string v)
{
	float x[100], y[100], x1[100], y1[100],xo[100],yo[100];
	int i, j, k, l, h=1, o,s, m,f=0,n,g;
	string p1,p2;
	j = polyno(z);
	n= atoi(v.substr(26).c_str());
	for (i = 1; i < j; i++)
	{
		p1 = getpoly(z, p1, i);
		k = polpts(p1, x, y);
	
			for (o = 0; o < k; o++)
			{
				h = 1;
				for (l = i + 1; l <= j; l++)
				{
					p2 = getpoly(z, p2, l);
					m = polpts(p2, x1, y1);
					for (g = 0; g < m; g++)
					{
						if (x[o] == x1[g] && y[o] == y1[g])
						{
							h++;
							break;
						}
					}
					if (h > n)break;

				}
				if (h > n)
				{
					g = 0;
					for (s = 0; s < f; s++)
					{
						if (x[o] == xo[s] && y[o] == yo[s])g=1;
						
					}

					if (g == 0)
					{
						xo[f] = x[o];
						yo[f] = y[o];
						f++;
					}
				}

		}
	}
	if (f == 0)cout << "none";
	printpointa(xo, yo, f);
}
void listptsless(string z, string v)
{
	float x[100], y[100], x1[100], y1[100], xo[100], yo[100];
	int i, j, k, l, h = 1, o, s, m, f = 0, n, g;
	string p1, p2;
	j = polyno(z);
	n = atoi(v.substr(26).c_str());
	for (i = 1; i < j; i++)
	{
		p1 = getpoly(z, p1, i);
		k = polpts(p1, x, y);

		for (o = 0; o < k; o++)
		{
			h = 1;
			for (l = i + 1; l <= j; l++)
			{
				p2 = getpoly(z, p2, l);
				m = polpts(p2, x1, y1);
				for (g = 0; g < m; g++)
				{
					if (x[o] == x1[g] && y[o] == y1[g])
					{
						h++;
						break;
					}
				}
			

			}
			if (h < n)
			{
				g = 0;
				for (s = 0; s < f; s++)
				{
					if (x[o] == xo[s] && y[o] == yo[s])g = 1;

				}

				if (g == 0)
				{
					xo[f] = x[o];
					yo[f] = y[o];
					f++;
				}
			}

		}
	}
	if (f == 0)cout << "none";
	printpointa(xo, yo, f);
	cout << endl << f;
}
int listptsmore(string z, int n, float xo[], float yo[], int f)
{
	float x[100], y[100], x1[100], y1[100];
	int i, j, k, l, h = 1, o, s, m,  g;
	f = 0;
	string p1, p2;
	j = polyno(z);
	
	for (i = 1; i < j; i++)
	{
		p1 = getpoly(z, p1, i);
		k = polpts(p1, x, y);

		for (o = 0; o < k; o++)
		{
			h = 1;
			for (l = i + 1; l <= j; l++)
			{
				p2 = getpoly(z, p2, l);
				m = polpts(p2, x1, y1);
				for (g = 0; g < m; g++)
				{
					if (x[o] == x1[g] && y[o] == y1[g])
					{
						h++;
						break;
					}
				}
				if (h > n)break;

			}
			if (h > n)
			{
				g = 0;
				for (s = 0; s < f; s++)
				{
					if (x[o] == xo[s] && y[o] == yo[s])g = 1;

				}

				if (g == 0)
				{
					xo[f] = x[o];
					yo[f] = y[o];
					f++;
				}
			}

		}
	}
	return f ;
}
int listptsless(string z,int n,float xo[],float yo[],int f)
{
	float x[100], y[100], x1[100], y1[100];
	int i, j, k, l, h = 1, o, s, m, g;
	f = 0;
	string p1, p2;
	j = polyno(z);

	for (i = 1; i < j; i++)
	{
		p1 = getpoly(z, p1, i);
		k = polpts(p1, x, y);

		for (o = 0; o < k; o++)
		{
			h = 1;
			for (l = i + 1; l <= j; l++)
			{
				p2 = getpoly(z, p2, l);
				m = polpts(p2, x1, y1);
				for (g = 0; g < m; g++)
				{
					if (x[o] == x1[g] && y[o] == y1[g])
					{
						h++;
						break;
					}
				}


			}
			if (h < n)
			{
				g = 0;
				for (s = 0; s < f; s++)
				{
					if (x[o] == xo[s] && y[o] == yo[s])g = 1;

				}

				if (g == 0)
				{
					xo[f] = x[o];
					yo[f] = y[o];
					f++;
				}
			}

		}
	}
	return f;
}
void listptseq(string z, string v)
{
	float x[100], y[100], x1[100], y1[100], xo[100], yo[100];
	int i=0, j, k=0, l, h = 1, o, s, m, f = 0, n, g;
	string p1, p2;
	j = polyno(z);
	n = atoi(v.substr(27).c_str());
	i = listptsless(z, n + 1, x, y, i);
	k = listptsmore(z, n - 1, x1, y1, k);
	
		for (l = 0; l < k; l++)
		{
			for (m = 0; m < i; m++)
			{
				if (x1[l] == x[m] && y1[l] == y[m])
				{
					xo[f] = x[m];
					yo[f] = y[m];
					f++;

				}
			}
		}
	
	
	if (f == 0)cout << "none";
	printpointa(xo, yo, f);
	cout << endl << f;
}