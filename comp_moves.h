#include<iostream>
#include "classes.cpp"

using namespace std;

void jump_check(moves &pos_moves[100], int &back, piece board[8][8], bool is_king, int i, int j, moves move,bool team)
{
		
	bool is_jump = false;
	piece temp;
	if(team)
		if((i+2)<8)
	        {
	                if((j+2)<8 && board[i+1][j+1]!=NULL && board[i+1][j+1].team()!=team && board[i+2][j+2]==NULL)
	                        {
	                                isJump=true;
	                                temp=board[i+1][j+1];
	                                board[i+1][j+1]=NULL;
	                                if(!move.checkFirst(i,j))
	                                        move.addIntermediate(i,j);
	                                move.addJump(i+1,j+1);
	                                jump_check(pos_moves, back, board, is_king, i+2, j+2,move, team);
	                                if(!move.checkFirst(i,j))
	                                        move.delIntermediate();
	                                move.delJump();
	                                board[i+1][j+1]=temp;
	                        }
	                if((j-2)>=0 && board[i+1][j-1]!=NULL && board[i+1][j-1].team()!=team && board[i+2][j-2]==NULL)
	                        {
	                                isJump=true;
	                                temp=board[i+1][j-1];
	                                board[i+1][j-1]=NULL;
	                                if(!move.checkFirst(i,j))
	                                        move.addIntermediate(i,j);
	                                move.addJump(i+1,j-1);
	                                jump_check(pos_moves,back, board, is_king, i+2, j-2,move, team);
	                                if(!move.checkFirst(i,j))
	                                        move.delIntermediate();
	                                move.delJump();
	                                board[i+1][j-1]=temp;
	                        }
	        }
		if(is_king && i-2>=0)
	        {
	                if((j+2)<8 && board[i-1][j+1]!=NULL && board[i-1][j+1].team()!=team && board[i-2][j+2]==NULL)
	                        {
	                                isJump=true;
	                                temp=board[i-1][j+1];
	                                board[i-1][j+1]=NULL;
	                                if(!move.checkFirst(i,j))
	                                        move.addIntermediate(i,j);
	                                move.addJump(i-1,j+1);
	                                jump_check(pos_moves, back, board, is_king, i-2, j+2,move, team);
	                                if(!move.checkFirst(i,j))
	                                        move.delIntermediate();
	                                move.delJump();
	                                board[i-1][j+1]=temp;
	                        }
	                if((j-2)>=0 && board[i-1][j-1]!=NULL && board[i-1][j-1].team()!=team && board[i-2][j-2]==NULL)
	                        {
	                                isJump=true;
	                                temp=board[i-1][j-1];
	                                board[i-1][j-1]=NULL;
	                                if(!move.checkFirst(i,j))
	                                        move.addIntermediate(i,j);
	                                move.addJump(i-1,j-1);
	                                jump_check(pos_moves, back, board, is_king, i-2, j-2,move,team);
	                                if(!move.checkFirst(i,j))
	                                        move.delIntermediate();
	                                move.delJump();
	                                board[i-1][j-1]=temp;
	                        }
	
	        }
	
		if(!isJump)
	        {
	                move.setFinish(i,j);
	                move.promote_piece(i, true);
	                pos_moves[back]=move;
			back++;
	        }
	}
	else
	{
		if(is_king && (i+2)<8)
	        {
	                if((j+2)<8 && board[i+1][j+1]!=NULL && board[i+1][j+1].team()!=team && board[i+2][j+2]==NULL)
	                        {
	                                isJump=true;
	                                temp=board[i+1][j+1];
	                                board[i+1][j+1]=NULL;
	                                if(!move.checkFirst(i,j))
	                                        move.addIntermediate(i,j);
	                                move.addJump(i+1,j+1);
	                                jump_check(pos_moves, back, board, is_king, i+2, j+2,move, team);
	                                if(!move.checkFirst(i,j))
	                                        move.delIntermediate();
	                                move.delJump();
	                                board[i+1][j+1]=temp;
	                        }
	                if((j-2)>=0 && board[i+1][j-1]!=NULL && board[i+1][j-1].team()!=team && board[i+2][j-2]==NULL)
	                        {
	                                isJump=true;
	                                temp=board[i+1][j-1];
	                                board[i+1][j-1]=NULL;
	                                if(!move.checkFirst(i,j))
	                                        move.addIntermediate(i,j);
	                                move.addJump(i+1,j-1);
	                                jump_check(pos_moves, back, board, is_king, i+2, j-2,move,team);
	                                if(!move.checkFirst(i,j))
	                                        move.delIntermediate();
	                                move.delJump();
	                                board[i+1][j-1]=temp;
	                        }
	        }
		if(i-2>=0)
	        {
	                if((j+2)<8 && board[i-1][j+1]!=NULL && board[i-1][j+1].team()!=team && board[i-2][j+2]==NULL)
	                        {
	                                isJump=true;
	                                temp=board[i-1][j+1];
	                                board[i-1][j+1]=NULL;
	                                if(!move.checkFirst(i,j))
	                                        move.addIntermediate(i,j);
	                                move.addJump(i-1,j+1);
	                                jump_check(pos_moves, back, board, is_king, i-2, j+2,move, team);
	                                if(!move.checkFirst(i,j))
	                                        move.delIntermediate();
	                                move.delJump();
	                                board[i-1][j+1]=temp;
	                        }
	                if((j-2)>=0 && board[i-1][j-1]!=NULL && board[i-1][j-1].team()!=team && board[i-2][j-2]==NULL)
	                        {
	                                isJump=true;
	                                temp=board[i-1][j-1];
	                                board[i-1][j-1]=NULL;
	                                if(!move.checkFirst(i,j))
	                                        move.addIntermediate(i,j);
	                                move.addJump(i-1,j-1);
	                                jump_check(pos_moves, back, board, is_king, i-2, j-2,move,team);
	                                if(!move.checkFirst(i,j))
	                                        move.delIntermediate();
	                                move.delJump();
	                                board[i-1][j-1]=temp;
	                        }
	
	        }
	
		if(!isJump)
	        {
	                move.setFinish(i,j);
	                move.promote_piece(i, false);
	                pos_moves[back]=move;
			back++;
	        }
	}
}

void legal_moves_gen(moves &pos_moves[100], int &back, piece non_ptr_board[8][8],bool team)
{
	bool jump=false;
	for(int i=0; i<8; i++)
	{	
		for(int j=(i+1); j<8; j+=2)
		{
			if(non_ptr_board[i][j]==NULL)
                                continue; 
			if(non_ptr_board[i][j].team())
			{
	                        if((i+2)<8)
        	                {
                	                if((j+2)<8 && non_ptr_board[i+1][j+1]!=NULL && non_ptr_board[i+1][j+1].team()!=team && non_ptr_board[i+2][j+2]==NULL)
                        	                {
                        	                        if(!jump)
                        	                        {
                               		                        jump=true;
                               	        	                fill(pos_moves.begin(), pos_moves.end(), NULL);
								back=0;
                                                	}
							moves temp=moves(i,j,i,j);
							jump_check(pos_moves,back, non_ptr_board, non_ptr_board[i][j].king(),i,j, temp, team); 	
                                                	continue;    
                                        	}    
                                	else if((j-2)>=0 && non_ptr_board[i+1][j-1]!=NULL && non_ptr_board[i+1][j-1].team()!=team && non_ptr_board[i+2][j-2]==NULL)
                                        	{
                                                	if(!jump)
                                                	{
                                                        	jump=true;
                                                        	fill(pos_moves.begin(), pos_moves.end(), NULL);
								back=0;
                                                	}
							moves temp=moves(i,j,i,j);
							jump_check(pos_moves,back, non_ptr_board, non_ptr_board[i][j].king(),i,j, temp, team); 	
                                                	continue;
                                        	}    
                        	}
                        	if(non_ptr_board[i][j].king() && i-2>=0)
                        	{
                                	if((j+2)<8 && non_ptr_board[i-1][j+1]!=NULL && non_ptr_board[i-1][j+1].team()!=team && non_ptr_board[i-2][j+2]==NULL)
                                        {
                                                if(!jump)
                                                {
                                                        jump=true;
                                                        fill(pos_moves.begin(), pos_moves.end(), NULL);
							back=0;
                                                }
						moves temp=moves(i,j,i,j);
						jump_check(pos_moves,back, non_ptr_board, non_ptr_board[i][j].king(),i,j, temp, team); 	
                                        }    
                              		else if((j-2)>=0 && non_ptr_board[i-1][j-1]!=NULL && non_ptr_board[i-1][j-1].team()!=team && non_ptr_board[i-2][j-2]==NULL)
                                       	{
                                                if(!jump)
                                                {
                                                        jump=true;
                                                        fill(pos_moves.begin(), pos_moves.end(), NULL);
							back=0;
                                                }
						moves temp=moves(i,j,i,j);
						jump_check(pos_moves,back, non_ptr_board, non_ptr_board[i][j].king(),i,j, temp, team); 	
                                        }    
    
                        	} 
 				if(!jump)
                        	{
                                	if((i+1)<8)
                                	{
                                	        if((j+1)<8 && non_ptr_board[i+1][j+1]==NULL)
                                       		{
                                                	moves temp= moves(i,j,i+1,j+1);
                                                	temp.promote_piece(i+1);
                                                	pos_moves[back]=temp;
							back++;
                                        	}
                                        	if((j-1)>=0 && non_ptr_board[i+1][j-1]==NULL)
                                        	{
                                        	        moves temp= moves(i,j,i+1,j-1);
                                        	        temp.promote_piece(i+1);
                                        	        pos_moves[back]=temp;
							back++;
                                        	}
                                	}
                                	if(non_ptr_board[i][j].king() && (i-1)>=0)
                                	{
                                	        if((j+1)<8 && non_ptr_board[i-1][j+1]==NULL)
                                	        {
                                	                moves temp= moves(i,j,i-1,j+1);
                                	                temp.promote_piece(i-1,non_ptr_board[i][j].team());
                                	                pos_moves[back]=temp;
							back++;
                                	        }
                                	        if((j-1)>=0 && non_ptr_board[i-1][j-1]==NULL)
                                	        {
                                	                moves temp= moves(i,j,i-1,j-1);
                                	                temp.promote_piece(i-1,non_ptr_board[i][j].team());
                                	                pos_moves[back]=temp;
							back++;
                                	        }
                                	}
                        	}
			}
			

			else
			{
	                        if(non_ptr_board[i][j].king() && (i+2)<8)
        	                {
                	                if((j+2)<8 && non_ptr_board[i+1][j+1]!=NULL && non_ptr_board[i+1][j+1].team()!=team && non_ptr_board[i+2][j+2]==NULL)
                        	                {
                        	                        if(!jump)
                        	                        {
                               		                        jump=true;
                               	        	                fill(pos_moves.begin(), pos_moves.end(), NULL);
								back=0;
                                                	}
							moves temp=moves(i,j,i,j);
							jump_check(pos_moves,back, non_ptr_board, non_ptr_board[i][j].king(),i,j, temp, team); 	
                                                	continue;    
                                        	}    
                                	else if((j-2)>=0 && non_ptr_board[i+1][j-1]!=NULL && non_ptr_board[i+1][j-1].team()!=team && non_ptr_board[i+2][j-2]==NULL)
                                        	{
                                                	if(!jump)
                                                	{
                                                        	jump=true;
                                                        	fill(pos_moves.begin(), pos_moves.end(), NULL);
								back=0;
                                                	}
							moves temp=moves(i,j,i,j);
							jump_check(pos_moves,back, non_ptr_board, non_ptr_board[i][j].king(),i,j, temp, team); 	
                                                	continue;
                                        	}    
                        	}
                        	if(i-2>=0)
                        	{
                                	if((j+2)<8 && non_ptr_board[i-1][j+1]!=NULL && non_ptr_board[i-1][j+1].team()!=team && non_ptr_board[i-2][j+2]==NULL)
                                        {
                                                if(!jump)
                                                {
                                                        jump=true;
                                                        fill(pos_moves.begin(), pos_moves.end(), NULL);
							back=0;
                                                }
						moves temp=moves(i,j,i,j);
						jump_check(pos_moves,back, non_ptr_board, non_ptr_board[i][j].king(),i,j, temp, team); 	
                                        }    
                              		else if((j-2)>=0 && non_ptr_board[i-1][j-1]!=NULL && non_ptr_board[i-1][j-1].team()!=team && non_ptr_board[i-2][j-2]==NULL)
                                       	{
                                                if(!jump)
                                                {
                                                        jump=true;
                                                        fill(pos_moves.begin(), pos_moves.end(), NULL);
							back=0;
                                                }
						moves temp=moves(i,j,i,j);
						jump_check(pos_moves,back, non_ptr_board, non_ptr_board[i][j].king(),i,j, temp, team); 	
                                        }    
    
                        	} 
 				if(!jump)
                        	{
                                	if(non_ptr_board[i][j].king() && (i+1)<8)
                                	{
                                	        if((j+1)<8 && non_ptr_board[i+1][j+1]==NULL)
                                       		{
                                                	moves temp= moves(i,j,i+1,j+1);
                                                	pos_moves[back]=temp;
							back++;
                                        	}
                                        	if((j-1)>=0 && non_ptr_board[i+1][j-1]==NULL)
                                        	{
                                        	        moves temp= moves(i,j,i+1,j-1);
                                        	        pos_moves[back]=temp;
							back++;
                                        	}
                                	}
                                	if((i-1)>=0)
                                	{
                                	        if((j+1)<8 && non_ptr_board[i-1][j+1]==NULL)
                                	        {
                                	                moves temp= moves(i,j,i-1,j+1);
                                	                temp.promote_piece(i-1,non_ptr_board[i][j].team());
                                	                pos_moves[back]=temp;
							back++;
                                	        }
                                	        if((j-1)>=0 && non_ptr_board[i-1][j-1]==NULL)
                                	        {
                                	                moves temp= moves(i,j,i-1,j-1);
                                	                temp.promote_piece(i-1,non_ptr_board[i][j].team());
                                	                pos_moves[back]=temp;
							back++;
                                	        }
                                	}
                        	}	


			}
		}
	}

	
}	


void comp_move_selector(piece* boardData[8][8])
{
	int back=0;
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
	
	comp_moves(pos_moves,back,non_ptr_board);
	
	int max=INT_MIN;
	int index_of_max;
	
	
	int max_depth;
	for(int i=0; pos_moves[i]!=NULL; i++)
	{
		int current =IDS(0,piece board[8][8], max_depth, pos_moves[i]);
		if(current>max)
		{
			max=current;
			index_of_max=i;
		}
	}
	//choose index_of_max move;	
}

int get_min(int first, int second)
{
	if(first<second)
		return first;
	else 
		return second;
}

int get_max(int first, int second)
{
	if(first>second)
		return first;
	else
		return second;
}

int IDS(int depth, piece board[8][8], int max_depth, int alpha, int beta, moves move)
{
	move.simulated_move(board);
	if(depth==max_depth)
		return depth;//this should be heuristic(board);
	else
	{
		int value;
		if(depth%2==0)
		{
			moves pos_moves[100]={NULL};
			int back=0;
			legal_moves_gen(pos_moves, back, board,true);
			value=INT_MIN;
			for(int i=0; pos_moves[i]!=NULL; i++)
			{
				value=get_max(value, IDS(depth+1, board, max_depth, alpha, beta, pos_moves[i]));
				alpha = get_max(value, alpha);
				if(alpha>=beta)
					break;
			}
			return value;
		}
		else
		{
			moves pos_moves[100]={NULL};
			int back=0;
			legal_moves_gen(pos_moves, back, board, false);
			value=INT_MAX;
			for(int i=0; pos_moves[i]!=NULL; i++_
			{
				value=get_min(value, IDS(depth+1, board, max_depth, alpha, beta, pos_moves[i]));
				beta = get_min(value,beta);
				if(alpha>=beta)
					break;
			}
			return value;
		}
	}
}



