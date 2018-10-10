#include<iostream>
#include<vector>
using namespace std;


class moves{
	int start[2];
	int finish[2];
	vector<pair<int,int>> jumps;
	vector<pair<int,int>> intermediates;
	
	void actuallyMove(piece* boardData[8][8])
	{
		boardData[finish[0]][finish[1]]=board[start[0]][start[1]];
		delete boardData[start[0]][start[1]];
		if(!jumps.empty())
		{
			for(auto i: jumps)
			{
				delete board[i->first][i->second];
			}
		}
	}
		
};
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

void boardBuilder(piece* boardData[8][8]);
void boardSetter(piece* boardData[8][8]);
void legalMoves(piece* boardData[8][8], bool compMove);

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
	cout<<"To set the board: type c to set piece to computer, type p to set piece to computer.\nFor king, add a 1 to the end.\n";
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
				if(input.size()>1)
				       boardData[i][j]->promote();
			}
			if(input[0]=='p')
			{
				boardData[i][j]=new piece(pos, false);
				if(input.size()>1)
					boardData[i][j]->promote();
			}	
		}

			
	}
}

void playerMoves(piece* boardData[8][8])
{
	vector<moves> legalMoves;
	for(int i=0; i<8; i++)
	{
		for(int j=i%2; j<
	}
}

int main()
{ 
	piece* boardData[8][8]={NULL};
	bool compMove=false;
	boardSetter(boardData);
	
	
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
