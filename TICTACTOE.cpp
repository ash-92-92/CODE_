#include<iostream>
#include<stdlib.h>
using namespace std;
#define row_count 3
//variables
int row=0,col=0;
char turn='X';
bool draw=false;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool gameover(){
     for(int row=0;row<row_count;row++){
        if(((board[row][0]==board[row][1])&&(board[row][1]==board[row][2]))||
        ((board[0][row]==board[1][row])&&(board[2][row]==board[1][row])))
            return false; 
        else if(((board[0][0]==board[1][1])&&(board[1][1]==board[2][2]))||((board[0][2]==board[2][0])&&(board[2][0]==board[1][1])))
            return false;
        for(int row=0;row<row_count;row++){
            for(int col=0;col<row_count;col++){
                if(board[row][col]!='X'&&board[row][col]!='O')
                    return true;
            }
        }
        draw=true;
        return false;
    }
}
void player_turn(){
    if(turn=='X')
        cout<<"\n\tPlayer -1 [X] turn:";
    else if(turn=='O')
        cout<<"\n\tPlayer -2 [O] turn:";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:row=0;col=0;break;
        case 2:row=0;col=1;break;
        case 3:row=0;col=2;break;
        case 4:row=1;col=0;break;
        case 5:row=1;col=1;break;
        case 6:row=1;col=2;break;
        case 7:row=2;col=0;break;
        case 8:row=2;col=1;break;
        case 9:row=2;col=2;break;
    }
    if(turn=='X'&&board[row][col]!='X'&&board[row][col]!='O'){
        board[row][col]='X';
        turn='O';
    }
    else if(turn=='O'&&board[row][col]!='X'&&board[row][col]!='O'){
        board[row][col]='O';
        turn='X';
    }
    else{
        cout<<"The You have chosen is already filled,choose any other box"<<endl;
        player_turn();
    }
}
void displayboard(){
    system("cls");
    cout<<"Player -1 [X]   Player -2 [O]"<<endl;
    cout<<"\t\t     |       |     "<<endl;
    cout<<"\t\t"<<board[0][0]<<"    |   "<<board[0][1]<<"   |   "<<board[0][2]<<endl;
    cout<<"\t\t     |       |     "<<endl;
    cout<<"\t\t___________________"<<endl;
    cout<<"\t\t     |       |     "<<endl;
    cout<<"\t\t"<<board[1][0]<<"    |   "<<board[1][1]<<"   |   "<<board[1][2]<<endl;
    cout<<"\t\t     |       |     "<<endl;
    cout<<"\t\t___________________"<<endl;
    cout<<"\t\t     |       |     "<<endl;
    cout<<"\t\t"<<board[2][0]<<"    |   "<<board[2][1]<<"   |   "<<board[2][2]<<endl;
    cout<<"\t\t     |       |     "<<endl;
}
int main(){
    while(gameover()){
        displayboard();
        player_turn();
    }
    if(turn=='X'&&draw==false){
        cout<<endl;
        cout<<"Congrats Player -2 won the Game"<<endl;
    }
    else if(turn=='O'&&draw==false){
        cout<<endl;
        cout<<"Congrats Player -1 won the Game"<<endl;
    }
    else{
        cout<<endl;
        cout<<"Game Ended in DRAW,Play again to find the real winner"<<endl;
    }
}