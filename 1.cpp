


#include<graphics.h>
#include<iostream>
using namespace std;

class pt 
{
   protected: int xco,yco,color;
   public:
          pt()
          {
            xco=0;yco=0;color=15;
          }

          void setco(int x,int y)
          {
            xco=x;
            yco=y;
          }

          void setcolor(int c)
          {
            color=c;
          }

          void draw()
          {
            putpixel(xco,yco,color);
          }

};

class dline: public pt 
{
    private: int x2,y2;
    public:
           dline():pt()
           {
             x2=0,y2=0;
           }

           void setline(int x, int y, int xx, int yy)
           {
             pt::setco(x,y);
             x2=xx;
             y2=yy;
           }

           void drawl() 
           {
             float x,y,dx,dy,e,temp;
             int i,s1,s2,ex;
             int xmax,xmid,ymax,ymid;
             xmax = getmaxx();
             ymax = getmaxy();
             xmid = xmax /2;
             ymid = ymax /2;

             
             dx=abs(x2-xco);
             dy=abs(y2-yco);

             
             x=xco;
             y=yco;
             pt::setco(x,y);
             pt::draw();

             
             if(x2 > xco) 
             {
                s1=1;
             }
             if(x2 < xco)
             {
                s1=-1;
             }
             if(x2 == xco)
             {
                s1=0;
             }

              
             if(y2 > yco)
             {
                s2=1;
             }
             if(y2 < yco)
             {
                s2=-1;
             }
             if(y2 == yco)
             {
                s2=0;
             }
             
             
             if(dy > dx)
             {
                temp = dx;
                dx = dy;
                dy = temp;

                ex = 1;
             }
             else
             {
                ex=0;
             }

            
             e=2*dy-dx; 
             cout<<"\t"<<1;
             cout<<"\t"<<e;
             cout<<"\t"<<x-xmid;
             cout<<"\t"<<ymid-y<<endl;
            
             
             i=1;
             do
             {
                  while(e>=0)
                  {
                     if(ex==1)
                     {
                        x = x + s1;
                     }
                     else
                     {
                        y = y + s2;
                     }
                     e = e - 2*dx;
                  }
                  if(ex==1)
                  {
                     y = y + s2;
                  }
                  else
                  {
                     x = x + s1;
                  }
     
                  e = e + 2*dy;
                  
                  pt::setco(x,y);
                  pt::draw();
                  i = i + 1;
                  cout<<"\t"<<i;
                  cout<<"\t"<<e;
                  cout<<"\t"<<x-xmid;
                  cout<<"\t"<<ymid-y<<endl;
                  
           }while(i<=dx);

      }

      
      void drawl(int colour) 
      {
          float x,y,dx,dy,len;
          int i;
          int xmax,xmid,ymax,ymid;
          xmax = getmaxx();
          ymax = getmaxy();
          xmid = xmax /2;
          ymid = ymax /2;
          pt::setcolor(colour);
           
          
          
          dx=abs(x2-xco);    
          dy=abs(y2-yco);

          
          if(dx >= dy)
          {
             len=dx;
          }
          else
          {
             len=dy;
          }

          
          dx=(x2-xco)/len;
          dy=(y2-yco)/len;

          
          x = xco + 0.5;
          y = yco + 0.5;
          pt::setco(x,y);
          pt::draw();
          cout<<"\t"<<1;
          cout<<"\t"<<x-xmid;
          cout<<"\t\t"<<ymid-y<<endl;

          
          i=1;
          while(i<=len)
          {
               x = x + dx;
               y = y + dy;
               i = i + 1;
               pt::setco(x,y);
               pt::draw();               
               cout<<"\t"<<i;
               cout<<"\t"<<x-xmid;
               cout<<"\t\t"<<ymid-y<<endl;
         }

     
     }

};

int main()
{
    int gd=DETECT,gm=VGAMAX;
    int ch,x1,y1,x2,y2, xmax,ymax,xmid,ymid;
    char a;
    initgraph(&gd,&gm,NULL);
    pt p;
    dline dda;

    xmax = getmaxx();
    ymax = getmaxy();
    xmid = xmax /2;
    ymid = ymax /2;

    line(xmid,0,xmid,ymax); 
    line(0,ymid,xmax,ymid); 

    while(1)
    {
       xmax = getmaxx();
       ymax = getmaxy();
       xmid = xmax /2;
       ymid = ymax /2;

      
       cout<<"\n1.DDA LINE..";
       cout<<"\n2.BRESENHAM'S LINE..";
       cout<<"\n3.EXIT..";
       cout<<"\nEnter your choice: ";
       cin>>ch;

       switch(ch)
       {
         case 1:
                 cout<<"\nEnter the co-ordinates of the endpoints of line Below";
                 cout<<"\nEnter x1: "; cin>>x1;
                 cout<<"Enter y1: "; cin>>y1;
                 cout<<"Enter x2: "; cin>>x2;
                 cout<<"Enter y2: "; cin>>y2;
                 
                 cout<<"\nFollowing Result Table Shows Step-by-Step Processing\n"; 
                 cout<<"\n------------------------------------------------------------------\n";
                 cout<<"\ti\tx\t\ty\n";
                 cout<<"-----------------------------------------------------------------\n";
                 dda.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
                 dda.drawl(15);
                 break;

         case 2:
                 cout<<"\nEnter the co-ordinates of the endpoints of line Below\n";
                 cout<<"\nEnter x1: "; cin>>x1;
                 cout<<"Enter y1: "; cin>>y1;
                 cout<<"Enter x2: "; cin>>x2;
                 cout<<"Enter y2: "; cin>>y2;
               
                 cout<<"\nFollowing Result Table Shows Step-by-Step Processing\n"; 
                 cout<<"\n------------------------------------------------------------------\n";
                 cout<<"\ti\te\tx\ty\n";
                 cout<<"-----------------------------------------------------------------\n";
                 dda.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
                 dda.drawl();
                 break;

         case 3:
                 exit(0);
                 break;

       }

      

   }

   delay(3000);
   closegraph();
   return 0;


}
