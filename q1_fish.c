// Question1 
//**(a) and (b)**
// Moving fish using keyboard interactions 
// 2D fish is made & movements are shown using following keys 
// l - left
// r - right
// u - up
// d - down 

//**(c)**
//background scenes 
// 1.  background is blue representing water 
// 2. 'sand' is placed as seen in oceans/seas
// 3. 'pebbles' are added in bottom to give it view of ocean/sea 
// 4. 'bubbles' are shown as found in water often
// 5. 'plants' are shown to give realistic view of ocean/sea
  
//**(d)**
// moving fish diagonally
// p : XY plane(both positive , 1st quadrant)
// n : -X-Y plane(both negative , 3rd quadrant)
// q : X-Y plane(4th quadrant)
// w : -XY plane(2nd quadrant)
 
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
float xt=1.0,yt=1.0;            // For translation 
float angle =0;  				// For Function animation
float Autorun = 300;			// default motion 

//to move diagonally , taking care of angle 
void animation(void)
{
	if(angle>=0 && angle<10)
		angle = angle+0.5;
	else angle = 0;
	glutPostRedisplay();
}

//default motion of fish 
void Auto(void)
{
	if(Autorun<=300 && Autorun>-350)
		Autorun = Autorun-0.05;
	else Autorun = 300;
	glutPostRedisplay();
}

//initialization of background scenes 
void init(void)
{
	glClearColor(0.0,0.0,1.0,1.0);                    //color of frame buffer , blue(water) 
	glPointSize(7.0);
	glLineWidth(1.0);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   
}

//setting viewport 
void reshape(int width, int height) 
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();                      //resets the current matrix 
  gluOrtho2D(0, 400, 0, 400);           //orthographic 2D projection
}

// fish drawn 
void fishbig(void)
{
		glPushMatrix();
		glPushMatrix(); 
	glRotatef(angle,0.0,0.0,0.0); 
	glTranslatef(Autorun,0.0,0.0); 
	glTranslatef(xt,yt,0.0);	     //For Movement  

//2D fish 
	glBegin(GL_POLYGON);		    // drawing body
	glColor3f(0.0,1.0,0.0);
	glVertex2f(40,200);
	glVertex2f(120,280);
	glVertex2f(320,200);
	glVertex2f(100,160);
	glEnd();
	
	glPushMatrix();
	glRotatef(angle,0.0,0.0,0.0); 
	glBegin(GL_POLYGON);			//drawing tail
	glColor3f(0.0,1.0,0.0);
	glVertex2f(320,200);
	glVertex2f(360,240);
	glVertex2f(340,200);
	glVertex2f(360,160);
	glVertex2f(320,200);
	glEnd();
	
	glBegin(GL_POLYGON);		    //drawing arm 
	glColor3f(1.0,0.0,0.0);
	glVertex2i(120,280);
	glVertex2i(140,300);
	glVertex2i(280,216);
	glVertex2i(120,280);
	glEnd();
	
	glBegin(GL_POINTS);		       //drawing eye
	glColor3f(0.0,0.0,0.0);
	glVertex2i(80,210);
	glEnd();

	glBegin(GL_POLYGON);		   //drawing mouth
	glColor3f(1.0,0.0,0.0);
	glVertex2i(100,160);
	glVertex2i(140,200);
	glVertex2i(120,164);
	glVertex2i(100,160);
	glEnd();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

//placing sand in bottom of water 
void sand()
{
 glColor3f(1.0,1.0,0.7);
 glBegin(GL_POLYGON);
 glVertex2f(0.0,0.0);
 glVertex2f(0.0,20.5);
 glVertex2f(400.0,20.5);
 glVertex2f(400.0,0.0);
 glEnd();
}

//growing plants 
void plant()
{	
	glColor3f(0,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(40+10,20);	
	glVertex2f(30+10,30);
	glVertex2f(50+10,10);
	glVertex2f(50+10,50);
	glVertex2f(60+10,10);
	glVertex2f(70+10,20);
	glVertex2f(80,40);
	glVertex2f(80,20);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(40+90,20);	
	glVertex2f(30+90,30);
	glVertex2f(50+90,10);
	glVertex2f(50+90,50);
	glVertex2f(60+90,10);
	glVertex2f(70+90,20);
	glVertex2f(80+90,40);
	glVertex2f(120,10);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(40+160,20);	
	glVertex2f(30+160,30);
	glVertex2f(50+160,10);
	glVertex2f(50+160,50);
	glVertex2f(60+160,10);
	glVertex2f(70+160,20);
	glVertex2f(80+160,40);
	glVertex2f(200,10);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(40+230,20);	
	glVertex2f(30+230,30);
	glVertex2f(50+230,10);
	glVertex2f(50+230,50);
	glVertex2f(60+230,10);
	glVertex2f(70+230,20);
	glVertex2f(80+230,40);
	glVertex2f(300,10);
	glEnd();
}

//adding pebbles in water 
void pebbles()
{
//1st row pebble unless specified 
	glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float i=0;i<180;i++)
	glVertex2f(10+12*cos(i),5+5+6*sin(i));
	glEnd();
	
	glColor3f(0.5,0.35,0.05);
	glBegin(GL_POLYGON);
	for(float j=0;j<180;j++)
	glVertex2f(30+12*cos(j),5+5+6*sin(j));
	glEnd();

    glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float l=0;l<180;l++)
	glVertex2f(50+12*cos(l),5+5+6*sin(l));
	glEnd();

	glColor3f(0.5,0.35,0.05);
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(70+12*cos(p),5+5+6*sin(p));
	glEnd();

	glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float r=0;r<180;r++)
	glVertex2f(90+12*cos(r),5+5+6*sin(r));
	glEnd();

    glColor3f(0.27,0.32,0.15);                          //2nd row pebble 
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(102+12*cos(p),15.5+5+6*sin(p));
	glEnd();	
	
	glColor3f(0.5,0.35,0.05);
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(110+12*cos(p),5+5+6*sin(p));
	glEnd();
	
	glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float r=0;r<180;r++)
	glVertex2f(130+12*cos(r),5+5+6*sin(r));
	glEnd();
	
	glColor3f(0.5,0.35,0.05);
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(150+12*cos(p),5+5+6*sin(p));
	glEnd();
	
	glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float r=0;r<180;r++)
	glVertex2f(170+12*cos(r),5+5+6*sin(r));
	glEnd();

    glColor3f(0.5,0.35,0.05);
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(190+12*cos(p),5+5+6*sin(p));
	glEnd();
	
	glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float r=0;r<180;r++)
	glVertex2f(210+12*cos(r),5+5+6*sin(r));
	glEnd();
	
	glColor3f(0.5,0.35,0.05);
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(230+12*cos(p),5+5+6*sin(p));
	glEnd();
	
	glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float r=0;r<180;r++)
	glVertex2f(250+12*cos(r),5+5+6*sin(r));
	glEnd();
	
	glColor3f(0.5,0.35,0.05);
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(270+12*cos(p),5+5+6*sin(p));
	glEnd();
	
	glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float r=0;r<180;r++)
	glVertex2f(290+12*cos(r),5+5+6*sin(r));
	glEnd();
	
	glColor3f(0.5,0.35,0.05);
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(310+12*cos(p),5+5+6*sin(p));
	glEnd();
	
	glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float r=0;r<180;r++)
	glVertex2f(330+12*cos(r),5+5+6*sin(r));
	glEnd();
	
	glColor3f(0.5,0.35,0.05);
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(350+12*cos(p),5+5+6*sin(p));
	glEnd();
	
	glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float r=0;r<180;r++)
	glVertex2f(370+12*cos(r),5+5+6*sin(r));
	glEnd();
	
	glColor3f(0.5,0.35,0.05);
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(390+12*cos(p),5+5+6*sin(p));
	glEnd();
	
	glColor3f(0.27,0.32,0.15);                         //2nd row pebble 
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(360+12*cos(p),15.5+5+6*sin(p));
	glEnd();
	
}

//adding bubbles to give realistic view 
void bubble()
{
    float i;
	glColor3f(0.5,0.78,0.85);
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(8.5+3*cos(i),30+3*sin(i));
	glEnd();
	
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(8.5+2.5*cos(i),60+2.5*sin(i));
	glEnd();
		
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(8.5+2*cos(i),90+2*sin(i));
	glEnd();
	
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(8.5+1.5*cos(i),110+1.5*sin(i));
	glEnd();
		
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(8.5+1*cos(i),130+1*sin(i));
	glEnd();
//
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(70+3*cos(i),50+3*sin(i));
	glEnd();
	
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(70+2.5*cos(i),70+2.5*sin(i));
	glEnd();
		
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(70+2*cos(i),90+2*sin(i));
	glEnd();
	
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(70+1.5*cos(i),110+1.5*sin(i));
	glEnd();
//
    glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(155+3*cos(i),50+3*sin(i));
	glEnd();
	
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(155+2.5*cos(i),70+2.5*sin(i));
	glEnd();
		
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(155+2*cos(i),90+2*sin(i));
	glEnd();
	
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(155+1.5*cos(i),110+1.5*sin(i));
	glEnd();
//
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(240+20+3*cos(i),30+3*sin(i));
	glEnd();
	
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(240+20+2.5*cos(i),60+2.5*sin(i));
	glEnd();
		
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(240+20+2*cos(i),90+2*sin(i));
	glEnd();
	
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(240+20+1.5*cos(i),110+1.5*sin(i));
	glEnd();
		
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(240+20+1*cos(i),130+1*sin(i));
	glEnd();		
//
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(310+20+3*cos(i),30+3*sin(i));
	glEnd();
	
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(310+20+2.5*cos(i),60+2.5*sin(i));
	glEnd();
		
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(310+20+2*cos(i),90+2*sin(i));
	glEnd();
	
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(310+20+1.5*cos(i),110+1.5*sin(i));
	glEnd();
		
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(310+20+1*cos(i),130+1*sin(i));
	glEnd();
//last bubble
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(370+20+3*cos(i),30+3*sin(i));
	glEnd();
	
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(370+20+2.5*cos(i),60+2.5*sin(i));
	glEnd();
		
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(370+20+2*cos(i),90+2*sin(i));
	glEnd();
	
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(370+20+1.5*cos(i),110+1.5*sin(i));
	glEnd();
		
	glBegin(GL_POLYGON);
	for(i=0;i<2*3.14;i+=0.5)
	glVertex2f(370+20+1*cos(i),130+1*sin(i));
	glEnd();
}	

//complete list of displayed things 
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);               //clearing the frame buffer
    fishbig(); 
    sand();
    plant();
    pebbles();
    bubble();
    glutSwapBuffers();
    glFlush();                                //to display frame buffer 
    	
}

// For keyboard interactivity
// moving left,right,up,down 
// moving diagonally 
void keyboard(GLubyte key, int x, int y)                   
{
	switch ( key )
	{
	case 'r':
			xt += 2.0;                                  // moving forward in X-direction
			glColor3f(0.0,1.0,0.0);
			glutPostRedisplay();
			break;

	case 'l':
			xt -= 2.0;	                                //moving backward in X-direction 
			glColor3f(1.0,0.0,0.0);
			glutPostRedisplay();
			break;

	case 'd':
			yt -= 2.0;                                  //moving downward in Y-direction 
			glColor3f(0.0,0.0,0.0);
			glutPostRedisplay();
			break;

	case 'u':
			yt += 2.0;                                  //moving upward in Y-direction
			glColor3f(0.0,0.0,1.0);
			glutPostRedisplay();
			break;

	case 'p':
			xt += 2.0;                                  //moving in XY plane (1st quadrant)
			yt += 2.0;
			glColor3f(1.0,0.0,1.0);
			glutPostRedisplay();
			break;

	case 'w':
			xt -= 2.0;                                  //moving in -XY plane (2nd quadrant)
			yt += 2.0;
			glColor3f(0.0,1.0,1.0);     
			glutPostRedisplay();
			break;
	case 'q':
			xt += 2.0;                                  //moving in X(-Y) plane (4th quadrant)
			yt -= 2.0;
			glColor3f(1.0,0.0,1.0);
			glutPostRedisplay();
			break;
	case 'n':
			xt -= 2.0;                                  //moving in (-X)(-Y) plane (3rd quadrant)
			yt -= 2.0;
			glColor3f(0.0,0.0,1.0);
			glutPostRedisplay();
			break;

	default:                                            //forward motion 
		    break;
	}
}

int main(int argc,char ** argv)
{
	glutInit(&argc , argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);          //Position of window to display 
	glutInitWindowSize(500,500);         
	glutCreateWindow("Fish");
	init();
	glutDisplayFunc(Display);            //'Display' callback function
	glutReshapeFunc(reshape);
	glutIdleFunc(animation);
	glutIdleFunc(Auto);
	glutKeyboardFunc(keyboard);
	glutMainLoop();                     //start of program 
}

//END
