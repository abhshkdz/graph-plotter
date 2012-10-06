#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <process.h>
#include <dos.h>
#include <stdio.h>
#include <string.h>
#include <fstream.h>

const PI = 3.1416;
int MidX = 320;
int MidY = 240;
char ans, ans_s, loadname[30], savename[30];

void readme()
{
   ofstream file("ReadMe.txt");
   file<<"\n\nWelcome to the GRAPH PLOTTER - ReadMe\n";
   file<<"\n\nIn the Main Menu, there are 4 options : ";
   file<<"\n\n\t1.\tPlot Graphs\n\n\t2.\tOpen Saved Graph\n\n\t3.\tReadme";
   file<<"\n\n\t4.\tExit";
   file<<"\n\n1.\tChoosing the 'Plot Graphs' option will lead you to a";
   file<<" new set of options\n\n\tto choose from, each of which represents a";
   file<<" different function and is\n\n\tvery well explained within.";
   file<<"\n\n2.\tChoosing the 'Open Saved Graph' option will let you";
   file<<" view an earlier\n\n\tsaved graph again.";
   file<<"\n\n3.\tThe 'Readme' option leads you to this page.";
   file<<"\n\n4.\tThe 'Exit' option will lead to the termination of the program.";
   file<<"\n\n\nThe GRAPH PLOTTER was programmed by Abhishek & Saksham.";
   file<<"\n\nThank you for using it.";
   file.close();
}

void display(char text[30],int y,int x,int t)
{
   clrscr();
   for (int i=1;i<80;i++)
   {
      delay(10);
      gotoxy(i,y);
      cout<<".";
   }
   for (i=0;i<50;i++)
   {
      delay(10);
      gotoxy(x,i);
      cout<<".";
   }
   for (int j=0, k=x+1; j<strlen(text); k++, j++)
   {
      gotoxy(k,t);
      delay(10);
      cout<<text[j];
   }
}

void show (char text[10],int y1,int x1,int y2,int x2)
{
   clrscr();
   for (int i=x1-3; i<=x1+7; i++)
   {
     delay(30);
     gotoxy(i,y1);
     cout<<".";
   }
   for (i=y1-3; i<=y1+7; i++)
   {
      delay(30);
      gotoxy(x1,i);
      cout<<".";
   }
   for (i=x2-7; i<x2+3; i++)
   {
      delay(30);
      gotoxy(i,y2);
      cout<<".";
   }
   for (i=y2-7; i<=y2+3; i++)
   {
      delay(30);
      gotoxy(x2,i);
      cout<<".";
   }
   for (int j=0, k=x1+1; j<strlen(text); k+=2,j++)
   {
      gotoxy(k,y1+2);
      delay(40);
      cout<<text[j];
   }
}

void trigaxes ()
{
   cleardevice();
   line (0, MidY, 640, MidY);
   line (MidX, 0, MidX, 480);
   for (int i=0; i<320; i+=(PI/2)*78.7)
      for (int j=-2; j<4; j++)
    putpixel (MidX+i, MidY+j, WHITE);
   for (i=0; i>-320; i=i-(PI/2)*79.0)
      for (j=-2; j<4; j++)
    putpixel (MidX+i, MidY+j, WHITE);
   for (j=-320; j<320; j+=10)
      putpixel (MidX+j, MidY+100, RED);
   for (j=-320; j<320; j+=10)
      putpixel (MidX+j, MidY-100, RED);
   settextstyle (0, 0, 0);
   outtextxy (MidX+((PI/2)*78.7)-20, MidY+5, "1.57");
   outtextxy (MidX+((PI/2)*78.7)*2-20, MidY+5, "3.14");
   outtextxy (MidX+((PI/2)*78.7)*3-20, MidY+5, "4.71");
   outtextxy (MidX+((PI/2)*78.7)*4-20, MidY+5, "6.28");
   outtextxy (MidX-((PI/2)*78.7)-5, MidY+5, "-1.57");
   outtextxy (MidX-((PI/2)*78.7)*2-5, MidY+5, "-3.14");
   outtextxy (MidX-((PI/2)*78.7)*3-5, MidY+5, "-4.71");
   outtextxy (MidX-((PI/2)*78.7)*4-5, MidY+5, "-6.28");
}

void axes ()
{
   line (0, MidY, 640, MidY);
   line (MidX, 0, MidX, 480);
   for (int i=-320; i<320; i+=10)
      for (int j=-2; j<4; j++)
    putpixel (MidX+i, MidY+j, RED);
   for (i=-240; i<240; i+=10)
      for (j=-2; j<4; j++)
    putpixel (MidX+j, MidY+i, RED);
   for (i=-300; i<301; i+=50)
      for (j=-2; j<4; j++)
    putpixel (MidX+i, MidY+j, WHITE);
   for (i=-200; i<201; i+=50)
      for (j=-2; j<4; j++)
    putpixel (MidX+j, MidY+i, WHITE);
   settextstyle (0, 0, 0);
   outtextxy (MidX+3, MidY+5, "0");
   outtextxy (MidX+48, MidY+5, "5");
   outtextxy (MidX+95, MidY+5, "10");
   outtextxy (MidX+145, MidY+5, "15");
   outtextxy (MidX+195, MidY+5, "20");
   outtextxy (MidX+245, MidY+5, "25");
   outtextxy (MidX+295, MidY+5, "30");
   outtextxy (MidX-60, MidY+5, "-5");
   outtextxy (MidX-115, MidY+5, "-10");
   outtextxy (MidX-165, MidY+5, "-15");
   outtextxy (MidX-215, MidY+5, "-20");
   outtextxy (MidX-265, MidY+5, "-25");
   outtextxy (MidX-315, MidY+5, "-30");
   settextstyle (0, 1, 0);
   outtextxy (MidX-5, MidY-55, "5");
   outtextxy (MidX-5, MidY-105, "10");
   outtextxy (MidX-5, MidY-155, "15");
   outtextxy (MidX-5, MidY-205, "20");
   outtextxy (MidX-5, MidY+45, "-5");
   outtextxy (MidX-5, MidY+95, "-10");
   outtextxy (MidX-5, MidY+145, "-15");
   outtextxy (MidX-5, MidY+195, "-20");
   settextstyle (0,0,0);
}

void loop ()
{
   outtextxy (MidX + 100, MidY + 200, "Press any key to continue...");
   getch();
   closegraph();
   textmode(C4350);
   clrscr();
   show("",15,9,25,63);
   gotoxy(10,20);cout<<"Do you want to continue using GRAPH PLOTTER (Y/N) : ";
   cin>>ans;
}

void credit ()
{
   show ("",15,22,30,51);
   gotoxy(25,18);
   cout<<" Programmed in C++ as";
   gotoxy(25,20);
   cout<<"part of school project.";
   gotoxy(25,22);
   cout<<"";
   gotoxy(25,24);
   cout<<"By Abhishek and Saksham";
   gotoxy(25,26);
   cout<<"\t    of XII D";
   gotoxy(25,28);
   cout<<"Sardar Patel Vidyalaya";
   getch();
}

class graph
{
   int a,b,c,d;
   float x;
   public :
   int deg, form, n;
   void init_linear()
   {
      display("LINEAR EQUATION",18,51,17);
      gotoxy(11,22);cout<<"General Form : ax + by + c = 0";
      gotoxy(11,24);cout<<"Give a : ";cin>>a;
      gotoxy(11,26);cout<<"Give b : ";cin>>b;
      gotoxy(11,28);cout<<"Give c : ";cin>>c;
   }
   void init_quadratic()
   {
      display("QUADRATIC EQUATION",18,51,17);
      gotoxy(11,22);cout<<"General Form : ax^2 + bx + c = 0";
      gotoxy(11,24);cout<<"Give a : ";cin>>a;
      gotoxy(11,26);cout<<"Give b : ";cin>>b;
      gotoxy(11,28);cout<<"Give c : ";cin>>c;
   }
   void init_cubic()
   {
      display("CUBIC EQUATION",18,51,17);
      gotoxy(11,22);cout<<"General Form : ax^3 + bx^2 + cx + d = 0";
      gotoxy(11,24);cout<<"Give a : ";cin>>a;
      gotoxy(11,26);cout<<"Give b : ";cin>>b;
      gotoxy(11,28);cout<<"Give c : ";cin>>c;
      gotoxy(11,30);cout<<"Give d : ";cin>>d;
   }
   void plot_linear(int col)
   {
      axes();
      if (b==0)
      {
    for (x=-240; x<240; x++)
    {
       putpixel (MidX+((-c/a)*10), MidY-x, col);
       delay(1);
    }
      }
   else
      {
    for (x=-35; x<35; x+=0.05)
    {
       putpixel (MidX+x*10, MidY-((-(a*x)-c)/b)*10, col);
       delay(1);
    }
      }
   }
   void plot_quadratic(int col)
   {
      axes();
      for (x=-15; x<15; x=x+0.005)
      {
    putpixel (MidX+x*10,MidY-((a*pow(x,2))+(b*x)+c)*10, col);
    delay(1);
      }
   }
   void plot_cubic(int col)
   {
      axes();
      for (x=-10; x<10; x=x+0.005)
      {
    putpixel (MidX+x*10,MidY-((a*pow(x,3))+(b*pow(x,2))+(c*x)+d)*10, col);
    delay(1);
      }
   }
   void init_para1()
   {
      display("PARABOLA",18,51,17);
      gotoxy(11,22);cout<<"General Form : y^2 = 4ax";
      gotoxy(11,24);cout<<"Give a : ";cin>>a;
   }
   void init_para2()
   {
      display("PARABOLA",18,51,17);
      gotoxy(11,22);cout<<"General Form : x^2 = 4ay";
      gotoxy(11,24);cout<<"Give a : ";cin>>a;
   }
   void plot_para1()
   {
      axes();
      for (x=0; x<320.0; x+=0.1)
      {
    if (a>0)
    {
       putpixel (MidX+x, MidY-(sqrt(4*a*x))*2, GREEN);
       putpixel (MidX+x, MidY+(sqrt(4*a*x))*2, GREEN);
       delay(1);
    }
    else
    {
       putpixel (MidX-x, MidY-(sqrt(-4*a*x))*2, GREEN);
       putpixel (MidX-x, MidY+(sqrt(-4*a*x))*2, GREEN);
       delay(1);
    }
      }
   }
   void plot_para2()
   {
      axes();
      for (x=0; x<320.0; x+=0.1)
      {
    if (a>0)
    {
       putpixel (MidX+(sqrt(4*a*x))*2, MidY-x, GREEN);
       putpixel (MidX-(sqrt(4*a*x))*2, MidY-x, GREEN);
       delay(1);
    }
    else
    {
       putpixel (MidX+(sqrt(-4*a*x))*2, MidY+x, GREEN);
       putpixel (MidX-(sqrt(-4*a*x))*2, MidY+x, GREEN);
       delay(1);
    }
      }
   }
};

void save (graph a[], int n)
{
   show("SAVE TO A FILE",4,4,40,77);
   gotoxy(12,30);
   cout<<"NOTE: The file by default is stored under the current ";
   gotoxy(12,32);
   cout<<"      working directory.";
   gotoxy(16,24);
   cout<<"Give a file name (e.g. graph.dat) : ";
   gets(savename);
   fstream file(savename, ios::out|ios::binary);
   for (int i=0; i<n; i++)
   {
      file.write((char *)&a[i], sizeof(a[i]));
   }
   cout<<"\nYour graph saved to a file successfully  ";
   gotoxy(12,40);cout<<"Press any key to continue...";
   getch();
   file.close();
}

graph load_one(char str[30])
{
   graph temp;
   fstream f3(str, ios::in|ios::binary);
   f3.read((char*)&temp, sizeof(temp));
   cout<<"\nGraph imported from file successfully";
   gotoxy(12,32);
   cout<<"Press any key to continue...";
   getch();
   f3.close();
   return temp;
}


graph load_multi (char str[30], int n)
{
   graph temp[10];
   fstream f2(str, ios::in|ios::binary);
   for (int i=0; i<n; i++)
   {
      f2.read((char*)&temp[i], sizeof(temp[i]));
   }
   cout<<"\nGraph imported from file successfully";
   gotoxy(12,32);
   cout<<"Press any key to continue...";
   getch();
   f2.close();
   return temp[10];
}

int load_n()
{
   graph a;
   display("IMPORTING EXTERNAL FILE",30,50,29);
   gotoxy(10,24);
   cout<<"File name (specify location if needed) ";
   gotoxy(15,26);
   cout<<": ";
   gets(loadname);
   fstream f1(loadname, ios::in|ios::binary);
   f1.read((char*)&a, sizeof(a));
   f1.close();
   return a.n;
}

void main ()
{
   int GDriver = DETECT; int Gmode;
   initgraph(&GDriver, &Gmode, "c:\\tc\\bgi");
   int deg, choice;
   setbkcolor (RED);
   for (int i=-100; i<MidX-120; i++)
   {
      cleardevice();
      settextstyle (3,0,5);
      outtextxy (i, MidY, "GRAPH PLOTTER");
      outtextxy (MidX-i, MidY-75, "WELCOME TO");
      delay (10);
   }
   settextstyle (0,0,0);
   setbkcolor (BLACK);
   outtextxy (MidX + 20, MidY + 200, "Press any key to continue.");
   getch();
   closegraph();
   readme();
   textmode(C4350);
   do
   {
    delay(2000);
    show("MENU",15,22,29,53);
    gotoxy(30,20);cout<<"1. Plot graphs";
    gotoxy(30,22);cout<<"2. Open Saved Graph";
    gotoxy(30,24);cout<<"3. View Readme";
    gotoxy(30,26);cout<<"4. Exit";
    gotoxy(30,28);cout<<"Your choice : ";
    cin>>choice;
    if (choice==1)
    {
       display("WELCOME TO GRAPH PLOTTER",18,51,17);
       gotoxy(10,22);cout<<"1. Polynomial";
       gotoxy(10,24);cout<<"2. Trigonometric Function";
       gotoxy(10,26);cout<<"3. Parabola";
       gotoxy(10,28);cout<<"4. Solve multiple polynomials graphically";
       gotoxy(10,30);cout<<"5. Exit";
       gotoxy(10,32);cout<<"Your choice : ";
       cin>>choice;
       if (choice==1)
       {
          graph a[10];
          a[0].n=1;
          show("",15,8,25,72);
          gotoxy(9,20);
          cout<<"Give the degree of the polynomial you want to plot (max 3) : ";
          cin>>a[0].deg;
          if (a[0].deg==1)
          {
        a[0].init_linear();
        int GDriver = DETECT; int Gmode;
        initgraph(&GDriver, &Gmode, "c:\\tc\\bgi");
        cleardevice();
        cout<<"\n\n\n\n\t\t\tPress any key to continue...";
        getch();
        cleardevice();
        a[0].plot_linear(GREEN);
        outtextxy (MidX + 100, MidY + 200, "Press any key to continue...");
        getch();
        closegraph();
        textmode(C4350);
        clrscr();
        show("",15,9,25,63);
        gotoxy(15,20);cout<<"Would you like to save your graph (Y/N) : ";
        cin>>ans_s;
        if (ans_s=='y'||ans_s=='Y')
        {
           save(a, a[0].n);
        }
        show("",15,9,25,63);
        gotoxy(10,20);cout<<"Do you want to continue using GRAPH PLOTTER (Y/N) : ";
        cin>>ans;
          }
          else if (a[0].deg==2)
          {
        a[0].init_quadratic();
        int GDriver = DETECT; int Gmode;
        initgraph(&GDriver, &Gmode, "c:\\tc\\bgi");
        cleardevice();
        cout<<"\n\n\n\n\t\t\tPress any key to continue...";
        getch();
        cleardevice();
        a[0].plot_quadratic(GREEN);
        outtextxy (MidX + 100, MidY + 200, "Press any key to continue...");
        getch();
        closegraph();
        textmode(C4350);
        clrscr();
        show("",15,9,25,63);
        gotoxy(15,20);cout<<"Would you like to save your graph (Y/N) : ";
        cin>>ans_s;
        if (ans_s=='y'||ans_s=='Y')
        {
           save(a, a[0].n);
        }
        show("",15,9,25,63);
        gotoxy(10,20);cout<<"Do you want to continue using GRAPH PLOTTER (Y/N) : ";
        cin>>ans;
          }
          else if (a[0].deg==3)
          {
        a[0].init_cubic();
        int GDriver = DETECT; int Gmode;
        initgraph(&GDriver, &Gmode, "c:\\tc\\bgi");
        cleardevice();
        cout<<"\n\n\n\n\t\t\tPress any key to continue...";
        getch();
        cleardevice();
        a[0].plot_cubic(GREEN);
        outtextxy (MidX + 100, MidY + 200, "Press any key to continue...");
        getch();
        closegraph();
        textmode(C4350);
        clrscr();
        show("",15,9,25,63);
        gotoxy(15,20);cout<<"Would you like to save your graph (Y/N) : ";
        cin>>ans_s;
        if (ans_s=='y'||ans_s=='Y')
        {
           save(a, a[0].n);
        }
        show("",15,9,25,63);
        gotoxy(10,20);cout<<"Do you want to continue using GRAPH PLOTTER (Y/N) : ";
        cin>>ans;
          }
       }
       else if (choice==2)
       {
          int trigchoice;
          display("TRIGONOMETRIC FUNCTIONS",18,51,17);
          gotoxy(11,22);cout<<"Choose one of the following options";
          gotoxy(11,24);cout<<"1. Sine";
          gotoxy(11,26);cout<<"2. Cosine";
          gotoxy(11,28);cout<<"3. Tangent";
          gotoxy(11,30);cout<<"Your choice : ";
          cin>>trigchoice;
          if (trigchoice==1)
          {
        int GDriver = DETECT; int Gmode;
        initgraph(&GDriver, &Gmode, "c:\\tc\\bgi");
        cleardevice();
        cout<<"\n\n\n\n\t\t\tPress any key to continue...";
        getch();
        trigaxes();
        float t=-8;
        while (t<8.0)
        {
           putpixel (MidX+(t*50), MidY-(sin(t))*100, GREEN);
           delay(1);
           t+=0.005;
        }
        loop();
          }
          else if (trigchoice==2)
          {
        int GDriver = DETECT; int Gmode;
        initgraph(&GDriver, &Gmode, "c:\\tc\\bgi");
        cleardevice();
        cout<<"\n\n\n\n\t\t\tPress any key to continue...";
        getch();
        trigaxes();
        float t=-8;
        while (t<8.0)
        {
           putpixel (MidX+(t*50), MidY-(cos(t))*100, GREEN);
           delay(1);
           t+=0.005;
        }
        loop();
          }
          else if (trigchoice==3)
          {
        int GDriver = DETECT; int Gmode;
        initgraph(&GDriver, &Gmode, "c:\\tc\\bgi");
        cleardevice();
        cout<<"\n\n\n\n\t\t\tPress any key to continue...";
        getch();
        trigaxes();
        float t=-8;
        while (t<8.0)
        {
           putpixel (MidX+(t*50), MidY-(tan(t))*100, GREEN);
           delay(1);
           t+=0.005;
        }
        loop();
          }
       }
       else if (choice==3)
       {
          graph para[10];
          para[0].n=1;
          show("PARABOLA",15,8,30,72);
          gotoxy(9,20);
          cout<<"Choose one of the following forms of parabola : ";
          gotoxy(15,22);
          cout<<"1. y^2=4ax";
          gotoxy(15,24);
          cout<<"2. x^2=4ay";
          gotoxy(15,26);
          cout<<"Your choice : ";
          cin>>para[0].form;
          if (para[0].form==1)
          {
        para[0].init_para1();
        int GDriver = DETECT; int Gmode;
        initgraph(&GDriver, &Gmode, "c:\\tc\\bgi");
        cleardevice();
        cout<<"\n\n\n\n\t\t\tPress any key to continue...";
        getch();
        cleardevice();
        para[0].plot_para1();
        outtextxy (MidX + 100, MidY + 200, "Press any key to continue...");
        getch();
        closegraph();
        textmode(C4350);
        clrscr();
        show("",15,9,25,63);
        gotoxy(15,20);cout<<"Would you like to save your graph (Y/N) : ";
        cin>>ans_s;
        if (ans_s=='y'||ans_s=='Y')
        {
           save(para, para[0].n);
        }
        show("",15,9,25,63);
        gotoxy(10,20);cout<<"Do you want to continue using GRAPH PLOTTER (Y/N) : ";
        cin>>ans;
          }
          else if (para[0].form==2)
          {
        para[0].init_para2();
        int GDriver = DETECT; int Gmode;
        initgraph(&GDriver, &Gmode, "c:\\tc\\bgi");
        cleardevice();
        cout<<"\n\n\n\n\t\t\tPress any key to continue...";
        getch();
        cleardevice();
        para[0].plot_para2();
        outtextxy (MidX + 100, MidY + 200, "Press any key to continue...");
        getch();
        closegraph();
        textmode(C4350);
        clrscr();
        show("",15,9,25,63);
        gotoxy(15,20);cout<<"Would you like to save your graph (Y/N) : ";
        cin>>ans_s;
        if (ans_s=='y'||ans_s=='Y')
        {
           save(para, para[0].n);
        }
        show("",15,9,25,63);
        gotoxy(10,20);cout<<"Do you want to continue using GRAPH PLOTTER (Y/N) : ";
        cin>>ans;
          }
          else exit(0);
       }
       else if (choice==4)
       {
          int num;
          graph poly[10];
          show("",15,15,25,65);
          gotoxy(17,20);
          cout<<"How many polynomials would you like to plot : ";
          cin>>num;
          for (int i=0; i<num; i++)
          {
        poly[i].n=num;
          }
          for (i=0; i<num; i++)
          {
        show("",15,15,25,62);
        gotoxy(17,20);
        cout<<"Give the degree of polynomial "<<i+1<<" (max 3) : ";
        cin>>poly[i].deg;
        if (poly[i].deg==1)
        poly[i].init_linear();
        else if (poly[i].deg==2)
        poly[i].init_quadratic();
        else if (poly[i].deg==3)
        poly[i].init_cubic();
          }
          int GDriver = DETECT; int Gmode;
          initgraph(&GDriver, &Gmode, "c:\\tc\\bgi");
          cleardevice();
          cout<<"\n\n\n\n\t\t\tPress any key to continue...";
          getch();
          cleardevice();
          int j=GREEN;
          for (i=1; i<=num; i++)
        {
           if (poly[i-1].deg==1)
           {
         poly[i-1].plot_linear(j);
           }
           else if (poly[i-1].deg==2)
           {
         poly[i-1].plot_quadratic(j);
           }
           else if (poly[i-1].deg==3)
           {
         poly[i-1].plot_cubic(j);
           }
           j++;
        }
          outtextxy (MidX + 100, MidY + 200, "Press any key to continue...");
          getch();
          closegraph();
          textmode(C4350);
          clrscr();
          show("",15,9,25,63);
          gotoxy(15,20);cout<<"Would you like to save your graph (Y/N) : ";
          cin>>ans_s;
          if (ans_s=='y'||ans_s=='Y')
          {
        save(poly, num);
          }
          show("",15,9,25,63);
          gotoxy(10,20);
       cout<<"Do you want to continue using GRAPH PLOTTER (Y/N) : ";
          cin>>ans;
       }
       else break;
    }
    else if (choice==2)
    {
       int num=load_n();
       if (num==1)
       {
          graph temp=load_one(loadname);
          int j=GREEN;
          int GDriver = DETECT; int Gmode;
          initgraph(&GDriver, &Gmode, "c:\\tc\\bgi");
          cleardevice();
          cout<<"\n\n\n\n\t\t\tPress any key to continue...";
          getch();
          cleardevice();
          if (temp.deg==1)
          {
        temp.plot_linear(j);
          }
          else if (temp.deg==2)
          {
        temp.plot_quadratic(j);
          }
          else if (temp.deg==3)
          {
        temp.plot_cubic(j);
          }
          else if (temp.form==1)
          {
        temp.plot_para1();
          }
          else if (temp.form==2)
          {
        temp.plot_para2();
          }
       loop();
       }
       else
       {
          graph temp[10];
          temp[10]=load_multi(loadname, num);
          int j=GREEN;
          int GDriver = DETECT; int Gmode;
          initgraph(&GDriver, &Gmode, "c:\\tc\\bgi");
          cleardevice();
          cout<<"\n\n\n\n\t\t\tPress any key to continue...";
          getch();
          cleardevice();
          for (int i=0; i<num; i++)
          {
        if (temp[i].deg==1)
        {
           temp[i].plot_linear(j);
        }
        else if (temp[i].deg==2)
        {
           temp[i].plot_quadratic(j);
        }
        else if (temp[i].deg==3)
        {
           temp[i].plot_cubic(j);
        }
        j++;
          }
       loop();
       }
    }
    else if (choice==3)
    {
       clrscr();
       char string[100];
       ifstream file("ReadMe.txt");
       while (!file.eof())
          {
        file.getline(string, 150);
        cout<<string<<endl;
          }
       file.close();
       gotoxy(10,300);cout<<"Do you want to continue using GRAPH PLOTTER (Y/N) : ";
       cin>>ans;
    }
    else break;
   } while (ans=='y'||ans=='Y');
credit ();
}