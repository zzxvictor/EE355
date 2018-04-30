#include "MyHeader.h"

GUI::GUI()
{
	for (int i = 0; i<SIZE; i++)
	{
		for (int j = 0; j<SIZE; j++)
		{
			for (int z = 0; z<RGB; z++)
				image[i][j][z] = 255;
		}
	}
}


void GUI::display (HunterBook* hb, Monsterbook* mb, PalicoBook *pb, ChampionBook *cb)
{
	clearScreen();
	addHunter(hb);
	addMonster(mb);
	addPalico(pb);
	addChampion(cb);
	showRGBBMP(image);
}

void GUI::addHunter(HunterBook* hb)
{
	//get X and Y
	int size = hb->getListSize();
	for (int i =0; i< size; i++)
	{
		int x = hb->indexAccess(i)->getX();
		int y = hb->indexAccess(i)->getY();
		std::string color = hb->indexAccess(i)->getColor();
		//plot it 
		printObj(x,y,color, 0);
	}
}
void GUI::addMonster(Monsterbook* mb)
{
	int size =mb->getListSize();
	for (int i =0; i< size; i++)
	{
		int x = mb->indexAccess(i)->getX();
		int y = mb->indexAccess(i)->getY();
		std::string color = mb->indexAccess(i)->getColor();
		//plot it 
		printObj(x,y,color, 1);
	}
}
void GUI::addPalico(PalicoBook* pb)
{
	int size = pb->getListSize();
	for (int i =0; i< size; i ++)
	{
		int x = pb->indexAccess(i)->getX();
		int y = pb->indexAccess(i)->getY();
		std::string color = pb->indexAccess(i)->getColor();
		printObj(x,y,color, 2);
	}
}

void GUI::addChampion(ChampionBook *cb)
{
	int size = cb->getListSize();
	for (int i =0; i< size; i ++)
	{
		int x = cb->indexAccess(i)->getX();
		int y = cb->indexAccess(i)->getY();
		std::string color = cb->indexAccess(i)->getColor();
		printObj(x,y,color, 3);
	}
}
void GUI::clearScreen()
{
	for (int i = 0; i<SIZE; i++)
	{
		for (int j = 0; j<SIZE; j++)
		{
			for (int z = 0; z<RGB; z++)
				image[i][j][z] = 255;
		}
	}
}








void GUI::printObj(int x, int y, std::string color, int option)
{
	if (option == 0)
	{
		//square
		if (color == "Schwarz")
		{
			for (int i = x*16; i< (x+1)*16; i++)
			{
				for (int j = y*16; j<(y+1)*16; j++)
					{
							image[i][j][0] = 0;
							image[i][j][1] = 0;
							image[i][j][2] = 0;
					}
			}

		}
		else if(color == "Blau")
		{
			for (int i = x*16; i< (x+1)*16; i++)
			{
				for (int j = y*16; j<(y+1)*16; j++)
					{
							image[i][j][0] = 0;
							image[i][j][1] = 32;
							image[i][j][2] = 255;
					}
			}
		}
		else if(color == "Rot")
		{
			for (int i = x*16; i< (x+1)*16; i++)
			{
				for (int j = y*16; j<(y+1)*16; j++)
					{
							image[i][j][0] = 255;
							image[i][j][1] = 0;
							image[i][j][2] = 0;
					}
			}
		}
		else if(color == "Geld")
		{
			for (int i = x*16; i< (x+1)*16; i++)
			{
				for (int j = y*16; j<(y+1)*16; j++)
					{
							image[i][j][0] = 255;
							image[i][j][1] = 254;
							image[i][j][2] = 32;
					}
			}
		}
		else if(color == "Gruen")
		{
			for (int i = x*16; i< (x+1)*16; i++)
			{
				for (int j = y*16; j<(y+1)*16; j++)
					{
							image[i][j][0] = 0;
							image[i][j][1] = 192;
							image[i][j][2] = 0;
					}
			}
		}
		else
		{
			std::cout<<"error"<<std::endl;
		}
	}

	else if (option == 1)
	{
		//triangle
		if (color == "Schwarz")
		{
			int k = 0;
			int flag = 0;
			for (int i = x*16; i< (x+1)*16; i++)
			{

				for (int j = y*16 + 8 -k; j<y*16 + 8 + k; j++)
				{
					image[i][j][0] = 0;
					image[i][j][1] = 0;
					image[i][j][2] = 0;
				}
				flag ++;
				if (flag%2 == 0)
					k ++;
			}

		}
		else if(color == "Blau")
		{
			int k = 0;
			int flag = 0;
			for (int i = x*16; i< (x+1)*16; i++)
			{

				for (int j = y*16 + 8 -k; j<y*16 + 8 + k; j++)
				{
					image[i][j][0] = 0;
					image[i][j][1] = 32;
					image[i][j][2] = 255;
				}
				flag ++;
				if (flag%2 == 0)
					k ++;
			}
		}
		else if(color == "Rot")
		{
			int k = 0;
			int flag = 0;
			for (int i = x*16; i< (x+1)*16; i++)
			{

				for (int j = y*16 + 8 -k; j<y*16 + 8 + k; j++)
				{
					image[i][j][0] = 255;
					image[i][j][1] = 0;
					image[i][j][2] = 0;
				}
				flag ++;
				if (flag%2 == 0)
					k++;
				

			}
		}
		else if(color == "Geld")
		{
			int k = 0;
			int flag = 0;
			for (int i = x*16; i< (x+1)*16; i++)
			{

				for (int j = y*16 + 8 -k; j<y*16 + 8 + k; j++)
				{
					image[i][j][0] = 255;
					image[i][j][1] = 224;
					image[i][j][2] = 32;
				}
				flag ++;
				if (flag%2 == 0)
					k++;
			}
		}
		else if(color == "Gruen")
		{
			int k = 0;
			int flag = 0;
			for (int i = x*16; i< (x+1)*16; i++)
			{

				for (int j = y*16 + 8 -k; j<y*16 + 8 + k; j++)
				{
					image[i][j][0] = 0;
					image[i][j][1] = 192;
					image[i][j][2] = 0;
				}
				flag ++;
				if (flag%2 == 0)
					k++;
			}
		}
		else
		{
			std::cout<<"error"<<std::endl;
		}
	}

	else if (option == 2)
	{
		int r = 8;
		if (color == "Schwarz")
		{
			for (double theta=0.0; theta < 2*M_PI; theta += .01) 
			{
		     	double nx = r*cos(theta);
		     	double ny = r*sin(theta);
		     	nx += (x*16+8);
		     	ny += (y*16+8);
		     	image[(int)nx][(int)ny][0] = 0;
		     	image[(int)nx][(int)ny][1] = 0;
		     	image[(int)nx][(int)ny][2] = 0;
	  		}

		}
		else if(color == "Blau")
		{
			for (double theta=0.0; theta < 2*M_PI; theta += .01) 
			{
		     	double nx = r*cos(theta);
		     	double ny = r*sin(theta);
		     	nx += (x*16+8);
		     	ny += (y*16+8);
		     	image[(int)nx][(int)ny][0] = 0;
		     	image[(int)nx][(int)ny][1] = 32;
		     	image[(int)nx][(int)ny][2] = 255;
	  		}
		}
		else if(color == "Rot")
		{
			for (double theta=0.0; theta < 2*M_PI; theta += .01) 
			{
		     	double nx = r*cos(theta);
		     	double ny = r*sin(theta);
		     	nx += (x*16+8);
		     	ny += (y*16+8);
		     	image[(int)nx][(int)ny][0] = 255;
		     	image[(int)nx][(int)ny][1] = 0;
		     	image[(int)nx][(int)ny][2] = 0;
	  		}
		}
		else if(color == "Geld")
		{
			for (double theta=0.0; theta < 2*M_PI; theta += .01) 
			{
		     	double nx = r*cos(theta);
		     	double ny = r*sin(theta);
		     	nx += (x*16+8);
		     	ny += (y*16+8);
		     	image[(int)nx][(int)ny][0] = 255;
		     	image[(int)nx][(int)ny][1] = 224;
		     	image[(int)nx][(int)ny][2] = 32;
	  		}
		}
		else if(color == "Gruen")
		{
			for (double theta=0.0; theta < 2*M_PI; theta += .01) 
			{
		     	double nx = r*cos(theta);
		     	double ny = r*sin(theta);
		     	nx += (x*16+8);
		     	ny += (y*16+8);
		     	image[(int)nx][(int)ny][0] = 0;
		     	image[(int)nx][(int)ny][1] = 192;
		     	image[(int)nx][(int)ny][2] = 0;
	  		}
		}
		else
		{
			std::cout<<"error"<<std::endl;
		}
	}
	else if (option == 3)
	{
				int r = 8;
		if (color == "Schwarz")
		{
			for (double theta=0.0; theta < 2*M_PI; theta += .01) 
			{
		     	double nx = r*cos(theta);
		     	double ny = r*sin(theta);
		     	nx += (x*16+8);
		     	ny += (y*16+8);
		     	image[(int)nx][(int)ny][0] = 0;
		     	image[(int)nx][(int)ny][1] = 0;
		     	image[(int)nx][(int)ny][2] = 0;
	  		}
	  		for (int i = (x*16)+3; i< (x+1)*16 -3; i++)
			{
				for (int j = (y*16) + 3; j<(y+1)*16 - 3; j++)
					{
							image[i][j][0] = 0;
							image[i][j][1] = 0;
							image[i][j][2] = 0;
					}
			}

		}
		else if(color == "Blau")
		{
			for (double theta=0.0; theta < 2*M_PI; theta += .01) 
			{
		     	double nx = r*cos(theta);
		     	double ny = r*sin(theta);
		     	nx += (x*16+8);
		     	ny += (y*16+8);
		     	image[(int)nx][(int)ny][0] = 0;
		     	image[(int)nx][(int)ny][1] = 32;
		     	image[(int)nx][(int)ny][2] = 255;
	  		}
	  		for (int i = (x*16) + 3; i< (x+1)*16 -3; i++)
			{
				for (int j = (y*16) + 3; j<(y+1)*16 - 3; j++)
					{
							image[i][j][0] = 0;
							image[i][j][1] = 32;
							image[i][j][2] = 255;
					}
			}
		}
		else if(color == "Rot")
		{
			for (double theta=0.0; theta < 2*M_PI; theta += .01) 
			{
		     	double nx = r*cos(theta);
		     	double ny = r*sin(theta);
		     	nx += (x*16+8);
		     	ny += (y*16+8);
		     	image[(int)nx][(int)ny][0] = 255;
		     	image[(int)nx][(int)ny][1] = 0;
		     	image[(int)nx][(int)ny][2] = 0;
	  		}
	  		for (int i = (x*16)+3; i< (x+1)*16 -3; i++)
			{
				for (int j = (y*16) + 3; j<(y+1)*16 - 3; j++)
					{
							image[i][j][0] = 255;
							image[i][j][1] = 0;
							image[i][j][2] = 0;
					}
			}
		}
		else if(color == "Geld")
		{
			for (double theta=0.0; theta < 2*M_PI; theta += .01) 
			{
		     	double nx = r*cos(theta);
		     	double ny = r*sin(theta);
		     	nx += (x*16+8);
		     	ny += (y*16+8);
		     	image[(int)nx][(int)ny][0] = 255;
		     	image[(int)nx][(int)ny][1] = 224;
		     	image[(int)nx][(int)ny][2] = 32;
	  		}
	  		for (int i = (x*16)+3; i< (x+1)*16 -3; i++)
			{
				for (int j = (y*16) + 3; j<(y+1)*16 - 3; j++)
					{
							image[i][j][0] = 255;
							image[i][j][1] = 224;
							image[i][j][2] = 32;
					}
			}
		}
		else if(color == "Gruen")
		{
			for (double theta=0.0; theta < 2*M_PI; theta += .01) 
			{
		     	double nx = r*cos(theta);
		     	double ny = r*sin(theta);
		     	nx += (x*16+8);
		     	ny += (y*16+8);
		     	image[(int)nx][(int)ny][0] = 0;
		     	image[(int)nx][(int)ny][1] = 192;
		     	image[(int)nx][(int)ny][2] = 0;
	  		}

	  		for (int i = (x*16) +3; i< (x+1)*16 -3; i++)
			{
				for (int j = (y*16) + 3; j<(y+1)*16 - 3; j++)
					{
							image[i][j][0] = 0;
							image[i][j][1] = 192;
							image[i][j][2] = 0;
					}
			}
		}

		else
		{
			std::cout<<"error"<<std::endl;
		}
	}

}