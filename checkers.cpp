#include<iostream>
#include<vector>
#include<string>
#include<ctype.h>
#include<sstream>
using namespace std;


class piece{
	private:
		bool isKing=false;
		int position[2];
		bool comp;
	public:
		piece(int pos[2], bool c)
		{
			comp=c;
			position[0]=pos[0];
			position[1]=pos[1];
		}

		void promote()
		{
			isKing=true;
		}
		
		bool team()
		{
			return comp;
		}
		bool king(){return isKing;}
		
};
class moves{
		int start[2];
		int finish[2];
		vector<pair<int,int> > jumps;
		vector<pair<int,int> > intermediates;
		bool doesPromote=false;
	public:
		moves(int s1, int s2, int f1, int f2)
		{
			start[0]=s1;
			start[1]=s2;
			finish[0]=f1;
			finish[1]=f2;
		}

		void addIntermediate(int i, int j)
		{
			intermediates.push_back(make_pair(i,j));
		}
		void delIntermediate()
		{
			intermediates.pop_back();
		}
		void addJump(int i, int j)
		{
			jumps.push_back(make_pair(i,j));	
		}
		void delJump()
		{
			jumps.pop_back();
		}
		

		bool checkFirst(int i, int j){return (i==start[0],j==start[1]);}

		
		void setFinish(int i, int j)
		{
			finish[0]=i;
			finish[1]=j;
		}
		void promoteP(int i)
		{
			if(i==0)
				doesPromote=true;
		}
		void actuallyMove(piece* boardData[8][8])
		{
			boardData[finish[0]][finish[1]]=boardData[start[0]][start[1]];
			if(doesPromote)
				boardData[finish[0]][finish[1]]->promote();
			boardData[start[0]][start[1]]=NULL;
			if(!jumps.empty())
			{
				for(const pair<int,int> &i : jumps)
				{
					delete boardData[i.first][i.second];
					boardData[i.first][i.second]=NULL;
				}
			}
		}
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

bool isWord(string);
void boardBuilder(piece* boardData[8][8]);
void boardSetter(piece* boardData[8][8]);
void legalMoves(piece* boardData[8][8], bool compMove);
void playerJumpCheck(vector<moves> &legalMoves, piece* boardData[8][8], bool isKing, int i, int j,moves move);
void playerMoves(piece* boardData[8][8]);


bool isNumber(string s){
	for(int i=0; i<s.size(); i++)
	{
		if(!isdigit(s[i]))
			return false;
	}
	return true;
}

void boardBuilder(piece* boardData[8][8])
{
	cout<<"\033[1m    a   b   c   d   e   f   g   h  \n"; 
	cout<<"\033[1m  ---------------------------------\n";
	for(int i=0; i<8; i++)
	{
		cout<<"\033[1m"<< i<< " ";
		for(int j =0; j<8; j++)
		{
			cout<<"\033[1m|";
			if(boardData[i][j]==NULL)
				cout<<"   ";
			else if(boardData[i][j]->team())
			{
				if(boardData[i][j]->king())
					cout<<"\033[1;41;37m KC\033[0m";
				else
					cout<<"\033[1;41;37m C \033[0m";
				
			}
			else
			{
				if(boardData[i][j]->king())
					cout<<"\033[1;44;37m KP\033[0m";
				else
					cout<<"\033[1;44;37m P \033[0m";
			}
		}
		cout<<"\033[1m|\n  ---------------------------------\n";
	}
	return;
}
void boardSetter(piece* boardData[8][8])
{
	boardBuilder(boardData);
	char letters[8]={'a','b','c','d','e','f','g','h'};
	string input;
	cout<<"To set the board: type c to set piece to computer, type p to set piece to computer, and type any other key for empty.\nFor king, add a 1 to the end.\n";
	for(int i=0; i<8; i++)
	{	
		for(int j=(i+1)%2; j<8; j+=2)
		{
			cout<<"row " << i << " column "<< letters[j]<<": ";
			cin >> input;
			int pos[2]={i,j};
			if(input[0]=='c')
			{
				boardData[i][j]= new piece(pos, true);
				if(input.size()>1||i==7)
				       boardData[i][j]->promote();
			}
			else if(input[0]=='p')
			{
				boardData[i][j]=new piece(pos, false);
				if(input.size()>1||i==0)
					boardData[i][j]->promote();
			}
			else
				boardData[i][j]=NULL;	
		}

			
	}
}

void playerJumpCheck(vector<moves> &legalMoves, piece* boardData[8][8], bool isKing, int i, int j,moves move)
{
	bool isJump =false;		
	piece* temp;
	if(isKing && (i+2)<8)
	{
		if((j+2)<8 && boardData[i+1][j+1]!=NULL && boardData[i+1][j+1]->team() && boardData[i+2][j+2]==NULL)
			{
				isJump=true;
				temp=boardData[i+1][j+1];
				boardData[i+1][j+1]=NULL;
				if(!move.checkFirst(i,j))
					move.addIntermediate(i,j);	
				move.addJump(i+1,j+1);
				playerJumpCheck(legalMoves, boardData, isKing, i+2, j+2,move);
				if(!move.checkFirst(i,j))
					move.delIntermediate();
				move.delJump();
				boardData[i+1][j+1]=temp;
			}	
		if((j-2)>=0 && boardData[i+1][j-1]!=NULL && boardData[i+1][j-1]->team() && boardData[i+2][j-2]==NULL)
			{		
				isJump=true;
				temp=boardData[i+1][j-1];
				boardData[i+1][j-1]=NULL;
				if(!move.checkFirst(i,j))
					move.addIntermediate(i,j);	
				move.addJump(i+1,j-1);
				playerJumpCheck(legalMoves, boardData, isKing, i+2, j-2,move);
				if(!move.checkFirst(i,j))
					move.delIntermediate();
				move.delJump();
				boardData[i+1][j-1]=temp;
			}	
	}
	if(i-2>=0)
	{
		if((j+2)<8 && boardData[i-1][j+1]!=NULL && boardData[i-1][j+1]->team() && boardData[i-2][j+2]==NULL)
			{
				isJump=true;
				temp=boardData[i-1][j+1];
				boardData[i-1][j+1]=NULL;
				if(!move.checkFirst(i,j))
					move.addIntermediate(i,j);	
				move.addJump(i-1,j+1);
				playerJumpCheck(legalMoves, boardData, isKing, i-2, j+2,move);
				if(!move.checkFirst(i,j))
					move.delIntermediate();
				move.delJump();
				boardData[i-1][j+1]=temp;
			}	
		if((j-2)>=0 && boardData[i-1][j-1]!=NULL && boardData[i-1][j-1]->team() && boardData[i-2][j-2]==NULL)
			{
				isJump=true;
				temp=boardData[i-1][j-1];
				boardData[i-1][j-1]=NULL;
				if(!move.checkFirst(i,j))
					move.addIntermediate(i,j);	
				move.addJump(i-1,j-1);
				playerJumpCheck(legalMoves, boardData, isKing, i-2, j-2,move);
				if(!move.checkFirst(i,j))
					move.delIntermediate();
				move.delJump();
				boardData[i-1][j-1]=temp;
			}	
	
	}
	if(!isJump)
	{
		move.setFinish(i,j);
		move.promoteP(i);
		legalMoves.push_back(move);
	}

} 


void playerMoves(piece* boardData[8][8])
{
	bool jump=false;
	vector<moves> legalMoves;
	
	for(int i=0; i<8; i++)
	{
		for(int j=(i+1)%2; j<8; j+=2)
		{
			if(boardData[i][j]==NULL||boardData[i][j]->team())
				continue;
			if(boardData[i][j]->king() && (i+2)<8)
			{
				if((j+2)<8 && boardData[i+1][j+1]!=NULL && boardData[i+1][j+1]->team() && boardData[i+2][j+2]==NULL)
					{
						if(!jump)
						{
							jump=true;
							legalMoves.clear();
						}
						moves temp=moves(i,j,i,j);
						playerJumpCheck(legalMoves, boardData, boardData[i][j]->king(), i, j,temp);
						continue;	
					}	
				else if((j-2)>=0 && boardData[i+1][j-1]!=NULL && boardData[i+1][j-1]->team() && boardData[i+2][j-2]==NULL)
					{
						if(!jump)
						{
							jump=true;
							legalMoves.clear();
						}
						moves temp=moves(i,j,i,j);
						playerJumpCheck(legalMoves, boardData, boardData[i][j]->king(),i,j,temp);	
						continue;
					}	
			}
			if(i-2>=0)
			{
				if((j+2)<8 && boardData[i-1][j+1]!=NULL && boardData[i-1][j+1]->team() && boardData[i-2][j+2]==NULL)
					{
						if(!jump)
						{
							jump=true;
							legalMoves.clear();
						}
						moves temp=moves(i,j,i,j);
						playerJumpCheck(legalMoves, boardData, boardData[i][j]->king(),i,j,temp);	
					}	
				else if((j-2)>=0 && boardData[i-1][j-1]!=NULL && boardData[i-1][j-1]->team() && boardData[i-2][j-2]==NULL)
					{
						if(!jump)
						{
							jump=true;
							legalMoves.clear();
						}
						moves temp=moves(i,j,i,j);
						playerJumpCheck(legalMoves, boardData, boardData[i][j]->king(),i,j,temp);	
					}	
	
			}			
			if(!jump)
			{
				if(boardData[i][j]->king() && (i+1)<8)
				{
					if((j+1)<8 && boardData[i+1][j+1]==NULL)
					{
						moves temp= moves(i,j,i+1,j+1);
						legalMoves.push_back(temp);
					}
					if((j-1)>=0 && boardData[i+1][j-1]==NULL)
					{	
						moves temp= moves(i,j,i+1,j-1);
						legalMoves.push_back(temp);
					}
				}
				if((i-1)>=0)
				{
					if((j+1)<8 && boardData[i-1][j+1]==NULL)
					{
						moves temp= moves(i,j,i-1,j+1);
						temp.promoteP(i-1);	
						legalMoves.push_back(temp);
					}
					if((j-1)>=0 && boardData[i-1][j-1]==NULL)
					{
						moves temp= moves(i,j,i-1,j-1);
						temp.promoteP(i-1);	
						legalMoves.push_back(temp);
					}
				}				 
			}
			
		}
	}

	for(int i=0; i<legalMoves.size(); i++)
	{
		cout<< i <<". ";
		legalMoves[i].print();
	}
	string input;
	while(1)
	{
		cin >> input;
		if(isNumber(input))
		{
			stringstream i(input);
			int val = 0;
			i>>val;
			if(val>=0 && val<legalMoves.size())
			{
				legalMoves[val].actuallyMove(boardData);
				break;
			}
			else
				cout<<"Please enter a number within the range";
		}
		else
			cout<<"Please enter a number\n";
	}
	
}

int main()
{ 
	piece* boardData[8][8]={NULL};
	bool compMove=false;
	boardSetter(boardData);
	boardBuilder(boardData);
	playerMoves(boardData);	
	
	/*
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			boardData[i][j]=1;
		}
	}
	*/
	boardBuilder(boardData);
	return 0;
}
