#include<iostream>
#include "classes.cpp"

using namespace std;




void comp_moves(piece* boardData[8][8])
{
	bool jump=false;
	int index=0;
	moves pos_moves[100]={NULL};
	piece non_ptr_board[8][8]={NULL};
	
	for(int i=0; i<8; i++)
	{
		for(int j=(i+1); j<8; j+=2)
		{
			if(boardData[i][j]!=NULL)
				non_ptr_board[i][j]=*boardData[i][j];
		}
	}

	for(int i=0; i<8; i++)
	{	
		for(int j=(i+1); j<8; j+=2)
		{
			if(non_ptr_board[i][j]==NULL||!non_ptr_board[i][j].team())
                                continue; 
                        if((i+2)<8)
                        {
                                if((j+2)<8 && non_ptr_board[i+1][j+1]!=NULL && non_ptr_board[i+1][j+1].team() && non_ptr_board[i+2][j+2]==NULL)
                                        {
                                                if(!jump)
                                                {
                                                        jump=true;
                                                        fill(pos_moves.begin(), pos_moves.end(), NULL);
                                                }
                                                continue;    
                                        }    
                                else if((j-2)>=0 && non_ptr_board[i+1][j-1]!=NULL && non_ptr_board[i+1][j-1].team() && non_ptr_board[i+2][j-2]==NULL)
                                        {
                                                if(!jump)
                                                {
                                                        jump=true;
                                                        fill(pos_moves.begin(), pos_moves.end(), NULL);
                                                }
                                                continue;
                                        }    
                        }
                        if(non_ptr_board[i][j].king() && i-2>=0)
                        {
                                if((j+2)<8 && non_ptr_board[i-1][j+1]!=NULL && non_ptr_board[i-1][j+1].team() && non_ptr_board[i-2][j+2]==NULL)
                                        {
                                                if(!jump)
                                                {
                                                        jump=true;
                                                        fill(pos_moves.begin(), pos_moves.end(), NULL);
                                                }
                                        }    
                                else if((j-2)>=0 && non_ptr_board[i-1][j-1]!=NULL && non_ptr_board[i-1][j-1].team() && non_ptr_board[i-2][j-2]==NULL)
                                        {
                                                if(!jump)
                                                {
                                                        jump=true;
                                                        fill(pos_moves.begin(), pos_moves.end(), NULL);
                                                }
                                        }    
    
                        } 
 			if(!jump)
                        {
                                if((i+1)<8)
                                {
                                        if((j+1)<8 && non_ptr_board[i+1][j+1]==NULL)
                                        {
                                                moves temp= moves(i,j,i+1,j+1);
                                                temp.promoteC(i+1);
                                                pos_moves[back]=temp;
                                        }
                                        if((j-1)>=0 && non_ptr_board[i+1][j-1]==NULL)
                                        {
                                                moves temp= moves(i,j,i+1,j-1);
                                                temp.promoteC(i+1);
                                                pos_moves[back]=temp;
                                        }
                                }
                                if(non_ptr_board[i][j].king() && (i-1)>=0)
                                {
                                        if((j+1)<8 && non_ptr_board[i-1][j+1]==NULL)
                                        {
                                                moves temp= moves(i,j,i-1,j+1);
                                                pos_moves[back]=temp;
                                        }
                                        if((j-1)>=0 && non_ptr_board[i-1][j-1]==NULL)
                                        {
                                                moves temp= moves(i,j,i-1,j-1);
                                                pos_moves[back]=temp;
                                        }
                                }
                        }
  

		}
	}
}	
		
