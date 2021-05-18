#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)

class Board   //contains specifications of board
{
    private:
        int size; //board is of size size*size
        int* array; 
        set<pair<int,int>>items; 
        int player1,player2; //current pos of players
        
    public:
        Board(int size){     //Constructor
            this->size=size;
            array=new int[size*size+1];
        }
        
        
        void addItem(int int_pos,int fin_pos)
        {
            int flag=1;
            for(auto i:items){if(i.first==int_pos){flag=0;}}
            
            if(flag==0){cout<<"error- initial pos already in use"<<endl;}
            else{items.insert({int_pos,fin_pos});}
        }
        
        
        void config_board()
        {
            player1=1;player2=1;
            
            rep(i,1,size*size+1){array[i]=0;}
            
            for(auto i:items)
            {
                array[i.first]=i.second-i.first;
            }
        }
        
        
        void move(int inc,int player_id)
        {
            //player1=100;player2=100;
            if(player_id==1)
            {
                int next_pos=player1+inc;
                //cerr<<next_pos<<" ";
                if(next_pos>size*size){return;}
                else
                {
                    while(array[next_pos]!=0)
                    {
                        next_pos=next_pos+array[next_pos];
                        if(next_pos==size*size){break;}
                    }
                    player1=next_pos;
                }
            }
            
            else
            {
                int next_pos=player2+inc;
                //cerr<<next_pos<<endl;
                if(next_pos>size*size){return;}
                else
                {
                    while(array[next_pos]!=0)
                    {
                        next_pos=next_pos+array[next_pos];
                        if(next_pos==size*size){break;}
                    }
                    player2=next_pos;
                }
            }
            
        }
        
        
        int p1_pos()
        {
            return player1;
        }
        int p2_pos()
        {
            return player2;
        }
        
};


int main() {
    
    Board b(10);
    b.addItem(10,20);
    b.addItem(30,20);
    b.config_board();
    int count=105;
    
    
    srand (time(NULL));
    while(b.p1_pos()<100&&b.p2_pos()<100&&count--)
    {
        
        int random=rand()%6+1;
        b.move(random,1);
        if(b.p1_pos()==100){break;}
        random=rand()%6+1;
        b.move(random,2);
        if(b.p2_pos()==100){break;}

    }
    
    if(b.p2_pos()==100){cout<<"P2 wins";}
    else if(b.p1_pos()==100){cout<<"P1 wins";}
    
    
    
	
	return 0;
}
