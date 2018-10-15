#include<iostream>
#include<vector>
#include<string>
#include<ctype.h>
#include<sstream>
using namespace std;

//This is the class that represents an individual piece on the board.
//It holds the position of the piece, whether or not the piece is a king, and what team the piece is on. 
class piece{
	private:
		bool isKing=false;//king value: true if it is a king
		int position[2];
		bool comp; //team: true if it is on the computer's team
	public:
		//Constructor for a piece that sets the position value and team
		piece(int pos[2], bool c)
		{
			comp=c;
			position[0]=pos[0];
			position[1]=pos[1];
		}
		
		//promotes a piece to a king
		void promote()
		{
			isKing=true;
		}
		
		//returns the piece's team
		bool team()
		{
			return comp;
		}

		//returns whether or not the piece is a king
		bool king(){return isKing;}
		
};

//this class is for moves. It stores where the piece would start, where the piece would end, the places the piece jumps over, the intermediate places between jumps, and whether the move would make the piece a king.
class moves{
		int start[2];//starting coordinates: x y
		int finish[2];//finishing coordinates: x y
		vector<pair<int,int> > jumps;//possible jumps
		vector<pair<int,int> > intermediates;//intermediates for jumps
		moves *next_moves[100]={NULL};
		bool doesPromote=false;
	public:
		//constructor with coordinates
		moves(int s1, int s2, int f1, int f2)
		{
			start[0]=s1;
			start[1]=s2;
			finish[0]=f1;
			finish[1]=f2;
		}
		
		//adds intermediate if a jump occurs
		void addIntermediate(int i, int j)
		{
			intermediates.push_back(make_pair(i,j));
		}
		
		//deletes an Intermediate. Needed for recursive calling
		void delIntermediate()
		{
			intermediates.pop_back();
		}
		//adds a jumped coordinate	
		void addJump(int i, int j)
		{
			jumps.push_back(make_pair(i,j));	
		}
		//deletes a jump
		void delJump()
		{
			jumps.pop_back();
		}
		
		//checks to see if the jump is the first jump
		bool checkFirst(int i, int j){return (i==start[0],j==start[1]);}

		//sets the ending coordinate.
		void setFinish(int i, int j)
		{
			finish[0]=i;
			finish[1]=j;
		}
		//checks to see if the player's piece will promote
		void promote_piece(int i, bool team)
		{
			if(team && i==7)
				doesPromote=true;
			else if(i==0 && !team)
				doesPromote=true;
		}
		

		//actually moves a piece when called.
		void actuallyMove(piece* boardData[8][8])
		{
			//changes the pointer of the finishing point to the piece
			boardData[finish[0]][finish[1]]=boardData[start[0]][start[1]];
			//promotes a piece if needed
			if(doesPromote)
				boardData[finish[0]][finish[1]]->promote();
			//empties starting point
			boardData[start[0]][start[1]]=NULL;
			//deletes the jumped pieces
			if(!jumps.empty())
			{
				for(const pair<int,int> &i : jumps)
				{
					delete boardData[i.first][i.second];
					boardData[i.first][i.second]=NULL;
				}
			}
		}
		//prints what the move will do
		void print()
		{
			char letters[8]={'a','b','c','d','e','f','g','h'};
			cout<<"From "<< start[0] << letters[start[1]]<<" to "<< finish[0] << letters[finish[1]];
			if(intermediates.size()!=0)
			{
				for(const pair<int,int> &i : intermediates)
				{
					cout<<" through " << i.first<<letters[i.second];
				}
			}
			cout<<endl;
		}
		
};

