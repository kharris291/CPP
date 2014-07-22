//include allegro
#include <allegro.h>
#include <winalleg.h>
//include all the classes
#include "shape.h"
#include "CIRCLE.h"
#include "BOX.h"
#include "LINE.h"

#include <iostream>
//call function for allowing string
#include <string>
//call function for the string stream
#include <sstream>
//include the libruary needed to open a file
#include <fstream>
#include <vector>

using namespace std;

void main()
{
	//put into files and make a screen
	if (allegro_init() != 0)
	{
      return;
	}

	set_color_depth(desktop_color_depth());
	
	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 400,400, 0, 0) != 0) 
	{
		return;
	}
	
	//install the keyboard input functions and sound functions
	install_keyboard();

	install_sound (DIGI_AUTODETECT,MIDI_AUTODETECT,"A");

	//load in the midi file
	MIDI* BACK;
	BACK = load_midi("FF7_Victiory_Fanfare.mid");//load the midi file into the program
	


	BITMAP * myBitmap = create_bitmap(400,400);
	vector<shape *> listofshapes;
	shape *cirCLE;//left eye
	shape *cirCLE1;//right puple
	shape *cirCLE2;//right eye
	shape *cirCLE3;//left puple
	shape *LiNE;//this is for the first line when 1 is pressed and left eyebrow
	shape *LiNE1;//right eyebrow
	shape *LiNE2;//top of lip
	shape *LiNE3;//bottom of lip
	shape *LiNE4;//left side of lip
	shape *LiNE5;//right side of lip
	shape *BoX;


	//open the file and 
	ofstream os;
	ifstream is;
	string s;// holds filec information
	string restofline;//used to hold the the parsed information
	int i=0;
	int l1=0,l2=0,l3=0,l4=0,l5=0,l6=0,l7=0;//these are for the line file
	int cir1=0,cir2=0,cir3=0,cir4=0,cir5=0,cir6=0;//circle
	int li1=0,li2=0,li3=0,li4=0,li5=0,li6=0,li7=0;//box
	string color;
	
	stringstream ss;
	
	//open the file
	string type;
	
	is.open("shapes.txt", ios::in);
	if(is.is_open())
	{
		while(!is.eof())
		{
			getline(is,s);//reads the line
			stringstream ss(s);// splits the line up
			ss >> restofline;//puts  the parsed line into restofline
			if (restofline=="line")
			{
				//input the line information from the string stream into the different variables
				ss >> l1;
				ss >> l2;
				ss >> l3;
				ss >> l4;
				ss >> color;
				if(color=="blue")
				{
					l5=0;
					l6=0;
					l7=255;
				}
				//send the parameters to the line class
				LiNE = new LINE(l1,l2,l3,l4,l5,l6,l7);//this is for the first line when 1 is pressed and left eyebrow
				LiNE1 = new LINE((l1+260),l2,(l3+90),l4,l5,l6,l7);//right eyebrow
				LiNE2 = new LINE(l1,(l2+250),(l3+235),(l4+220),(l5+40),(l6+210),l7);//top of lip
				LiNE3 = new LINE(l1,(l2+220),(l3+235),(l4+190),(l5+40),(l6+210),l7);//bottom of lip
				LiNE4 = new LINE(l1,(l2+220),(l3-30),(l4+220),(l5+40),(l6+210),l7);//left side of lip
				LiNE5 = new LINE((l1+265),(l2+220),(l3+235),(l4+220),(l5+40),(l6+210),l7);//right side of lip
				//push back shapes into the vector
				listofshapes.push_back(LiNE);
				listofshapes.push_back(LiNE1);
				listofshapes.push_back(LiNE2);
				listofshapes.push_back(LiNE3);
				listofshapes.push_back(LiNE4);
				listofshapes.push_back(LiNE5);
			}
			
			if(restofline=="circle")
			{
				//input the circle information from the string stream into the different variables
				ss >> cir1;
				ss >> cir2;
				ss >> cir3;
				ss >> color;
				if(color=="red")
				{
					cir4=255;
					cir5=0;
					cir6=0;
				}
				//send parameters to the circle class
				cirCLE = new CIRCLE(cir1,cir2,cir3,cir4,cir5,cir6);//right eye
				cirCLE1 = new CIRCLE(cir1,cir2,cir3-8,cir4,cir5,cir6);//right puple
				cirCLE2 = new CIRCLE((cir1+100),cir2,cir3,cir4,cir5,cir6);//left eye
				cirCLE3 = new CIRCLE(cir1+100,cir2,cir3-8,cir4,cir5,cir6);//for the left puple
				//push back shapes
				listofshapes.push_back(cirCLE);
				listofshapes.push_back(cirCLE1);
				listofshapes.push_back(cirCLE2);
				listofshapes.push_back(cirCLE3);

			}
			
			if (restofline=="box")
			{
				//input the box information from the string stream into the different variables
				ss >> li1;
				ss >> li2;
				ss >> li3;
				ss >> li4;
				ss >> color;
				if(color=="purple")
				{
					li5= 160;
					li6= 32;
					li7= 240;
	
				}

				//send parameters to the box class
				BoX = new BOX(li1,li2,li3,li4,li5,li6,li7);
				//push the box into the vector
				listofshapes.push_back(BoX);
				
			}

			i++;
		}
		//close the program
		is.close();
	
	}
	//tell if file not open
	else
	{
		cout << "file not open" << endl;
	}
	
	
	clear_to_color(myBitmap, makecol(0, 0, 0));
	
	bool done = false;
	while (! done)
	{
		if (keypressed())
		{
			int key = readkey() >> 8;
			switch (key)
			{
				case KEY_ESC:
					done = true;
					break;
				case KEY_1:
					stop_midi();//make sure the file has stopped
					clear_to_color(myBitmap, makecol(0, 0, 0));
					cirCLE->draw(myBitmap);//draws the left circle

					continue;
				case KEY_2:
					stop_midi();//make sure the file has stopped
					clear_to_color(myBitmap, makecol(0, 0, 0));
					LiNE->draw(myBitmap); //draws the left eyebrow
					continue;
				case KEY_3:
					stop_midi();//make sure the file has stopped
					clear_to_color(myBitmap, makecol(0, 0, 0));
					BoX->draw(myBitmap);
					continue;
				case KEY_4://number 4 is to display all the shapes that have been pushed back into the vector and play a midi file
					clear_to_color(myBitmap, makecol(0, 0, 0));
					
					play_midi(BACK, true);//plays midi file

					//iterate throught the vector of shapes and draw them
					for (vector<shape *>::iterator i = listofshapes.begin() ; i < listofshapes.end() ; i ++)
					{
						(*i)->draw(myBitmap);
					}
					
					continue;
					stop_midi();//stop midi file
				
					Sleep(50);
			}
		}
		blit(myBitmap, screen, 0, 0, 0, 0, 400,400);
	}
}
END_OF_MAIN()